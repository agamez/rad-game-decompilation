#!/usr/bin/env python3
"""
Batch rename fn1EDA_XXXX -> util_XXXX across the entire codebase.
"""

import re
import os

RENAME_MAP = {
    'fn1EDA_0000': 'util_init_program',
    'fn1EDA_00E2': 'util_fatal_enter',
    'fn1EDA_00E9': 'util_fatal_dispatcher',
    'fn1EDA_00ED': 'util_fatal_handle',
    'fn1EDA_00FC': 'util_find_heap_block',
    'fn1EDA_011B': 'util_fatal_cleanup',
    'fn1EDA_01A5': 'util_puts',
    'fn1EDA_01B3': 'util_putdec16',
    'fn1EDA_01BF': 'util_putdec8',
    'fn1EDA_01CD': 'util_putdec32',
    'fn1EDA_01D4': 'util_puthex8',
    'fn1EDA_01DF': 'util_puthexnibble',
    'fn1EDA_01E7': 'util_console_putc',
    'fn1EDA_023F': 'util_heap_alloc',
    'fn1EDA_0254': 'util_heap_free',
    'fn1EDA_0308': 'util_heap_alloc_core',
    'fn1EDA_03D3': 'util_heap_free_insert',
    'fn1EDA_0432': 'util_heap_coalesce',
    'fn1EDA_0491': 'util_align_heap',
    'fn1EDA_04A2': 'util_get_error_word',
    'fn1EDA_04A9': 'util_check_error',
    'fn1EDA_04B7': 'util_check_bounds',
    'fn1EDA_04F5': 'util_stream_init',
    'fn1EDA_0565': 'util_stream_open_read',
    'fn1EDA_056A': 'util_stream_open_write',
    'fn1EDA_0572': 'util_stream_reopen',
    'fn1EDA_05BF': 'util_stream_close',
    'fn1EDA_05FB': 'util_stream_dispatch_cb',
    'fn1EDA_0776': 'util_stream_prelude_getc',
    'fn1EDA_079A': 'util_stream_getc',
    'fn1EDA_07B6': 'util_stream_prelude_putc',
    'fn1EDA_07DA': 'util_stream_putc',
    'fn1EDA_07E9': 'util_stream_flush_block',
    'fn1EDA_0801': 'util_stream_error_epilogue',
    'fn1EDA_060C': 'util_stream_cb_open',
    'fn1EDA_068E': 'util_stream_trim_append',
    'fn1EDA_06E8': 'util_stream_cb_read',
    'fn1EDA_0718': 'util_stream_cb_write',
    'fn1EDA_073D': 'util_stream_cb_char_write',
    'fn1EDA_075D': 'util_stream_cb_close',
    'fn1EDA_081A': 'util_stream_read_line',
    'fn1EDA_0848': 'util_stream_write_crlf',
    'fn1EDA_086C': 'util_stream_flush',
    'fn1EDA_0879': 'util_stream_flush_cb',
    'fn1EDA_0896': 'util_stream_read_string',
    'fn1EDA_08CE': 'util_stream_write_padded',
    'fn1EDA_0918': 'util_stream_scan_char',
    'fn1EDA_0953': 'util_copy_bytes',
    'fn1EDA_096F': 'util_multiply_32x32',
    'fn1EDA_098A': 'util_divide_32x32',
    'fn1EDA_0A1F': 'util_copy_lenstr',
    'fn1EDA_0A39': 'util_copy_lenstr_clamp',
    'fn1EDA_0A6B': 'util_substr',
    'fn1EDA_0AAC': 'util_append_lenstr',
    'fn1EDA_0AD8': 'util_match_lenstr',
    'fn1EDA_0B24': 'util_cmp_lenstr',
    'fn1EDA_0B4F': 'util_make_lenstr_byte',
    'fn1EDA_0B61': 'util_make_lenstr_word',
    'fn1EDA_0B7C': 'util_record_wrap',
    'fn1EDA_0BD0': 'util_record_wrap_cond',
    'fn1EDA_0CD4': 'util_bit_test',
    'fn1EDA_0D80': 'util_divide_random',
    'fn1EDA_0DCF': 'util_random_next',
    'fn1EDA_0E07': 'util_latch_time',
    'fn1EDA_0E14': 'util_format_i32',
    'fn1EDA_0E8E': 'util_parse_number',
    'fn1EDA_0F26': 'util_format_field',
    'fn1EDA_0F71': 'util_parse_field',
    'fn1EDA_0FA2': 'util_stream_reinit',
    'fn1EDA_0FD0': 'util_stream_open',
    'fn1EDA_1051': 'util_stream_close_rearm',
    'fn1EDA_1076': 'util_stream_is_open',
    'fn1EDA_1085': 'util_stream_read_record',
    'fn1EDA_108C': 'util_stream_write_record',
    'fn1EDA_1091': 'util_stream_io_record',
    'fn1EDA_10BB': 'util_stream_read_records',
    'fn1EDA_1123': 'util_stream_seek_record',
    'fn1EDA_116A': 'util_stream_record_count',
    'fn1EDA_1185': 'util_stream_eof_check',
    'fn1EDA_119A': 'util_stream_size_restore',
    'fn1EDA_11DF': 'util_overlap_copy',
    'fn1EDA_1202': 'util_fill_bytes',
    'fn1EDA_1216': 'util_fill_cmdline',
    'fn1EDA_1265': 'util_count_tokens',
    'fn1EDA_126C': 'util_tokenize_psp',
    'fn1EDA_129E': 'util_build_cwd_path',
    'fn1EDA_1384': 'util_uppercase',
}

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_DIR = os.path.join(PROJECT_ROOT, 'src')


def is_comment_line(line):
    """Check if the line is a C comment (/* ... */ or // ... or block comment continuation)."""
    stripped = line.lstrip()
    if stripped.startswith('/*') or stripped.startswith('*/') or stripped.startswith('//'):
        return True
    if stripped.startswith('*'):
        return True
    return False


def is_fn_def(line, old_name, new_name):
    """Check if line is a function definition (not a declaration, call, or comment)."""
    if is_comment_line(line):
        return False

    pat = r'\b' + re.escape(new_name) + r'\b\s*\('
    if not re.search(pat, line):
        return False

    m = re.search(pat, line)
    pos = m.start()
    before = line[:pos].rstrip()

    if not before.strip():
        return False

    bs = before.strip()
    if '=' in before:
        return False
    if bs.startswith('('):
        return False
    if bs.endswith(')'):
        return False

    after_fn = line[m.end():]
    last_paren = after_fn.rfind(')')
    if last_paren >= 0:
        rest = after_fn[last_paren+1:].strip()
        if rest == ';' or rest.startswith(';'):
            return False

    lc = before.rstrip()
    if not lc or lc[-1] not in 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_*&':
        return False

    return True


def rename_file(fpath):
    with open(fpath, 'r') as f:
        content = f.read()

    original = content

    # Step 1: Replace all old names with new names first
    for old_name, new_name in RENAME_MAP.items():
        content = re.sub(r'\b' + re.escape(old_name) + r'\b', new_name, content)

    # Step 2: For .c files, add /* was ... */ before function definitions
    lines = content.split('\n')
    insertions = []
    for i, line in enumerate(lines):
        for old_name, new_name in RENAME_MAP.items():
            if is_fn_def(line, old_name, new_name):
                indent = ''
                for ch in line:
                    if ch in (' ', '\t'):
                        indent += ch
                    else:
                        break
                insertions.append((i, indent + '/* was ' + old_name + ' */'))
                break

    for idx, text in reversed(insertions):
        lines.insert(idx, text)

    content = '\n'.join(lines)

    if content != original:
        with open(fpath, 'w') as f:
            f.write(content)
        return True
    return False


def main():
    files = []
    for root, dirs, filenames in os.walk(SRC_DIR):
        for fname in filenames:
            if fname.endswith('.c') or fname.endswith('.h'):
                files.append(os.path.join(root, fname))
    files.sort()

    count = 0
    for fpath in files:
        if rename_file(fpath):
            print("  Updated: " + os.path.relpath(fpath, SRC_DIR))
            count += 1

    print("\nDone. Updated " + str(count) + " files.")


if __name__ == '__main__':
    main()
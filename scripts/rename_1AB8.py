#!/usr/bin/env python3
"""Batch rename fn1AB8_XXXX → bgi_<semantic> in src/ seg1AB8 files.

For each function:
  - On the C definition line: replace name and add /* was old_name */
  - On the header declaration lines: just replace name  
  - On all other lines (calls, references): just replace name
"""

import re
import os
import sys

# ====== Mapping: old_name -> new_name ======
RENAME_MAP = [
    ("fn1AB8_0000",   "bgi_print_error_code"),
    ("fn1AB8_008B",   "bgi_error_not_initialized"),
    ("fn1AB8_027E",   "bgi_color_name_to_string"),
    ("fn1AB8_04F3",   "bgi_get_error_code"),
    ("fn1AB8_0569",   "bgi_reloc_copy_with_alignment"),
    ("fn1AB8_05D3",   "bgi_find_video_driver_index"),
    ("fn1AB8_06CA",   "bgi_unload_video_driver"),
    ("fn1AB8_0813",   "bgi_init_graphics_error"),
    ("fn1AB8_0887",   "bgi_open_video_driver_file"),
    ("fn1AB8_097B",   "bgi_install_video_driver"),
    ("fn1AB8_0AEE",   "bgi_init_graphics_system"),
    ("fn1AB8_0BAE",   "bgi_load_bgi_driver"),
    ("fn1AB8_0E88",   "bgi_swap_graphics_gateway"),
    ("fn1AB8_0EB5",   "bgi_shutdown_video_driver"),
    ("fn1AB8_0F80",   "bgi_set_text_window"),
    ("fn1AB8_0F93",   "bgi_draw_text_rectangle"),
    ("fn1AB8_1028",   "bgi_update_text_window_position"),
    ("fn1AB8_108B",   "bgi_set_text_color"),
    ("fn1AB8_10A8",   "bgi_get_text_foreground"),
    ("fn1AB8_10BB",   "bgi_get_text_background"),
    ("fn1AB8_10CE",   "bgi_get_text_cols"),
    ("fn1AB8_10E1",   "bgi_get_text_rows"),
    ("fn1AB8_10F4",   "bgi_set_text_background_color"),
    ("fn1AB8_112E",   "bgi_clip_text_rectangle"),
    ("fn1AB8_1175",   "bgi_set_text_font_size"),
    ("fn1AB8_11A0",   "bgi_load_font_file"),
    ("fn1AB8_11FB",   "bgi_get_char_byte_width"),
    ("fn1AB8_122E",   "bgi_draw_scaled_text_number"),
    ("fn1AB8_1250",   "bgi_set_text_color_attribute"),
    ("fn1AB8_1285",   "bgi_get_text_color_info"),
    ("fn1AB8_129A",   "bgi_install_text_font"),
    ("fn1AB8_1342",   "bgi_set_text_character_color"),
    ("fn1AB8_1384",   "bgi_load_font_info"),
    ("fn1AB8_13A3",   "bgi_clamp_rectangle_coords"),
    ("fn1AB8_13D7",   "bgi_signed_rectangle_intersect"),
    ("fn1AB8_1492",   "bgi_draw_text_string"),
    ("fn1AB8_14F4",   "bgi_set_text_rectangle"),
    ("fn1AB8_1536",   "bgi_load_video_driver_file"),
    ("fn1AB8_1783",   "bgi_display_error_string"),
    ("fn1AB8_17AE",   "bgi_init_graphics_driver"),
    ("fn1AB8_1807",   "bgi_driver_trampoline"),
    ("fn1AB8_180A",   "bgi_init_video_mode"),
    ("fn1AB8_1855",   "bgi_set_text_cursor_position"),
    ("fn1AB8_1895",   "bgi_draw_text"),
    ("fn1AB8_18E3",   "bgi_set_video_mode"),
    ("fn1AB8_194E",   "bgi_set_text_style"),
    ("fn1AB8_1968",   "bgi_set_text_cursor_attributes"),
    ("fn1AB8_1992",   "bgi_set_text_color_palette"),
    ("fn1AB8_19A6",   "bgi_compute_char_block_size"),
    ("fn1AB8_19EE",   "bgi_select_text_mode"),
    ("fn1AB8_1A62",   "bgi_sync_text_mode"),
    ("fn1AB8_1A84",   "bgi_clear_video_state"),
    ("fn1AB8_1AA6",   "bgi_set_active_font"),
    ("fn1AB8_1AC2",   "bgi_clear_text_window"),
    ("fn1AB8_1ACE",   "bgi_set_text_window_position"),
    ("fn1AB8_1AF6",   "bgi_set_pixel"),
    ("fn1AB8_1B3E",   "bgi_draw_rectangle"),
    ("fn1AB8_1B90",   "bgi_draw_scaled_text"),
    ("fn1AB8_1C32",   "bgi_get_text_cursor_attributes"),
    ("fn1AB8_1C4A",   "bgi_get_char_width"),
    ("fn1AB8_1C5A",   "bgi_get_char_cell_height"),
    ("fn1AB8_1C6A",   "bgi_get_char_info"),
    ("fn1AB8_1C93",   "bgi_get_current_page"),
    ("fn1AB8_1CA4",   "bgi_select_text_font"),
    ("fn1AB8_1CBA",   "bgi_get_pixel"),
    ("fn1AB8_1CD7",   "bgi_text_cell_color"),
    ("fn1AB8_1CED",   "bgi_set_text_style_attribute"),
    ("fn1AB8_1CFF",   "bgi_set_color_attributes"),
    ("fn1AB8_1D5B",   "bgi_set_text_color_attributes"),
    ("fn1AB8_1D82",   "bgi_get_char_size_info"),
    ("fn1AB8_1DA6",   "bgi_get_text_color_selector"),
    ("fn1AB8_1E0B",   "bgi_advance_text_pointer"),
    ("fn1AB8_1E26",   "bgi_get_string_length"),
    ("fn1AB8_1E3C",   "bgi_draw_line"),
    ("fn1AB8_1E54",   "bgi_get_line_attributes"),
    ("fn1AB8_1E6B",   "bgi_draw_clip_rectangle"),
    ("fn1AB8_1E9F",   "bgi_draw_char_pixel"),
    ("fn1AB8_1EE3",   "bgi_init_video_mode_info"),
    ("fn1AB8_1F19",   "bgi_detect_video_mode"),
    ("fn1AB8_1F80",   "bgi_get_vga_info"),
    ("fn1AB8_1F9E",   "bgi_set_video_adapter_type"),
    ("fn1AB8_1FDE",   "bgi_video_mode_valid"),
    ("fn1AB8_1FED",   "bgi_get_display_combo_code"),
    ("fn1AB8_200E",   "bgi_check_video_memory"),
    ("fn1AB8_2011",   "bgi_detect_vga_adapter"),
    ("fn1AB8_2043",   "bgi_detect_video_adapter"),
]

# Static helper functions (not in header, only in .c files)
STATIC_RENAME_MAP = [
    ("fn1AB8_051F",   "bgi_alloc_driver_blob"),
    ("fn1AB8_0538",   "bgi_free_driver_blob"),
    ("fn1AB8_call_0B896", "bgi_call_display_driver_cb"),
    ("fn1AB8_call_0B820", "bgi_call_graphics_driver"),
]


def find_definition_line(line, old_name):
    """Check if line is a function definition/declaration for old_name.
    Returns the return type prefix or None."""
    # Simple approach: check if the line has old_name followed by ( or ;
    # and has a return type before it
    idx = line.find(old_name)
    if idx == -1:
        return None
    # Check what follows
    after = line[idx + len(old_name):]
    if after.startswith('(') or after.startswith(';'):
        # Check that there's a return type before old_name
        before = line[:idx].rstrip()
        if not before:
            return None
        # Check it ends with a type keyword or pointer star
        # This handles: void, u16, u8, u32, s16, s32, u8*, void*, u16*, etc.
        # Also handles static, inline, extern qualifiers
        type_pattern = re.compile(
            r'^\s*(?:static\s+)?(?:inline\s+)?(?:extern\s+)?'
            r'(?:void|u8|u16|u32|s16|s32|u8\*|void\*|u16\*|u32\*)\s*$',
            re.MULTILINE
        )
        return type_pattern.search(before)
    return None


def rename_in_line(line, old_name, new_name):
    """Replace old_name with new_name, adding /* was old_name */ on definition lines."""
    result = find_definition_line(line, old_name)
    if result:
        line = line.replace(old_name, new_name)
        line = line.rstrip('\n')
        if f'/* was {old_name} */' not in line:
            line += f'  /* was {old_name} */'
        line += '\n'
        return line, True  # was a definition
    else:
        if old_name in line:
            return line.replace(old_name, new_name), False  # just a replacement
        return line, False


def rename_file(filepath, rename_list):
    """Process one file with the given rename list."""
    try:
        with open(filepath, 'r') as f:
            content = f.read()
    except (FileNotFoundError, UnicodeDecodeError):
        return 0

    original = content
    new_content = content

    for old_name, new_name in rename_list:
        if old_name not in new_content:
            continue
        # Process line by line for definition detection
        lines = new_content.split('\n')
        new_lines = []
        for line in lines:
            new_line, is_def = rename_in_line(line, old_name, new_name)
            new_lines.append(new_line)
        new_content = '\n'.join(new_lines)

    if new_content != original:
        with open(filepath, 'w') as f:
            f.write(new_content)
        return 1
    return 0


def main():
    src_dir = "/home/sslayer/Proyectos/rad/src"
    
    all_files = sorted([f for f in os.listdir(src_dir) if f.endswith('.c') or f.endswith('.h')])
    
    total_changed = 0
    
    for filename in all_files:
        filepath = os.path.join(src_dir, filename)
        
        if filename == 'seg1AB8.h':
            # Header: only public function declarations, no def annotation
            try:
                with open(filepath, 'r') as f:
                    content = f.read()
                old_content = content
                for old_name, new_name in RENAME_MAP:
                    content = content.replace(old_name, new_name)
                if content != old_content:
                    with open(filepath, 'w') as f:
                        f.write(content)
                    print(f"  Modified: {filename}")
                    total_changed += 1
            except Exception as e:
                print(f"  ERROR {filename}: {e}", file=sys.stderr)
        
        elif filename == 'seg1AB8_driverB.c':
            # Driver batch: only static helpers (no public functions here)
            changed = rename_file(filepath, STATIC_RENAME_MAP)
            if changed:
                print(f"  Modified: {filename} (static helpers)")
                total_changed += 1
        else:
            # Part files: public functions first, then static helpers
            c1 = rename_file(filepath, RENAME_MAP)
            c2 = rename_file(filepath, STATIC_RENAME_MAP)
            if c1 or c2:
                print(f"  Modified: {filename} ({c1 + c2} passes)")
                total_changed += 1

    print(f"\nTotal files modified: {total_changed}")
    
    # Verify no remaining fn1AB8_ public function references in src/
    import subprocess
    result = subprocess.run(
        ['grep', '-n', '-E', r'\bfn1AB8_[0-9A-Fa-f]{4}\b', 
         '--include=*.c', '--include=*.h', src_dir],
        capture_output=True, text=True
    )
    if result.stdout:
        print("\nRemaining fn1AB8_ references:")
        print(result.stdout)
    else:
        print("\nAll fn1AB8_ public function references successfully renamed.")


if __name__ == "__main__":
    main()
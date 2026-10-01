#!/usr/bin/env python3
"""Add /* was fn1AB8_XXXX */ to function definition lines in seg1AB8_part*.c files."""

import re
import os
import glob

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
    ("fn1AB8_051F",   "bgi_alloc_driver_blob"),
    ("fn1AB8_0538",   "bgi_free_driver_blob"),
    ("fn1AB8_call_0B896", "bgi_call_display_driver_cb"),
    ("fn1AB8_call_0B820", "bgi_call_graphics_driver"),
]

NEW_TO_OLD = {v: k for k, v in RENAME_MAP}

def process_file(fpath):
    fname = os.path.basename(fpath)
    with open(fpath, 'r') as f:
        lines = f.readlines()

    count = 0
    new_lines = []
    for line in lines:
        stripped = line.rstrip('\n')

        # Match bgi_name( at a position where there's a return type before it
        m = re.search(r'\b(bgi_[a-zA-Z_]+)\(', stripped)
        if m:
            new_name = m.group(1)
            old_name = NEW_TO_OLD.get(new_name)
            if old_name:
                if f'/* was {old_name} */' in stripped:
                    continue  # already annotated

                # Check that the part before the function name ends with a return type
                before = stripped[:m.start()].rstrip()
                # Match: (static | inline | extern)? followed by return type at end
                # Return types: void, u8, u16, u32, s16, s32, u8*, void*, u16*
                if re.match(r'(?:static\s+|inline\s+|extern\s+)?(?:void|u8|u16|u32|s16|s32|u8 \*|void \*|u16 \*|u32 \*)\s*$', before):
                    stripped += '  /* was %s */' % old_name
                    count += 1

        new_lines.append(stripped + '\n')

    if count > 0:
        with open(fpath, 'w') as f:
            f.writelines(new_lines)

    return count

src_dir = "/home/sslayer/Proyectos/rad/src"
total = 0
for fpath in sorted(glob.glob(os.path.join(src_dir, "seg1AB8_part*.c"))):
    c = process_file(fpath)
    if c > 0:
        print(f"  Annotated {c} definitions: {os.path.basename(fpath)}")
        total += c

# Also process the header
for fpath in sorted(glob.glob(os.path.join(src_dir, "seg1AB8_driverB.c"))):
    c = process_file(fpath)
    if c > 0:
        print(f"  Annotated {c} definitions: {os.path.basename(fpath)}")
        total += c

print(f"\nTotal definitions annotated: {total}")
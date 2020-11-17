#include QMK_KEYBOARD_H
#include "keymap_french.h"

enum alt_keycodes {
	U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

enum custom_layers {
	CL_STD, // Standard
	CL_CTM, // Custom
	CL_NMB, // Numbers
	CL_MOV, // Movements
	CL_ERA, // Erase
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [CL_STD] = LAYOUT_65_ansi_blocker(
        KC_ESC,  FR_AMPR, FR_EACU, FR_DQUO, FR_QUOT, FR_LPRN, FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN,    FR_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,    FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,    FR_CIRC,    FR_DLR,  KC_BSLS, TG(CL_GAM), \
        KC_CAPS, FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,    FR_H,    FR_J,    FR_K,    FR_L,    FR_M,    FR_UGRV,             KC_ENT,  KC_PGUP, \
        KC_LSFT, FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, KC_RSFT,             KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, TG(CL_CTM), KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [CL_CTM] = LAYOUT_65_ansi_blocker(
        _______,      _______, _______,      _______,         _______, _______, _______,          _______,      _______, _______,         _______, _______,    _______, _______, MD_BOOT, \
        _______,      _______, _______,      _______,         _______, _______, _______,          _______,      _______, _______,         _______, _______,    _______, RGB_HUD, RGB_HUI, \
        _______, LSFT_T(FR_Q), _______, LALT_T(FR_D), LT(CL_NMB,FR_F), _______, _______, LT(CL_MOV, FR_J), LALT_T(FR_K), _______,    RSFT_T(FR_M), _______,             _______, RGB_VAI, \
        _______, LCTL_T(FR_W), _______,      _______,         _______, _______, _______,          _______,      _______, _______, RCTL_T(FR_ASTR), _______,             RGB_TOG, RGB_VAD, \
        _______,      _______, _______,                              LT(CL_ERA, KC_SPC),                                                  _______, _______, KC_MUTE, KC_VOLD, KC_VOLU  \
    ),
    [CL_NMB] = LAYOUT_65_ansi_blocker(
	    _______, _______, _______,   _______, _______, _______, _______,  KC_F7,     KC_F8,   KC_F9,         KC_F10,  KC_F11,  KC_F12, RGB_MOD, RGB_RMOD, \
        _______, _______, _______,   _______, _______, _______, _______,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ASTERISK, _______, _______, _______, _______, \
	    _______, _______, _______, KC_KP_DOT, _______, _______, KC_EQUAL, KC_KP_4, KC_KP_5, KC_KP_6,    KC_KP_MINUS, _______,          _______, _______, \
        _______, _______, _______,   _______, _______, _______, KC_KP_0,  KC_KP_1, KC_KP_2, KC_KP_3,     KC_KP_PLUS, _______,          _______, _______, \
	    _______, _______, _______,                              _______,                                    _______, _______, _______, _______, _______ \
    ),
    [CL_MOV] = LAYOUT_65_ansi_blocker(
        FR_SUP2, KC_F1,   KC_F2,     KC_F3,    KC_F4,   KC_F5,   KC_F6, _______,         _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_PGUP, KC_HOME,   KC_UP,   KC_END, KC_PGDN, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
        _______, FR_LBRC, KC_LEFT, KC_DOWN, KC_RIGHT, FR_RBRC, _______, _______, LALT_T(FR_LPRN), FR_RPRN, _______, _______,          _______, _______, \
        _______, FR_LESS, FR_TILD, FR_PERC,  FR_HASH,  FR_DLR, _______, _______,         _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                             _______,                                    _______, _______, _______, _______, _______  \
    ),
    [CL_ERA] = LAYOUT_65_ansi_blocker(
        DBG_MTRX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        DBG_KBD, _______, _______, _______, _______, FR_LCBR, FR_RCBR, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, KC_BSPC,  KC_DEL, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),

    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool is_fn_activated(void) {
	return IS_LAYER_ON(CL_CTM);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
	                rgb_matrix_set_flags(LED_FLAG_NONE);
	                rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}



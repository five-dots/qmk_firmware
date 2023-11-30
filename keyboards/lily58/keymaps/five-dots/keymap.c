#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  MT_CJEC = SAFE_RANGE,
};

// Layer Mod-Tap
#define LMT_LWR LT(_LOWER, KC_Q)

// Layer Switch
#define MO_LWR MO(_LOWER)

// Mod-Tap
#define MT_SSPC SFT_T(KC_SPC)  // Shift when held, SPC when tapped
#define MT_GF12 GUI_T(KC_F12)  // Super when held, F12 when tapped
#define MT_GHEN GUI_T(KC_HENK) // Super when held, Henkan when tapped
#define MT_ECTL CTL_T(KC_ESC)  // Cntrol when held, ESC when tapped

// Shortcut
#define COPY C(KC_C)
#define CUT  C(KC_X)
#define PSTE C(KC_V)
#define UNDO C(KC_Z)
#define SALL C(KC_A) // Select All

#define NTAB C(KC_TAB)   // Next TAB (Ctrl+Tab)
#define PTAB RCS(KC_TAB) // Previous TAB (Ctrl+Shift+Tab)
#define CTAB C(KC_W)     // Close TAB/Window

#define VOLU KC__VOLUP
#define VOLM KC__MUTE
#define VOLD KC__VOLDOWN

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------.              ,-----------------------------------.
 * |   `  |  1  |  2  |  3  |  4  |  5  |              |  6  |  7  |  8  |  9  |  0  |  -  |
 * |------+-----+-----+-----+-----+-----|              |-----+-----+-----+-----+-----+-----|
 * | TAB  |  Q  |  W  |  E  |  R  |  T  |              |  Y  |  U  |  I  |  O  |  P  |  \  |
 * |------+-----+-----+-----+-----+-----|              |-----+-----+-----+-----+-----+-----|
 * | CTL' |  A  |  S  |  D  |  F  |  G  |-----.  ,-----|  H  |  J  |  K  |  L  |  ;  |  '  |
 * |------+-----+-----+-----+-----+-----|  [  |  |  ]  |-----+-----+-----+-----+-----+-----|
 * | SHFT |  Z  |  X  |  C  |  V  |  B  |-----|  |-----|  N  |  M  |  ,  |  .  |  /  |  =  |
 * `-----------------------------------/     /    \     \----------------------------------'
 *                | LWR | ALT | GUI'| / SPC'/      \ ENT \ | BSP | DEL | ESC |
 *                `------------------------'        '------------------------'
 */

[_QWERTY] = LAYOUT( \
//_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  LMT_LWR, KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  MT_ECTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,  \
                    MO_LWR,  KC_LALT, MT_GHEN, MT_SSPC,                   KC_ENT,  KC_BSPC, KC_DEL,  KC_ESC \
),

/* LOWER
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |  F12 |  F13 |  F14 | VOL+ |                  | Copy | Undo | PgUp | Ins  | Pste |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      | SALL |      |      |      | MUTE |-------.  ,-------| Left | Down |  Up  | Right| End  |      |
 * |------+------+------+------+------+------|       |  |       |------+------+------+------+------+------|
 * |      |      | CUT  |      |      | VOL- |-------|  |-------| Home | PgDn | PTab | NTab | PSCR |      |
 * `-----------------------------------------/      /    \      \-----------------------------------------'
 *                   |      |      |      | /      /      \      \ |      |      |      |
 *                   `----------------------------'        '----------------------------'
 */

[_LOWER] = LAYOUT( \
//_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 , \
  _______, _______, KC_F12,  KC_F13 , KC_F14 , VOLU,                      COPY,    UNDO,    KC_PGUP, KC_INS,  PSTE,    _______, \
  _______, _______, _______, _______, SALL,    VOLM,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  _______, \
  _______, _______, _______, _______, CUT,     VOLD,    _______, _______, KC_HOME, KC_PGDN, PTAB,    NTAB,    CTAB,    KC_PSCR, \
                    _______, _______, _______, _______,                   _______, KC_DEL,  _______, _______ \
),

/* RAISE
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.  ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |  |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|  |-------|      |      |      |      |      |      |
 * `-----------------------------------------/      /    \      \-----------------------------------------'
 *                   |      |      |      | /      /      \      \ |      |      |      |
 *                   `----------------------------'        '----------------------------'
 */

[_RAISE] = LAYOUT( \
//_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______,                   _______, _______, _______, _______ \
),

/* ADJUST
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.  ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |  |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|  |-------|      |      |      |      |      |      |
 * `-----------------------------------------/      /    \      \-----------------------------------------'
 *                   |      |      |      | /      /      \      \ |      |      |      |
 *                   `----------------------------'        '----------------------------'
 */

[_ADJUST] = LAYOUT(                                                     \
//_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______,                   _______, _______, _______, _______ \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_ENABLE

uint16_t key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Ctrl when held, [Muhenkan -> ESC] when tapped
    // https://www.reddit.com/r/olkb/comments/afm9ii/qmk_macro_in_modtap_keys/e%20%7B%20unregister_c
    case MT_CJEC:
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
        if (timer_elapsed(key_timer) < TAPPING_TERM) {
          tap_code(KC_MHEN);
          tap_code(KC_ESC);
        }
      }
      break;
  }
  return true;
}

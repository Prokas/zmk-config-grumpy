#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>

#define APT 0
#define NUM 1
#define NAV 2
#define SYM 3
#define FUN 4

// &lt {
//     quick_tap_ms = <170>;
// };

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
    macros {
        macro_shiftable_sch: macro_shiftable_sch {
            label = "Macro_shiftable_sch";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <
                    &macro_tap &kp S
                    &macro_release &kp RSHIFT
                    &macro_tap &kp C &kp H
            >;
            tap-ms = <10>;
        };
    };
};


#define COMBO(NAME, BINDINGS, KEYPOS) \
combo_##NAME { \
    timeout-ms = <20>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
};

/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        COMBO(q, &kp Q, 0 1)
        COMBO(z, &kp Y, 4 5)
        COMBO(v, &kp X, 19 20)
        COMBO(sch, &macro_shiftable_sch, 0 2)
        COMBO(slash, &kp SLASH, 23 24)
        COMBO(dash, &kp MINUS, 22 23)
        COMBO(enter, &kp ENTER, 22 24)
        COMBO(esc, &kp ESC, 20 21)
        COMBO(h, &kp H, 13 22)
/* parentheticals */
        COMBO(lbrc, &kp LBRC, 0 9)
        COMBO(lbkt, &kp LBKT, 1 10)
        COMBO(lpar, &kp LPAR, 2 11)
        COMBO(lt, &kp LT, 3 12)
        COMBO(gt, &kp GT, 4 13)
        COMBO(rpar, &kp RPAR, 5 14)
        COMBO(rbkt, &kp RBKT, 6 15)
        COMBO(rbrc, &kp RBRC, 7 16)
/* caps */
        COMBO(caps, &caps_word, 11 14)
        COMBO(capslock, &kp CAPSLOCK, 0 7)
/* deletion */
        COMBO(bspc, &kp BSPC, 5 6)
        COMBO(del, &kp DEL, 6 7)
        COMBO(delword, &kp LC(BSPC), 5 7)
/* alternative shifting */
    
        COMBO(Scomma, &kp SEMI, 23 27)
        COMBO(Sdot, &kp COLON, 24 27)
        COMBO(Se, &kp LS(E), 14 15 27)
    };
};
//   ____________________________  ____________________________
//  /       0  |  1  |  2  |  3  \/   4 |   5 |   6 |   7      \
// |  8  |  9  | 10  | 11  | 12  /\  13 |  14 |  15 |  16 | 17  |
// | 19  | 19  | 20  | 21       /  \       22 |  23 |  24 | 25  |
//                      \  26  /    \  27  /
//                       ------      ------


/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <4 5 6 7 13 14 15 16 17 22 23 24 25 26 27>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 8 9 10 11 12 17 18 19 20 21 26>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <160>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            // hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25>;
        };
//   ____________________________  ____________________________
//  /       0  |  1  |  2  |  3  \/   4 |   5 |   6 |   7      \
// |  8  |  9  | 10  | 11  | 12  /\  13 |  14 |  15 |  16 | 17  |
// | 18  | 19  | 20  | 21       /  \       22 |  23 |  24 | 25  |
//                      \  26  /    \  27  /
//                       ------      ------


        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};

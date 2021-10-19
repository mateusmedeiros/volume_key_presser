#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#define VOLUME_DOWN 0xAE
#define VOLUME_UP 0xAF
#define KEY_DOWN 0x0000
#define KEY_UP 0x0002
#define UNUSED_SCAN_CODE 0
#define UNUSED_EXTRA_VALUE 0

int main(int argc, char** argv) {
    bool has_argument = argc > 1;

    if (has_argument) {
        int is_vol_down_key = strcmp(argv[1], "down") == 0;
        int is_vol_up_key = strcmp(argv[1], "up") == 0;

        if (!is_vol_up_key && !is_vol_down_key) {
            return 0;
        }

        BYTE keycode;

        if (is_vol_down_key) {
            keycode = VOLUME_DOWN;
        } else {
            keycode = VOLUME_UP;
        }

        keybd_event(keycode, UNUSED_SCAN_CODE, KEY_DOWN, UNUSED_EXTRA_VALUE);
        Sleep(50);
        keybd_event(keycode, UNUSED_SCAN_CODE, KEY_UP, UNUSED_EXTRA_VALUE);
    } else {
        printf("volume_key_presser up / volume_key_presser down");
    }
        
    return 0;
}
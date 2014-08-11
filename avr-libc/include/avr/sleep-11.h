    #define SLEEP_MODE_IDLE         (0)
    #define SLEEP_MODE_PWR_DOWN     (SLEEP_SMODE1_bm)
    #define SLEEP_MODE_PWR_SAVE     (SLEEP_SMODE1_bm | SLEEP_SMODE0_bm)
    #define SLEEP_MODE_STANDBY      (SLEEP_SMODE2_bm | SLEEP_SMODE1_bm)
    #define SLEEP_MODE_EXT_STANDBY  (SLEEP_SMODE2_bm | SLEEP_SMODE1_bm | SLEEP_SMODE0_bm)

    #define set_sleep_mode(mode) \
    do { \
        _SLEEP_CONTROL_REG = ((_SLEEP_CONTROL_REG & ~(SLEEP_SMODE2_bm | SLEEP_SMODE1_bm | SLEEP_SMODE0_bm)) | (mode)); \
    } while(0)

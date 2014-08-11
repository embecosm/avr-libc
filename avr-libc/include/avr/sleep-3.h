    #define SLEEP_MODE_IDLE         0
    #define SLEEP_MODE_PWR_DOWN     _BV(SM)

    #define set_sleep_mode(mode) \
    do { \
        _SLEEP_CONTROL_REG = ((_SLEEP_CONTROL_REG & ~_BV(SM)) | (mode)); \
    } while(0)

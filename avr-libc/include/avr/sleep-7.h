    #define SLEEP_MODE_IDLE         0
    #define SLEEP_MODE_PWR_DOWN     _BV(SM1)
    #define SLEEP_MODE_PWR_SAVE     (_BV(SM0) | _BV(SM1))

    #define set_sleep_mode(mode) \
    do { \
        _SLEEP_CONTROL_REG = ((_SLEEP_CONTROL_REG & ~(_BV(SM0) | _BV(SM1))) | (mode)); \
    } while(0)

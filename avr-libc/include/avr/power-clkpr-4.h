typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7
} clock_div_t;

static __inline__ void system_clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

void system_clock_prescale_set(clock_div_t __x)
{
    uint8_t __t;
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "in %[temp],%[clpr]" "\n\t"
        "out %[clpr],%[enable]" "\n\t"
        "andi %[temp],%[not_CLKPS]" "\n\t"
        "or %[temp], %[set_value]" "\n\t"
        "out %[clpr],%[temp]" "\n\t"
        "sei" "\n\t"
        "out __SREG__,__tmp_reg__" "\n\t"
        : /* no outputs */
        : [temp] "r" (__t),
          [clpr] "I" (_SFR_IO_ADDR(CLKPR)),
          [enable] "r" _BV(CLPCE),
          [not_CLKPS] "M" (0xFF & (~ ((1 << CLKPS2) | (1 << CLKPS1) | (1 << CLKPS0)))),
          [set_value] "r" (__x & 7)
        : "r0");
}

#define system_clock_prescale_get()  (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)))

typedef enum
{
    timer_clock_div_reset = 0,
    timer_clock_div_1 = 1,
    timer_clock_div_2 = 2,
    timer_clock_div_4 = 3,
    timer_clock_div_8 = 4,
    timer_clock_div_16 = 5,
    timer_clock_div_32 = 6,
    timer_clock_div_64 = 7
} timer_clock_div_t;

static __inline__ void timer_clock_prescale_set(timer_clock_div_t) __attribute__((__always_inline__));

void timer_clock_prescale_set(timer_clock_div_t __x)
{
    uint8_t __t;
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "in %[temp],%[clpr]" "\n\t"
        "out %[clpr],%[enable]" "\n\t"
        "andi %[temp],%[not_CLTPS]" "\n\t"
        "or %[temp], %[set_value]" "\n\t"
        "out %[clpr],%[temp]" "\n\t"
        "sei" "\n\t"
        "out __SREG__,__tmp_reg__" "\n\t"
        : /* no outputs */
        : [temp] "r" (__t),
          [clpr] "I" (_SFR_IO_ADDR(CLKPR)),
          [enable] "r" (_BV(CLPCE)),	  
          [not_CLTPS] "M" (0xFF & (~ ((1 << CLTPS2) | (1 << CLTPS1) | (1 << CLTPS0)))),
          [set_value] "r" ((__x & 7) << 3)
        : "r0");
}

#define timer_clock_prescale_get()  (timer_clock_div_t)(CLKPR & (uint8_t)((1<<CLTPS0)|(1<<CLTPS1)|(1<<CLTPS2)))

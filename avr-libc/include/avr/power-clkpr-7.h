typedef enum 
{ 
    clock_div_1 = 0, 
    clock_div_2 = 1, 
    clock_div_4 = 2, 
    clock_div_8 = 3, 
    clock_div_16 = 4, 
    clock_div_32 = 5, 
    clock_div_64 = 6, 
    clock_div_128 = 7, 
    clock_div_256 = 8 
} clock_div_t; 

static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

void clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = 0xD8;
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "out %1, %0" "\n\t"
        "out %2, %3" "\n\t"
        "out __SREG__, __tmp_reg__"
        : /* no outputs */
        : "d" (__tmp),
          "I" (_SFR_IO_ADDR(CCP)),
          "I" (_SFR_IO_ADDR(CLKPSR)),
          "d" (__x)
        : "r16");
}

#define clock_prescale_get()  (clock_div_t)(CLKPSR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)|(1<<CLKPS3)))

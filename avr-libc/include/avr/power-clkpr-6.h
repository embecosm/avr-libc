//Enum is declared for code compatibility
typedef enum
{
    clock_div_1 = 1,
    clock_div_2 = 2,
    clock_div_4 = 4,
    clock_div_8 = 8,
    clock_div_16 = 16,
    clock_div_32 = 32,
    clock_div_64 = 64,
    clock_div_128 = 128
} clock_div_t;

static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

void clock_prescale_set(clock_div_t __x)
{
    if((__x <= 0) || (__x > 129))
    {
        return;//Invalid value.
    }
    else
    {
        uint8_t __tmp = 0;
        //Algo explained:
        //1 - Clear XDIV in order for it to accept a new value (actually only
        //    XDIVEN need to be cleared, but clearing XDIV is faster than
        //    read-modify-write since we will rewrite XDIV later anyway)
        //2 - wait 8 clock cycle for stability, see datasheet erreta
        //3 - Exist if requested prescaller is 1
        //4 - Calculate XDIV6..0 value = 129 - __x
        //5 - Set XDIVEN bit in calculated value
        //6 - write XDIV with calculated value
        //7 - wait 8 clock cycle for stability, see datasheet erreta
        __asm__ __volatile__ (
            "in __tmp_reg__,__SREG__" "\n\t"
            "cli" "\n\t"
            "out %1, __zero_reg__" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "cpi %0, 0x01" "\n\t"
            "breq L_%=" "\n\t"
            "ldi %2, 0x81" "\n\t" //129
            "sub %2, %0" "\n\t"
            "ori %2, 0x80" "\n\t" //128
            "out %1, %2" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "L_%=: " "out __SREG__, __tmp_reg__"
            : /* no outputs */
            :"d" (__x),
             "I" (_SFR_IO_ADDR(XDIV)),
             "d" (__tmp)
            : "r0");
    }
}

static __inline__ clock_div_t clock_prescale_get(void) __attribute__((__always_inline__));

clock_div_t clock_prescale_get(void)
{
    if(bit_is_clear(XDIV, XDIVEN))
    {
        return 1;
    }
    else
    {
        return (clock_div_t)(129 - (XDIV & 0x7F));
    }
}

/** \addtogroup avr_power

Some of the newer AVRs contain a System Clock Prescale Register (CLKPR) that
allows you to decrease the system clock frequency and the power consumption
when the need for processing power is low.
On some earlier AVRs (ATmega103, ATmega64, ATmega128), similar
functionality can be achieved through the XTAL Divide Control Register.
Below are two macros and an enumerated type that can be used to
interface to the Clock Prescale Register or
XTAL Divide Control Register.

\note Not all AVR devices have a clock prescaler. On those devices
without a Clock Prescale Register or XTAL Divide Control Register, these
macros are not available.
*/


/** \addtogroup avr_power
\code 
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
    clock_div_256 = 8,
    clock_div_1_rc = 15, // ATmega128RFA1 only
} clock_div_t;
\endcode
Clock prescaler setting enumerations for device using
System Clock Prescale Register.

\code
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
\endcode
Clock prescaler setting enumerations for device using
XTAL Divide Control Register.

*/
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
#ifdef __AVR_HAVE_CLOCK_DIV_1_RC
    , clock_div_1_rc = 15
#endif
} clock_div_t;


static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

/** \addtogroup avr_power
\code clock_prescale_set(x) \endcode

Set the clock prescaler register select bits, selecting a system clock
division setting. This function is inlined, even if compiler
optimizations are disabled.

The type of \c x is \c clock_div_t.

\note For device with XTAL Divide Control Register (XDIV), \c x can actually range
from 1 to 129. Thus, one does not need to use \c clock_div_t type as argument.
*/
void clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = _BV(CLKPCE);
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "sts %1, %0" "\n\t"
        "sts %1, %2" "\n\t"
        "out __SREG__, __tmp_reg__"
        : /* no outputs */
        : "d" (__tmp),
          "M" (_SFR_MEM_ADDR(CLKPR)),
          "d" (__x)
        : "r0");
}

/** \addtogroup avr_power
\code clock_prescale_get() \endcode
Gets and returns the clock prescaler register setting. The return type is \c clock_div_t.

\note For device with XTAL Divide Control Register (XDIV), return can actually
range from 1 to 129. Care should be taken has the return value could differ from the
typedef enum clock_div_t. This should only happen if clock_prescale_set was previously
called with a value other than those defined by \c clock_div_t.
*/
#define clock_prescale_get()  (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)|(1<<CLKPS3)))

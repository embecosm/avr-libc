/* Copyright (c) 2002, 2004 Marek Michalkiewicz
   Copyright (c) 2005, 2006, 2007 Eric B. Weddington
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/*
   avr/wdt.h - macros for AVR watchdog timer
 */

#ifndef _AVR_WDT_H_
#define _AVR_WDT_H_

#include <avr/io.h>
#include <stdint.h>

/** \file */
/** \defgroup avr_watchdog <avr/wdt.h>: Watchdog timer handling
    \code #include <avr/wdt.h> \endcode

    This header file declares the interface to some inline macros
    handling the watchdog timer present in many AVR devices.  In order
    to prevent the watchdog timer configuration from being
    accidentally altered by a crashing application, a special timed
    sequence is required in order to change it.  The macros within
    this header file handle the required sequence automatically
    before changing any value.  Interrupts will be disabled during
    the manipulation.

    \note Depending on the fuse configuration of the particular
    device, further restrictions might apply, in particular it might
    be disallowed to turn off the watchdog timer.

    Note that for newer devices (ATmega88 and newer, effectively any
    AVR that has the option to also generate interrupts), the watchdog
    timer remains active even after a system reset (except a power-on
    condition), using the fastest prescaler value (approximately 15
    ms).  It is therefore required to turn off the watchdog early
    during program startup, the datasheet recommends a sequence like
    the following:

    \code
    #include <stdint.h>
    #include <avr/wdt.h>

    uint8_t mcusr_mirror __attribute__ ((section (".noinit")));

    void get_mcusr(void) \
      __attribute__((naked)) \
      __attribute__((section(".init3")));
    void get_mcusr(void)
    {
      mcusr_mirror = MCUSR;
      MCUSR = 0;
      wdt_disable();
    }
    \endcode

    Saving the value of MCUSR in \c mcusr_mirror is only needed if the
    application later wants to examine the reset source, but in particular, 
    clearing the watchdog reset flag before disabling the
    watchdog is required, according to the datasheet.
*/

/**
   \ingroup avr_watchdog
   Reset the watchdog timer.  When the watchdog timer is enabled,
   a call to this instruction is required before the timer expires,
   otherwise a watchdog-initiated device reset will occur. 
*/

#define wdt_reset() __asm__ __volatile__ ("wdr")


#if defined(WDP3)
# define _WD_PS3_MASK       _BV(WDP3)
#else
# define _WD_PS3_MASK       0x00
#endif

#if defined(WDTCSR)
#  define _WD_CONTROL_REG     WDTCSR
#elif defined(WDTCR)
#  define _WD_CONTROL_REG     WDTCR
#else
#  define _WD_CONTROL_REG     WDT
#endif

#if defined(WDTOE)
#define _WD_CHANGE_BIT      WDTOE
#else
#define _WD_CHANGE_BIT      WDCE
#endif


/**
   \ingroup avr_watchdog
   Enable the watchdog timer, configuring it for expiry after
   \c timeout (which is a combination of the \c WDP0 through
   \c WDP2 bits to write into the \c WDTCR register; For those devices 
   that have a \c WDTCSR register, it uses the combination of the \c WDP0 
   through \c WDP3 bits).

   See also the symbolic constants \c WDTO_15MS et al.
*/


#if defined(__AVR_HAVE_WDT_ENABLE_1STS)

/*
   wdt_enable(timeout) for xmega devices
** write signature (CCP_IOREG_gc) that enables change of protected I/O
   registers to the CCP register
** At the same time,
   1) set WDT change enable (WDT_CEN_bm)
   2) enable WDT (WDT_ENABLE_bm)
   3) set timeout (timeout)
** Synchronization starts when ENABLE bit of WDT is set. So, wait till it 
   finishes (SYNCBUSY of STATUS register is automatically cleared after the
   sync is finished).
*/
#define wdt_enable(timeout) \
do { \
uint8_t temp; \
__asm__ __volatile__ (         \
    "out %[ccp_reg], %[ioreg_cen_mask]"     "\n\t" \
    "sts %[wdt_reg], %[wdt_enable_timeout]" "\n\t" \
    "1:lds %[tmp], %[wdt_status_reg]"       "\n\t" \
    "sbrc  %[tmp], %[wdt_syncbusy_bit]"     "\n\t" \
    "rjmp 1b"                               "\n\t" \
    "wdr"                                   "\n\t" \
    : \
    : [ccp_reg]            "M" _SFR_MEM_ADDR(CCP),        \
      [ioreg_cen_mask]     "r" CCP_IOREG_gc,              \
      [wdt_reg]            "M" _SFR_MEM_ADDR(WDT_CTRL),   \
      [wdt_enable_timeout] "r" (WDT_CEN_bm | WDT_ENABLE_bm | timeout), \
      [wdt_status_reg]     "M" _SFR_MEM_ADDR(WDT_STATUS), \
      [wdt_syncbusy_bit]   "I" WDT_SYNCBUSY_bm,           \
      [tmp]                "r" temp                       \
    : "r0" \
) \
} while(0)

#define wdt_disable() \
do { \
uint8_t temp; \
__asm__ __volatile__ (  \
    "out %[ccp_reg], %[ioreg_cen_mask]" "\n\t" \
    "lds %[tmp], %[wdt_reg]"            "\n\t" \
    "andi %[tmp], %[disable_mask]"      "\n\t" \
    "sts %[wdt_reg], %[wdt_disable]"    "\n\t" \
    : \
    : [ccp_reg]           "M" _SFR_MEM_ADDR(CCP),      \
      [ioreg_cen_mask]    "r" CCP_IOREG_gc,            \
      [wdt_reg]           "M" _SFR_MEM_ADDR(WDT_CTRL), \
      [tmp]               "r" temp,                    \
      [disable_mask]      "M" ~WDT_ENABLE_bm,          \
      [wdt_disable]       "r" (temp | WDT_CEN_bm)      \
)

#elif defined(__AVR_HAVE_WDT_ENABLE_2STS)

/* Use STS instruction. */
 
#define wdt_enable(value)   \
__asm__ __volatile__ (  \
    "in __tmp_reg__,__SREG__" "\n\t"    \
    "cli" "\n\t"    \
    "wdr" "\n\t"    \
    "sts %0,%1" "\n\t"  \
    "out __SREG__,__tmp_reg__" "\n\t"   \
    "sts %0,%2" "\n\t" \
    : /* no outputs */  \
    : "M" (_SFR_MEM_ADDR(_WD_CONTROL_REG)), \
    "r" ((uint8_t)(_BV(_WD_CHANGE_BIT) | _BV(WDE))), \
    "r" ((uint8_t) ((value & 0x08 ? _WD_PS3_MASK : 0x00) | \
        _BV(WDE) | (value & 0x07)) ) \
    : "r0"  \
)

#define wdt_disable() \
__asm__ __volatile__ (  \
    "in __tmp_reg__, __SREG__" "\n\t" \
    "cli" "\n\t" \
    "sts %0, %1" "\n\t" \
    "sts %0, __zero_reg__" "\n\t" \
    "out __SREG__,__tmp_reg__" "\n\t" \
    : /* no outputs */ \
    : "M" (_SFR_MEM_ADDR(_WD_CONTROL_REG)), \
    "r" ((uint8_t)(_BV(_WD_CHANGE_BIT) | _BV(WDE))) \
    : "r0" \
)


#elif defined(__AVR_HAVE_WDT_ENABLE_OUT1

#define wdt_enable(value) \
__asm__ __volatile__ ( \
    "in __tmp_reg__,__SREG__" "\n\t"  \
    "cli" "\n\t"  \
    "wdr" "\n\t"  \
    "out %[CCPADDRESS],%[SIGNATURE]" "\n\t"  \
    "out %[WDTREG],%[WDVALUE]" "\n\t"  \
    "out __SREG__,__tmp_reg__" "\n\t"  \
    : /* no outputs */  \
    : [CCPADDRESS] "I" (_SFR_IO_ADDR(CCP)),  \
      [SIGNATURE] "r" ((uint8_t)0xD8), \
      [WDTREG] "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)), \
      [WDVALUE] "r" ((uint8_t)((value & 0x08 ? _WD_PS3_MASK : 0x00) \
      | _BV(WDE) | value)) \
    : "r16" \
)

#define wdt_disable() \
do { \
uint8_t temp_wd; \
__asm__ __volatile__ ( \
    "in __tmp_reg__,__SREG__" "\n\t"  \
    "cli" "\n\t"  \
    "wdr" "\n\t"  \
    "out %[CCPADDRESS],%[SIGNATURE]" "\n\t"  \
    "in  %[TEMP_WD],%[WDTREG]" "\n\t" \
    "cbr %[TEMP_WD],%[WDVALUE]" "\n\t" \
    "out %[WDTREG],%[TEMP_WD]" "\n\t" \
    "out __SREG__,__tmp_reg__" "\n\t" \
    : /*no output */ \
    : [CCPADDRESS] "I" (_SFR_IO_ADDR(CCP)), \
      [SIGNATURE] "r" ((uint8_t)0xD8), \
      [WDTREG] "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)), \
      [TEMP_WD] "d" (temp_wd), \
      [WDVALUE] "I" (1 << WDE) \
    : "r16" \
); \
}while(0)
    
#else  

/* Use OUT instruction. */

#define wdt_enable(value)   \
    __asm__ __volatile__ (  \
        "in __tmp_reg__,__SREG__" "\n\t"    \
        "cli" "\n\t"    \
        "wdr" "\n\t"    \
        "out %0,%1" "\n\t"  \
        "out __SREG__,__tmp_reg__" "\n\t"   \
        "out %0,%2" \
        : /* no outputs */  \
        : "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)), \
        "r" ((uint8_t)(_BV(_WD_CHANGE_BIT) | _BV(WDE))),   \
        "r" ((uint8_t) ((value & 0x08 ? _WD_PS3_MASK : 0x00) | \
            _BV(WDE) | (value & 0x07)) ) \
        : "r0"  \
    )

/**
   \ingroup avr_watchdog
   Disable the watchdog timer, if possible.  This attempts to turn off the 
   Enable bit in the watchdog control register. See the datasheet for 
   details.
*/
#define wdt_disable() \
__asm__ __volatile__ (  \
    "in __tmp_reg__, __SREG__" "\n\t" \
     "cli" "\n\t" \
    "out %0, %1" "\n\t" \
    "out %0, __zero_reg__" "\n\t" \
    "out __SREG__,__tmp_reg__" "\n\t" \
    : /* no outputs */ \
    : "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)), \
    "r" ((uint8_t)(_BV(_WD_CHANGE_BIT) | _BV(WDE))) \
    : "r0" \
)

#endif



/**
   \ingroup avr_watchdog
   Symbolic constants for the watchdog timeout.  Since the watchdog
   timer is based on a free-running RC oscillator, the times are
   approximate only and apply to a supply voltage of 5 V.  At lower
   supply voltages, the times will increase.  For older devices, the
   times will be as large as three times when operating at Vcc = 3 V,
   while the newer devices (e. g. ATmega128, ATmega8) only experience
   a negligible change.

   Possible timeout values are: 15 ms, 30 ms, 60 ms, 120 ms, 250 ms,
   500 ms, 1 s, 2 s.  (Some devices also allow for 4 s and 8 s.)
   Symbolic constants are formed by the prefix
   \c WDTO_, followed by the time.

   Example that would select a watchdog timer expiry of approximately
   500 ms:
   \code
   wdt_enable(WDTO_500MS);
   \endcode
*/
#define WDTO_15MS   0

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_30MS   1

/** \ingroup avr_watchdog See
    \c WDT0_15MS */
#define WDTO_60MS   2

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_120MS  3

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_250MS  4

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_500MS  5

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_1S     6

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_2S     7

#if defined(__DOXYGEN__) || defined(WDP3)

/** \ingroup avr_watchdog
    See \c WDT0_15MS
    Note: This is only available on the 
    ATtiny2313, 
    ATtiny24, ATtiny44, ATtiny84, ATtiny84A,
    ATtiny25, ATtiny45, ATtiny85, 
    ATtiny261, ATtiny461, ATtiny861, 
    ATmega48, ATmega88, ATmega168,
    ATmega48P, ATmega88P, ATmega168P, ATmega328P,
    ATmega164P, ATmega324P, ATmega644P, ATmega644,
    ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561,
    ATmega8HVA, ATmega16HVA, ATmega32HVB,
    ATmega406, ATmega1284P,
    AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316,
    AT90PWM81, AT90PWM161,
    AT90USB82, AT90USB162,
    AT90USB646, AT90USB647, AT90USB1286, AT90USB1287,
    ATtiny48, ATtiny88.
    */
#define WDTO_4S     8

/** \ingroup avr_watchdog
    See \c WDT0_15MS
    Note: This is only available on the 
    ATtiny2313, 
    ATtiny24, ATtiny44, ATtiny84, ATtiny84A,
    ATtiny25, ATtiny45, ATtiny85, 
    ATtiny261, ATtiny461, ATtiny861, 
    ATmega48, ATmega48A, ATmega48PA, ATmega88, ATmega168,
    ATmega48P, ATmega88P, ATmega168P, ATmega328P,
    ATmega164P, ATmega324P, ATmega644P, ATmega644,
    ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561,
    ATmega8HVA, ATmega16HVA, ATmega32HVB,
    ATmega406, ATmega1284P,
    ATmega2564RFR2, ATmega256RFR2, ATmega1284RFR2, ATmega128RFR2, ATmega644RFR2, ATmega64RFR2
    AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316,
    AT90PWM81, AT90PWM161,
    AT90USB82, AT90USB162,
    AT90USB646, AT90USB647, AT90USB1286, AT90USB1287,
    ATtiny48, ATtiny88,
    ATxmega16a4u, ATxmega32a4u,
    ATxmega16c4, ATxmega32c4,
    ATxmega128c3, ATxmega192c3, ATxmega256c3.
    */
#define WDTO_8S     9

#endif  /* defined(__DOXYGEN__) || defined(WDP3) */
   

#endif /* _AVR_WDT_H_ */

/* Copyright (c) 2006, 2007, 2008  Eric B. Weddington
   Copyright (c) 2011 Frédéric Nadeau
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

#ifndef _AVR_POWER_H_
#define _AVR_POWER_H_   1

#include <avr/io.h>
#include <stdint.h>


/** \file */
/** \defgroup avr_power <avr/power.h>: Power Reduction Management

\code #include <avr/power.h>\endcode

Many AVRs contain a Power Reduction Register (PRR) or Registers (PRRx) that 
allow you to reduce power consumption by disabling or enabling various on-board 
peripherals as needed. Some devices have the XTAL Divide Control Register
(XDIV) which offer similar functionality as System Clock Prescale
Register (CLKPR).

There are many macros in this header file that provide an easy interface
to enable or disable on-board peripherals to reduce power. See the table below.

\note Not all AVR devices have a Power Reduction Register (for example
the ATmega8). On those devices without a Power Reduction Register, the
power reduction macros are not available..

\note Not all AVR devices contain the same peripherals (for example, the LCD
interface), or they will be named differently (for example, USART and 
USART0). Please consult your device's datasheet, or the header file, to 
find out which macros are applicable to your device.

\note For device using the XTAL Divide Control Register (XDIV), when prescaler
is used, Timer/Counter0 can only be used in asynchronous mode. Keep in mind
that Timer/Counter0 source shall be less than ¼th of peripheral clock.
Therefore, when using a typical 32.768 kHz crystal, one shall not scale
the clock below 131.072 kHz.

*/


/** \addtogroup avr_power

\anchor avr_powermacros
<small>
<center>
<table border="3">
  <tr>
    <td width="10%"><strong>Power Macro</strong></td>
    <td width="15%"><strong>Description</strong></td>
    <td width="75%"><strong>Applicable for device</strong></td>
  </tr>

  <tr>
    <td>power_aca_disable()</td>
    <td>Disable the Analog Comparator on PortA.</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_aca_enable()</td>
    <td>Enable the Analog Comparator on PortA.</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_adc_enable()</td>
    <td>Enable the Analog to Digital Converter module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_adc_disable()</td>
    <td>Disable the Analog to Digital Converter module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_adca_disable()</td>
    <td>Disable the Analog to Digital Converter module on PortA</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_adca_enable()</td>
    <td>Enable the Analog to Digital Converter module on PortA</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_evsys_disable()</td>
    <td>Disable the EVSYS module</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_evsys_enable()</td>
    <td>Enable the EVSYS module</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_hiresc_disable()</td>
    <td>Disable the HIRES module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_hiresc_enable()</td>
    <td>Enable the HIRES module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

   <tr>
    <td>power_lcd_enable()</td>
    <td>Enable the LCD module.</td>
    <td>ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega649, ATmega6490, ATxmega64B1, ATxmega64B3, ATxmega128B3</td>
  </tr>

  <tr>
    <td>power_lcd_disable().</td>
    <td>Disable the LCD module.</td>
    <td>ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega649, ATmega6490, ATxmega64B1, ATxmega128B1, ATxmega64B3, ATxmega128B3</td>
  </tr>

  <tr>
    <td>power_pga_enable()</td>
    <td>Enable the Programmable Gain Amplifier module.</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_pga_disable()</td>
    <td>Disable the Programmable Gain Amplifier module.</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>
  
  <tr>
    <td>power_pscr_enable()</td>
    <td>Enable the Reduced Power Stage Controller module.</td>
    <td>AT90PWM81</td>
  </tr>

  <tr>
    <td>power_pscr_disable()</td>
    <td>Disable the Reduced Power Stage Controller module.</td>
    <td>AT90PWM81</td>
  </tr>

  <tr>
    <td>power_psc0_enable()</td>
    <td>Enable the Power Stage Controller 0 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_psc0_disable()</td>
    <td>Disable the Power Stage Controller 0 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_psc1_enable()</td>
    <td>Enable the Power Stage Controller 1 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_psc1_disable()</td>
    <td>Disable the Power Stage Controller 1 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_psc2_enable()</td>
    <td>Enable the Power Stage Controller 2 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM81</td>
  </tr>

  <tr>
    <td>power_psc2_disable()</td>
    <td>Disable the Power Stage Controller 2 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM81</td>
  </tr>

  <tr>
    <td>power_ram0_enable()</td>
    <td>Enable the SRAM block 0 .</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram0_disable()</td>
    <td>Disable the SRAM block 0. </td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram1_enable()</td>
    <td>Enable the SRAM block 1 .</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram1_disable()</td>
    <td>Disable the SRAM block 1. </td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram2_enable()</td>
    <td>Enable the SRAM block 2 .</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram2_disable()</td>
    <td>Disable the SRAM block 2. </td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram3_enable()</td>
    <td>Enable the SRAM block 3 .</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram3_disable()</td>
    <td>Disable the SRAM block 3. </td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_rtc_disable()</td>
    <td>Disable the RTC module</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_rtc_enable()</td>
    <td>Enable the RTC module</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_spi_enable()</td>
    <td>Enable the Serial Peripheral Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_spi_disable()</td>
    <td>Disable the Serial Peripheral Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_spic_disable()</td>
    <td>Disable the SPI module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_spic_enable()</td>
    <td>Enable the SPI module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_spid_disable()</td>
    <td>Disable the SPI module on PortD</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_spid_enable()</td>
    <td>Enable the SPI module on PortD</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0c_disable()</td>
    <td>Disable the TC0 module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0c_enable()</td>
    <td>Enable the TC0 module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0d_disable()</td>
    <td>Disable the TC0 module on PortD</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0d_enable()</td>
    <td>Enable the TC0 module on PortD</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0e_disable()</td>
    <td>Disable the TC0 module on PortE</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0e_enable()</td>
    <td>Enable the TC0 module on PortE</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0f_disable()</td>
    <td>Disable the TC0 module on PortF</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0f_enable()</td>
    <td>Enable the TC0 module on PortF</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc1c_disable()</td>
    <td>Disable the TC1 module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc1c_enable()</td>
    <td>Enable the TC1 module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_twic_disable()</td>
    <td>Disable the Two Wire Interface module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_twic_enable()</td>
    <td>Enable the Two Wire Interface module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_twie_disable()</td>
    <td>Disable the Two Wire Interface module on PortE</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_twie_enable()</td>
    <td>Enable the Two Wire Interface module on PortE</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_timer0_enable()</td>
    <td>Enable the Timer 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM216, AT90PWM316, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega3250, ATmega3250A, ATmega645, ATmega6450, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_timer0_disable()</td>
    <td>Disable the Timer 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega3250, ATmega3250A, ATmega645, ATmega6450, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_timer1_enable()</td>
    <td>Enable the Timer 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_timer1_disable()</td>
    <td>Disable the Timer 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_timer2_enable()</td>
    <td>Enable the Timer 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer2_disable()</td>
    <td>Disable the Timer 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer3_enable()</td>
    <td>Enable the Timer 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer3_disable()</td>
    <td>Disable the Timer 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer4_enable()</td>
    <td>Enable the Timer 4 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer4_disable()</td>
    <td>Disable the Timer 4 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer5_enable()</td>
    <td>Enable the Timer 5 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer5_disable()</td>
    <td>Disable the Timer 5 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_twi_enable()</td>
    <td>Enable the Two Wire Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_twi_disable()</td>
    <td>Disable the Two Wire Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_usart_enable()</td>
    <td>Enable the USART module.</td>
    <td>AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_usart_disable()</td>
    <td>Disable the USART module.</td>
    <td>AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_usart0_enable()</td>
    <td>Enable the USART 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_usart0_disable()</td>
    <td>Disable the USART 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_usart1_enable()</td>
    <td>Enable the USART 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_usart1_disable()</td>
    <td>Disable the USART 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_usart2_enable()</td>
    <td>Enable the USART 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usart2_disable()</td>
    <td>Disable the USART 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usart3_enable()</td>
    <td>Enable the USART 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usart3_disable()</td>
    <td>Disable the USART 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartc0_disable()</td>
    <td> Disable the USART0 module on PortC</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartc0_enable()</td>
    <td> Enable the USART0 module on PortC</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartd0_disable()</td>
    <td> Disable the USART0 module on PortD</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartd0_enable()</td>
    <td> Enable the USART0 module on PortD</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usarte0_disable()</td>
    <td> Disable the USART0 module on PortE</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usarte0_enable()</td>
    <td> Enable the USART0 module on PortE</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartf0_disable()</td>
    <td> Disable the USART0 module on PortF</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartf0_enable()</td>
    <td> Enable the USART0 module on PortF</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usb_enable()</td>
    <td>Enable the USB module.</td>
    <td>AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATxmega64B1, ATxmega128B1, ATxmega64B3, ATxmega128B3, ATxmega16A4U, ATxmega32A4U, ATxmega128c3, ATxmega256c3, ATxmega16c4, ATxmega32c4</td>
  </tr>

  <tr>
    <td>power_usb_disable()</td>
    <td>Disable the USB module.</td>
    <td>AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATxmega64B1, ATxmega128B1, ATxmega64B3, ATxmega128B3, ATxmega16A4U, ATxmega32A4U,ATxmega128c3, ATxmega256c3, ATxmega16c4, ATxmega32c4</td>
  </tr>

  <tr>
    <td>power_usi_enable()</td>
    <td>Enable the Universal Serial Interface module.</td>
    <td>ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861</td>
  </tr>

  <tr>
    <td>power_usi_disable()</td>
    <td>Disable the Universal Serial Interface module.</td>
    <td>ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861</td>
  </tr>

  <tr>
    <td>power_vadc_enable()</td>
    <td>Enable the Voltage ADC module.</td>
    <td>ATmega406</td>
  </tr>

  <tr>
    <td>power_vadc_disable()</td>
    <td>Disable the Voltage ADC module.</td>
    <td>ATmega406</td>
  </tr>

  <tr>
    <td>power_all_enable()</td>
    <td>Enable all modules.</td>
    <td>ATxmega6A4, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmegaA1, ATxmegaA1U, ATxmega128A3, ATxmega192A3, ATxmega256A3, ATxmegaA3B, ATxmega16D4, ATxmega32D4, ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3, ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega64B1, ATxmega128B1, ATxmega64B3, ATxmega128B3, ATxmega16A4U, ATxmega32A4U, ATxmega64A3U, ATxmega128A3U, ATxmega192A3U, ATxmega256A3U</td>
  </tr>

  <tr>
    <td>power_all_disable()</td>
    <td>Disable all modules.</td>
    <td>ATxmega6A4, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmegaA1, ATxmegaA1U, ATxmega128A3, ATxmega192A3, ATxmega256A3, ATxmegaA3B, ATxmega16D4, ATxmega32D4, ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3, ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega64B1, ATxmega128B1, ATxmega64B3, ATxmega128B3, ATxmega16A4U, ATxmega32A4U, ATxmega64A3U, ATxmega128A3U, ATxmega192A3U, ATxmega256A3U</td>
  </tr>
</table>
</center>
</small>

@} */

// Xmega A series has AES, EBI and DMA bits
// Mark any other device on need basis in respective io*.h

/* Use !defined(..._enable) so that io<mcu>.h can override our definitions if they won't
   work for a new device.  */

#if !defined (power_aes_enable) && defined (PR_PRGEN) && defined (PR_AES_bm)
#define power_aes_enable()  (PR_PRGEN &= (uint8_t)~(PR_AES_bm))
#define power_aes_disable() (PR_PRGEN |= (uint8_t)PR_AES_bm)
#elif !defined (power_aes_enable) && defined (PRR1) && defined (PRAES)
#define power_aes_enable()      (PRR1 &= (uint8_t)~(1 << PRAES))
#define power_aes_disable()     (PRR1 |= (uint8_t)(1 << PRAES))
#endif

#if !defined (power_ebi_enable) && defined (PR_PRGEN) && defined (PR_EBI_bm)
#define power_ebi_enable()  (PR_PRGEN &= (uint8_t)~(PR_EBI_bm))
#define power_ebi_disable() (PR_PRGEN |= (uint8_t)PR_EBI_bm)
#endif

#if !defined (power_dma_enable) && defined (PR_PRGEN) && defined (PR_DMA_bm)
#define power_dma_enable()    (PR_PRGEN &= (uint8_t)~(PR_DMA_bm))
#define power_dma_disable()   (PR_PRGEN |= (uint8_t)PR_DMA_bm)
#endif

#if !defined (power_daca_enable) && defined (PR_PRPA) && defined (PR_DAC_bm)
#define power_daca_enable()     (PR_PRPA &= (uint8_t)~(PR_DAC_bm))
#define power_daca_disable()    (PR_PRPA |= (uint8_t)PR_DAC_bm)
#endif
#if !defined (power_dacb_enable) && defined (PR_PRPB) && defined (PR_DAC_bm)
#define power_dacb_enable()     (PR_PRPB &= (uint8_t)~(PR_DAC_bm))
#define power_dacb_disable()    (PR_PRPB |= (uint8_t)PR_DAC_bm)
#endif

#if !defined (power_usartc1_enable) && defined (PR_PRPC) && defined (PR_USART1_bm)
#define power_usartc1_enable()  (PR_PRPC &= (uint8_t)~(PR_USART1_bm))
#define power_usartc1_disable() (PR_PRPC |= (uint8_t)PR_USART1_bm)
#endif
#if !defined (power_usartd1_enable) && defined (PR_PRPD) && defined (__AVR_HAVE_USART1_DEF)
#define power_usartd1_enable()  (PR_PRPD &= (uint8_t)~(PR_USART1_bm))
#define power_usartd1_disable() (PR_PRPD |= (uint8_t)PR_USART1_bm)
#endif
#if !defined (power_usarte1_enable) && defined (PR_PRPE) && defined (__AVR_HAVE_USART1_DEF)
#define power_usarte1_enable()  (PR_PRPE &= (uint8_t)~(PR_USART1_bm))
#define power_usarte1_disable() (PR_PRPE |= (uint8_t)PR_USART1_bm)
#endif
#if !defined (power_usartf1_enable) && defined (PR_PRPF) && defined (__AVR_HAVE_USART1_DEF)
#define power_usartf1_enable()  (PR_PRPF &= (uint8_t)~(PR_USART1_bm))
#define power_usartf1_disable() (PR_PRPF |= (uint8_t)PR_USART1_bm)
#endif

#if !defined (power_usb_enable) && defined (PR_PRGEN) && defined (PR_USB_bm)
#define power_usb_enable()   (PR_PRGEN &= (uint8_t)~(PR_USB_bm))
// ??? some mucs had: power_usb_disable()  (PR_PRGEN &= (uint8_t)(PR_USB_bm))
#define power_usb_disable() (PR_PRGEN |= (uint8_t)PR_USB_bm)
#elif !defined (power_usb_enable) && defined (PRR1) && defined (PRUSB)
#define power_usb_enable()      (PRR1 &= (uint8_t)~(1 << PRUSB))
#define power_usb_disable()     (PRR1 |= (uint8_t)(1 << PRUSB))
#endif

#if defined (PR_PRGEN) && defined (PR_RTC_bm)
#define power_rtc_enable()  (PR_PRGEN &= (uint8_t)~(PR_RTC_bm))
#define power_rtc_disable() (PR_PRGEN |= (uint8_t)PR_RTC_bm)
#endif

#if !defined (power_evsys_enable) && defined (PR_PRGEN) && defined (PR_EVSYS_bm)
#define power_evsys_enable()    (PR_PRGEN &= (uint8_t)~(PR_EVSYS_bm))
#define power_evsys_disable()   (PR_PRGEN |= (uint8_t)PR_EVSYS_bm)
#endif

#if !defined (power_adca_enable) && defined (PR_PRPA) && defined (PR_ADC_bm)
#define power_adca_enable()     (PR_PRPA &= (uint8_t)~(PR_ADC_bm))
#define power_adca_disable()    (PR_PRPA |= (uint8_t)PR_ADC_bm)
#endif
#if !defined (power_adcb_enable) && defined (PR_PRPB) && defined (PR_ADC_bm)
#define power_adcb_enable()     (PR_PRPB &= (uint8_t)~(PR_ADC_bm))
#define power_adcb_disable()    (PR_PRPB |= (uint8_t)PR_ADC_bm)
#endif

#if !defined (power_aca_enable) && defined (PR_PRPA) && defined (PR_AC_bm)
#define power_aca_enable()      (PR_PRPA &= (uint8_t)~(PR_AC_bm))
#define power_aca_disable()     (PR_PRPA |= (uint8_t)PR_AC_bm)
#endif
#if !defined (power_acb_enable) && defined (PR_PRPB) && defined (PR_AC_bm)
#define power_acb_enable()      (PR_PRPB &= (uint8_t)~(PR_AC_bm))
#define power_acb_disable()     (PR_PRPB |= (uint8_t)PR_AC_bm)
#endif

#if !defined (power_twic_enable) && defined (PR_PRPC) && defined (PR_TWI_bm)
#define power_twic_enable()     (PR_PRPC &= (uint8_t)~(PR_TWI_bm))
#define power_twic_disable()    (PR_PRPC |= (uint8_t)PR_TWI_bm)
#endif
#if !defined (power_twie_enable) && defined (PR_PRPE) && defined (__AVR_HAVE_TWI_E)
#define power_twie_enable()     (PR_PRPE &= (uint8_t)~(PR_TWI_bm))
#define power_twie_disable()    (PR_PRPE |= (uint8_t)PR_TWI_bm)
#endif
#if !defined (power_twid_enable) && defined (PR_PRPD) && defined (__AVR_HAVE_TWI_DF)
#define power_twid_enable()     (PR_PRPD &= (uint8_t)~(PR_TWI_bm))
#define power_twid_disable()    (PR_PRPD |= (uint8_t)PR_TWI_bm)
#endif
#if !defined (power_twif_enable) && defined (PR_PRPF) && defined (__AVR_HAVE_TWI_DF)
#define power_twif_enable()     (PR_PRPF &= (uint8_t)~(PR_TWI_bm))
#define power_twif_disable()    (PR_PRPF |= (uint8_t)PR_TWI_bm)
#endif

#if !defined (power_spic_enable) && defined (PR_PRPC) && defined (PR_SPI_bm)
#define power_spic_enable()     (PR_PRPC &= (uint8_t)~(PR_SPI_bm))
#define power_spic_disable()    (PR_PRPC |= (uint8_t)PR_SPI_bm)
#endif
#if !defined (power_spid_enable) && defined (PR_PRPD) && defined (__AVR_HAVE_SPI_D)
#define power_spid_enable()     (PR_PRPD &= (uint8_t)~(PR_SPI_bm))
#define power_spid_disable()    (PR_PRPD |= (uint8_t)PR_SPI_bm)
#endif
#if !defined (power_spie_enable) && defined (PR_PRPE) && defined (__AVR_HAVE_SPI_EF)
#define power_spie_enable()     (PR_PRPE &= (uint8_t)~(PR_SPI_bm))
#define power_spie_disable()    (PR_PRPE |= (uint8_t)PR_SPI_bm)
#endif
#if !defined (power_spif_enable) && defined (PR_PRPF) && defined (__AVR_HAVE_SPI_EF)
#define power_spif_enable()     (PR_PRPF &= (uint8_t)~(PR_SPI_bm))
#define power_spif_disable()    (PR_PRPF |= (uint8_t)PR_SPI_bm)
#endif

#if !defined (power_hiresc_enable) && defined (PR_PRPC) && defined (PR_HIRES_bm)
#define power_hiresc_enable()   (PR_PRPC &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresc_disable()  (PR_PRPC |= (uint8_t)PR_HIRES_bm)
#endif
#if !defined (power_hiresd_enable) && defined (PR_PRPD) && defined (__AVR_HAVE_HIRES_DEF)
#define power_hiresd_enable()   (PR_PRPD &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresd_disable()  (PR_PRPD |= (uint8_t)PR_HIRES_bm)
#endif
#if !defined (power_hirese_enable) && defined (PR_PRPE) && defined (__AVR_HAVE_HIRES_DEF)
#define power_hirese_enable()   (PR_PRPE &= (uint8_t)~(PR_HIRES_bm))
#define power_hirese_disable()  (PR_PRPE |= (uint8_t)PR_HIRES_bm)
#endif
#if !defined (power_hiresf_enable) && defined (PR_PRPF) && defined (__AVR_HAVE_HIRES_DEF)
#define power_hiresf_enable()   (PR_PRPF &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresf_disable()  (PR_PRPF |= (uint8_t)PR_HIRES_bm)
#endif

#if !defined (power_tc1c_enable) && defined (PR_PRPC) && defined (PR_TC1_bm)
#define power_tc1c_enable()     (PR_PRPC &= (uint8_t)~(PR_TC1_bm))
#define power_tc1c_disable()    (PR_PRPC |= (uint8_t)PR_TC1_bm)
#endif
#if !defined (power_tc1d_enable) && defined (PR_PRPD) && defined (__AVR_HAVE_TC1_DEF)
#define power_tc1d_enable()     (PR_PRPD &= (uint8_t)~(PR_TC1_bm))
#define power_tc1d_disable()    (PR_PRPD |= (uint8_t)PR_TC1_bm)
#endif
#if !defined (power_tc1e_enable) && defined (PR_PRPE) && defined (__AVR_HAVE_TC1_DEF)
#define power_tc1e_enable()     (PR_PRPE &= (uint8_t)~(PR_TC1_bm))
#define power_tc1e_disable()    (PR_PRPE |= (uint8_t)PR_TC1_bm)
#endif
#if !defined (power_tc1f_enable) && defined (PR_PRPF) && defined (__AVR_HAVE_TC1_DEF)
#define power_tc1f_enable()     (PR_PRPF &= (uint8_t)~(PR_TC1_bm))
#define power_tc1f_disable()    (PR_PRPF |= (uint8_t)PR_TC1_bm)
#endif

#if !defined (power_tc0c_enable) && defined (PR_PRPC) && defined (PR_TC0_bm)
#define power_tc0c_enable()     (PR_PRPC &= (uint8_t)~(PR_TC0_bm))
#define power_tc0c_disable()    (PR_PRPC |= (uint8_t)PR_TC0_bm)
#endif
#if !defined (power_tc0d_enable) && defined (PR_PRPD) && defined (PR_TC0_bm)
#define power_tc0d_enable()     (PR_PRPD &= (uint8_t)~(PR_TC0_bm))
#define power_tc0d_disable()    (PR_PRPD |= (uint8_t)PR_TC0_bm)
#endif
#if !defined (power_tc0e_enable) && defined (PR_PRPE) && defined (PR_TC0_bm)
#define power_tc0e_enable()     (PR_PRPE &= (uint8_t)~(PR_TC0_bm))
#define power_tc0e_disable()    (PR_PRPE |= (uint8_t)PR_TC0_bm)
#endif
#if !defined (power_tc0f_enable) && defined (PR_PRPF) && defined (PR_TC0_bm)
#define power_tc0f_enable()     (PR_PRPF &= (uint8_t)~(PR_TC0_bm))
#define power_tc0f_disable()    (PR_PRPF |= (uint8_t)PR_TC0_bm)
#endif

#if !defined (power_lcd_enable) && defined (PR_PRGEN) && defined (PR_LCD_bm)
#define power_lcd_enable()  (PR_PRGEN &= (uint8_t)~(PR_LCD_bm))
#define power_lcd_disable() (PR_PRGEN |= (uint8_t)PR_LCD_bm)
#endif
#elif !define (power_lcd_enable) && defined (PRR) && defined (PRLCD)
#define power_lcd_enable()      (PRR &= (uint8_t)~(1 << PRLCD))
#define power_lcd_disable()     (PRR |= (uint8_t)(1 << PRLCD))
#endif


static __inline void
__attribute__ ((__always_inline__))
__power_all_enable (bool enable)
{
  uint8_t mask, dmask, emask, fmask;
#ifdef PR_PRGEN
  mask = (0
#ifdef PR_AES_bm
	  | PR_AES_bm
#endif
#ifdef PR_EBI_bm
	  | PR_EBI_bm
#ifdef PR_RC_bm
	  | PR_RTC_bm
#endif
#ifdef PR_EVSYS_bm
	  | PR_EVSYS_bm
#endif
#ifdef PR_DMA_bm
	  | PR_DMA_bm
#endif
#ifdef PR_USB_bm
	  | PR_USB_bm
#endif
#ifdef PR_LCD_bm
	  | PR_LCD_bm
#endif
	   );
  if (enable)
    PR_PRGEN &= (uint8_t)~mask;
  else
    PR_PRGEN |= mask;
#endif /* PR_PRGEN */
  mask = (0
#ifdef PR_ADC_bm
	  | PR_ADC_bm
#endif
#ifdef PR_AC_bm
	  | PR_AC_bm
#endif
#ifdef PR_DAC_bm
	  | PR_DAC_bm
#endif
	   );
#ifdef PR_PRPA
  if (enable)
    PR_PRPA &= (uint8_t)~mask;
  else
    PR_PRPA |= mask;
#endif /* PR_PRPA */
#ifdef PR_PRPB
  if (enable)
    PR_PRPB &= (uint8_t)~mask;
  else
    PR_PRPB |= mask;
#endif /* PR_PRPB */
  mask = (0
#ifdef PR_USART0_bm
	  | PR_USART0_bm
#endif
#ifdef PR_TC0_bm
	  | PR_TC0_bm
#endif
	   );
#ifdef PR_PRPC
  uint8_t cmask = (mask
#ifdef PR_TWI_bm
		   | PR_TWI_bm
#endif
#ifdef PR_USART1_bm
		   | PR_USART1_bm
#endif
#ifdef PR_SPI_bm
		   | PR_SPI_bm
#endif
#ifdef PR_HIRES_bm
		   | PR_HIRES_bm
#endif
#ifdef PR_TC1_bm
		   | PR_TC1_bm
#endif
		    );
  if (enable)
    PR_PRPB &= (uint8_t)~cmask;
  else
    PR_PRPB |= cmask;
#endif /* PR_PRPC */
  dmask = emask = fmask
  = (mask
#ifdef __AVR_HAVE_USART1_DEF
     | PR_USART1_bm
#endif
#ifdef __AVR_HAVE_HIRES_DEF
     | PR_HIRES_bm
#endif
#ifdef __AVR_HAVE_TC1_DEF
     | PR_TC1_bm
#endif
      );
#ifdef __AVR_HAVE_SPI_D
  dmask |= PR_SPI_bm;
#endif
#ifdef __AVR_HAVE_SPI_EF
  emask |= PR_SPI_bm;
  fmask |= PR_SPI_bm;
#endif
#ifdef __AVR_HAVE_TWI_DF
  dmask |= PR_TWI_bm;
  fmask |= PR_TWI_bm;
#endif
#ifdef __AVR_HAVE_TWI_E
  emask |= PR_TWI_bm;
#endif
#ifdef PR_PRPD
  if (enable)
    PR_PRPD &= (uint8_t)~dmask;
  else
    PR_PRPD |= dmask;
#endif /* PR_PRPD */
#ifdef PR_PRPE
  if (enable)
    PR_PRPE &= (uint8_t)~emask;
  else
    PR_PRPE |= emask;
#endif /* PR_PRPE */
#ifdef PR_PRPF
  if (enable)
    PR_PRPF &= (uint8_t)~fmask;
  else
    PR_PRPF |= fmask;
#endif /* PR_PRPF */
  mask = (0
#ifdef PRADC
	  | (1<<PRADC)
#endif
#ifdef PRCAN
	  | (1<<PRCAN)
#endif
#ifdef PRLCD
	  | (1<<PRLCD)
#endif
#ifdef PRLIN
	  | (1<<PRLIN)
#endif
#ifdef PRPSC
	  | (1<<PRPSC)
#endif
#ifdef PRPSC0
	  | (1<<PRPSC0)
#endif
#ifdef PRPSC1
	  | (1<<PRPSC1)
#endif
#ifdef PRPSC2
	  | (1<<PRPSC2)
#endif
#ifdef PRPSCR
	  | (1<<PRPSCR)
#endif
#ifdef PRSPI
	  | (1<<PRSPI)
#ifdef PRTIM0
	  | (1<<PRTIM0)
#endif
#ifdef PRTIM1
	  | (1<<PRTIM1)
#endif
#ifdef PRTIM2
	  | (1<<PRTIM2)
#endif
#ifdef PRTWI
	  | (1<<PRTWI)
#endif
#ifdef PRUSART
	  | (1<<PRUSART)
#endif
#ifdef PRUSART0
	  | (1<<PRUSART0)
#endif
#if defined (__AVR_HAVE_PRR0_USART1) || (!defined (PRR0) && defined (PRUSART1))
	  | (1<<PRUSART1)
#endif
#ifdef PRUSI
	  | (1 << PRUSI)
#endif
#ifdef PRVADC
	| (1<<PRVADC)
#endif
#ifdef PRVRM
	  | (1<<PRVRM)
#endif
#ifdef PRVM
	  | (1<<PRVM)
#endif
#ifdef PRDS
	  | (1<<PRDS)
#endif
#ifdef PRCU
	  | (1<<PRCU)
#endif
#ifdef PRTM
	  | (1<<PRTM)
#endif
#ifdef PRT3
	  | (1<<PRT3)
#endif
#ifdef PRT2
	  | (1<<PRT2)
#endif
#ifdef PRT1
	  | (1<<PRT1)
#endif
#ifdef PRLFR
	  | (1<<PRLFR)
#endif
	   );
#ifdef PRR0
  if (enable)
    PRR0 &= (uint8_t)~mask;
  else
    PRR0 |= mask;
#elif defined (PRR)
  if (enable)
    PRR &= (uint8_t)~mask;
  else
    PRR |= mask;
#endif

#ifdef PRR1
  mask = (0
#ifdef PRTIM3
	  | (1<<PRTIM3)
#endif
#ifdef PRTIM4
	  | (1<<PRTIM4)
#endif
#ifdef PRTIM5
	  | (1<<PRTIM5)
#endif
#ifdef __AVR_HAVE_PRR1_USART1
	  | (1<<PRUSART1)
#endif
#ifdef PRUSART2
	  | (1<<PRUSART2)
#endif
#ifdef PRUSART3
	  | (1<<PRUSART3)
#endif
#ifdef PRTRX24
	  | (1<<PRTRX24)
#endif
#ifdef PRSPI
	  | (1<<PRSPI)
#endif
#ifdef PRCI
	  | (1<<PRCI)
#endif
#ifdef PRUSBH
	  | (1<<PRUSBH)
#endif
#ifdef PRUSB
	  | (1<<PRUSB)
#endif
#ifdef PRHSSPI
	  | (1<<PRHSSPI)
#endif
#ifdef PRSCI
	  | (1<<PRSCI)
#endif
#ifdef PRAES
	  | (1<<PRAES)
#endif
#ifdef PRKB
	  | (1<<PRKB)
#endif
	   );
  if (enable)
    PRR1 &= (uint8_t)~mask;
  else
    PRR1 |= mask;
#endif /* PRR1 */

#ifdef PRR2
  mask = (0
#ifdef PRRAM0
	  | (1<<PRRAM0)
#endif
#ifdef PRRAM1
	  | (1<<PRRAM1)
#endif
#ifdef PRRAM2
	  | (1<<PRRAM2)
#endif
#ifdef PRRAM3
	  | (1<<PRRAM3)
#endif
	   );
  if (enable)
    PRR2 &= (uint8_t)~mask;
  else
    PRR2 |= mask;
#endif /* PRR2 */
}


#ifndef power_all_enable
#define power_all_enable __power_all_enable (true)
#endif

#ifndef power_all_disable
#define power_all_disable __power_all_enable (false)
#endif


#if !defined (power_adc_enable) && defined (PRR0) && defined (PRADC)
#define power_adc_enable()      (PRR0 &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR0 |= (uint8_t)(1 << PRADC))
#endif

#if !defined (power_spi_enable) && defined (PRR0) && defined (PRSPI)
#define power_spi_enable()      (PRR0 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR0 |= (uint8_t)(1 << PRSPI))
#endif

#if !defined (power_twi_enable) && defined (PRR0) && defined (PRTWI)
#define power_twi_enable()      (PRR0 &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR0 |= (uint8_t)(1 << PRTWI))
#endif

#if !defined (power_timer0_enable) && defined (PRR0) && defined (PRTIM0)
#define power_timer0_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR0 |= (uint8_t)(1 << PRTIM0))
#endif

#if !defined (power_timer1_enable) && defined (PRR0) && defined (PRTIM1)
#define power_timer1_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR0 |= (uint8_t)(1 << PRTIM1))
#endif

#if !defined (power_timer2_enable) && defined (PRR0) && defined (PRTIM2)
#define power_timer2_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable()  (PRR0 |= (uint8_t)(1 << PRTIM2))
#endif

#if !defined (power_timer3_enable) && defined (PRR1) && defined (PRTIM3)
#define power_timer3_enable()   (PRR1 &= (uint8_t)~(1 << PRTIM3))
#define power_timer3_disable()  (PRR1 |= (uint8_t)(1 << PRTIM3))
#endif

#if !defined (power_timer4_enable) && defined (PRR1) && defined (PRTIM4)
#define power_timer4_enable()   (PRR1 &= (uint8_t)~(1 << PRTIM4))
#define power_timer4_disable()  (PRR1 |= (uint8_t)(1 << PRTIM4))
#endif

#if !defined (power_timer5_enable) && defined (PRR1) && defined (PRTIM5)
#define power_timer5_enable()   (PRR1 &= (uint8_t)~(1 << PRTIM5))
#define power_timer5_disable()  (PRR1 |= (uint8_t)(1 << PRTIM5))
#endif

#if !defined (power_usart0_enable) && defined (PRR0) && defined (PRUSART0)
#define power_usart0_enable()   (PRR0 &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR0 |= (uint8_t)(1 << PRUSART0))
#endif

#if !defined (power_usart1_enable) && defined (__AVR_HAVE_USART1_PRR1)
#define power_usart1_enable()   (PRR1 &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable()  (PRR1 |= (uint8_t)(1 << PRUSART1))
#endif

#if !defined (power_usart2_enable) && defined (PRR1) && defined (PRUSART2)
#define power_usart2_enable()   (PRR1 &= (uint8_t)~(1 << PRUSART2))
#define power_usart2_disable()  (PRR1 |= (uint8_t)(1 << PRUSART2))
#endif

#if !defined (power_usart3_enable) && defined (PRR1) && defined (PRUSART3)
#define power_usart3_enable()   (PRR1 &= (uint8_t)~(1 << PRUSART3))
#define power_usart3_disable()  (PRR1 |= (uint8_t)(1 << PRUSART3))
#endif

#if !defined (power_pga_enable) && defined (PRR0) && defined (PRPGA)
#define power_pga_enable()           (PRR0 &= (uint8_t)~(1 << PRPGA))
#define power_pga_disable()          (PRR0 |= (uint8_t)(1 << PRPGA))
#endif

#if !defined (power_transceiver_enable) && defined (PRR1) && defined (PRTRX24)
#define power_transceiver_enable()   (PRR1 &= (uint8_t)~(1 << PRTRX24))
#define power_transceiver_disable()  (PRR1 |= (uint8_t)(1 << PRTRX24))
#endif

#if !defined (power_ram0_enable) && defined (PRR2) && defined (PRRAM0)
#define power_ram0_enable()          (PRR2 &= (uint8_t)~(1 << PRRAM0))
#define power_ram0_disable()         (PRR2 |= (uint8_t)(1 << PRRAM0))
#endif

#if !defined (power_ram1_enable) && defined (PRR2) && defined (PRRAM1)
#define power_ram1_enable()          (PRR2 &= (uint8_t)~(1 << PRRAM1))
#define power_ram1_disable()         (PRR2 |= (uint8_t)(1 << PRRAM1))
#endif

#if !defined (power_ram2_enable) && defined (PRR2) && defined (PRRAM2)
#define power_ram2_enable()          (PRR2 &= (uint8_t)~(1 << PRRAM2))
#define power_ram2_disable()         (PRR2 |= (uint8_t)(1 << PRRAM2))
#endif

#if !defined (power_ram3_enable) && defined (PRR2) && defined (PRRAM3)
#define power_ram3_enable()          (PRR2 &= (uint8_t)~(1 << PRRAM3))
#define power_ram3_disable()         (PRR2 |= (uint8_t)(1 << PRRAM3))
#endif

#if !defined (power_adc_enable) && defined (PRR) && defined (PRADC)
#define power_adc_enable()      (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR |= (uint8_t)(1 << PRADC))
#endif

#if !defined (power_spi_enable) && defined (PRR) && defined (PRSPI)
#define power_spi_enable()      (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR |= (uint8_t)(1 << PRSPI))
#endif

#if !defined (power_timer0_enable) && defined (PRR) && defined (PRTIM0)
#define power_timer0_enable()   (PRR &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR |= (uint8_t)(1 << PRTIM0))
#endif

#if !defined (power_timer1_enable) && defined (PRR) && defined (PRTIM1)
#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))
#endif

/* Power Stage Controller 0 */
#if !defined (power_psc0_enable) && defined (PRR) && defined (PRPSC0)
#define power_psc0_enable()     (PRR &= (uint8_t)~(1 << PRPSC0))
#define power_psc0_disable()    (PRR |= (uint8_t)(1 << PRPSC0))
#endif

/* Power Stage Controller 1 */
#if !defined (power_psc1_enable) && defined (PRR) && defined (PRPSC1)
#define power_psc1_enable()     (PRR &= (uint8_t)~(1 << PRPSC1))
#define power_psc1_disable()    (PRR |= (uint8_t)(1 << PRPSC1))
#endif

/* Power Stage Controller 2 */
#if !defined (power_psc2_enable) && defined (PRR) && defined (PRPSC2)
#define power_psc2_enable()     (PRR &= (uint8_t)~(1 << PRPSC2))
#define power_psc2_disable()    (PRR |= (uint8_t)(1 << PRPSC2))
#endif

#if !defined (power_usart_enable) && defined (PRR) && defined (PRUSART)
#define power_usart_enable()    (PRR &= (uint8_t)~(1 << PRUSART))
#define power_usart_disable()   (PRR |= (uint8_t)(1 << PRUSART))
#endif

/* Reduced Power Stage Controller */
#if !defined (power_pscr_enable) && defined (PRR) && defined (PRPSCR)
#define power_pscr_enable()     (PRR &= (uint8_t)~(1 << PRPSCR))
#define power_pscr_disable()    (PRR |= (uint8_t)(1 << PRPSCR))
#endif

#if !defined (power_usart0_enable) && defined (PRR) && defined (PRUSART0)
#define power_usart0_enable()   (PRR &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR |= (uint8_t)(1 << PRUSART0))
#endif

#if !defined (power_usart1_enable) && defined (__AVR_HAVE_USART1_PRR0
#define power_usart1_enable()   (PRR0 &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable()  (PRR0 |= (uint8_t)(1 << PRUSART1))
#endif

/* Voltage ADC */
#if !defined (power_vadc_enable) && defined (PRR0) && defined (PRVADC)
#define power_vadc_enable()     (PRR0 &= (uint8_t)~(1 << PRVADC))
#define power_vadc_disable()    (PRR0 |= (uint8_t)(1 << PRVADC))
#endif

#if !defined (power_timer2_enable) && defined (PRR) && defined (PRTIM2)
#define power_timer2_enable()   (PRR &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable()  (PRR |= (uint8_t)(1 << PRTIM2))
#endif

#if !defined (power_twi_enable) && defined (PRR) && defined (PRTWI)
#define power_twi_enable()      (PRR &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR |= (uint8_t)(1 << PRTWI))
#endif

/* Universal Serial Interface */
#if !defined (power_usi_enable) && defined (PRR) && defined (PRUSI)
#define power_usi_enable()      (PRR &= (uint8_t)~(1 << PRUSI))
#define power_usi_disable()     (PRR |= (uint8_t)(1 << PRUSI))
#endif

#define power_vrm_enable()      (PRR0 &= (uint8_t)~(1 << PRVRM))
#define power_vrm_disable()     (PRR0 |= (uint8_t)(1 << PRVRM))
#endif

// Enable the voltage monitor 
#if !defined (power_vmonitor_enable) && defined (PRR0) && defined (PRVM)
#define power_vmonitor_enable()          (PRR0 &= (uint8_t)~(1 << PRVM))
#define power_vmonitor_disable()         (PRR0 |= (uint8_t)(1 << PRVM))
#endif

#if !defined (power_irdriver_enable) && defined (PRR0) && defined (PRDS)
#define power_irdriver_enable()          (PRR0 &= (uint8_t)~(1 << PRDS))
#define power_irdriver_disable()         (PRR0 |= (uint8_t)(1 << PRDS))
#endif

#if !defined (power_crypto_enable) && defined (PRR0) && defined (PRCU)
#define power_crypto_enable()            (PRR0 &= (uint8_t)~(1 << PRCU))
#define power_crypto_disable()           (PRR0 |= (uint8_t)(1 << PRCU))
#endif

#if !defined (power_timermodulator_enable) && defined (PRR0) && defined (PRTM)
#define power_timermodulator_enable()    (PRR0 &= (uint8_t)~(1 << PRTM))
#define power_timermodulator_disable()   (PRR0 |= (uint8_t)(1 << PRTM))
#endif

#if !defined (power_timer1_enable) && defined (PRR0) && defined (PRT1)
#define power_timer1_enable()            (PRR0 &= (uint8_t)~(1 << PRT1))
#define power_timer1_disable()           (PRR0 |= (uint8_t)(1 << PRT1))
#endif

#if !defined (power_timer2_enable) && defined (PRR0) && defined (PRT2)
#define power_timer2_enable()            (PRR0 &= (uint8_t)~(1 << PRT2))
#define power_timer2_disable()           (PRR0 |= (uint8_t)(1 << PRT2))
#endif

#if !defined (power_timer3_enable) && defined (PRR0) && defined (PRT3)
#define power_timer3_enable()            (PRR0 &= (uint8_t)~(1 << PRT3))
#define power_timer3_disable()           (PRR0 |= (uint8_t)(1 << PRT3))
#endif

#if !defined (power_cinterface_enable) && defined (PRR1) && defined (PRCI)
#define power_cinterface_enable()        (PRR1 &= (uint8_t)~(1 << PRCI))
#define power_cinterface_disable()       (PRR1 |= (uint8_t)(1 << PRCI))
#endif

#if !defined (power_lfreceiver_enable) && defined (PRR0) && defined (PRLFR)            
#define power_lfreceiver_enable()        (PRR0 &= (uint8_t)~(1 << PRLFR))            
#define power_lfreceiver_disable()       (PRR0 |= (uint8_t)(1 << PRLFR))            
#endif

#if !defined (power_lin_enable) && defined (PRR) && defined (PRLIN)
#define power_lin_enable()      (PRR &= (uint8_t)~(1 << PRLIN))
#define power_lin_disable()     (PRR |= (uint8_t)(1 << PRLIN))
#endif

#if !defined (power_spi_enable) && defined (PRR) && defined (PRSPI)
#define power_spi_enable()      (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR |= (uint8_t)(1 << PRSPI))
#endif

#if !defined (power_psc_enable) && defined (PRR) && defined (PRPSC)
#define power_psc_enable()      (PRR &= (uint8_t)~(1 << PRPSC))
#define power_psc_disable()     (PRR |= (uint8_t)(1 << PRPSC))
#endif

#if !defined (power_can_enable) && defined (PRR) && defined (PRCAN)
#define power_can_enable()      (PRR &= (uint8_t)~(1 << PRCAN))
#define power_can_disable()     (PRR |= (uint8_t)(1 << PRCAN))
#endif

#if !defined (power_usart1_enable) && defined (PRR) && defined (PRUSART1)
#define power_usart1_enable()      (PRR &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable()     (PRR |= (uint8_t)(1 << PRUSART1))
#endif

#if !defined (power_usbh_enable) && defined (PRR1) && defined (PRUSBH)
#define power_usbh_enable()     (PRR1 &= (uint8_t)~(1 << PRUSBH))
#define power_usbh_disable()    (PRR1 |= (uint8_t)(1 << PRUSBH))
#endif

#if !defined (power_hsspi_enable) && defined (PRR1) && defined (PRHSSPI)
#define power_hsspi_enable()    (PRR1 &= (uint8_t)~(1 << PRHSSPI))
#define power_hsspi_disable()   (PRR1 |= (uint8_t)(1 << PRHSSPI))
#endif

#if !defined (power_sci_enable) && defined (PRR1) && defined (PRSCI)
#define power_sci_enable()      (PRR1 &= (uint8_t)~(1 << PRSCI))
#define power_sci_disable()     (PRR1 |= (uint8_t)(1 << PRSCI))
#endif

#if !defined (power_kb_enable) && defined (PRR1) && defined (PRKB)
#define power_kb_enable()       (PRR1 &= (uint8_t)~(1 << PRKB))
#define power_kb_disable()      (PRR1 |= (uint8_t)(1 << PRKB))
#endif


#ifdef __AVR_POWER_CLKPR_HEADER__
#include __AVR_POWER_CLKPR_HEADER__
#endif

#endif /* _AVR_POWER_H_ */

/* Copyright (c) 2002,2003,2005,2006,2007 Marek Michalkiewicz, Joerg Wunsch
   Copyright (c) 2007 Eric B. Weddington
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

/** \file */
/** \defgroup avr_io <avr/io.h>: AVR device-specific IO definitions
    \code #include <avr/io.h> \endcode

    This header file includes the apropriate IO definitions for the
    device that has been specified by the <tt>-mmcu=</tt> compiler
    command-line switch.  This is done by diverting to the appropriate
    file <tt>&lt;avr/io</tt><em>XXXX</em><tt>.h&gt;</tt> which should
    never be included directly.  Some register names common to all
    AVR devices are defined directly within <tt>&lt;avr/common.h&gt;</tt>,
    which is included in <tt>&lt;avr/io.h&gt;</tt>,
    but most of the details come from the respective include file.

    Note that this file always includes the following files:
    \code 
    #include <avr/sfr_defs.h>
    #include <avr/portpins.h>
    #include <avr/common.h>
    #include <avr/version.h>
    \endcode
    See \ref avr_sfr for more details about that header file.

    Included are definitions of the IO register set and their
    respective bit values as specified in the Atmel documentation.
    Note that inconsistencies in naming conventions,
    so even identical functions sometimes get different names on
    different devices.

    Also included are the specific names useable for interrupt
    function definitions as documented
    \ref avr_signames "here".

    Finally, the following macros are defined:

    - \b RAMEND
    <br>
    The last on-chip RAM address.
    <br>
    - \b XRAMEND
    <br>
    The last possible RAM location that is addressable. This is equal to 
    RAMEND for devices that do not allow for external RAM. For devices 
    that allow external RAM, this will be larger than RAMEND.
    <br>
    - \b E2END
    <br>
    The last EEPROM address.
    <br>
    - \b FLASHEND
    <br>
    The last byte address in the Flash program space.
    <br>
    - \b SPM_PAGESIZE
    <br>
    For devices with bootloader support, the flash pagesize
    (in bytes) to be used for the \c SPM instruction. 
    - \b E2PAGESIZE
    <br>
    The size of the EEPROM page.
    
*/

#ifndef _AVR_IO_H_
#define _AVR_IO_H_

#include <avr/sfr_defs.h>

#if defined (__AVR_AT43USB320__)
#  include <avr/io43u32x.h>
#elif defined (__AVR_AT43USB355__)
#  include <avr/io43u35x.h>
#elif defined (__AVR_AT76C711__)
#  include <avr/io76c711.h>
#elif defined (__AVR_AT86RF401__)
#  include <avr/io86r401.h>
#elif defined (__AVR_AT90PWM2__)
#  include <avr/io90pwmx.h>
#elif defined (__AVR_AT90PWM3__)
#  include <avr/io90pwmx.h>
#elif defined (__AVR_ATmega644__) || defined (__AVR_ATmega644A__)
#  include <avr/iom644.h>
#elif defined (__AVR_ATmega645__) || defined (__AVR_ATmega645A__) || defined (__AVR_ATmega645P__)
#  include <avr/iom645.h>
#elif defined (__AVR_ATmega6450__) || defined (__AVR_ATmega6450A__) || defined (__AVR_ATmega6450P__)
#  include <avr/iom6450.h>
#elif defined (__AVR_ATmega649__) || defined (__AVR_ATmega649A__)
#  include <avr/iom649.h>
#elif defined (__AVR_ATmega6490__) || defined (__AVR_ATmega6490A__) || defined (__AVR_ATmega6490P__)
#  include <avr/iom6490.h>
#elif defined (__AVR_ATmega324P__) || defined (__AVR_ATmega324A__)
#  include <avr/iom324.h>
#elif defined (__AVR_ATmega325__) || defined (__AVR_ATmega325A__)
#  include <avr/iom325.h>
#elif defined (__AVR_ATmega325P__)
#  include <avr/iom325.h>
#elif defined (__AVR_ATmega3250__) || defined (__AVR_ATmega3250A__)
#  include <avr/iom3250.h>
#elif defined (__AVR_ATmega3250P__)
#  include <avr/iom3250.h>
#elif defined (__AVR_ATmega328P__) || defined (__AVR_ATmega328__)
#  include <avr/iom328p.h>
#elif defined (__AVR_ATmega329__) || defined (__AVR_ATmega329A__)
#  include <avr/iom329.h>
#elif defined (__AVR_ATmega329P__) || defined (__AVR_ATmega329PA__)
#  include <avr/iom329.h>
#elif defined (__AVR_ATmega3290__) || defined (__AVR_ATmega3290A__)
#  include <avr/iom3290.h>
#elif defined (__AVR_ATmega3290P__)
#  include <avr/iom3290.h>
#elif defined (__AVR_ATmega164P__) || defined (__AVR_ATmega164A__)
#  include <avr/iom164.h>
#elif defined (__AVR_ATmega165__) || defined (__AVR_ATmega165A__)
#  include <avr/iom165.h>
#elif defined (__AVR_ATmega168__) || defined (__AVR_ATmega168A__)
#  include <avr/iom168.h>
#elif defined (__AVR_ATmega169__) || defined (__AVR_ATmega169A__)
#  include <avr/iom169.h>
#elif defined (__AVR_ATmega48__) || defined (__AVR_ATmega48A__)
#  include <avr/iom48.h>
#elif defined (__AVR_ATmega88__) || defined (__AVR_ATmega88A__)
#  include <avr/iom88.h>
#elif defined (__AVR_AT90S8535__)
#  include <avr/io8535.h>
#elif defined (__AVR_AT90C8534__)
#  include <avr/io8534.h>
#elif defined (__AVR_AT90S8515__)
#  include <avr/io8515.h>
#elif defined (__AVR_AT90S4434__)
#  include <avr/io4434.h>
#elif defined (__AVR_AT90S4433__)
#  include <avr/io4433.h>
#elif defined (__AVR_AT90S4414__)
#  include <avr/io4414.h>
#elif defined (__AVR_AT90S2343__)
#  include <avr/io2343.h>
#elif defined (__AVR_AT90S2333__)
#  include <avr/io2333.h>
#elif defined (__AVR_AT90S2323__)
#  include <avr/io2323.h>
#elif defined (__AVR_AT90S2313__)
#  include <avr/io2313.h>
#elif defined (__AVR_ATtiny84A__)
#  include <avr/iotn84a.h>  
/* avr1: the following only supported for assembler programs */
#elif defined (__AVR_AT90S1200__)
#  include <avr/io1200.h>
#elif defined (__AVR_DEV_LIB_NAME__)
#  define __eval__(a) a
#  define __concat__(a,b) a##b
#  define __header1__(a,b) __concat__(a,b)
#  define __AVR_DEVICE_HEADER__ <avr/__header1__(io,__AVR_DEV_LIB_NAME__).h>
#  include __AVR_DEVICE_HEADER__
#else
#  if !defined(__COMPILING_AVR_LIBC__)
#    warning "device type not defined"
#  endif
#endif

#include <avr/portpins.h>

#include <avr/common.h>

#include <avr/version.h>

#if __AVR_ARCH__ >= 100
#  include <avr/xmega.h>
#endif

/* Include fuse.h after individual IO header files. */
#include <avr/fuse.h>

/* Include lock.h after individual IO header files. */
#include <avr/lock.h>

#endif /* _AVR_IO_H_ */

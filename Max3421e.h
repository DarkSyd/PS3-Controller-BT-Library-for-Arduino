/* Copyright 2009-2011 Oleg Mazurov, Circuits At Home, http://www.circuitsathome.com */
/* MAX3421E functions */
#ifndef _MAX3421E_H_
#define _MAX3421E_H_


//#include <Spi.h>
//#include <WProgram.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Max3421e_constants.h"

class MAX3421E /* : public SPI */ {
    // byte vbusState;
    public:
        MAX3421E( void );
        uint8_t getVbusState( void );
//        void toggle( byte pin );
        static void regWr( byte, byte );
        char * bytesWr( byte, byte, char * );
        static void gpioWr( byte );
        uint8_t regRd( byte );
        char * bytesRd( byte, byte, char * );
        uint8_t gpioRd( void );
        boolean reset();
        boolean vbusPwr ( boolean );
        void busprobe( void );
        void powerOn();
        uint8_t IntHandler();
        uint8_t GpxHandler();
        uint8_t Task();
    private:
      static void spi_init() {
        uint8_t tmp;
        // initialize SPI pins
        pinMode(SCK_PIN, OUTPUT);
        pinMode(MOSI_PIN, OUTPUT);
        pinMode(MISO_PIN, INPUT);
        pinMode(SS_PIN, OUTPUT);
        digitalWrite( SS_PIN, HIGH ); 
        /* mode 00 (CPOL=0, CPHA=0) master, fclk/2. Mode 11 (CPOL=11, CPHA=11) is also supported by MAX3421E */
        SPCR = 0x50;
        SPSR = 0x01;
        /**/
        tmp = SPSR;
        tmp = SPDR;
    }
//        void init();
    friend class Max_LCD;        
};




#endif //_MAX3421E_H_

/* Copyright 2016, XXXX
 *
 *  * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "06_pantalla.h"       /* <= own header */
#define LIMIT_SUP 1020
#define LIMIT_INF 5
#define CONST_TIMER 300000
#define TEXTO "HOLA"
#define TIEMPO 1000

void Delay (void){
uint64_t i;
for (i=CONST_TIMER;i!=0;i--);
}

void Convertir_senal(void)
{
	uint16_t valor, tension;
	char *cad;
	valor=(read_ADC_value_pooling()*33)/1023;
	sendString_UART_USB_EDUCIAA("\n\r Tension entregada: ",25);
	sendString_UART_USB_EDUCIAA(Itoa(valor,10),4);
	sendString_UART_USB_EDUCIAA(" mVolt ",6);

	if (valor > LIMIT_SUP)
	    {
	    TooggleLed(LED_1);
	    Delay();
	    ApagarLed(LED_3);
	    }
	 else
	    {
	    if (valor<LIMIT_INF)
	    	{
	    	EncenderLed(LED_3);
	    	ApagarLed(LED_1);
	    	}
	    else
	    	{
	    	ApagarLed(LED_1);
	    	ApagarLed(LED_3);
	    	}
	    }

}
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */



int main(void)
{
	void (*pfunc)();
	uint16_t valor;
   /* inicializaciones */
	InitLeds();
	init_ADC_EDUCIAA();
	init_UART_FTDI_EDUCIAA();
	ADC_Sel(CH1);


		pfunc= &Convertir_senal;
		timerInit(TIEMPO,pfunc);

    /*acá va mi programa principal */
   
    while(1){

    };
    	return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/


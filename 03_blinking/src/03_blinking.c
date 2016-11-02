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
#include "stdint.h"
#include "03_blinking.h"       /* <= own header */



/*==================[macros and definitions]=================================*/
#define CONST_TIMER 300000

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
void Delay(uint8_t c ){
	uint64_t i;

 for(i=CONST_TIMER * c; i!=0; i--);

}

void IzquierdoLed(uint8_t *led_encendido){



	      switch(*led_encendido){


	      	  case LED_3:
	    			 *led_encendido = LED_2;
	    	  break;
	      	  case LED_2:
	      	    	 *led_encendido = LED_1;
	      	    break;
	      	  case LED_1:
	      		     *led_encendido = LED_RED;
	      		break;
	      	  case  LED_RED:
	      		    *led_encendido = LED_GREEN;
	      		break;
	      	  case LED_GREEN:
	      		  *led_encendido = LED_BLUE;
	      		  break;
	      	  case LED_BLUE:
	      		  *led_encendido = LED_3;
	      		  break;
	      	  default:break;

	      }
	      TooggleLed(*led_encendido);



}

void DerechoLed(uint8_t *led_encendido){



	      switch(*led_encendido){


	      	  case LED_RED:
	    			 *led_encendido = LED_GREEN;
	    	  break;
	      	  case LED_GREEN:
	      	    	 *led_encendido = LED_BLUE;
	      	    break;
	      	  case LED_BLUE:
	      		     *led_encendido = LED_1;
	      		break;
	      	  case  LED_1:
	      		    *led_encendido = LED_2;
	      		break;
	      	  case LED_2:
	      		  *led_encendido = LED_3;
	      		  break;
	      	  case LED_3:
	      		  *led_encendido = LED_RED;
	      		  break;
	      	  default:break;

	      }
	      TooggleLed(*led_encendido);




}
int main(void)
{

	uint8_t frecuencia =1;
	uint8_t led_encendido = LED_3;
	uint8_t tecla;


   /* inicializaciones */
     InitLeds();
	 Init_Switches();

	 /*Enceder Led*/
	 EncenderLed(led_encendido);





	 /*Lectura de Tecla */

   
   
   /*acá va mi programa principal */
while(1){
 do{
	 TooggleLed(led_encendido);
	 Delay(frecuencia);
	   tecla = Read_Switches();
   }while(tecla==0);

 ApagarLed(led_encendido);

switch(tecla){
	case TEC3:
		IzquierdoLed(&led_encendido);
	break;
	case TEC4:
		 DerechoLed(&led_encendido);
	case TEC2:
		frecuencia++;

	break;
	case TEC1:
		if(frecuencia > 1)
		  frecuencia--;
		else
			frecuencia=1;

	break;
}
Delay(frecuencia);
TooggleLed(led_encendido);
};
	return 0;


}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/


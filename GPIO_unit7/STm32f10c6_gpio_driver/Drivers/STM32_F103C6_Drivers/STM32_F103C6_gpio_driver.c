/*
 * STM32_F103C6_gpio_driver.c
 *
 *  Created on: Sep 24, 2024
 *      Author: thomas ashraf zaki
 */

#include "STM32_F103C6_gpio_driver.h"
/**================================================================
 * @Fn                 - GPIO_CRHL_Position
 * @brief              - detect the position of the selected pin in CRL or CRH
 * @param[in] 		  - pin_num :  pin num from pin config @ref GPIO_pin_define
 * @retval             - vuint8_t
 * Note                - none
 */
vuint8_t GPIO_CRHL_Position(vuint16_t pin_num){
	switch(pin_num){
	case GPIO_pin_0 :
	{
		return 0;
		break;
	}
	case GPIO_pin_1 :
	{
		return 4;
		break;
	}
	case GPIO_pin_2 :
	{
		return 8;
		break;
	}
	case GPIO_pin_3 :
	{
		return 12;
		break;
	}
	case GPIO_pin_4 :
	{
		return 16;
		break;
	}
	case GPIO_pin_5 :
	{
		return 20;
		break;
	}
	case GPIO_pin_6 :
	{
		return 24;
		break;
	}
	case GPIO_pin_7 :
	{
		return 28;
		break;
	}
	case GPIO_pin_8 :
	{
		return 0;
		break;
	}
	case GPIO_pin_9 :
	{
		return 4;
		break;
	}
	case GPIO_pin_10 :
	{
		return 8;
		break;
	}
	case GPIO_pin_11 :
	{
		return 12;
		break;
	}
	case GPIO_pin_12 :
	{
		return 16;
		break;
	}
	case GPIO_pin_13 :
	{
		return 20;
		break;
	}
	case GPIO_pin_14 :
	{
		return 24;
		break;
	}
	case GPIO_pin_15 :
	{
		return 28;
		break;
	}
	default:
	{
		return 0;
		break;
	}
	}
}
/**================================================================
 * @Fn                 - MCAL_GPIO_Init
 * @brief              - initialize GPIOx Piny according to the specified parameters in PinConfig
 * @param[in] 		  - GPIOx: where x(A....E) is pointer that contain the addresses of the registers of GPIO
 * @param[in]          - PinConfig: is pointer to GPIO_pin_config_t that contain the configuration
 * 						information of the specified GPIO pin
 * @retval             - none
 * Note                - stm32f103c6 contain GPIO PORT(A....E)
 * 						but LQFP48 package contain full pins of GPIOA,GPIOB .partial of GPIOC,GPIOD.not used GPIOE
 */
void MCAL_GPIO_Init  (GPIO_Register_t* GPIOx ,GPIO_pin_config_t* PinConfig){

	//CRL Register ==>Port x configuration bits (y= 0 .. 7)
	//CRH Register ==>Port x configuration bits (y= 8 .. 15)
	vuint8_t pin;
	vuint32_t *ConfigReg=NULL;
	//select the register
	ConfigReg=((PinConfig->GPIO_pin_number) < GPIO_pin_8)? &(GPIOx->CRL) : &(GPIOx->CRH);

	//clear CNFy[1:0] MODEy[1:0]
	*ConfigReg &=~(0x0f<<GPIO_CRHL_Position(PinConfig->GPIO_pin_number));

	//if pin is output
	if((PinConfig->GPIO_mode==GPIO_mode_output_PP)||(PinConfig->GPIO_mode==GPIO_mode_AF_output_OD)||(PinConfig->GPIO_mode==GPIO_mode_AF_output_PP)||(PinConfig->GPIO_mode==GPIO_mode_output_OD)){
		//set CNFy[1:0] MODEy[1:0]
		pin =((((PinConfig->GPIO_mode) - 4)<<2)|(PinConfig->GPIO_speed))&0x0f;
	}
	else{//if pin is input
		if((PinConfig->GPIO_mode==GPIO_mode_Analog)||(PinConfig->GPIO_mode==GPIO_mode_Input_FLO)){
			//set CNFy[1:0] MODEy[1:0]00
			pin =(((PinConfig->GPIO_mode)<<2)|(0x0))&0x0f;
		}
		else if((PinConfig->GPIO_mode==GPIO_mode_AF_input)){
			//act as floating pin input
			PinConfig->GPIO_mode=GPIO_mode_Input_FLO;
			pin =(((PinConfig->GPIO_mode)<<2)|(0x0))&0x0f;
		}
		else{//pull up or pull down
			//10: Input with pull-up / pull-down=======>in TRM
			pin =(((0b10)<<2)|(0x0))&0x0f;
			//to make difference between pull up , pull down ====>use ODR Register
			if(PinConfig->GPIO_mode==GPIO_mode_Input_PU){
				//set pin
				//according Table 20. Port bit configuration table
				GPIOx->ODR  |=(PinConfig->GPIO_pin_number); // @ref GPIO_pin_define
			}
			else
			{
				//clear pin
				//according Table 20. Port bit configuration table
				GPIOx->ODR  &=~(PinConfig->GPIO_pin_number); // @ref GPIO_pin_define
			}
		}
	}
	//shift this value to real position in the register
	*ConfigReg |= ((pin)<< (GPIO_CRHL_Position(PinConfig->GPIO_pin_number)));
}




/**================================================================
 * @Fn                 - MCAL_GPIO_DeInit
 * @brief              - reset ALL registers to the reset value
 * @param[in] 		  - GPIOx: where x(A....E) is pointer that contain the addresses of the registers of GPIO
 * @retval             - none
 * Note                - none
 */
void MCAL_GPIO_DeInit(GPIO_Register_t* GPIOx){
	//reset manual if you donot have reset controler
	//GPIOx->CRH=0x44444444;
	//GPIOx->CRL=0x44444444;
	//GPIOx->IDR  (READ only)
	//GPIOx->ODR=0x00000000;
	//GPIOx->LCKR=0x00000000;

	//by reset controller in RCC
	if(GPIOx==GPIOA){//Bit 2 IOPARST: IO port A reset
		//Set and cleared by software.
		RCC->APB2RSTR |=(1<<2);
		RCC->APB2RSTR &=~(1<<2);
	}else if (GPIOx==GPIOB){//Bit 3 IOPBRST: IO port B reset
		//Set and cleared by software.
		RCC->APB2RSTR |=(1<<3);
		RCC->APB2RSTR &=~(1<<3);
	}else if (GPIOx==GPIOC){//Bit 4 IOPCRST: IO port C reset
		//Set and cleared by software.
		RCC->APB2RSTR |=(1<<4);
		RCC->APB2RSTR &=~(1<<4);
	}else if (GPIOx==GPIOD){//Bit 5 IOPDRST: IO port D reset
		//Set and cleared by software.
		RCC->APB2RSTR |=(1<<5);
		RCC->APB2RSTR &=~(1<<5);
	}else if (GPIOx==GPIOE){//Bit 6 IOPERST: IO port E reset
		//Set and cleared by software.
		RCC->APB2RSTR |=(1<<6);
		RCC->APB2RSTR &=~(1<<6);
	}
}




/**================================================================
 * @Fn                 - MCAL_GPIO_ReadPin
 * @brief              - read a input value from pin
 * @param[in] 		  - GPIOx: where x(A....E) is pointer that contain the addresses of the registers of GPIO
 * @param[in]          - PinNumber: is the specified pin to Read (according to @ref GPIO_pin_define)
 * @retval             - return the input value of pin reading (according to @ref GPIO_ReadPin_state)
 * Note                - none
 */
vuint8_t MCAL_GPIO_ReadPin(GPIO_Register_t* GPIOx,vuint16_t PinNumber){

	vuint8_t pinStatus ;
	//check if pin is 1
	if ((GPIOx->IDR) & PinNumber){
		pinStatus = (vuint8_t)GPIO_ReadPin_set;
	}else{
		pinStatus = (vuint8_t)GPIO_ReadPin_reset;
	}
	return pinStatus;
}




/**================================================================
 * @Fn                 - MCAL_GPIO_ReadPort
 * @brief              - read a input value from port
 * @param[in] 		  - GPIOx: where x(A....E) is pointer that contain the addresses of the registers of GPIO
 * @retval             - return the input value of port reading
 * Note                - none
 */
vuint16_t MCAL_GPIO_ReadPort(GPIO_Register_t* GPIOx){

	vuint16_t portReading;
	portReading= (vuint16_t)GPIOx->IDR;
	return portReading;
}




/**================================================================
 * @Fn                 - MCAL_GPIO_WritePin
 * @brief              - write a value in specific pin
 * @param[in] 		  - GPIOx: where x(A....E) is pointer that contain the addresses of the registers of GPIO
 * @param[in]          - PinNumber: is the specific pin to write on it (according to @ref GPIO_pin_define)
 * @param[in]          - value: pin value
 * @retval             - none
 * Note                - none
 */
void MCAL_GPIO_WritePin(GPIO_Register_t* GPIOx,vuint16_t PinNumber,vuint8_t value){

	if ( value == (vuint8_t)GPIO_ReadPin_set){
		//GPIOx->ODR |=PinNumber;
		//or use BSRR Register
		/*Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Set the corresponding ODRx bit*/
		GPIOx->BSRR =(vuint32_t)PinNumber;
	}else{
		//GPIOx->ODR &=~(PinNumber);
		//or use BRR Register
		/*Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Reset the corresponding ODRx bit*/
		GPIOx->BRR =(vuint32_t)PinNumber;
	}
}




/**================================================================
 * @Fn                 - MCAL_GPIO_WritePort
 * @brief              - write a value in specific port
 * @param[in] 		  - GPIOx: where x(A....E) is pointer that contain the addresses of the registers of GPIO
 * @param[in]          - value: port value
 * @retval             - none
 * Note                - none
 */
void MCAL_GPIO_WritePort(GPIO_Register_t* GPIOx,vuint16_t value){

	GPIOx->ODR =(vuint32_t)value;
}




/**================================================================
 * @Fn                 - MCAL_GPIO_TogglePin
 * @brief              - toggle the specific pin
 * @param[in] 		  - GPIOx: where x(A....E) is pointer that contain the addresses of the registers of GPIO
 * @param[in]          - PinNumber: is the specified pin to toggle (according to @ref GPIO_pin_define)
 * @retval             - none
 * Note                - none
 */
void MCAL_GPIO_TogglePin(GPIO_Register_t* GPIOx,vuint16_t PinNumber){

	GPIOx->ODR ^=(PinNumber);
}




/**================================================================
 * @Fn                 - MCAL_GPIO_LockPin
 * @brief              - lock a specific pin of GPIOx
 * @param[in] 		  - GPIOx: where x(A....E) is pointer that contain the addresses of the registers of GPIO
 * @param[in]          - PinNumber: is the specified pin to lock (according to @ref GPIO_pin_define)
 * @retval             - return ok if lock is successful  , error if lock failed (according to @ref GPIO_Lockpin_state)
 * Note                - none
 */
vuint8_t MCAL_GPIO_LockPin(GPIO_Register_t* GPIOx,vuint16_t PinNumber){

	/*This register is used to lock the configuration of the port bits when a correct write sequence
is applied to bit 16 (LCKK). The value of bits [15:0] is used to lock the configuration of the
GPIO. During the write sequence, the value of LCKR[15:0] must not change. When the
LOCK sequence has been applied on a port bit it is no longer possible to modify the value of
the port bit until the next reset.*/
	/*Bit 16 LCKK[16]: Lock key
This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
0: Port configuration lock key not active
1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
LOCK key writing sequence:
Write 1
Write 0
Write 1
Read 0
Read 1 (this read is optional but confirms that the lock is active)
Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
Any error in the lock sequence will abort the lock.
Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
These bits are read write but can only be written when the LCKK bit is 0.
0: Port configuration not locked*/
	vuint32_t temp;
	//set LCKy
	GPIOx->LCKR |=PinNumber;
	//Write 1
	GPIOx->LCKR |=(1<<16);
	//Write 0
	GPIOx->LCKR &=~(1<<16);
	//Write 1
	GPIOx->LCKR |=(1<<16);
	//Read 0
	temp=GPIOx->LCKR;
	//Read 1 (this read is optional but confirms that the lock is active)
	if(GPIOx->LCKR & (1<<16)){
		return GPIO_Lockpin_ok;
	}else{
		return GPIO_Lockpin_error;
	}
}





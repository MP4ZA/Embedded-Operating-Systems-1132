/*
 * bluetooth.c
 *
 *  Created on: Jun 4, 2025
 *      Author: ray88
 */




/* Includes ------------------------------------------------------------------*/
#include "bluetooth.h"
#include "main.h"

/* variable ------------------------------------------------------------------*/
BLUETOOTH_DEVICE_InfoTypeDef BT_INFO;

/*
 * Function: Wait_init
 * -------------------
 * Initializes the system for WAIT_MODE.
 *
 * Behavior:
 * - Turns off all LEDs (connected to GPIOD Pins 12–15).
 * - Intended to disable or initialize other peripheral components (commented out).
 * - Sets the system mode to WAIT_MODE.
 */
void Wait_init(){

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); // Turn off Green LED
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET); // Turn off Orange LED
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); // Turn off Red LED
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET); // Turn off Blue LED
	// ClosePeripheralComponents(); // Shut down other modules

	// Activate required functions.
	// low_energy_operation();

	BT_INFO.BT_state = WAIT_MODE; // Set the current mode to WAIT_MODE
}


/*
 * Function: Work_init
 * -------------------
 * Initializes the system for WORK_MODE.
 *
 * Behavior:
 * - Turns on the Green LED (GPIOD Pin 12) to indicate WORK_MODE.
 * - Turns off the Orange, Red, and Blue LEDs (Pins 13–15).
 * - Placeholder for other functions required in WORK_MODE (commented out).
 * - Sets the Bluetooth state to WORK_MODE in the BT_INFO structure.
 */
void Work_init(){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);


	//OtherfunctionworkinWORK_MODE();

	BT_INFO.BT_state = WORK_MODE;
}


/*
 * Function: Find_init
 * -------------------
 * Initializes the system for FIND_MODE.
 *
 * Behavior:
 * - Turns on the Blue LED (GPIOD Pin 15) to indicate FIND_MODE.
 * - Turns off the Green, Orange, and Red LEDs (Pins 12–14).
 * - Placeholder for other functions required in FIND_MODE (commented out).
 * - Sets the Bluetooth state to FIND_MODE in the BT_INFO structure.
 */
void Find_init(){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);

	////OtherfunctionworkinFIND_MODE();
	BT_INFO.BT_state = FIND_MODE;
}


/**
 * Function: SwitchMode
 * --------------------
 * Switches the Bluetooth operating mode based on the given state.
 *
 * Parameters:
 *   state - The target Bluetooth state to switch to. Possible values:
 *           WAIT_MODE:  Sets the device into idle/waiting mode.
 *           WORK_MODE:  Sets the device into active/working mode.
 *           FIND_MODE:  Sets the device into scanning/searching mode.
 *
 * Notes:
 * - Optional functions like ClosePeripheralComponents() and OpenPeripheralComponents()
 *   can be enabled to manage power or peripherals when entering specific modes.
 * - The current mode is stored in the global variable BT_MODE.
 */
void SwitchMode(BLUETOOTH_STATETypeDef state){
	switch(state){
	case WAIT_MODE:
		//ClosePeripheralComponents();
		Wait_init();
		break;
	case WORK_MODE:
		//OpenPeripheralComponents();
		Work_init();
		break;
	case FIND_MODE:
		Find_init();
		break;
	default:
		break;
	}
}

//To be determined
void Send_RSSI(){

}


/*
 * bluetooth.h
 *
 *  Created on: Jun 4, 2025
 *      Author: ray88
 */

#ifndef INC_BLUETOOTH_H_
#define INC_BLUETOOTH_H_

#include "main.h"

/*
 * BLUETOOTH_STATETypeDef - Bluetooth operational state definition.
 *
 * This enumeration defines the various operational modes for the Bluetooth module
 * in the embedded system, used to manage behavior based on user interaction
 * or power-saving requirements.
 *
 * (1) WAIT_MODE:
 *     - Description: Low-power idle mode where the system remains in standby.
 *     - Behavior: No active user tasks are executed; Bluetooth may still broadcast presence.
 *     - Use Case: Activated when the device is not in use, helping conserve energy.
 *
 * (2) WORK_MODE:
 *     - Description: Normal operation mode where main features are active.
 *     - Behavior: The device performs user-defined actions, such as turning on LEDs,
 *                 activating a buzzer, or communicating with a paired host device.
 *     - Use Case: Entered after successful Bluetooth connection or user command.
 *
 * (3) FIND_MODE:
 *     - Description: Device-locating mode to assist the user in physically locating the hardware.
 *     - Behavior: Triggers visual and/or audible signals (e.g., blinking LEDs, buzzer alarm).
 *     - Use Case: Invoked remotely (e.g., via mobile app) to help users find a misplaced device.
 */
typedef enum {
	WAIT_MODE,
	WORK_MODE,
	FIND_MODE
} BLUETOOTH_STATETypeDef;



/*
 * BLUETOOTH_DEVICE_InfoTypeDef - Structure for storing Bluetooth device information.
 *
 * Fields:
 * - BT_Name:       Name of the Bluetooth device (up to 19 characters + null terminator).
 * - BT_password:   8-bit pairing password (numeric or code-based, depending on implementation).
 * - BT_distance:   Estimated distance or signal strength indicator (e.g., RSSI-based value).
 * - BT_state:      Current operational state of the device (see BLUETOOTH_STATETypeDef).
 */
typedef struct{
	char BT_Name[20];
	uint8_t BT_password;
	uint8_t BT_distance;
	BLUETOOTH_STATETypeDef BT_state;
}BLUETOOTH_DEVICE_InfoTypeDef;

/*
 * SWITCHMODE - Handles switching between different Bluetooth operation modes.
 *
 * @param state: The target Bluetooth state to switch to.
 *                (WAIT_MODE, WORK_MODE, or FIND_MODE as defined in BLUETOOTH_STATETypeDef)
 *
 * This function is responsible for updating the system behavior according to
 * the specified Bluetooth mode. It may control peripheral actions such as
 * enabling/disabling LEDs, buzzers, or entering low-power state.
 */
void SwitchMode(BLUETOOTH_STATETypeDef state);

void Send_RSSI();






#endif /* INC_BLUETOOTH_H_ */

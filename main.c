/**
* @main.c
* @brief 
*
*This program is used to get serial data from a serial device and displays over terminal
*
*
* 
* @note
*
* Revision History:
* - 101121  DAM : Creation Date
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 
#include "serial_monitor.h"

/*******************************************
* Const and Macro Defines
*******************************************/

#define ARGC_REQUIRED 2

/***********************************
* Typedefs and Enum Declarations
***********************************/

// none

/***********************************
* External Variable Declarations
***********************************/

// none

/***********************************
* Const Declarations
***********************************/

// none

/***********************************
* Public Variables
********************/

// none

/***********************************
* Private Variables
***********************************/

// none

/***********************************
* Private Prototypes
***********************************/

// none

/***********************************
* Public Functions
***********************************/

int main(int argc, char *argv[])
{
	char *serial_device;
	int serial_port_return;
	if(argc==ARGC_REQUIRED){
		printf("\nSearch Initialized for ");	
		serial_device = argv[1];
		printf("%s",serial_device);
		serial_open(serial_device);
		printf("\nConfiguration Successfully Completed");
		//serial_monitor(serial_port_return);
	}
	return 0;
}

















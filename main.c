/**
* @main.c
* @brief 
*
*This program is used to get customer details froom user and displays it
*
*
* 
* @note
*
* Revision History:
* - 240921  DAM : Creation Date
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
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
	if(argc==ARGC_REQUIRED){
		printf("\nSearch Initialized for ");	
		serial_device = argv[1];
		printf("%s",serial_device);
		serial_open(serial_device);
	}
	return 0;
}

















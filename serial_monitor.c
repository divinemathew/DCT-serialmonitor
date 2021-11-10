
/**
* @serial_monitor.c
* @brief 
*
*This program deals with all function related to serial device
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
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 
#include "serial_monitor.h"
/*******************************************
* Const and Macro Defines
*******************************************/

#define CLEAR "\e[1;1H\e[2J"

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


int serial_open(char *serial_device)
{
	int status = open(serial_device, O_RDWR);
	if(status<0 && status!=(-1)){
		printf("\nError Opening Serial Device: %s",serial_device);
	} else if(status==(-1)){
		printf("\nPermission Denied");
		printf("\nError Code : %i, | %s",status,strerror(status));
	} else{
		printf("\nConnection Established with %s",serial_device);
		serial_monitor_setup(serial_device,status);
	}
	return 0;
}



void serial_monitor_setup(char *serial_device,int port)
{
	struct termios configuration;
	if(tcgetattr(port, &configuration) != 0) {
    printf("\nError %i from tcgetattr: %s\n", errno, strerror(errno));		
	}
	
	configuration.c_cflag &= ~(PARENB);
	configuration.c_cflag &= ~(CSTOPB);
	configuration.c_cflag &= ~(CSIZE);
	configuration.c_cflag |= CS8;
	configuration.c_cflag &= ~CRTSCTS;
	
}





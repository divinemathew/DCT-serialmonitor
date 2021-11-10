
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


void serial_open(char *serial_device)
{	
	int status = open(serial_device, O_RDWR);
	int port;
	if(status<0 && status!=(-1)){
		printf("\nError Opening Serial Device: %s",serial_device);
	} else if(status==(-1)){
		printf("\nPermission Denied");
		printf("\nError Code : %i, | %s",status,strerror(status));
	} else{
		printf("\nConnection Established with %s",serial_device);
		serial_monitor_setup(serial_device,status);
	}
	serial_monitor_setup(serial_device,status);
}



int serial_monitor_setup(char *serial_device,int port)
{
	struct termios configuration;
	struct termios terminal_configuration;

	if(tcgetattr(port, &configuration) != 0) {
    	printf("\nError %i from tcgetattr: %s\n", errno, strerror(errno));		
		return 0;
	}
	
	/* Configuration of Serial Port  Parity Bit,Stop bit, Bit Size --> 8,
 * Disable CTS,RTS*/
	
	configuration.c_cflag &= ~(PARENB); //parity
	configuration.c_cflag &= ~(CSTOPB);	//stop bit
	configuration.c_cflag &= ~(CSIZE);	//size of bit
	configuration.c_cflag |= CS8;		// 8 bit data frame
	configuration.c_cflag &= ~(CRTSCTS);
	configuration.c_cflag |= CREAD | CLOCAL; 
	
	/* Local Modes Flag Configuration --> Non Canonical Form Activated*/
	configuration.c_lflag &= ~ICANON;
	configuration.c_lflag &= ~ECHO; 
	configuration.c_lflag &= ~ECHOE;
	configuration.c_lflag |= ECHONL;
	
	/* Input Control Flag Configuration */
	configuration.c_iflag &= ~(IXON | IXOFF | IXANY); 	
	configuration.c_iflag &= ~(IXON);
 	configuration.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
	
	/* Output Control Flag Configuration */
	configuration.c_oflag &= ~OPOST;
	configuration.c_oflag &= ~ONLCR;

	configuration.c_cc[VTIME] = 1;
	configuration.c_cc[VMIN] = 0;
	
	cfsetspeed(&configuration, B115200);
	
	if(tcsetattr(port,0, &configuration) != 0) {
    	printf("\nError %i from tcsetattr: %s\n", errno, strerror(errno));		
		return 0;
	}



/*  
	if(tcgetattr(STDIN_FILENO, &terminal_configuration) != 0) {
    	printf("\nError %i from tcgetattr: %s\n", errno, strerror(errno));		
		return 0;
	}
	
	terminal_configuration.c_lflag &= ~ICANON;
	terminal_configuration.c_cc[VTIME] = 1;
	terminal_configuration.c_cc[VMIN] = 0;
	terminal_configuration.c_cc


	if(tcsetattr(STDIN_FILENO,0, &terminal_configuration) != 0) {
    	printf("\nError %i from tcsetattr: %s\n", errno, strerror(errno));		
		return 0;
	}*/

	serial_monitor(port);
	return port;
}



void serial_monitor(int port)
{ 	char received_data;
 	char transmit_data;

	printf("\nReading Serial Device\n");	
	while(1){
		 /*  if(read(port,&received_data,sizeof(received_data))!=0){
			printf("%c",received_data);
			while(read(port,received_data,sizeof(received_data))!=0){
				read(port,&received_data,sizeof(received_data));
				printf("%c",received_data);
			}
		
		}*/
		/*  
		transmit_data = getchar();
		write(port,transmit_data,sizeof(transmit_data));*/

		/*  while(read(port,&received_data,sizeof(received_data))){	
			printf("%c",received_data);
		}*/
		

				
		 while(read(port,&received_data,sizeof(received_data))){	
			printf("%c",received_data);
		}
		//read(port,&received_data,sizeof(received_data));
		//printf("%c",received_data);	
		//transmit_data = getchar();
		read(0,&transmit_data,sizeof(transmit_data));
		write(port,&transmit_data,sizeof(transmit_data));
	}
}

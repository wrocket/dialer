#include <stdio.h>
#include <stdlib.h>

#include "dialer.h"
#include "connect.h"
//#include "disconnect.h"

#define NUMBER_TO_DIAL "16123445525"

int main(int argc, char ** argv){
	if(argc != 2){
		printf("Usage: %s [-connect or -disconnect]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if(strncmp(argv[1], "-connect", strlen(argv[1])) == 0){
		printf("Dialing %s...\n", NUMBER_TO_DIAL);
		if(dialer_connect(NUMBER_TO_DIAL) != 0){
			printf("Error on connection.\n");
			exit(EXIT_FAILURE);
		}
		else{
			printf("Connected!\n");
		}
	}
	else if(strncmp(argv[1], "-disconnect", strlen(argv[1])) == 0){
		if(dialer_disconnect(NUMBER_TO_DIAL) != 0){
			printf("Error on disconnection.\n");
			exit(EXIT_FAILURE);
		}
		else{
			printf("Disconnected.\n");
		}
	}
	else{
		printf("Unknown operation: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}

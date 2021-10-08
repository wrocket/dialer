#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>

#include "senddata.h"

int dialer_connect(char * numberToDial){

	char * request;
	int retVal;
	
	if(strlen(numberToDial) > 11){
		perror("Error: Invalid number %s\n");
		return -1;
	}

	request = malloc(8192);

	if(request == NULL){
		perror("Memory error (how?)\n");
		return -1;
	}

	request[0] = '\0';
	strcat(request, "GET /cgi-bin/testcgi?AcTiOnNeXt=\%2Fhtdocs\%2Fstatus.html&CoNnEcTNoW=connect&sta_version=2.0.0.0.19n-R7000M&MoDeMStAtUs=Disconnected&DiScReAsOn=None&sta_type=PPP&CoNnEcTtSpEeD=&WaNmAsK=255.255.255.0&CuRrEnTnUmBeR="); 
	strncat(request, numberToDial, strlen(numberToDial));
	strcat(request, "&LaNiP=192.168.0.1&DhCpSeRvEr=on HTTP/1.1\r\n");
	strcat(request, "Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, */*\r\n");
	strcat(request, "Referer: http://192.168.0.1/cgi-bin/testcgi?AcTiOnNeXt=/htdocs/status.html\r\n");
	strcat(request, "Accept-Language: en-us\r\n");
	strcat(request, "UA-CPU: x86\r\n");
	strcat(request, "User-Agent: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0)\r\n");
	strcat(request, "Host: 192.168.0.1\r\n");
	strcat(request, "Connection: Keep-Alive\r\n\r\n");

	retVal = senddata(request);
	
	free(request);
	return retVal;
}

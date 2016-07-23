#include <stdio.h>		/* Standard input/output definitions */
#include <string.h>		/* String function definitions */
#include <unistd.h>		/* UNIX standard function definitions */
#include <fcntl.h>		/* File control definitions */
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

int main(void){
	float temperature;
	char buffer[10];
	int fd = open("/dev/serial/by-id/usb-STMicroelectronics_STM32_Virtual_ComPort_00000000001A-if00", O_RDWR | O_NOCTTY);

	while (1) {
		memset(buffer, ' ', sizeof(buffer));
		write(fd, "", 1);
		read(fd, buffer, sizeof(buffer));
		temperature = atof(buffer);
		printf("%lu, %d, %f\n", (unsigned long)time(NULL),  1, temperature);

		sleep(600);
	}
	return close(fd);
}

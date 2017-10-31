#include <stdio.h>	/* Standard input/output definitions */
#include <string.h>	/* String function definitions */
#include <unistd.h>	/* UNIX standard function definitions */
#include <fcntl.h>	/* File control definitions */
#include <errno.h>	/* Error number definitions */
#include <termios.h>	/* POSIX terminal control definitions */

#define DEVNAME "/dev/ttyUSB0"

int main(void)
{
	int fd;	/* File descriptor for the port */
    struct termios options;

    /* 以非阻塞方式打开串口 */
    fd = open(DEVNAME, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd < 0) {
        printf("Open the serial port error!\n");
        return -1;
    }

    fcntl(fd, F_SETFL, 0);

    tcgetattr(fd, &options);

    /*
     * Set the baud rates to 9600
     */
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);

    /*
     * Enable the receiver and set local mode
     */
    options.c_cflag |= (CLOCAL | CREAD);

    /*
     * Select 8 data bits, 1 stop bit and no parity bit
     */
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;

    /*
     * Disable hardware flow control
     */
    options.c_cflag &= ~CRTSCTS;

    /*
     * Choosing raw input
     */
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    /*
     * Disable software flow control
     */
    options.c_iflag &= ~(IXON | IXOFF | IXANY);

    /*
     * Choosing raw output
     */
    options.c_oflag &= ~OPOST;


    /*
     * Set read timeouts
     */
    options.c_cc[VMIN] = 8;
    options.c_cc[VTIME] = 10;
    //options.c_cc[VMIN] = 0;
    //options.c_cc[VTIME] = 0;

    tcsetattr(fd, TCSANOW, &options);



	//close(fd);

	//fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);

	if (fd == -1)
	{
		/*
		 * Could not open the port.
		 */

		perror("open_port: Unable to open /dev/ttyUSB0 - ");
	}
	else
		fcntl(fd, F_SETFL, 0);

		int n;
        n = write(fd, "ATZ\r", 4);
        if (n < 0)
        	fputs("write() fo 4 bytes failed!\n", stderr);
        	printf("hello world");

    close(fd);
	return (fd);
}

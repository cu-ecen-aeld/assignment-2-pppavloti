#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>

#define MIN_NUM_OF_ARGUMENTS 3

int main(int argc, char * argv[])
{
    // Open syslog
    openlog(argv[0], LOG_PID, LOG_USER);
    syslog(LOG_ERR, "Writing %s to file %s", argv[2], argv[1]);

    // check if number of input arguments is sufficient
    if(argc < MIN_NUM_OF_ARGUMENTS)
    {
        // Unsuficient number of input parameters
        printf("\nUnsufficient number of input parameters: \n");        
        closelog();
        exit(1);
    }

    // open file handle for read and write
    FILE * handle = fopen(argv[1], "r+");
    // check if file successfully opened
    if(handle == NULL)
    {
        perror("Not able to open file");        
        closelog();
        exit(1);
    }

    // find the end of the file
    fseek(handle, 0, SEEK_END);

    // write data to the file
    fwrite(argv[2], sizeof(char), strlen(argv[2]), handle);
    fwrite("\r\n", sizeof(char), 2, handle);
    
    // exit application 
    closelog();
    exit(0);
}

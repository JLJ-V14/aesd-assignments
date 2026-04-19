#include <fcntl.h>    // open()
#include <unistd.h>   // write(), close()
#include <syslog.h>   // openlog(), syslog(), closelog()
#include <string.h>   // strlen()

int main(int argc, char *argv[]){
    
    openlog("writer",LOG_PID,LOG_USER);

    if(argc < 3){

        
        syslog(LOG_ERR,"Number of arguments insufficient");
        
        closelog();
        return 1;
        
    }

    int fd = open(argv[1],O_WRONLY | O_CREAT | O_TRUNC,0644);

    if(fd == -1){
        syslog(LOG_ERR,"File could not be opened");       
        closelog();
        return 1;   
    }

    if(write(fd,argv[2],strlen(argv[2])) == -1){
        syslog(LOG_ERR,"File could not be written");       
        closelog();
        return 1;
    }

    syslog(LOG_DEBUG," Writing %s in %s",argv[2],argv[1]);
    close(fd);
    closelog();

    return 0;
}
#include<stdio.h>

#include<sys/types.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    pid=vfork();
    if(pid==-1)
    {
        perror("vfork");
        return 1;
    }else if(pid==0)
    {
        printf("child process:hello,I,m child\n");
        printf("child process:my pid is %d\n",getpid());
        printf("child process:my parent pid is %d\n",getppid());
        _exit(0);

    }
    else{
        printf("parent process:hello,I,m parent \n");
        printf("parent process:my pid is %d\n",getpid());
        printf("parent process:my child  pid is %d\n",pid);

        int status;
        waitpid(pid,&status,0);
        if(WIFEXITED(status)){
            printf("PARENT PROCESS:child process is terminated normally.\n");

        }else{
            printf("parent process:child process terminated abnormally.\n");
        }
    }

    
}
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    printf("PID текущего процесса is: %d\nPID родительского процесса: %d\n", getpid(), getppid());
    return 0; 
}

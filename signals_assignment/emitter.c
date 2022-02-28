#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc == 3)
  {
    if ((strcmp(argv[2], "SIGUSR1") == 0) || (strcmp(argv[2], "SIGUSR2") == 0))
    {
      // getting pid
      int pid = atoi(argv[1]);
      int sig;
      // trying to define signal number, int
      if ((strcmp(argv[2], "SIGUSR1") == 0))
      {
        sig = 10;
      }
      else
      {
        sig = 12;
      }
      // send signal
      kill(pid, sig);
      printf("Signal sended.\n");
    }
    // raise error
    else
    {
      printf("Argumets error.\n");
    }
  }
  else if (argc > 3)
  {
    printf("Too many arguments supplied.\n");
  }
  else
  {
    printf("Argumets error.\n");
  }
}

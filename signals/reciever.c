// Бесконечно выводит заранее заданную строку на экран и ожидает сигналов SIGUSR1 и SIGUSR2. 
// При получении каждого из сигналов она меняет выводимую строку.
// Для запуска программы необходимо ввести в консоль ./reciever, если что-то пошло не так попробовать заново скомпилировать командой gcc reciever.c -o reciever и повторить первую инструкцию

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

char str[40] = "Wait for signal...\n"; 

// обраотчик сигналов
void signalHandler(int signalCode)
{
  switch (signalCode)
  {
  case SIGUSR1:
    printf("SIGUSR1 Recieved\n");
    strcpy(str, "Last received signal is: SIGUSR1\n"); // redefinition of start string
    break;
  case SIGUSR2:
    printf("SIGUSR2 Recieved\n");
    strcpy(str, "Last received signal is: SIGUSR2\n"); // redefinition of start string
    break;
  }
}

int main()
{
  // registration of signals
  signal(SIGUSR1, signalHandler);
  signal(SIGUSR2, signalHandler);
  printf("[ PID: %d ]: Started...\n", getpid());
  while (1)
  {
    printf("%s", str);
    sleep(2);
  }
  return 0;
}

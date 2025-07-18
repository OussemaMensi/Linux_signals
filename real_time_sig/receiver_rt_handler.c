#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int num_sig, siginfo_t *info, void *context) {
    printf("Signal %d reçu\n", num_sig);
    printf("  PID émetteur : %d\n", info->si_pid);
    printf("  Code source  : %d\n", info->si_code);
    printf("  sival_int    : %d\n", info->si_value.sival_int);
    // tu peux aussi utiliser info->si_value.sival_ptr
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);

    // Remplace signal() par sigaction()
    if (sigaction(SIGRTMIN, &sa, NULL) == -1) {
        perror("sigaction");
        return EXIT_FAILURE;
    }

    printf("Récepteur prêt. PID = %d\n", getpid());
    while (1) pause();
}

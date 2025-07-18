#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <PID> <SIGNAL_NUMBER>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pid_t pid = atoi(argv[1]);
    int sig = atoi(argv[2]);

    if (kill(pid, sig) == -1) {
        perror("Erreur lors de l'envoi du signal");
        return EXIT_FAILURE;
    }

    printf("Signal %d envoyé avec succès au processus %d.\n", sig, pid);
    return EXIT_SUCCESS;
}

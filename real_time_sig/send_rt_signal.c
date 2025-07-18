#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pid_t pid = atoi(argv[1]);  // PID du destinataire
    union sigval data;
    data.sival_int = 42;        // Valeur à envoyer

    if (sigqueue(pid, SIGRTMIN, data) == -1) {
        perror("sigqueue échoué");
        return EXIT_FAILURE;
    }
    printf("L'emetteur possède le pid %d \n",getpid());
    printf("Signal SIGRTMIN envoyé à %d avec valeur %d\n", pid, data.sival_int);
    return EXIT_SUCCESS;
}

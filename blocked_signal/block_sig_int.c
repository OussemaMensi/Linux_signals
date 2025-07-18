#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Handler du signal SIGINT (Ctrl+C)
void handle_sigint(int sig) {
    printf("\n[Handler] Reçu SIGINT (signal %d). Fin du programme.\n", sig);
    exit(0);
}

int main() {
    // 1. Définir un handler personnalisé pour SIGINT
    signal(SIGINT, handle_sigint);

    // 2. Créer un masque pour bloquer SIGINT
    sigset_t block_set;
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);
    sigprocmask(SIG_BLOCK, &block_set, NULL);
    // 3. Attente pour observer le traitement du signal
    while (1) {
        printf("Le programme tourne... (SIGINT maintenant ne le stoppera pas )\n");
        sleep(3);
    }

    return 0;
}


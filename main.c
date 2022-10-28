#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#include <monkey/mk_lib.h>

// very epic global state
int program_exit = 0;

void handle_sigint(int signum) {
    program_exit = 1;
}

int main() {
    mk_ctx_t* srv = mk_create();
    mk_config_set(
        srv,
        "Listen", "127.0.0.1:42069",
        "Workers", "1",
        NULL
    );
    int start = mk_start(srv);
    if (start == -1) {
        mk_destroy(srv);
        return 1;
    }

    printf("starting the server\n");
     
    // Wait for sigint and sigterm to cleanly exit
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
    while (!program_exit) {}

    // Or if I'm running in a debugger and don't wanna 
    // mess with sending a signal
    // sleep(1);

    printf("we're outta here\n");
    mk_stop(srv);

    // no leaks allowed
    printf("we're cleaning up\n");
    mk_destroy(srv);

    return 0;
}
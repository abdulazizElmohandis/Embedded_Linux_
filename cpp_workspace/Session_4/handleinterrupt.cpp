#include <iostream>
#include <csignal>
#include <unistd.h>
// Function to handle the signal
void signalHandler(int signum) {
    std::cout << "\nInterrupt signal (" << signum << ") received.\n";


    // Terminate the program
    exit(signum);
}

int main() {

    if (signal(SIGINT, signalHandler) == SIG_ERR) {
        std::cerr << "Error setting up signal handler.\n";
        return 1;
    }
    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, signalHandler);

    std::cout << "Press Ctrl+C to trigger the signal handler...\n";

        while (1) {
            std::cout << "n";
            std::cout.flush(); 

        sleep(1);   
        }
        return 0;
}

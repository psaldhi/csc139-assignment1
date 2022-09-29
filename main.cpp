// Main source file
/* Authors:
    James Armstrong,
    Minh-Hieu Le,
    Ethan Lee
    Julian Hernandez,
    Devesh Naidu,
    Pratham Saldhi
*/

#include <iostream>
#include <string>
#include <pthread.h>

using namespace std;

// EXAMPLE THREAD FUNCTION, WILL BE CALLED BY pthread_create()
void *threadDummyFunc(void *arg)
{
    string *str = (string *)arg;
    std::cout << "dummy function\n";
    std::cout << "argument 1 passed: " << str[0] << endl;

    pthread_exit(0);
}

void *path(void *arg)
{
    std::cout << "Printing path env\n";
    system("echo \"$PATH\"");
    pthread_exit(0);
}

void *notepad(void *arg)
{
    std::cout << "Launching text editor\n";
    system("nano");
    pthread_exit(0);
}

int main()
{
    while (1)
    {
        string cmd;
        string *args = new string[4];

        cout << "Enter command: ";
        cin >> cmd;

        std::cout << "Enter 4 arguments. type something random to skip arguments if more isn't needed\n";

        cout << "Enter arg 1: ";
        cin >> args[0];

        cout << "Enter arg 2: ";
        cin >> args[1];

        cout << "Enter arg 3: ";
        cin >> args[2];

        cout << "Enter arg 4: ";
        cin >> args[3];

        pthread_t thread;
        int error;
        if (cmd == "dummy")
            error = pthread_create(&thread, NULL, &threadDummyFunc, args);
        // Print system enviroment PATH
        else if (cmd == "path")
                error = pthread_create(&thread, NULL, &path, NULL);
        // Launch a text editor
        else if (cmd == "notepad")
            error = pthread_create(&thread, NULL, &notepad, NULL);
        /*
                else if (cmd == "dir")
                    error = pthread_create(&thread, NULL, &dir, NULL);

                else if (cmd == "echo")
                    error = pthread_create(&thread, NULL, &echo, NULL);

                else if (cmd == "help")
                    error = pthread_create(&thread, NULL, &help, NULL);

                else if (cmd == "color")
                    error = pthread_create(&thread, NULL, &color, NULL);

                else if (cmd == "vol")
                    error = pthread_create(&thread, NULL, &vol, NULL);

                else if (cmd == "ping")
                    error = pthread_create(&thread, NULL, &ping, NULL);

                else if (cmd == "path")
                    error = pthread_create(&thread, NULL, &path, NULL);

                else if (cmd == "notepad")
                    error = pthread_create(&thread, NULL, &notepad, NULL);
        */
        //////////

        if (error)
            cout << "Failed to create thread\n";
        else
            cout << "Thread created\n";

        // Wait for thread to stop
        pthread_join(thread, NULL);
    }
    return 0;
}
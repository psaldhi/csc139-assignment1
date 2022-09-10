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

string args;
string parsedArgs[5];

// TO BE DONE BY TERMINATOR
// MODIFY parsedArgs[5]
void argumentParser(string args)
{
}
/////////////////////////////

// EXAMPLE THREAD FUNCTION, WILL BE CALLED BY pthread_create()
void *threadDummyFunc(void *arg)
{
    std::cout << "dummy function\n";
    std::cout << "argument passed: " << (string *)arg << endl;

    pthread_exit(0);
}

int main()
{
    while (1)
    {
        string cmd;

        cout << "Enter command: ";
        cin >> cmd;

        cout << "Enter arguments, spacing them out (arg1 arg2 arg3): ";
        cin >> args;

        argumentParser(args);

        pthread_t thread;
        int error;
        if (cmd == "dummy")
            error = pthread_create(&thread, NULL, &threadDummyFunc, NULL);

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
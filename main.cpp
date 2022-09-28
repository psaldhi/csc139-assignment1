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

// TO BE DONE BY TERMINATOR
// MODIFY parsedArgs[5]
// Return parsed string array
string *argumentParser(string args)
{
}
/////////////////////////////

// EXAMPLE THREAD FUNCTION, WILL BE CALLED BY pthread_create()
void *threadDummyFunc(void *arg)
{
    string *str = (string *)arg;
    std::cout << "dummy function\n";
    std::cout << "argument passed: " << str[0] << endl;

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
        string args;

        cout << "Enter command: ";
        cin >> cmd;

        cout << "Enter arguments, spacing them out (arg1 arg2 arg3): ";
        cin >> args;

        // Parse input to get the arguments as string array

        // THIS IS A TEST PARSEDARGS VAR UNTIL PARSE ARG FUNCTION IS COMPLETED
        /////////////////////////////////////////////////////
        string *parsedArgs = new string[5];
        parsedArgs[0] = "1";
        parsedArgs[1] = "2";
        /////////////////////////////////////////////////////
        // REPLACE ABOVE WITH THE COMMENTED CODE BELOW WHEN PARSE ARG FUNCTION IS COMPLETED
        // string *parsedArgs = argumentParser(args);

        pthread_t thread;
        int error;
        if (cmd == "dummy")
            error = pthread_create(&thread, NULL, &threadDummyFunc, (void *)parsedArgs);
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
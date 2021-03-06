#include <iostream>
#include <stdlib.h>
#include <string>

#include "clearScreen.h"
#include "play.h"

using namespace std;

void menu() {

    int option = 0;
    string playerName;

    while (option < 1 || option > 3) {
        cout << "Welcome to the naval battle game\n";

        cout << "\n1 - Play";
        cout << "\n2 - About";
        cout << "\n3 - Exit\n";
        cout << "\nChoice an option and press the key enter: ";

        cin >> option;

        clearScreen();

        switch (option) {

        case 1:
            cout << "The game started!\n";

            cout << "\nEnter your name: ";
            cin >> playerName;

            play(playerName);
            break;
        case 2:
            cout << "About the game\n";
            break;
        case 3:
            cout << "See ya!\n";
            break;
        }

    }

}

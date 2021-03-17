#include <iostream>

int main() {
    char names[100];
    char abbrev[50];
    short abbrevIndex = 0;
    bool lastWasLetter = false;

    std::cin >> names;

    for (int i = 0; i < 100; i++) {
        if (names[i] == '\0') break;

        if (names[i] == '-') {
            lastWasLetter = false;
            continue;
        }

        if (!lastWasLetter) {
            abbrev[abbrevIndex] = names[i];
            abbrevIndex++;
            lastWasLetter = true;
        }
    }

    abbrev[abbrevIndex] = '\0';
    
    std::cout << abbrev;
}

#include <iostream>

int main() {
    short hour, minute;

    std::cin >> hour >> minute;

    minute -= 45;

    if(minute < 0) {
        minute = 60 + minute;
        hour--;

        if(hour < 0) hour = 24 + hour;
    }

    std::cout << hour << " " << minute;
}

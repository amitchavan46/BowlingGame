// main.cpp
#include <iostream>
#include "header/bowling.h"
using namespace std;

int main() {
    BowlingGame game;
    int frame = 1;

    while (frame <= 10) {
        int firstRoll, secondRoll = 0;

        // First roll
        cout << "Frame " << frame << " - Roll 1: ";
        cin >> firstRoll;
        while (firstRoll < 0 || firstRoll > 10) {
            cout << "Invalid input. Enter 0–10: ";
            cin >> firstRoll;
        }
        game.roll(firstRoll);

        // If strike and not 10th frame, skip second roll
        if (frame < 10 && firstRoll == 10) {
            frame++;
            continue;
        }

        // Second roll
        cout << "Frame " << frame << " - Roll 2: ";
        cin >> secondRoll;
        while (secondRoll < 0 || secondRoll > 10 || (frame < 10 && firstRoll + secondRoll > 10)) {
            cout << "Invalid input. Total pins can't exceed 10. Enter again: ";
            cin >> secondRoll;
        }
        game.roll(secondRoll);

        // 10th frame extra roll if strike or spare
        if (frame == 10 && (firstRoll == 10 || firstRoll + secondRoll == 10)) {
            int thirdRoll;
            cout << "Frame 10 - Roll 3: ";
            cin >> thirdRoll;
            while (thirdRoll < 0 || thirdRoll > 10) {
                cout << "Invalid input. Enter 0–10: ";
                cin >> thirdRoll;
            }
            game.roll(thirdRoll);
        }

        frame++;
    }

    cout << "Final Score: " << game.score() << endl;
    return 0;
}
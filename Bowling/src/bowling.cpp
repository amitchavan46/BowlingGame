// bowling.cpp
#include "bowling.h"

void BowlingGame::roll(int pins) {
    rolls.push_back(pins);
}

int BowlingGame::score() {
    int totalScore = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < 10; ++frame) {
        if (isStrike(rollIndex)) {
            totalScore += 10 + strikeBonus(rollIndex);
            rollIndex += 1;
        } else if (isSpare(rollIndex)) {
            totalScore += 10 + spareBonus(rollIndex);
            rollIndex += 2;
        } else {
            totalScore += framePoints(rollIndex);
            rollIndex += 2;
        }
    }

    return totalScore;
}

bool BowlingGame::isStrike(int rollIndex) {
    return rolls[rollIndex] == 10;
}

bool BowlingGame::isSpare(int rollIndex) {
    return rolls[rollIndex] + rolls[rollIndex + 1] == 10;
}

int BowlingGame::strikeBonus(int rollIndex) {
    return rolls[rollIndex + 1] + rolls[rollIndex + 2];
}

int BowlingGame::spareBonus(int rollIndex) {
    return rolls[rollIndex + 2];
}

int BowlingGame::framePoints(int rollIndex) {
    return rolls[rollIndex] + rolls[rollIndex + 1];
}

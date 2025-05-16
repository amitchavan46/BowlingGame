// bowling_game.cpp
#include "bowling.h"

void BowlingGame::roll(int pins) {
    rolls.push_back(pins);
}

int BowlingGame::score() {
    int score = 0;
    int index = 0;

    for (int frame = 0; frame < 10; ++frame) {
        if (isStrike(index)) {
            score += 10 + strikeBonus(index);
            index += 1;
        } else if (isSpare(index)) {
            score += 10 + spareBonus(index);
            index += 2;
        } else {
            score += framePoints(index);
            index += 2;
        }
    }

    return score;
}

bool BowlingGame::isStrike(int index) {
    return rolls[index] == 10;
}

bool BowlingGame::isSpare(int index) {
    return rolls[index] + rolls[index + 1] == 10;
}

int BowlingGame::strikeBonus(int index) {
    return rolls[index + 1] + rolls[index + 2];
}

int BowlingGame::spareBonus(int index) {
    return rolls[index + 2];
}

int BowlingGame::framePoints(int index) {
    return rolls[index] + rolls[index + 1];
}

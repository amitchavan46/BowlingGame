// bowling_game.h
#ifndef BOWLING_H
#define BOWLING_H

#include <vector>

class BowlingGame {
public:
    void roll(int pins);
    int score();

private:
    std::vector<int> rolls;

    bool isStrike(int index);
    bool isSpare(int index);
    int strikeBonus(int index);
    int spareBonus(int index);
    int framePoints(int index);
};

#endif // BOWLING_H

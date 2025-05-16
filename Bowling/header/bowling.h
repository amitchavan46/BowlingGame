// bowling.h
#ifndef BOWLING_H
#define BOWLING_H

#include <vector>

class BowlingGame {
public:
    void roll(int pins);
    int score();

private:
    std::vector<int> rolls;

    bool isStrike(int rollIndex);
    bool isSpare(int rollIndex);
    int strikeBonus(int rollIndex);
    int spareBonus(int rollIndex);
    int framePoints(int rollIndex);
};

#endif // BOWLING_H

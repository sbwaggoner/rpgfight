#pragma once
#include <cstdlib>

class Dice
{
int sides;
public:
  Dice(int sides);
  ~Dice();

  int RollDice() {
    return rand() % sides + 1;
  }
};


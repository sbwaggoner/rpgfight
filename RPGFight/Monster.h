#pragma once
#include <string>

class Monster
{
  std::string getMonsterName() {
    return "dragon";
  }
public:
  int hp;
  int str;
  std::string mtype;
  Monster();
  ~Monster();

  void getDamage(int dmg) {
    hp -= dmg;
  }
};


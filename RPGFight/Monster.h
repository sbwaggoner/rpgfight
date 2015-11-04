#pragma once
#include <string>

class Monster
{
  std::string getMonsterName() {
    int tid = rand() % 3 + 1;
    switch (tid) {
      case 1:
        return "dragon";
        break;
      case 2:
        return "ogre";
        break;
      case 3:
        return "goblin";
        break;
    }
  }
public:
  int hp;
  int str;
  std::string mtype;
  Monster();
  ~Monster();

  void takeDamage(int dmg) {
    hp -= dmg;
  }

  void initMonster() {
    hp = rand() % 20 + 10;
    str = rand() % 10 + 1;
    mtype = getMonsterName();
  }
};


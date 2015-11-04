// RPGFight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Dice.h"
#include "Monster.h"

using namespace std;

Dice getDice(int sides) {
  auto dice = new Dice(sides);
  return *dice;
}

int rollDice(Dice dice) {
  auto result = dice.RollDice();
  cout << "You rolled " << result << ".\n\n";

  return result;
}

bool rollAgain() {
  cout << "Roll again? (N to stop)";

  string input;
  getline(cin, input);

  return input != "N";
}

Monster getMonster() {
  auto monster = new Monster();
  cout << "You see a " << monster->mtype << ".\n";
  cout << "HP: " << monster->hp << "\n";
  cout << "STR: " << monster->str << "\n";
  
  return *monster;
}

int main(int argc, char argv[])
{
  Dice dice = getDice(6);
  Monster monster = getMonster();
  do {
    int dmg = rollDice(dice);
    monster.getDamage(dmg);
    if (monster.hp > 0) {
      cout << "The " << monster.mtype << " sustained " << dmg << " damage and has " << monster.hp << " HP remaining.\n\n";
    }
    else {
      cout << "You've defeated the " << monster.mtype << ".\n\n";
    }
  } while (rollAgain());
  
	return 0;
}


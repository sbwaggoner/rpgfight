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

bool getYN(string message, string endval) {
  cout << message;

  string input;
  getline(cin, input);

  return input != endval;
}

bool rollAgain() {
  return getYN("Enter to roll again; N to quit.", "N");
}

bool fightAgain() {
  return getYN("Enter to fight again; N to quit.", "N");
}

Monster getMonster() {
  Monster *monster = new Monster();
  cout << "You see a " << monster->mtype << ".\n";
  cout << "HP: " << monster->hp << "\n";
  cout << "STR: " << monster->str << "\n";
  
  return *monster;
}

void doBattle(Dice dice, Monster monster) {
  do {
    int dmg = rollDice(dice);
    monster.getDamage(dmg);
    if (monster.hp > 0) {
      cout << "The " << monster.mtype << " sustained " << dmg << " damage and has " << monster.hp << " HP remaining.\n\n";
    }
    else {
      cout << "You've defeated the " << monster.mtype << ".\n\n";
      return;
    }
  } while (rollAgain() && monster.hp > 0);
}

int main(int argc, char argv[])
{
  do {
    doBattle(getDice(6), getMonster());
  } while (fightAgain());
  

	return 0;
}


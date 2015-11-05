// RPGFight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Dice.h"
#include "Monster.h"
#include "Player.h"
#include "utilityfunc.h"

using namespace std;
using namespace ufunc;

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

void updateHUD(Monster monster, int dmg) {
  if (monster.hp > 0) {
    string msg = wrapText("The " + monster.mtype + " sustained " + to_string(dmg) + " damage and has " + to_string(monster.hp) + " HP remaining.");
    cout << msg;
  }
  else {
    string msg = wrapText("You've defeated the " + monster.mtype);
    cout << msg;
    return;
  }
}

void doBattle(Dice dice, Monster monster, Player *player) {
  do {
    system("cls");
    int dmg = rollDice(dice);
    monster.takeDamage(dmg);
    updateHUD(monster, dmg);
  } while (rollAgain() && monster.hp > 0);
}

int main(int argc, char argv[])
{
  auto *player = new Player();
  do {
    doBattle(getDice(6), getMonster(), player);
  } while (fightAgain());

	return 0;
}


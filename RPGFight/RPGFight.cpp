// RPGFight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Dice.h"
#include "Monster.h"

using namespace std;

void rollDice() {
  auto *dice = new Dice(6);
  auto result = dice->RollDice();

  cout << "You rolled " << result << ".\n\n";
}

bool rollAgain() {
  cout << "Roll again? (N to stop)";

  string input;
  getline(cin, input);

  return input != "N";
}

void getMonster() {
  auto *monster = new Monster();
  cout << "You see a " << monster->mtype << ".\n";
  cout << "HP: " << monster->hp << "\n";
  cout << "STR: " << monster->str << "\n";
  delete monster;
}

int main(int argc, char argv[])
{
  do {
    getMonster();
    rollDice();
  } while (rollAgain());
  
	return 0;
}


#include "stdafx.h"
#include "Monster.h"
#include <cstdlib>


Monster::Monster()
{
  hp = rand() % 20 + 10;
  str = rand() % 10 + 1;
  mtype = getMonsterName();
}


Monster::~Monster()
{
}

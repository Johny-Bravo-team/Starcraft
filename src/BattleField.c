#include <string.h>
#include <stdio.h>
#include "BattleField.h"
#include "Vector.h"
#include "Ships.h"
/*
Battlefield -> terranFleet -> &items[i] = Terran_ship;
Battlefield -> protossFleet -> &items[i] = Protoss_ship;
*/


void generateTerranFleet(BattleField *battleField, const char *terranFleetStr)
{
  Vector *Terran = (Vector*) malloc (sizeof(Vector));
  vectorInit(Terran, 1);
  for (int i = 0; i < strlen(terranFleetStr); i++)
  {
    if (terranFleetStr[i] == 'v')
    {
      vectorPush(Terran, &Viking);
    }
    if (terranFleetStr[i] == 'b')
    {
      vectorPush(Terran, &BattleCruiser);
    }
  }
  printf("%lu", vectorGetSize(Terran));
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr)
{

  Vector *protoss = malloc(sizeof(Vector));

  for (int i = 0; i < strlen(protossFleetStr); i++)
  {
    if (protossFleetStr[i] == 'p')

      vectorPush(protoss, &Phoenix);

    if (protossFleetStr[i] == 'c')
    {
      vectorPush(protoss, &Carrier);
    }
  }

  printf("%lu", vectorGetSize(protoss));
}

/*void startBattle(BattleField *battleField)
{
  while (true)
  {
    if (processTerranTurn(battleField))
    {
      printf("TERRAN has won!\n");
      break;
    }

    if (processProtossTurn(battleField))
    {
      printf("PROTOSS has won!\n");
      break;
    }
  }
}*/

/*void deinit(BattleField *battleField)
{
}

bool processTerranTurn(BattleField *battleField)
{
  return false;
}

bool processProtossTurn(BattleField *battleField)
{
  return false;
}*/

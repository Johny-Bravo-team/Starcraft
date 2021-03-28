#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "BattleField.h"
#include "Vector.h"
#include "Ships.h"
#include "GameTurn.h"

void generateTerranFleet(BattleField *battleField, const char *terranFleetStr, int initialCapacity){
  vectorInit(&battleField->terranFleet, initialCapacity);
  for (size_t i = 0; i < strlen(terranFleetStr); i++){
    vectorPush(&battleField->terranFleet, ShipInitTerran(terranFleetStr[i]));
  }
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr, int initialCapacity){
  vectorInit(&battleField->protossFleet, initialCapacity);
  for (size_t i = 0; i < strlen(protossFleetStr); i++){
    vectorPush(&battleField->protossFleet, ShipInitProtoss(protossFleetStr[i]));
  }
}

void startBattle(BattleField *battleField){
  int TurnCounter = 1;
  while (true){
    TakeTurn(&battleField->terranFleet, &battleField->protossFleet, TurnCounter);
    if (vectorIsEmpty(&battleField->protossFleet)){
      printf("TERRAN has won!\n");
      break;
    }
    Ship *Protoss = vectorBack(&battleField->protossFleet);
    printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", vectorGetSize(&battleField->protossFleet) - 1, Protoss->health, Protoss->shield);

    TakeTurn(&battleField->protossFleet, &battleField->terranFleet, TurnCounter);
    if (vectorIsEmpty(&battleField->terranFleet)){
      printf("PROTOSS has won!\n");
      break;
    }
    Ship *Terran = vectorBack(&battleField->terranFleet);
    printf("Last Terran AirShip with ID: %d has %d health left\n", vectorGetSize(&battleField->terranFleet) - 1, Terran->health);

    TurnCounter++;
  }
}

void deinit(BattleField *battleField){
  while(vectorBack(&battleField->terranFleet)!=NULL){
    free(vectorBack(&battleField->terranFleet));
    vectorPop(&battleField->terranFleet);
  }

  while(vectorBack(&battleField->protossFleet)!=NULL){
    free(vectorBack(&battleField->protossFleet));
    vectorPop(&battleField->protossFleet);
  }

  vectorFree(&battleField->protossFleet);
  vectorFree(&battleField->terranFleet);
}

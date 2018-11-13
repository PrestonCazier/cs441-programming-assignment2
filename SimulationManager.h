#include <string>
#include "KnapsackObject.h"

using namespace std;

#ifndef SIMULATIONMANAGER_08142018
#define SIMULATIONMANAGER_08142018

class SimulationManager
{
  private:
    KnapsackObject *objList;
    string *popList;
    static int PopulationSize;

  public:
    SimulationManager();
    ~SimulationManager();
    int FitnessFunction(string);
    void PairUp();
    string Mutate(string old);
    string Run();
    void Print(string knapsack);
};
#endif SIMULATIONMANAGER_08142018
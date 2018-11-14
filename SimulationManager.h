#include <string>
#include <tuple>
#include "KnapsackObject.h"

using namespace std;

#ifndef SIMULATIONMANAGER_08142018
#define SIMULATIONMANAGER_08142018

struct Individual
{
  string genome;
  int fitness;
};

class SimulationManager
{
  private:
    KnapsackObject *objList;
    Individual *popList;
    int PopulationSize = 100;
    int maxWeight = 100;
    int NumIterations = 1000;
    float MutationPct = .01f;

  public:
    SimulationManager();
    SimulationManager(int weight, int size, int numiter, float mpct);
    ~SimulationManager();
    Individual Generate();
    int FitnessFunction(string genome);
    void Run();
    void Overwrite(string newStr);
    tuple<string, string> Crossover();
    string KTournamentSelect();
    string Mutate(string old);
    void Print(Individual i);
    string ListObjects(Individual i);
    int Weigh(Individual i);
};
#endif SIMULATIONMANAGER_08142018
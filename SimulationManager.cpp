#include <iostream>
#include <string>
#include <time.h>
#include <tuple>
#include "SimulationManager.h"

using namespace std;

SimulationManager::SimulationManager()
{
    srand(time(NULL));

    objList = new KnapsackObject[4];
    objList[0].SetObject("A", 45, 3);
    objList[1].SetObject("B", 40, 5);
    objList[2].SetObject("C", 50, 8);
    objList[3].SetObject("D", 90, 10);

    popList = new Individual[PopulationSize];

    for (int i = 0; i < PopulationSize; i++)
    {
        popList[i] = Generate();
    }
}

SimulationManager::SimulationManager(int weight, int size, int numiter, float mpct)
{
    PopulationSize = size;
    maxWeight = weight;
    NumIterations = numiter;
    MutationPct = mpct;

    srand(time(NULL));

    objList = new KnapsackObject[4];
    objList[0].SetObject("A", 45, 3);
    objList[1].SetObject("B", 40, 5);
    objList[2].SetObject("C", 50, 8);
    objList[3].SetObject("D", 90, 10);

    popList = new Individual[PopulationSize];

    for (int i = 0; i < PopulationSize; i++)
    {
        popList[i] = Generate();
    }
}

SimulationManager::~SimulationManager()
{
    delete[] objList;
    delete[] popList;
}

Individual SimulationManager::Generate()
{
    Individual ret;
    char genomes[5] = "0000";
    for (int i = 0; i < 4; i++)
    {
		int random = rand() % 2;
        if (random == 1)
        {
            genomes[i] = '1';
        }
    }
    ret.genome = genomes;
    ret.fitness = FitnessFunction(ret.genome);
    return ret;
}

int SimulationManager::FitnessFunction(string genome)
{
    int value = 0;
    int weight = 0;

    for(int i = 0; i < genome.length(); i++)
    {
        if(genome.at(i) == '1')
        {
            value += objList[i].GetValue();
            weight += objList[i].GetWeight();
        }
    }

    return (weight > maxWeight) ? 0 : value;
}

void SimulationManager::Run()
{
    for (int i = 0; i < NumIterations; i++)
    {
        tuple<string, string> children = Crossover();
        Overwrite(Mutate(get<0>(children)));
        Overwrite(Mutate(get<1>(children)));
    }

    // return best fitness
    int fitness = 0;
    int best = 0;
    for (int i = 0; i < PopulationSize; i++)
    {
        if (popList[i].fitness > fitness)
        {
            fitness = popList[i].fitness;
            best = i;
        }
    }
    Print(popList[best]);
}

tuple<string, string> SimulationManager::Crossover()
{
    string parent1 = KTournamentSelect();
    string parent2 = KTournamentSelect();
    string temp = parent1;
    int split = rand() % 3 + 1;

    parent1 = parent1.substr(0, split) + parent2.substr(split);
    parent2 = parent2.substr(0, split) + temp.substr(split);

    return make_tuple(parent1, parent2);
}

string SimulationManager::KTournamentSelect()
{
	int pct = 3;
    int* winners = new int[pct];
    int* list = new int[pct];
    int best = 0;
    int fitness = 0;

    for (int i = 0; i < pct; i++)
    {
        list[i] = rand() % PopulationSize;
        winners[i] = popList[list[i]].fitness;
    }

    for (int i = 0; i < pct; i++)
    {
        if(winners[i] > fitness)
        {
            best = i;
            fitness = winners[i];
        }
    }

    delete[] winners;
    delete[] list;
    return popList[best].genome;
}

string SimulationManager::Mutate(string old)
{
    int roll = (rand() % 100);
	int length = old.length();
    int spot = rand() % length;
    if (roll >= MutationPct)
    {
        return old;
    }
    old[spot] = (old[spot] == '1') ? '0': '1';
    return old;
}

void SimulationManager::Overwrite(string newStr)
{
	// find lowest and overwrite
	int fitness = 100000;
	int worst = 0;
	for (int i = 0; i < PopulationSize; i++)
	{
		if (popList[i].fitness < fitness)
		{
			worst = i;
			fitness = popList[i].fitness;
		}
	}
	popList[worst].genome = newStr;
	popList[worst].fitness = FitnessFunction(newStr);
}

void SimulationManager::Print(Individual i)
{
    cout << "The knapsack contains objects " << ListObjects(i) << endl;
    cout << "The knapsack has a weight of " << Weigh(i) << " and a value of " << i.fitness << endl;
	cout << "The final genome was " << i.genome << endl;
}

string SimulationManager::ListObjects(Individual i)
{
    string ret = "";
    for (int index = 0; index < 4; index++)
    {
        if (ret != "")
        {
            ret += ", ";
        }
        if (i.genome.at(index) == '1')
        {
            ret += objList[index].GetName();
        }
    }
	return ret;
}

int SimulationManager::Weigh(Individual i)
{
    int weight = 0;
	int length = i.genome.length();

    for (int index = 0; index < length; index++)
    {
        if (i.genome.at(index) == '1')
        {
            weight += objList[index].GetWeight();
        }
    }
    return weight;
}
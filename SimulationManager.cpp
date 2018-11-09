#include <string>

using namespace std;

//CROSSOVER Operator

/// called twice on a pair of strings, swapping s1 and s2 for each
/// input
///     string s1 - the main string
///     string s2 -  the string with the part or crossover into s1
/// return
///     string - the new version of s1 with the tail part of s2
string Crossover(string s1, string s2);

int FitnessFunction(string);

float Normalize(int);

void SortDescending();

static int POPSIZE = 0;
static float MUTATEPCT = .5f;
static int NUMITERATIONS = 100;

void GeneratePopulation();

int* objectList;
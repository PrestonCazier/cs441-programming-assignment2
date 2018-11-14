#include <iostream>
#include <string>
#include "SimulationManager.h"

using namespace std;

int main(int argc, char const *argv[])
{
    SimulationManager* sm = new SimulationManager();
    sm->Run();
    delete sm;
	char c = getchar();\
    return 0;
}

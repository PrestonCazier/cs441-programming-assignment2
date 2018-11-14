#include <string>

using namespace std;

#ifndef KNAPSACKOBJECT_08112018
#define KNAPSACKOBJECT_08112018

class KnapsackObject
{
	private:
	string name;
	int weight;
	int value;

	public:
	  KnapsackObject();
	  KnapsackObject(string n, int w, int v);
	  ~KnapsackObject();

	  string GetName();
	  int GetWeight();
	  int GetValue();

	  void SetObject(string n, int w, int v);
};
#endif KNAPSACKOBJECT_08112018
#include "KnapsackObject.h"

KnapsackObject::KnapsackObject()
{
}

KnapsackObject::KnapsackObject(string n, int w, int v)
{
    name = n;
    weight = w;
    value = v;
}

KnapsackObject::~KnapsackObject()
{
}

string KnapsackObject::GetName()
{
    return name;
}

int KnapsackObject::GetWeight()
{
    return weight;
}

int KnapsackObject::GetValue()
{
    return value;
}

void KnapsackObject::SetObject(string n, int w, int v)
{
    name = n;
    weight = w;
    value = v;
}
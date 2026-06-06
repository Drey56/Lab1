#pragma once
#include <string>

using namespace std;

struct Tovar
{
    string name;
    string country;
    int volume;
    int money;
};

bool operator < (Tovar a, Tovar b);
bool operator > (Tovar a, Tovar b);
bool operator <= (Tovar a, Tovar b);
bool operator >= (Tovar a, Tovar b);
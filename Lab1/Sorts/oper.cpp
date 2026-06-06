#include "oper.h"

bool operator < (Tovar a, Tovar b)
{
    //сравниваем по названию
    if (a.name != b.name)
        return a.name < b.name;

    //сравниваем по объему
    if (a.volume != b.volume)
        return a.volume < b.volume;

    //сравниваем по стране
    return a.country < b.country;
}

bool operator > (Tovar a, Tovar b)
{
    return b < a;
}

bool operator <= (Tovar a, Tovar b)
{
    return !(a > b);
}

bool operator >= (Tovar a, Tovar b)
{
    return !(a < b);
}
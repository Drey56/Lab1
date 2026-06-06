#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("ds.txt");

    string tovar[25] =
    {
        "Oil", "Gas", "Coal", "Steel", "Aluminum",
        "Nickel", "Copper", "Wheat", "Barley", "Corn",
        "Fertilizer", "Timber", "Wood", "Paper", "Diesel",
        "Petrol", "Gold", "Silver", "Palladium", "Platinum",
        "Fish", "Seafood", "Machinery", "Chemicals", "Rubber"
    };

    string cs[25] =
    {
        "China", "India", "Turkey", "Kazakhstan", "Belarus",
        "Uzbekistan", "Armenia", "Kyrgyzstan", "Egypt", "UAE",
        "SaudiArabia", "Iran", "Pakistan", "Brazil", "Vietnam",
        "Indonesia", "Mongolia", "Serbia", "Algeria", "SouthAfrica",
        "Thailand", "Malaysia", "Bangladesh", "Mexico", "Morocco"
    };

    for (int i = 0; i < 100000; i++)
    {
        string product = tovar[rand() % 25];
        string country = cs[rand() % 25];
        int volume = (rand() % 10000) + 1;
        int money = (rand() % 5000000) + 10000;

        fout << product << ";" << country << ";" << volume << ";" << money << endl;
    }

    fout.close();

    return 0;
}
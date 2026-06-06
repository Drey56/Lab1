#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
#include "oper.h"
#include "MySortings.h"

using namespace std;
using namespace chrono;

int readData(Tovar a[], int needSize)
{
    ifstream fin("../DataSetMaker/ds.txt");

    string line;
    int i = 0;

    while (getline(fin, line) && i < needSize)
    {
        int p1 = line.find(';');
        int p2 = line.find(';', p1 + 1);
        int p3 = line.find(';', p2 + 1);

        //считываем название товара
        a[i].name = line.substr(0, p1);

        //считываем страну
        a[i].country = line.substr(p1 + 1, p2 - p1 - 1);

        //считываем объем продукции
        a[i].volume = stoi(line.substr(p2 + 1, p3 - p2 - 1));

        //считываем сумму в рублях
        a[i].money = stoi(line.substr(p3 + 1));

        i++;
    }

    fin.close();

    return i;
}

void copyArray(Tovar from[], Tovar to[], int size)
{
    for (int i = 0; i < size; i++)
    {
        //копируем элемент массива
        to[i] = from[i];
    }
}

void writeData(Tovar a[], int size)
{
    ofstream fout("sorted.txt");

    for (int i = 0; i < size; i++)
    {
        //записываем один товар
        fout << a[i].name << ";"
            << a[i].country << ";"
            << a[i].volume << ";"
            << a[i].money << endl;
    }

    fout.close();
}

int main()
{
    const int maxSize = 100000;

    int sizes[12] = {100, 500, 1000, 2500, 5000, 10000, 20000, 40000, 60000, 80000, 90000, 100000};

    //создаем массив для исходных данных
    Tovar* original = new Tovar[maxSize];

    //создаем массив для сортировки
    Tovar* a = new Tovar[maxSize];

    ofstream result("result.txt", ios::trunc);

    result << "size bubble shaker merge std_sort" << endl;

    for (int i = 0; i < 12; i++)
    {
        //считываем нужное количество записей
        int size = readData(original, sizes[i]);

        //копируем исходный массив перед сортировкой
        copyArray(original, a, size);

        auto start = high_resolution_clock::now();
        bubbleSort(a, size);
        auto end = high_resolution_clock::now();

        //считаем время сортировки пузырьком
        long long bubbleTime = duration_cast<microseconds>(end - start).count();

        //копируем исходный массив перед сортировкой
        copyArray(original, a, size);

        start = high_resolution_clock::now();
        shakerSort(a, size);
        end = high_resolution_clock::now();

        //считаем время шейкерной сортировки
        long long shakerTime = duration_cast<microseconds>(end - start).count();

        //копируем исходный массив перед сортировкой
        copyArray(original, a, size);

        start = high_resolution_clock::now();
        merge_sort(a, 0, size - 1);
        end = high_resolution_clock::now();

        //считаем время сортировки слиянием
        long long mergeTime = duration_cast<microseconds>(end - start).count();

        //копируем исходный массив перед сортировкой
        copyArray(original, a, size);

        start = high_resolution_clock::now();
        sort(a, a + size);
        end = high_resolution_clock::now();

        //считаем время стандартной сортировки
        long long stdSortTime = duration_cast<microseconds>(end - start).count();

        //записываем результаты замеров
        result << size << " "
            << bubbleTime << " "
            << shakerTime << " "
            << mergeTime << " "
            << stdSortTime << endl;
    }

    //считываем весь набор данных
    int size = readData(original, maxSize);

    //сортируем итоговый массив
    merge_sort(original, 0, size - 1);

    //записываем отсортированные данные
    writeData(original, size);

    result.close();

    //освобождаем память
    delete[] original;

    //освобождаем память
    delete[] a;

    return 0;
}
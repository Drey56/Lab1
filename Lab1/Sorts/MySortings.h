#pragma once

template<class T>
void bubbleSort(T a[], int size)
{
    T x;

    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            //меняем элементы местами
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
            }
        }
    }
}

template<class T>
void shakerSort(T a[], int size)
{
    int j;
    int k = size - 1;
    int lb = 1;
    int ub = size - 1;
    T x;

    do
    {
        for (j = ub; j > 0; j--)
        {
            //проход справа налево
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
            }
        }

        lb = k + 1;

        for (j = 1; j <= ub; j++)
        {
            //проход слева направо
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
            }
        }

        ub = k - 1;

    } while (lb < ub);
}

template<class T>
void merge(T a[], int low, int mid, int high)
{
    //создаем временный массив
    T* b = new T[high + 1 - low];

    int h = low;
    int i = 0;
    int j = mid + 1;

    while ((h <= mid) && (j <= high))
    {
        //выбираем меньший элемент
        if (a[h] <= a[j])
        {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }

        i++;
    }

    //копируем остаток правой части
    if (h > mid)
    {
        for (int k = j; k <= high; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        //копируем остаток левой части
        for (int k = h; k <= mid; k++)
        {
            b[i] = a[k];
            i++;
        }
    }

    for (int k = 0; k <= high - low; k++)
    {
        //возвращаем элементы в исходный массив
        a[k + low] = b[k];
    }

    delete[] b;
}

template<class T>
void merge_sort(T a[], int low, int high)
{
    if (low < high)
    {
        //делим массив на две части
        int mid = (low + high) / 2;

        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);

        //сливаем две отсортированные части
        merge(a, low, mid, high);
    }
}
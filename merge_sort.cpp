#include "merge_sort.h"


void merge(int* arr, int l, int m, int r)
{
    const int nl = m - l + 1;
    const int nr = r - m;

    // создаем временные массивы
    int* left = new int [nl] {};
    int* right = new int [nr] {};

    // копируем данные во временные массивы
    for (int i = 0; i < nl; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < nr; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    int k = l;  // начало левой части

    while (i < nl && j < nr) {
        // записываем минимальные элементы обратно во входной массив
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // записываем оставшиеся элементы левой части
    while (i < nl) {
        arr[k] = left[i];
        i++;
        k++;
    }
    // записываем оставшиеся элементы правой части
    while (j < nr) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}


void split(int* arr, int l, int r)
{
    if (l >= r)
        return;


    int m = (l + r - 1) / 2;

    if ((m - l) > 5)
    {

        std::future<void> f = std::async(std::launch::async, split, arr, l, m);
        split(arr, m + 1, r);

    }
    else
    {
        split(arr, l, m);
        split(arr, m + 1, r);
    }


    merge(arr, l, m, r);
}


void mergeSort(int* arr, int l, int r)
{
    r -= 1;

    split(arr, l, r);

}


bool operator==(const std::vector<int>& my, const std::vector<int> other)
{
    bool result = true;

    for (int i = 0; i < my.size(); ++i)
    {
        if (my.at(i) != other.at(i))
        {
            result = false;
            break;
        }
    }

    return result;
}


std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec)
{
    for (int t : vec)
    {
        out << t << " ";
    }
    out << std::endl;

    return out;
}
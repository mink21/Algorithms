#include <iostream>
using namespace std;

int check(int arr[], int index)
{
    int test[sizeof(arr) / 4];
    for (int i = 0; i < index; i++)
    {
        test[arr[i]]++;
    }
    for (int i = 0; i < index; i++)
    {
        if (test[i] > 1)
            return 0;
    }
    return 1;
}

void choose(int index, int arr[], int max)
{
    if (index == sizeof(arr) / 4)
    {
        arr[index] = index;
        return;
    }
    if (check(arr, max))
    {
        choose(index + 1, arr, max);
    }
}

void main()
{
    int N, M;
    cin >> N >> M;
    int arr[M];
    choose(arr, N);
}
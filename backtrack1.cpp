#include <iostream>
using namespace std;

int check(int arr[], int index, int tmp)
{
    for (int i = 0; i < index; i++)
    {
        if (arr[i] == tmp)
            return 0;
    }
    return 1;
}

void choose(int *arr, int size, int max, int index)
{
    if (index == size)
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= max; i++)
    {
        arr[index] = i;
        if (check(arr, index, i))
        {
            choose(arr, size, max, index + 1);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    int arr[M];
    choose(arr, M, N, 0);
    return 0;
}
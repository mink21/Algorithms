#include <iostream>
using namespace std;

void bubbleSort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - j - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                sawp(&arr[j], &arr[j + 1]);
        }
    }
}

int main(void)
{
    return 0;
}
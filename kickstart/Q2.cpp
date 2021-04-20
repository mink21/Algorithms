#include <iostream>
using namespace std;

int markStart, markStep;

int subarray(int arr[], int start, int size)
{
    if (size == 1)
        return 1;
    else if (size == 2)
        return 2;
    else
    {
        int count = 1, step, ans, idx;
        //count consecutive
        step = arr[start + 1] - arr[start];
        idx = start + 1;
        while ((arr[idx] - arr[idx - 1]) == step)
        {
            count++;
            idx++;
            if (idx == size)
                break;
        }

        ans = subarray(arr, start + 1, size - 1);
        count = (count < ans) ? ans : count;

        return count;
    }
}

void findStep(int arr[], int cons, int size)
{
    int idx, step, count;
    for (int i = 0; i < size - 1; i++)
    {
        idx = i;
        step = arr[i] - arr[i + 1];
        count = 1;
        while ((arr[idx] - arr[idx + 1]) == step)
        {
            idx++;
            count++;
            if (count == cons)
            {
                markStart = i;
                markStep = step;
                return;
            }
        }
    }
}

void check(int arr[])
{
}

void solve(int test_case)
{
    int size, ans, start;
    cin >> size;
    int n[size];
    for (int i = 0; i < size; i++)
        cin >> n[i];

    ans = subarray(n, 0, size);
    if (ans == size - 1)
        ans++;
    else if (ans != size)
    {
        //still need to figure out
        findStep(n, ans, size);
        check(n);
        n[markStart - 1] = n[markStart] + markStep;
        ans = subarray(n, 0, size);
    }

    cout << "Case #" << test_case << ": " << ans << "\n";
}

int main(void)
{
    int test_case;
    cin >> test_case;
    for (int i = 1; i <= test_case; i++)
    {
        solve(i);
    }
}
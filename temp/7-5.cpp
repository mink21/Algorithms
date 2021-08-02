#include <iostream>
#include <algorithm>
using namespace std;

int n, m, target;
int N[1000000];

bool binarySearch(int target, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (N[mid] == target){
            return true;
        }
        else if (N[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return false;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> N[i];
    sort(N, N + n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> target;
        if (binarySearch(target, 0, n - 1) == 1)
            cout<<"yes ";
        else
            cout<<"no ";
    }
    cout<<"\n";
    return 0;
}
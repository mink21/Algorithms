#include <iostream>
using namespace std;

int cnt = 0;

void towerOfHanoiCount(int n, int from_rod, int to_rod, int aux_rod)
{
    if (n == 1)
    {
        cnt++;
        return;
    }
    towerOfHanoiCount(n - 1, from_rod, aux_rod, to_rod);
    cnt++;
    towerOfHanoiCount(n - 1, aux_rod, to_rod, from_rod);
}

void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod)
{
    if (n == 1)
    {
        cout << from_rod << " " << to_rod << "\n";
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << from_rod << " " << to_rod << "\n";
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    cin >> n;
    towerOfHanoiCount(n, 1, 3, 2);
    cout << cnt << "\n";
    towerOfHanoi(n, 1, 3, 2);
    return 0;
}

#include <iostream>
using namespace std;

int main(void)
{
    int A, B;
    cin >> A >> B;

    int B1, B2, B3;
    B1 = B / 100;
    B2 = (B - B1 * 100) / 10;
    B3 = (B - B1 * 100 - B2 * 10);

    cout << A * B3 << endl;
    cout << A * B2 << endl;
    cout << A * B1 << endl;
    cout << A * B << endl;
    return 0;
}
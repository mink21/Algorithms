#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, V, ans;
    cin >> A >> B >> V;

    if ((V - A) % (A - B) == 0)
        ans = 1 + (V - A) / (A - B);
    else
        ans = 2 + (V - A) / (A - B);

    cout << ans << "\n";
    return 0;
}

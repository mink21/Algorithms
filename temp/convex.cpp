#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;
int N;
double Dx, Dy;
typedef pair<double, pair<double, double>> dot;
vector<dot> dots;
int convexhull[100001]; // stack
int top;                // stack push idx
int ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c)
{
    pair<double, double> ab;
    ab.first = b.first - a.first;
    ab.second = b.second - a.second;
    pair<double, double> bc;
    bc.first = c.first - b.first;
    bc.second = c.second - b.second;
    double ret = ab.first * bc.second - ab.second * bc.first;
    ret = -ret;
    if (ret > 0)
        return 1;
    else if (ret == 0)
        return 0;
    else
        return -1;
}

double getDistance(const dot A, const dot B)
{
    return sqrt(pow(A.second.first - B.second.first, 2.0) + pow(A.second.second - B.second.second, 2.0));
}

bool settingDots(dot A, dot B)
{
    int cw = ccw(dots[0].second, A.second, B.second);
    if (cw > 0)
        return 1;
    if (cw < 0)
        return 0;
    else if (A.first < B.first)
    {
        return 1;
    } // dist A < dist B (기준 점에서 거리)
    return 0;
}

void setSlope(const dot P0)
{
    for (int i = 1; i < N; i++)
    {
        dots[i].first = getDistance(P0, dots[i]);
    }
    sort(dots.begin() + 1, dots.end(), settingDots);
}
void ConvexHull()
{
    for (int i = 2; i < N; i++)
    {
        while (top >= 2 && ccw(dots[convexhull[top - 2]].second, dots[convexhull[top - 1]].second, dots[i].second) <= 0)
            top--;
        convexhull[top++] = i;
    }
}
int main()
{
    cin >> N;
    dots.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Dx >> Dy;
        dots[i].second.first = Dy;
        dots[i].second.second = Dx;
    }
    sort(dots.begin(), dots.end());
    setSlope(dots[0]);
    convexhull[top++] = 0;
    ;
    convexhull[top++] = 1;
    ConvexHull();

    cout << top << endl;
}
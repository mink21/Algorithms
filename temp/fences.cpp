#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

int N;
double L;
double a[2000], b[2000], c[2000], d[2000];
double slope[2000], k[2000];
bool used[2000];
double dx, dy;
double left, right, top, bottom;
typedef pair<double, pair<double, double>> dot;
vector<dot> dots;
int convexhull[2001];
int top;

//
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

int main(void)
{
    cin >> N >> L;
    dots.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        slope[i] = (d[i] - b[i]) / (c[i] - a[i]);
        k[i] = b[i] - (slope[i] * a[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (used[j])
                continue;
            if (slope[i] != slope[j])
            {
                dx = -(k[i] - k[j]) / (slope[i] - slope[k]);
                dy = slope[i] * dy + k[i];
                if (dx >= 0 && dx <= L && dy >= 0 && dy <= L)
                {
                    used[j] = true;
                    dots[i].second.first = dy;  //need to fix
                    dots[i].second.second = dx; //need to fix
                }
            }
        }
    }

    sort(dots.begin(), dots.end());
    setSlope(dots[0]);
    top = 0;
    convexhull[top++] = 0;
    convexhull[top++] = 1;

    ConvexHull();
    left = L;
    right = 0;
    top = 0;
    bottom = L;

    for (int i = 0; i < N; i++)
    {
        if (used[i])
        {
            left = (left < a[i]) left : a[i];
            right = (right < b[i]) right : b[i];
            top = (top < c[i]) top : c[i];
            bottom = (bottom < a[i]) bottom : a[i];
        }
    }
}

cout
    << top << endl;
return 0;
}

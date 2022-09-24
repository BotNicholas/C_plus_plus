#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;

int n;
float smax;

struct point
{
    float x, y;
}P[30], P1, P2, P3;



float Area(float a, float b, float c)
{
    float p = (a+b+c)/2;

    return sqrt(p*(p-a)*(p-b)*(p-c));
}



float distance(point A, point B)
{
    return sqrt(pow((A.x-B.x), 2)+pow((A.y-B.y), 2));
}



bool posiblesolution(int i, int j, int k)
{
    if(i!=j && j!= k && i!= k) return true;
        else return false;
}



void processingsolution(point A, point B, point C)
{
    float d1 = distance(A, B);
    float d2 = distance(B, C);
    float d3 = distance(A, C);

    float ar = Area(d1, d2, d3);

    if(ar>smax)
    {
        P1 = A;
        P2 = B;
        P3 = C;
        smax = ar;
    }
}


int main()
{
    cout << "Input number of points (n): ";
    cin >> n;

    cout << "Input coordinates (x and y) for "<< n << " points: " << endl;
    for(int i=0; i<n; i++)
    {
        cout <<"P[" << i+1 << "]\'s x: ";
        cin >> P[i].x;
        cout <<"P[" << i+1 << "]\'s y: ";
        cin >> P[i].y;

    }

    cout << endl;
    for(int i=0; i<n; i++, cout << endl)
    {
        cout <<"P[" << i+1 << "]\'s x = " << P[i].x << endl;
        cout <<"P[" << i+1 << "]\'s y = " << P[i].y << endl;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++) // 3 cicla tak kak smotrim 3 tocki
             if(posiblesolution(i, j, k)) processingsolution(P[i], P[j], P[k]);

    cout << "P1 = ( " << P1.x << ", " << P1.y << " )" << endl;
    cout << "P2 = ( " << P2.x << ", " << P2.y << " )" << endl;
    cout << "P3 = ( " << P3.x << ", " << P3.y << " )" << endl;
    return 0;
}

//9 1 3 3 10 4 5 5 1 7 9 8 5 9 1 10 11 10 8

//9 0 3 3 10 4 5 5 1 7 9 8 5 9 1 10 11 10 8

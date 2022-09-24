#include <iostream>
#include <cmath>
using namespace std;

int n, R;

struct point
{
    int x, y, z;
}P[30];

float distance(point A)
{
    return sqrt(pow(A.x, 2)+pow(A.y,2)+pow(A.z,2));
}

bool PosibleSolution(point P) //zadat vopros
{
    if(R>=distance(P)) return true;
    else return false;
}

void ProcessingSolution(point P, int i)
{
    cout << "\nP" << i+1 << " (" << P.x << ", " << P.y << ", " << P.z << ") - is in sphere" << endl;
}

int main()
{
    cout << "Input number of points: ";
    cin >> n;

    cout << "Input radius: ";
    cin >>R;

    cout << "Input coordinates (x, y and z) for " << n << " points: " << endl;

    for(int i=0; i<n; i++)
    {
        cout << "P[" << i+1 << "] x:";
        cin >> P[i].x;
        cout << "P[" << i+1 << "] y:";
        cin >> P[i].y;
        cout << "P[" << i+1 << "] z:";
        cin >> P[i].z;
    }

    cout << endl; //output
    for(int i=0; i<n; i++)
    {
        cout << "P[" << i+1 << "] x - " << P[i].x << ", y - " << P[i].y << ", z - " << P[i].z << endl;
    }

    cout << endl;

    for(int i=0; i<n; i++)
    {
        if(PosibleSolution(P[i])) ProcessingSolution(P[i], i);

    }

    return 0;
}
//9 4 -4 6 4 3 6 6 1 3 4 4 1 6 -1 -1 -1 -5 -3 -10 -1 -4 4 3 -6 1 4 4 4

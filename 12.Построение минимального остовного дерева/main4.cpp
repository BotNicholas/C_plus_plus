#include <iostream>
using namespace std;

const int p = 5;

bool IsDirak(int A[p][p])
{
    int degree = 0;

    for(int i=0; i<p; i++)
    {
        for(int j=0; j<p; j++)
            degree+=A[i][j];
        if(degree < p/2)
            if(degree < 2) return false;
    }
    return true;
}

int main()
{

    int Amatr[p][p] = {{0, 1, 0, 0, 0},
                       {1, 0, 1, 1, 1},
                       {0, 1, 0, 1, 1},
                       {0, 1, 1, 0, 1},
                       {0, 1, 1, 1, 0}};


    cout << "\nThe Adjacency matrix: " << endl;
    for(int i=0; i<p; i++, cout << endl)
        for(int j=0; j<p; j++)
            cout << Amatr[i][j] << " ";


    cout << "\nThis Gamelton\'s graph by Dirak's theoreme - " << boolalpha << IsDirak(Amatr) << endl;

    return 0;
}

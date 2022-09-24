#include <iostream>

using namespace std;

int main()
{
    int n = 5;
    int G[n][n] = {{0, 1, 0, 1, 0},
                   {1, 0, 1, 1, 1},
                   {0, 1, 0, 1, 0},
                   {1, 1, 1, 0, 1},
                   {0, 1, 0, 1, 0}};

    cout << "The G adjacensy matrix: " << endl;
    for(int i=0; i<n; i++, cout << endl)
    for(int j=0; j<n; j++)
        cout << G[i][j] << ", ";


    int cycles=0;
    cout << "\nGraph's cycles with 3 edges:" << endl;
    for(int i=0; i<n; i++)
        for(int j = i+1; j<n; j++)
            if(G[i][j] == 1)
                for(int l= j+1; l<n; l++)
                    if(G[j][l] && G[i][l])
                    {
                        cout << i << ", " << j << ", " << l << endl;
                        cycles++;
                    }
    if (cycles == 0)
        cout << "There are no cycles with 3 edges" << endl;

    return 0;
}


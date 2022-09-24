#include <iostream>

using namespace std;

const int n = 5;

int main()
{
    int v;
    int matri[n][n] = {{0, 1, 1, 1, 1},
                       {1, 0, 1, 1, 1},
                       {1, 1, 0, 1, 1},
                       {1, 1, 1, 0, 1},
                       {1, 1, 1, 1, 0}};

     do
     {
         cout << "\nInput nod to work: " << endl;
         cin >> v;

         if(v>=n) cout << "Nod should be < " << n << endl;
         else if(v<0) cout << "Nod should be >= 0 " << n << endl;
     } while((v>=n)||(v<0));


    cout << "\nThe adjacensy matrix: " << endl;
    for(int i=0; i<n; i++, cout << endl)
    for(int j=0; j<n; j++)
        cout << matri[i][j] << ", ";

    cout << "\nEdges, which are incident to " << v << " nod:" << endl;
    cout << "It is ";
    for(int j=0; j<n; j++)
        if(matri[v][j] == 1)
            cout << "(" << v << ", " << j << "), ";

    cout << " edges." << endl;
    return 0;
}


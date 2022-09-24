#include <iostream>
using namespace std;

const int n = 6;
int m = 0;

int **IncidenceM(int Amatr[n][n])
{
    int x=0;
    m = 0;

    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            if(Amatr[i][j]==1) m++;

    int **Imatr = new int* [n];

    for(int i=0; i<n; i++)
        Imatr[i] = new int[m];

            for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((j < i) and (Amatr[i][j] == 1))
            {
                for (int k = 0; k < n; k++)
                {
                    if ((k == i) or (k == j)) Imatr[k][x] = 1;
                    else Imatr[k][x] = 0;
                }
                x++;
            }


//            cout << "The incidence matrix:\n\n";
//    for (int i = 0; i < n; i++, cout << endl)
//        for (int j = 0; j < m; j++)
//            cout << " " << Imatr[i][j];

    return Imatr;
}

bool IsChain(int A[n][n], int *N, int s)
{
    for(int i=0; i<s-1; i++)
        if((A[N[i]][N[i+1]] != 1) || (A[N[i]][N[i+1]] == 1 && N[i]==N[i+2]))
        return false;
}

bool IsSimpleChain(int A[n][n], int *N, int s)
{
    for(int i=0; i<s-1; i++)
        if((A[N[i]][N[i+1]] != 1) || (A[N[i]][N[i+1]] == 1 && N[i]==N[i+2]))
        return false;

    //proverim, povtoriauitsa li ticki. Esli net, to eto prostaia cepi, tak kak v cepi mogut povtoriatsia vershini, no riobra net, a v prostoi cepi ne nogut povtoriatsa ni rebra, ni vershini (s ciklom toze samoie)
    for(int i=0; i<s-1; i++)
    for(int j=i+1; j<s; j++)
    if(N[i]==N[j]) return false;

      if(N[0] != N[s-1]) return true;
        else return false;
}

bool IsCycle(int A[n][n], int *N, int s)
{
    for(int i=0; i<s-1; i++)
        if((A[N[i]][N[i+1]] != 1) || (A[N[i]][N[i+1]] == 1 && N[i]==N[i+2]))
        return false;

    if(N[0] == N[s-1]) return true;
        else return false;

}

bool IsSimpleCycle(int A[n][n], int *N, int s)
{
    for(int i=0; i<s-1; i++)
        if((A[N[i]][N[i+1]] != 1) || (A[N[i]][N[i+1]] == 1 && N[i]==N[i+2]))
        return false;

    //proverim, povtoriauitsa li ticki. Esli net, to eto prostaia cepi, tak kak v cepi mogut povtoriatsia vershini, no riobra net, a v prostoi cepi ne nogut povtoriatsa ni rebra, ni vershini (s ciklom toze samoie)
    for(int i=1; i<s-2; i++)
    for(int j=i+1; j<s-1; j++)
    if(N[i]==N[j]) return false;

    if(N[0] == N[s-1]) return true;
        else return false;
}

int main()
{
    int Amatr[n][n] = {{0, 1, 1, 0, 0, 1},
                       {1, 0, 0, 0, 1, 1},
                       {1, 0, 0, 1, 0, 1}, // [0][2] == 1 and [2][3] == 1 and [0][0] == 0 ili mozno bilo bi N[0] == N[s-1]
                       {0, 0, 1, 0, 0, 0},
                       {0, 1, 0, 0, 0, 1},
                       {1, 1, 1, 0, 1, 0}};

    int **I = IncidenceM(Amatr);

    int s;

    do
    {
        cout << "Input how many nodes you have: ";
        cin >> s;
    } while(s>n);


    int Nods[s];

    cout << "\nInput ", s, " nodes: ";
    for(int i=0; i<s; i++)
    {
        cout << "Nods[" << i << "] = ";
        cin >> Nods[i];
    }

    cout << "\nThe Adjacency matrix: " << endl;
    for(int i=0; i<n; i++, cout << endl)
        for(int j=0; j<n; j++)
            cout << Amatr[i][j] << " ";


    cout << "\nThis way is a chain - " << boolalpha << IsChain(Amatr, Nods, s) << endl;
    cout << "This way is a cycle - " << boolalpha << IsCycle(Amatr, Nods, s) << endl;
    cout << "This way is a simple chain - " << boolalpha << IsSimpleChain(Amatr, Nods, s) << endl;
    cout << "This way is a simple cycle - " << boolalpha << IsSimpleCycle(Amatr, Nods, s) << endl;

    return 0;
}

#include <iostream>
using namespace std;

const int n = 5;

bool IsGamelton(int A[n][n], int *N, int s)
{
    if(s!=n+1) return false; //tak kak cicl

    for(int i=0; i<s-1; i++)
        if((A[N[i]][N[i+1]] != 1) || (A[N[i]][N[i+1]] == 1 && N[i]==N[i+2]))
        return false;

    //proverim, povtoriauitsa li ticki. Esli net, to eto prostaia cepi, tak kak v cepi mogut povtoriatsia vershini, no riobra net, a v prostoi cepi ne nogut povtoriatsa ni rebra, ni vershini (s ciklom toze samoie)
    for(int i=1; i<s-2; i++) // s 1 i do s-2, tak kak 1-i i s-1-i elementi == (poetomu i=1), a posledniii element nescem proveriati(poetomu s-2)
    for(int j=i+1; j<s-1; j++)
    if(N[i]==N[j]) return false;

    if(N[0] == N[s-1]) return true;
        else return false;
}

int main()
{

    int Amatr[n][n] = {{0, 1, 0, 0, 1},
                       {1, 0, 1, 0, 0},
                       {0, 1, 0, 1, 0},
                       {0, 0, 1, 0, 1},
                       {1, 0, 0, 1, 0}};

    int s;

    do
    {
        cout << "Input how many nodes you have: ";
        cin >> s;
    } while(s>n+1); // tak kak cicl


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


    cout << "\nThis way is a Gamelton\'s cycle - " << boolalpha << IsGamelton(Amatr, Nods, s) << endl;

    return 0;
}

//    int Amatr[n][n] = {{0, 1, 1, 0, 0, 1},
//                       {1, 0, 0, 0, 1, 1},
//                       {1, 0, 0, 1, 0, 1}, // [0][2] == 1 and [2][3] == 1 and [0][0] == 0 ili mozno bilo bi N[0] == N[s-1]
//                       {0, 0, 1, 0, 0, 0},
//                       {0, 1, 0, 0, 0, 1},
//                       {1, 1, 1, 0, 1, 0}};

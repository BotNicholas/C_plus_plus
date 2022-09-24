#include <iostream>

using namespace std;

const int n = 6;

int main()
{
    int G[n][n] = {{0, 1, 1, 0, 0, 0},
                   {1, 0, 0, 1, 1, 0},
                   {1, 0, 0, 0, 0, 1},
                   {0, 1, 0, 0, 0, 0},
                   {0, 1, 0, 0, 0, 0},
                   {0, 0, 1, 0, 0, 0}};

    cout << "The G adjacensy matrix: " << endl;
    for(int i=0; i<n; i++, cout << endl)
    for(int j=0; j<n; j++)
        cout << G[i][j] << ", ";

    int sum = 0;
    bool flag = true;

    for(int i=0; i<n; i++)
    {
        sum = 0;

        for(int j=i; j<n; j++)
            sum += G[i][j];

        if(sum >2)
        {
            flag = false;
            break;
        }
        else if(sum == 0) // 0 mozet biti ili u lista ili u izolirovannogo (to esti ot nix ne idet sviaz), no k listu, v otlicii ot izolirovannogo uzla, idet sviaz => proveriaem
        {
            for(int j=0; j<n; j++)
            sum += G[i][j];
            if(sum == 0)
            {
                flag = false;
                break;
            }
        }
    }

    if(!flag) cout << "\nThis Graph is not a binary tree!" << endl;
    else
        cout << "\nThis Graph is a binary tree!!!" << endl;

    return 0;
}

//int G[n][n] = {{0, 1, 1, 1, 1},
//                   {1, 0, 1, 1, 1},
//                   {1, 1, 0, 1, 1},
//                   {1, 1, 1, 0, 1},
//                   {1, 1, 1, 1, 0}};








//    int G[n][n] = {{0, 1, 0, 1, 0, 0, 0, 0},
//                   {1, 0, 1, 0, 0, 0, 1, 0},
//                   {0, 1, 0, 0, 1, 0, 0, 0},
//                   {1, 0, 0, 0, 0, 1, 0, 1},
//                   {0, 0, 1, 0, 0, 0, 0, 0},
//                   {0, 0, 0, 1, 0, 0, 0, 0},
//                   {0, 1, 0, 0, 0, 0, 0, 0},
//                   {0, 0, 0, 1, 0, 0, 0, 0}};


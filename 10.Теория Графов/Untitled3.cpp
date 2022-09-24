#include <iostream>

using namespace std;


int main()
{
    int m = 0;
    int nods = 7;
    int x = 0;

int matr_s[nods][nods] = {{0, 1, 0, 0, 0, 1, 0},  //0
        {1, 0, 1, 0, 0, 0, 0},   //1
        {0, 1, 0, 0, 0, 0, 0},   //2
        {0, 0, 0, 0, 1, 0, 0},   //3
        {0, 0, 0, 1, 0, 1, 0},   //4
        {1, 0, 0, 0, 1, 0, 1},   //5
        {0, 0, 0, 0, 0, 1, 0}};

    for (int i = 0; i < nods; i++)
    {
        for (int j = 0; j < nods; j++)
        {
            if ((j > i) and (matr_s[i][j] == 1)) m++;
        }
    }

    int matr_i[nods][m];
    for (int i = 0; i < nods; i++)
        for (int j = 0; j < nods; j++)
            if ((j < i) and (matr_s[i][j] == 1))
            {
                for (int k = 0; k < nods; k++)
                {
                    if ((k == i) or (k == j)) matr_i[k][x] = 1;
                    else matr_i[k][x] = 0;
                }
                x++;
            }

    cout << "The incidence matrix:\n\n";
    for (int i = 0; i < nods; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << " " << matr_i[i][j];
    return 0;
}






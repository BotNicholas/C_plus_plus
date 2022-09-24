//Program "Kukunber" for real kukumbers)))))
#include <iostream>

using namespace std;

const int n = 5;
const int n1 = 5;

int main()
{
    int m=0, m1=0;

    int G[n][n] = {{0, 1, 1, 1, 1},
                   {1, 0, 1, 1, 1},
                   {1, 1, 0, 1, 1},
                   {1, 1, 1, 0, 1},
                   {1, 1, 1, 1, 0}};

    int G1[n1][n1] = {{0, 0, 1, 0, 1},
                      {0, 0, 1, 1, 0},
                      {1, 1, 0, 1, 0},
                      {0, 1, 1, 0, 1},
                      {1, 0, 0, 1, 0}};

    cout << "The G adjacensy matrix: " << endl;
    for(int i=0; i<n; i++, cout << endl)
    for(int j=0; j<n; j++)
        cout << G[i][j] << ", ";

    cout << endl;
     cout << "\nThe G1 adjacensy matrix: " << endl;
    for(int i=0; i<n1; i++, cout << endl)
    for(int j=0; j<n1; j++)
        cout << G1[i][j] << ", ";

    if(n==n1)
    {
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                if(G[i][j]==1) m++;

        for(int i=0; i<n1; i++)
            for(int j=i; j<n1; j++)
                if(G1[i][j]==1) m1++;

        int Gm[n][m];
        int Gm1[n1][m1];

        for (int i = 0; i < n; i++)
            for(int j=0; j<m; j++)
                Gm[i][j] = 0;

        for(int i=0; i<n1; i++)
            for(int j=0; j<m1; j++)
                Gm1[i][j] = 0;

        int k=0, k1=0;

            for(int i=0; i<n; i++)
            for(int j=i; j<n; j++) // tak kak tak mi ne bude prosmatrivati sviazi sverhu/sleva - to esti te sviazi, kotorie uze bili. Tut nam nado smotreti sviazi dlia kazdoi tocki => dvigaeshsia "kvadratom"
            {
                if(G[i][j] == 1)
                {
                    Gm[i][k] = 1;
                    Gm[j][k] = 1;
                    k++;
                }
            }

        cout << endl;
        cout << "\nThe G incident matrix: " << endl;
        for(int i=0; i<n; i++, cout << endl)
            for(int j=0; j<m; j++)
                cout << Gm[i][j] << ", ";

            for(int i=0; i<n1; i++)
                for(int j=i; j<n1; j++)
            {
                if(G1[i][j] == 1)
                {
                    Gm1[i][k1] = 1;
                    Gm1[j][k1] = 1;
                    k1++;
                }
            }

        cout << endl;
        cout << "\nThe G1 incident matrix: " << endl;
        for(int i=0; i<n1; i++, cout << endl)
            for(int j=0; j<m1; j++)
                cout << Gm1[i][j] << ", ";

        int ie = 0;
        int flag = 0;

        for(int i=0; i<m1; i++)
        {
            for(int l=0; l<m; l++/*, cout << endl*/)
            {
                ie = 0;
                for(int j=0; j<n; j++)
                {
                    //cout << "Gm1[" << j << "][" << i << "] = " << Gm1[j][i] << ", Gm[" << j << "][" << l << "] = " << Gm[j][l] << endl;
                    if(Gm1[j][i] == Gm[j][l])
                        ie++;
                }

                if(ie == n)
                {
                    flag++;
                }
            }
        }

       // cout << flag << endl;

        if(flag == m1) cout << "\nG1 is partial graph of G!" << endl; // esli vse sviazi iz Gm1 soderzatsa v Gm
        else
            cout << "\nG1 is not partial graph of G!" << endl;
    }
    else
        cout << "\nG1 is not partial graph of G!" << endl;

    return 0;
}

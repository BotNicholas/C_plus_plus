#include <iostream>

using namespace std;

const int n = 5;

bool is_full(int A[n][n], int n)
{
    bool flag = true;
    int sum=0;

    for(int i=0; i<n; i++)
    {
        sum = 0;
        for(int j=0; j<n; j++)
            sum+=A[i][j];

        if(sum!=n-1) return false; //n-1 - tak kak za vicetom samoi tocki (0, 0)
    }
    return true;
}

int main()
{
    int matri[n][n] = {{0, 1, 1, 1, 1},
                       {1, 0, 1, 1, 1},
                       {1, 1, 0, 1, 1},
                       {1, 1, 1, 0, 1},
                       {1, 1, 1, 1, 0}};

    cout << "The adjacensy matrix: " << endl;
    for(int i=0; i<n; i++, cout << endl)
    for(int j=0; j<n; j++)
        cout << matri[i][j] << ", ";

    if(!is_full(matri, n))
        cout << "\nThis graph isn\'t full!" << endl;
    else
        cout << "\nThis graph is full." << endl;

    return 0;
}

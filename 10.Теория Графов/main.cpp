#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int sum=0, leaf_n=0, i_nodes_n=0;
    int nods = 7;
    int max_gr = 0, max_n;
    int matr_s[nods][nods] = {{0, 1, 0, 0, 0, 1, 0},  //0
        {1, 0, 1, 0, 0, 0, 0},   //1
        {0, 1, 0, 0, 0, 0, 0},   //2
        {0, 0, 0, 0, 1, 0, 0},   //3
        {0, 0, 0, 1, 0, 1, 0},   //4
        {1, 0, 0, 0, 1, 0, 1},   //5
        {0, 0, 0, 0, 0, 1, 0}};  //6


    cout << "Leafs:" << endl;
    for(int i=0; i<nods; i++)
    {
        sum = 0;
        for(int j=0; j<nods; j++)
        {
            sum+=matr_s[i][j];
        }
        if(sum == 1)
        {
            cout << "It's the " << i << "\'th nod;" << endl;
            leaf_n++;
        }
    }

    cout << "\nIsolated nodes:" << endl;
    for(int i=0; i<nods; i++)
    {
        sum = 0;
        for(int j=0; j<nods; j++)
        {
            sum+=matr_s[i][j];
        }
        if(sum == 0)
        {
            cout << "It's the " << i << "\'th nod;" << endl;
            i_nodes_n++;
        }
    }

    cout << "\nEven grade nodes:" << endl;
    for(int i=0; i<nods; i++)
    {
        sum = 0;
        for(int j=0; j<nods; j++)
        {
            sum+=matr_s[i][j];
        }
        if(sum %2 == 0)
            cout << "It's the " << i << "\'th nod;" << endl;
    }

    cout << "\nEach node\'s grade:" << endl;
    for(int i=0; i<nods; i++)
    {
        sum = 0;
        for(int j=0; j<nods; j++)
        {
            sum+=matr_s[i][j];
        }


        cout << i << "\'st nod\'s grade = " << sum << ";" << endl;


        if(sum > max_gr)
        {
            max_gr = sum;
            max_n = i;
        }

    }

    cout << "\nNode with maximal grade - " << max_n << "\'th nod;" << endl; //described in 74 - 78 lines
    cout << "\nNode with maximal grade - " << max_n << "\'th nod;" << endl; //described in 74 - 78 lines

//    cout << "\nEach node grade:" << endl;
//    for(int i=0; i<nods; i++)
//    {
//        sum = 0;
//        for(int j=0; j<nods; j++)
//        {
//            sum+=matr_s[i][j];
//        }
//        cout << i << "\'st nod\'s grade = " << sum << ";" << endl;
//
//    }

    cout << "\nNumber of leafs = " << leaf_n << endl; //described in 19 - 32 lines
    cout << "\nIsolated nodes = " << i_nodes_n << endl; //described in 33 - 46 lines

    return 0;
}







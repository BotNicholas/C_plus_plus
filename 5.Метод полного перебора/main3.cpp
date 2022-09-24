#include <iostream>
#include <limits.h>
using namespace std;

int N, G, SumMin = INT_MAX;

struct coin
{
    int value;
    int weight;
    int numb;
    int numb2;
}c[5];

bool posibleSolution()
{
    int numb_of_coins = 0;
    for(int i=0; i<5; i++)
        numb_of_coins += c[i].numb;

    int coins_weight = 0;
    for(int i=0; i<5; i++)
    coins_weight+=(c[i].numb*c[i].weight);

if( (numb_of_coins == N) and (coins_weight == G))
    {
        return true;
    }
    else return false;
}

void processingSolution()
{
    int Sum = 0;
    for(int i=0; i<5; i++)
        Sum+=(c[i].value*c[i].numb);

    if(Sum < SumMin)
    {
        for(int i=0; i<5; i++)
            c[i].numb2 = c[i].numb;
        SumMin = Sum;
    }

}

int main()
{
    c[0].value = 1;
    c[1].value = 5;
    c[2].value = 10;
    c[3].value = 25;
    c[4].value = 50;

    for(int i=0; i<5; i++)
    {
        c[i].weight = i+1;
        c[i].numb = 0;
        c[i].numb2 = 0;
    }

    cout << "Input number of coins: ";
    cin >> N;

    cout << "Input total weight of coins: ";
    cin >> G;
//Scitaiu kolicestvo monet s raznim nominalon dlia kazdogo sluciaia
    for(int i=0; i<=N; i++)//== Mozet biti N*1 monet
    for(int j=0; j<=N; j++)//== Mozet biti N*5 monet
    for(int k=0; k<=N; k++)//== Mozet biti N*10 monet
    for(int l=0; l<=N; l++)//== Mozet biti N*25 monet
    for(int m=0; m<=N; m++)//== Mozet biti N*50 monet => nado poscitati cislo monet dlia cazdogo varianta s nominalom
    {
        c[0].numb = i;
        c[1].numb = j;
        c[2].numb = k;
        c[3].numb = l;
        c[4].numb = m;
        if(posibleSolution())processingSolution();
    }
       // cout << c[i].value << " " << c[j].value << " " << c[k].value << " " << c[l].value << " " << c[m].value << endl;

       cout << "\nAnswer: " << endl;
       cout << "N = " << N << endl;
       cout << "G = " << G << endl;
       cout << "\nCoins nominals: " << endl;
       cout << c[0].value << " - " << c[0].numb2 << endl;
       cout << c[1].value << " - " << c[1].numb2 << endl;
       cout << c[2].value << " - " << c[2].numb2 << endl;
       cout << c[3].value << " - " << c[3].numb2 << endl;
       cout << c[4].value << " - " << c[4].numb2 << endl;
       cout << "\nMinimal Sum = " << SumMin << endl;

    return 0;
}

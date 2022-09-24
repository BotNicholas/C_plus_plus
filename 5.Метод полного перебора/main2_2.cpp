#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

int a, b, x;

bool posibleSolution(int j)
{
    x = j;
    int i = a;
    int maxnumb = INT_MIN;
    //bool is_true = false;
    int Sum = 0;

    while(i)
    {
        int number = i%10;
        if(number>maxnumb) maxnumb = number;
        i/=10;
    }

    if(maxnumb<x)
    {
        i=a;
        int numba = 0;

        while(i)
        {
            numba++;
            i/=10;
        }

        int numba2 = numba;

        i=a;

        while(i)
        {
            Sum+=i%10*pow(x, (numba2 - numba));
            i/=10;
            numba--;
        }

        if(Sum == b) return true;
        else
        {
            return false;
        }
    }
    else
        {
            return false;
        }
}

void processingSolution()
{
    cout << "Here is the answer! x = " << x <<endl;
}

int main()
{
    bool is_existing = false;

    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    for(int i=1; i<=10; i++)
        if(posibleSolution(i))
        {
            processingSolution();
            is_existing = true;
        }
        if(!is_existing) cout << "There is no answer!"<<endl;
    return 0;
}

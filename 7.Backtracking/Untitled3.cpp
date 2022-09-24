#include <iostream>

using namespace std;

int n, m, x[50], sn;
bool flag = false;

bool Continue(int k)
{
    int sum = 0;
    for (int i = 0; i <= k; i++)
        sum += x[i];
    if (x[k] < x[k - 1])
     return false;
    if (((k < n - 1) and (sum <= n)) or ((k == n - 1) and (sum == n)))
     return true;
    else
     return false;
}

void ProcessingSolution()
{
    cout << endl << " solution " << ++sn << " :" << endl;
    for (int i = 0; i < n - 1; i++)
        if (x[i] != 0 or (x[i] == 0 and x[i + 1] == n))
         cout << x[i] << " + ";
    cout << x[n - 1] << " = " << n << endl;
    flag = true;
}

void Backtracking(int k)
{
    x[k] = 0;
    if (k < n) {
        if (Continue(k)) Backtracking(k + 1);
        while (x[k] < n)
        {
            x[k]++;
            if (Continue(k)) Backtracking(k + 1);
        }
    }
    else ProcessingSolution();
}

int main()
{
    cout << "Input a number to decompose: ";
    cin >> n;
    Backtracking(0);
    if(!flag) cout << "There is no solution!";
}

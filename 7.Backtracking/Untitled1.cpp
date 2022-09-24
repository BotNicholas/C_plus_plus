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
    if (((k < m - 1) and (sum <= n)) or ((k == m - 1) and (sum == n)))
        return true;
    else
        return false;
}

void ProcessingSolution()
{
    cout << endl << " solution " << ++sn << ":" << endl;
    for (int i = 0; i < m - 1; i++)
        cout << x[i] << " + ";

    cout << x[m - 1] << " = " << n << endl;
    flag = true;
}

void Backtracking(int k)
{
    if (k < m)
    {
        x[k] = k;
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
    cout << "Input the number to decompose: ";
    cin >> n;
    cout << "Input how many numbers should decompose the number: ";
    cin >> m;
    Backtracking(0);
    if(!flag) cout << "There are no solution!";
}

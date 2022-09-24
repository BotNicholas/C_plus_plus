#include <iostream>
using namespace std;

int A[50];
int n;

int NOD(int a, int b)
{
	if ((a == 0) || (b == 0)) return 0;
	else
		if (b % a == 0) return a;
		else
			if (a % b == 0) return b;
			else
				if (a > b) return NOD(a % b, b);
	return NOD(a, b % a);
}

bool DirectSolution(int i, int j) //only if will remain 2 numbers (then you can find the NOD between them)
{
	if ((j - i) < 2) return true;
	else return false;
}

void ProcessingSolution(int i, int j, int x)
{
	int nod = NOD(A[i], A[j]);
	if (x > nod) x = nod;
}

void Merge(int x1, int x2, int& x)
{
	if (x1 > x2)x = x1;
	else x = x2;
}

void Devide_et_Impera(int i, int j, int &x)
{
	int m;
	int x1, x2;
	if (DirectSolution(i, j)) ProcessingSolution(i, j, x);
	else
	{
		m = (j - i) / 2;
		Devide_et_Impera(i, i+m, x1);
		Devide_et_Impera(i+m+1, j, x2);
		Merge(x1, x2, x);
	}
}

int main()
{
	cout << "Input how many numbers you would like to use: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}

	int x = A[0];
	Devide_et_Impera(0, n - 1, x);

	cout << "The NOD of this numbers = " << x << endl;

	return 0;
}

#include <iostream>
using namespace std;

int A[50];
int n, p;
bool flag = false;

void arrsort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
}


bool directsolution(int i, int j) //if there are only one number left...
{
	if (j-i < 1) return true;
	else return false;
}

void processingsolution(int i, int p) // Because it will work if only one number has remained...
{
	if (A[i] == p) flag = true;
}

void Merge(bool x1, bool x2)
{
	if (x1 > x2) flag = x1;
	else if (x2 > x1) flag = x2;
}

void Devide_et_Impera(int i, int j, bool &flag)
{
	int m;
	bool x1, x2;
	if (directsolution(i, j)) processingsolution(i, p);
	else
	{
		m = (j - i) / 2;
		Devide_et_Impera(i, i + m, x1);
		Devide_et_Impera(i + m + 1, j, x2);
		Merge(x1, x2);
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

	arrsort(A, n);

	cout << "Input number to search: ";
	cin >> p;

	Devide_et_Impera(0, n-1, flag);

	cout << p << " is existing in array - " << boolalpha << flag << "." << endl;

	return 0;
}

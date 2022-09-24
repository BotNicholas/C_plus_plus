//Ferzi
#include<iostream>
using namespace std;
int a[10][10], n, x[50];
bool flag;

int FirstElement(int k)
{
	return 0;
}
bool Continue(int k)
{
	for (int i = 0; i < k; i++)
	{
		if (x[i] == x[k]) return false; //Èñêëþ÷àåì ïî ñòðîêàì

		if (abs(x[k] - x[i]) == abs(k - i)) return false; //Èñêëþ÷àåì ïî äèàãîíàëÿì
	}
	return true;
}

bool ExistSuccessor(int k)
{
	return (x[k] < n - 1);
}

int Successor(int k)
{
	return x[k] + 1;
}

void ProcessingSolution()
{
	cout << endl << "Ðåøåíèå:" << endl;
	for (int i = 0; i < n; i++)
		a[x[i]][i] = 1;

	for (int i = 0; i < n; i++, cout << endl)
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 0;

	cout << endl;
	flag = true;
}

void Backtracking(int k)
{
	if (k < n)
	{
		x[k] = FirstElement(k);
		if (Continue(k))Backtracking(k + 1);
		while (ExistSuccessor(k))
		{
			x[k] = Successor(k);
			if (Continue(k)) Backtracking(k + 1);
		}
	}
	else ProcessingSolution();
}

int main()
{
	setlocale(0, "");
	cout << "Ââåäèòå êîëè÷åñòâî ôåðçåé =";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			a[i][j] = 0;
	}
	flag = false;
	Backtracking(0);
	if (!flag) cout << "Ðåøåíèÿ íåò";

 return 0;
}

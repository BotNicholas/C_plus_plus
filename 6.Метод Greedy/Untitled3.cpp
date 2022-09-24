#include <iostream>
#include <iomanip>
using namespace std;

int n, m=0;

struct file
{
	int t;
	int f_number;
}f[50], lenta[50];

bool ExistElement()
{
	for (int i = 0; i < n; i++)
		if (f[i].t > 0)
			return true;
	return false;
}

void SelectElement(int &x)
{
	int Minf = 0; // predpoloshim, cito 1-i (0-i) element minimalnii. Togda naciniom prosmotr so 2-go (1-go)

	for (int i = 1; i < n; i++)
		if ((f[i].t < f[Minf].t) and (f[i].t!=0)) Minf = i; // tak kak ne a>b, to esli f[i].t == 0 - udavletvaritelino. (f[Minf].t != 0 nikogda, i daze esli budet, to if == false)

	x = Minf;
}

void IncludeElement(int x)
{
	lenta[m].f_number = f[x].f_number;
	lenta[m].t = f[x].t;

	m++;
	f[x].t = 0;
}

int main()
{
	cout << "Input number of files: ";
	cin >> n;
	cout << "\nInput accessing time for each file and ID number: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl << i + 1 << "\'st file\'s accessing time: ";
		cin >> f[i].t;
		cout << i + 1 << "\'st file\'s ID: ";
		cin >> f[i].f_number;
	}

	int x; //Hranit adres minimalnogo. Tak kak snaciala vibiru, a potom dobavliu po i

	while (ExistElement())
	{
		SelectElement(x);
		IncludeElement(x);
	}

	cout << "\n\n-------------------------------------------" << endl;
	cout << "The way of storing files on magnetic tape: " << endl;
	cout << "-------------------------------------------" << endl;
	cout << " No" << setw(8) << "ID" << setw(20) << "time" << endl;
	cout << "-------------------------------------------" << endl;
	for (int i = 0; i < m; i++)
		cout << i+1 << "\'st -" << setw(5) << lenta[i].f_number << setw(10) << " (" << lenta[i].t << "s of accessing time);" << endl;
	return 0;
}

//5 10 4 3 34 7 78 9 81 1 1

//1, 5, 10, 20, 50, 100, 200, 500 è 1000
#include <iostream>
using namespace std;

int sum;

struct money
{
	int nom;
	int nom2;
	int n;
}b[9];

bool ExistElement()
{
	for (int i = 0; i < 9; i++)
		if (b[i].nom > 0) return true;
	return false;
}

void SelectElement(int &x)
{
	int Maxb = 0;

	for (int i = 1; i < 9; i++)
		if (b[i].nom > b[Maxb].nom) Maxb = i;

	x = Maxb;
}

void IncludeElement(int x)
{
	b[x].n = sum / b[x].nom;

	sum -= b[x].n * b[x].nom;

	b[x].nom = 0;
}

int main()
{
	b[0].nom = 1000;
	b[1].nom = 500;
	b[2].nom = 200;
	b[3].nom = 100;
	b[4].nom = 50;
	b[5].nom = 20;
	b[6].nom = 10;
	b[7].nom = 5;
	b[8].nom = 1;

	for (int i = 0; i < 9; i++)
	{
		b[i].n = 0;
		b[i].nom2 = b[i].nom;
	}

	cout << "Input the sum: ";
	cin >> sum;

	/*cout << endl << "Desponible banknotes: " << endl;
	for (int i = 0; i < 9; i++)
		cout << b[i].nom << " lei;" << endl;*/

	int x;

	while (ExistElement())
	{
		SelectElement(x);
		IncludeElement(x);
	}


	cout << "\nRest: " << endl;
	for(int i=0; i<9; i++)
	{
		cout << b[i].nom2 << " - " << b[i].n << endl;
	}

	return 0;
}

#include <iostream>
using namespace std;

float Gmax = 0;
float Cmax = 0;
int n;

struct obbject
{
	float g; // Element's weight
	float c; // Price for element
	float p; // Number of element (1 || <1)
}o[30];

bool ExistElement()
{
	for (int i = 0; i < n; i++)
		if (o[i].c > 0)
			return true;
	return false;
}

void SelectElement(int& x)
{
	int MaxE = 0;
	for (int i = 1; i < n; i++)
		if (o[i].c / o[i].g > o[MaxE].c / o[MaxE].g) MaxE = i;

	x = MaxE;
}


void IncludeElement(int x)
{


	if (o[x].g < Gmax)
	{
		o[x].p = 1;
		Gmax -= o[x].g;
		Cmax += o[x].c;
	}
	else
		if (o[x].g >= Gmax)
		{
			o[x].p = Gmax / o[x].g;
			o[x].g = Gmax;
			Gmax = 0;
			Cmax += o[x].c * o[x].p;
		}
	o[x].c = 0;
}

int main()
{
	cout << "Input capacity of the backpack: ";
	cin >> Gmax;

	cout << "\nInput number od objects: ";
	cin >> n;

	cout << "\nInput information about " << n << " objects: " << endl << endl;
	for (int i = 0; i < n; i++, cout << endl)
	{
		cout << "Input price for the object: ";
		cin >> o[i].c;
		cout << "Input object\'s weight: ";
		cin >> o[i].g;

		o[i].p = 0;
	}

	int x;

	while (ExistElement())
	{
		SelectElement(x);
		//cout << x << "\t" << o[x].p << endl;
		IncludeElement(x);
	}

	cout << "\nResult: " << endl;
	for (int i = 0; i < n; i++)
		cout << i + 1 << " element - " << o[i].p << " (it is " << o[i].g << " kg); " << endl;
	cout << "\nObtimal sum = " << Cmax << endl;

	return 0;
}

//7 3 20 4 18 3 14 2

//10 4 30 6 14 3 16 4 9 2

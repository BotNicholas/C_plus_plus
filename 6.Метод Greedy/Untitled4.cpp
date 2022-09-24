#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int n, m;

struct robot
{
	int x;
	int y;
}b;

struct movement
{
	string v;
}mov[4];

float distance(int x1, int x2, int y1, int y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool ExistElement(int **A)
{
	if ((A[b.y][b.x - 1] == 0) ||
		(A[b.y][b.x + 1] == 0) ||
		(A[b.y - 1][b.x] == 0) ||
		(A[b.y + 1][b.x] == 0))
		return true;
	return false;
}

void SelectElement(int &x, int **A)
{
	int MinX;
	//int MinV;

	if (A[b.y][b.x - 1] == 0 && distance(b.x - 1, m - 2, b.y, n - 1) < distance(b.x, m - 2, b.y, n - 1)) MinX = 1;
	else
		if (A[b.y][b.x + 1] == 0 && distance(b.x + 1, m - 2, b.y, n - 1) < distance(b.x, m - 2, b.y, n - 1)) MinX = 3;
		else
			if (A[b.y - 1][b.x] == 0 && distance(b.x, m - 2, b.y - 1, n - 1) < distance(b.x, m - 2, b.y, n - 1)) MinX = 2;
			else
				if (A[b.y + 1][b.x] == 0 && distance(b.x, m - 2, b.y + 1, n - 1) < distance(b.x, m - 2, b.y, n - 1)) MinX = 0;

	x = MinX;
	A[b.y][b.x] = 0;
}

void IncludeElement(int x)
{
	fstream F("Hrube.out", ios::out);

	F << mov[x].v << endl;

	F.close();
}

int main()
{
	fstream F ("Hrube.in", ios::in);

	if (!F.is_open()) cout << "File reading error!" << endl;
	else
	{
        F >> n >> m;

		int** A = new int* [n];

		for (int i = 0; i < 30; i++)
			A[i] = new int[m];

        while (!F.eof())
        {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					F >> A[i][j];
        }
		F.close();

		for (int i = 0; i < n; i++, cout << endl)
			for (int j = 0; j < m; j++)
				cout << A[i][j] << " ";


		mov[0].v = "up";
		mov[1].v = "left";
		mov[2].v = "down";
		mov[3].v = "right";

		b.x = m - (m - 1);
		b.y = n - 1;

		int x1;

		while (ExistElement(A))
		{
			SelectElement(x1, A);
			IncludeElement(x1);
		}
	}

	return 0;
}

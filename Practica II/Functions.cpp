#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Functions.h"

using namespace std;

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

bool flag;

int path[100];
int c=0;



void Thanks_for_using()
{


    cout << endl;

    SetConsoleTextAttribute(handle, 10);
    cout << 'T';
    SetConsoleTextAttribute(handle, 11);
    cout << 'h';
    SetConsoleTextAttribute(handle, 12);
    cout << 'a';
    SetConsoleTextAttribute(handle, 13);
    cout << 'n';
    SetConsoleTextAttribute(handle, 14);
    cout << 'k';
    SetConsoleTextAttribute(handle, 15);
    cout << "'";
    cout << 's';

    cout << " ";

    SetConsoleTextAttribute(handle, 12);
    cout << 'f';
    SetConsoleTextAttribute(handle, 13);
    cout << 'o';
    SetConsoleTextAttribute(handle, 14);
    cout << 'r';

    cout << " ";

    SetConsoleTextAttribute(handle, 15);
    cout << 'u';
    SetConsoleTextAttribute(handle, 10);
    cout << 's';
    SetConsoleTextAttribute(handle, 12);
    cout << 'i';
    SetConsoleTextAttribute(handle, 15);
    cout << 'n';
    SetConsoleTextAttribute(handle, 11);
    cout << 'g';
    SetConsoleTextAttribute(handle, 14);
    cout << '!' << endl << endl;

    SetConsoleTextAttribute(handle, 7);
}


void find_max_high(int **teren, int &i, int &j)
{
    int maxP=0;

    for(int i1=0; i1<n; i1++)
        for(int j1=0; j1<m; j1++)
            if(teren[i1][j1]>maxP)
            {
                maxP = teren[i1][j1];
                i=i1;
                j=j1;
            }
}


void draw_a_map(string **strat, int **teren)
{

    cout << "\nTerrain map:\n" << endl;
    //рамка карты (верх):
    cout << "    ";
    for(int i=0; i<m; i++)
        cout << i << " ";
    cout << endl;

    cout << "   ";
    for(int i=0; i<m*2+1; i++)
        cout << "-";
    cout << endl;

    for(int i=0; i<n; i++)
    {
        SetConsoleTextAttribute(handle, 7);
        cout << i << " | ";

        for(int j=0; j<m; j++)
        {
            if(strat[i][j] == "nisip")
            {
                SetConsoleTextAttribute(handle, 6);
                cout << char(176) << " ";
            }
            if(strat[i][j] == "podzol")
            {
                SetConsoleTextAttribute(handle, 7);
                cout<<char(178) << " ";
            }
            if(strat[i][j] == "pietris")
            {
                SetConsoleTextAttribute(handle, 4);
                cout<<char(177) << " ";
            }
            if(strat[i][j] == "granit")
            {
                SetConsoleTextAttribute(handle, 9);
                cout<<char(254) << " ";
            }
            if(strat[i][j] == "marmura")
            {
                SetConsoleTextAttribute(handle, 2);
                cout<<char(35) << " ";
            }
            if(strat[i][j] == "bazalt")
            {
                SetConsoleTextAttribute(handle, 14);
                cout<<char(206) << " ";
            }
            if(strat[i][j] == "piatra")
            {
                SetConsoleTextAttribute(handle, 8);
                cout<<char(30)<<" ";
            }

        }

        SetConsoleTextAttribute(handle, 7);
        cout << "|" << endl;
    }

    SetConsoleTextAttribute(handle, 7); // Вернем белый текст

    //рамка карты (низ):
    cout << "   ";
    for(int i=0; i<m*2+1; i++)
        cout << "-";
    cout << endl;





    cout << "\n\nTerrain height map:\n" <<endl;

    //рамка карты (верх):
    cout << "     ";
    for(int i=0; i<m; i++)
        cout << setw(3) << i;
    cout << endl;

    cout << "     ";
    for(int i=0; i<m*3+2; i++)
        cout << "-";
    cout << endl;



    for(int i=0; i<n; i++)
    {
        cout << setw(3) << i << " |";
        for(int j=0; j<m; j++)
            cout << setw(3) << teren[i][j];
        cout << setw(3) << "|" << endl;
    }

    //рамка карты (низ):
    cout << "     ";
    for(int i=0; i<m*3+2; i++)
        cout << "-";
    cout << endl;



}


void draw_alpinists_map(string **strat, int **teren, int xa, int ya)
{

    string **strat2 = new string*[n];
    for(int i=0; i<n; i++)
        strat2[i] = new string[m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            strat2[i][j] = strat[i][j];

    int imax, jmax;
    find_max_high(teren, imax, jmax);

    cout << "\nTerrain map:\n" << endl;
    //рамка карты (верх):
    cout << "    ";
    for(int i=0; i<m; i++)
        cout << i << " ";
    cout << endl;

    cout << "   ";
    for(int i=0; i<m*2+1; i++)
        cout << "-";
    cout << endl;
    for(int i=0; i<n; i++)
    {
        SetConsoleTextAttribute(handle, 7);
        cout << i << " | ";

        for(int j=0; j<m; j++)
        {
            if(i==imax and j==jmax)
            {
                SetConsoleTextAttribute(handle, 20);
                cout << "* ";
            }
            else if(i == ya and j == xa)
            {
                SetConsoleTextAttribute(handle, 21);
                cout<< "8 ";
            }
            else
            {
                if(strat2[i][j] == "nisip")
                {
                    SetConsoleTextAttribute(handle, 6);
                    cout << char(176) << " ";
                }
                if(strat2[i][j] == "podzol")
                {
                    SetConsoleTextAttribute(handle, 7);
                    cout<<char(178) << " ";
                }
                if(strat2[i][j] == "pietris")
                {
                    SetConsoleTextAttribute(handle, 4);
                    cout<<char(177) << " ";
                }
                if(strat2[i][j] == "granit")
                {
                    SetConsoleTextAttribute(handle, 9);
                    cout<<char(254) << " ";
                }
                if(strat2[i][j] == "marmura")
                {
                    SetConsoleTextAttribute(handle, 2);
                    cout<<char(35) << " ";
                }
                if(strat2[i][j] == "bazalt")
                {
                    SetConsoleTextAttribute(handle, 14);
                    cout<<char(206) << " ";
                }
                if(strat2[i][j] == "piatra")
                {
                    SetConsoleTextAttribute(handle, 8);
                    cout<<char(30)<<" ";
                }

            }


        }

        SetConsoleTextAttribute(handle, 7);
        cout << "|" << endl;
    }

    SetConsoleTextAttribute(handle, 7); // Вернем белый текст

    //рамка карты (низ):
    cout << "   ";
    for(int i=0; i<m*2+1; i++)
        cout << "-";
    cout << endl;


    cout << "\n\nTerrain height map:\n" <<endl;

    //рамка карты (верх):
    cout << "     ";
    for(int i=0; i<m; i++)
        cout << setw(3) << i;
    cout << endl;

    cout << "     ";
    for(int i=0; i<m*3+2; i++)
        cout << "-";
    cout << endl;



    for(int i=0; i<n; i++)
    {
        cout << setw(3) << i << " |";
        for(int j=0; j<m; j++)
            cout << setw(3) << teren[i][j];
        cout << setw(3) << "|" << endl;
    }

    //рамка карты (низ):
    cout << "     ";
    for(int i=0; i<m*3+2; i++)
        cout << "-";
    cout << endl;



}


void Insert_col_row(string where, int **&teren, string **&strat)
{

    if(where=="north" || where=="North")
    {
        n++;

        int **teren2 = new int*[n];
        for(int i=0; i<n; i++)
        {
            teren2[i] = new int[m];
        }


        for(int i=0; i<n-1; i++)
            for(int j=0; j<m; j++)
                teren2[i+1][j] = teren[i][j];



        cout << "Insert new terrain heights: " << endl;
        for(int i=0; i<m; i++)
        {
            cout << "> ";
            cin >> teren2[0][i];
        }


        string **strat2 = new string*[n];
        for(int i=0; i<n; i++)
        {
            strat2[i] = new string[m];
        }


        for(int i=0; i<n-1; i++)
            for(int j=0; j<m; j++)
                strat2[i+1][j] = strat[i][j];

        cout << "Insert new terrain strats (nisip, podzol, pietris, granit, marmura, bazalt, piatra): " << endl;
        for(int i=0; i<m; i++)
        {
            cout << "> ";
            cin >> strat2[0][i];
        }


        for(int i=0; i<n-1; i++)
        {
            delete[] teren[i];
            delete[] strat[i];
        }

        delete[] teren;
        delete[] strat;

        teren = teren2;

        strat = strat2;
    }


    if(where=="south"|| where=="South")
    {
        n++;

        int **teren2 = new int*[n];
        for(int i=0; i<n; i++)
        {
            teren2[i] = new int[m];
        }


        for(int i=0; i<n-1; i++)
            for(int j=0; j<m; j++)
                teren2[i][j] = teren[i][j];



        cout << "Insert new terrain heights: " << endl;
        for(int i=0; i<m; i++)
        {
            cout << "> ";
            cin >> teren2[n-1][i];
        }


        string **strat2 = new string*[n];
        for(int i=0; i<n; i++)
        {
            strat2[i] = new string[m];
        }


        for(int i=0; i<n-1; i++)
            for(int j=0; j<m; j++)
                strat2[i][j] = strat[i][j];

        cout << "Insert new terrain strats (nisip, podzol, pietris, granit, marmura, bazalt, piatra): " << endl;
        for(int i=0; i<m; i++)
        {
            cout << "> ";
            cin >> strat2[n-1][i];
        }


        for(int i=0; i<n-1; i++)
        {
            delete[] teren[i];
            delete[] strat[i];
        }

        delete[] teren;
        delete[] strat;

        teren = teren2;

        strat = strat2;
    }

    if(where=="east"|| where=="East")
    {
        m++;

        int **teren2 = new int*[n];
        for(int i=0; i<n; i++)
        {
            teren2[i] = new int[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m-1; j++)
                teren2[i][j+1] = teren[i][j];



        cout << "Insert new terrain heights: " << endl;
        for(int i=0; i<n; i++)
        {
            cout << "> ";
            cin >> teren2[i][0];
        }


        string **strat2 = new string*[n];
        for(int i=0; i<n; i++)
        {
            strat2[i] = new string[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m-1; j++)
                strat2[i][j+1] = strat[i][j];

        cout << "Insert new terrain strats (nisip, podzol, pietris, granit, marmura, bazalt, piatra): " << endl;
        for(int i=0; i<n; i++)
        {
            cout << "> ";
            cin >> strat2[i][0];
        }


        for(int i=0; i<n-1; i++)
        {
            delete[] teren[i];
            delete[] strat[i];
        }

        delete[] teren;
        delete[] strat;

        teren = teren2;

        strat = strat2;
    }

    if(where=="west"|| where=="West")
    {
        m++;

        int **teren2 = new int*[n];
        for(int i=0; i<n; i++)
        {
            teren2[i] = new int[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m-1; j++)
                teren2[i][j] = teren[i][j];



        cout << "Insert new terrain heights: " << endl;
        for(int i=0; i<n; i++)
        {
            cout << "> ";
            cin >> teren2[i][m-1];
        }


        string **strat2 = new string*[n];
        for(int i=0; i<n; i++)
        {
            strat2[i] = new string[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m-1; j++)
                strat2[i][j] = strat[i][j];

        cout << "Insert new terrain strats (nisip, podzol, pietris, granit, marmura, bazalt, piatra): " << endl;
        for(int i=0; i<n; i++)
        {
            cout << "> ";
            cin >> strat2[i][m-1];
        }


        for(int i=0; i<n-1; i++)
        {
            delete[] teren[i];
            delete[] strat[i];
        }

        delete[] teren;
        delete[] strat;

        teren = teren2;

        strat = strat2;
    }
}


void Exclude_col_row(string where, int **&teren, string **&strat)
{
    if(where=="north" || where=="North")
    {
        n--;

        int **teren2 = new int*[n];
        for(int i=0; i<n; i++)
        {
            teren2[i] = new int[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                teren2[i][j] = teren[i+1][j];


        string **strat2 = new string*[n];
        for(int i=0; i<n; i++)
        {
            strat2[i] = new string[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                strat2[i][j] = strat[i+1][j];


        for(int i=0; i<n-1; i++)
        {
            delete[] teren[i];
            delete[] strat[i];
        }

        delete[] teren;
        delete[] strat;



        teren = teren2;

        strat = strat2;
    }

    if(where=="south"|| where=="South")
    {
        n--;

        int **teren2 = new int*[n];
        for(int i=0; i<n; i++)
        {
            teren2[i] = new int[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                teren2[i][j] = teren[i][j];


        string **strat2 = new string*[n];
        for(int i=0; i<n; i++)
        {
            strat2[i] = new string[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                strat2[i][j] = strat[i][j];


        for(int i=0; i<n-1; i++)
        {
            delete[] teren[i];
            delete[] strat[i];
        }

        delete[] teren;
        delete[] strat;



        teren = teren2;

        strat = strat2;
    }

    if(where=="east"|| where=="East")
    {
        m--;

        int **teren2 = new int*[n];
        for(int i=0; i<n; i++)
        {
            teren2[i] = new int[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                teren2[i][j] = teren[i][j+1];


        string **strat2 = new string*[n];
        for(int i=0; i<n; i++)
        {
            strat2[i] = new string[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                strat2[i][j] = strat[i][j+1];


        for(int i=0; i<n-1; i++)
        {
            delete[] teren[i];
            delete[] strat[i];
        }

        delete[] teren;
        delete[] strat;



        teren = teren2;

        strat = strat2;
    }

    if(where=="west"|| where=="West")
    {
        m--;

        int **teren2 = new int*[n];
        for(int i=0; i<n; i++)
        {
            teren2[i] = new int[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                teren2[i][j] = teren[i][j];


        string **strat2 = new string*[n];
        for(int i=0; i<n; i++)
        {
            strat2[i] = new string[m];
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                strat2[i][j] = strat[i][j];


        for(int i=0; i<n-1; i++)
        {
            delete[] teren[i];
            delete[] strat[i];
        }

        delete[] teren;
        delete[] strat;



        teren = teren2;

        strat = strat2;
    }
}


void find_minimum(int ** teren, string **strat, int i, int j)
{

    int minX=j, minY=i;

    for(int i1 = i; i1<i+3; i1++)
        for(int j1 = j; j1<j+3; j1++)
        {
            if(teren[i1][j1]<teren[minY][minX])
            {
                minX = j1;
                minY = i1;
            }
        }
    cout << "\nMinimal's area coordinates for (" << i << ":" << j << ") x (" << i+2 << ":" << j+2 << ") area block: " << endl;
    cout << minY << ":" << minX;
    cout << " - " << teren[minY][minX] << "m";



    /*
    for(int i1 = i+1; i1<i+3; i1++)
        for(int j1 = j+1; j1<j+3; j1++)
        {
            if(teren[i1][j1]<teren[minX][minY])
            {
                minX = i1;
                minY = j1;
            }
        }
    */


    //nisip podzol pietris granit marmura bazalt piatra

    if(strat[minY][minX] == "nisip")
    {
        cout  << " - it's " ;
        SetConsoleTextAttribute(handle, 6);
        cout << strat[minX][minY];
        SetConsoleTextAttribute(handle, 7);
        cout << "(";
        SetConsoleTextAttribute(handle, 6);
        cout << char(176);
        SetConsoleTextAttribute(handle, 7);
        cout << ");" << endl;
    }

    if(strat[minY][minX] == "podzol")
    {
        cout  << " - it's " ;
        SetConsoleTextAttribute(handle, 7);
        cout << strat[minX][minY];
        SetConsoleTextAttribute(handle, 7);
        cout << "(";
        SetConsoleTextAttribute(handle, 7);
        cout << char(178);
        SetConsoleTextAttribute(handle, 7);
        cout << ");" << endl;
    }

    if(strat[minY][minX] == "pietris")
    {
        cout  << " - it's " ;
        SetConsoleTextAttribute(handle, 4);
        cout << strat[minX][minY];
        SetConsoleTextAttribute(handle, 7);
        cout << "(";
        SetConsoleTextAttribute(handle, 4);
        cout << char(177);
        SetConsoleTextAttribute(handle, 7);
        cout << ");" << endl;
    }

    if(strat[minY][minX] == "granit")
    {
        cout  << " - it's " ;
        SetConsoleTextAttribute(handle, 9);
        cout << strat[minX][minY];
        SetConsoleTextAttribute(handle, 7);
        cout << "(";
        SetConsoleTextAttribute(handle, 9);
        cout << char(254);
        SetConsoleTextAttribute(handle, 7);
        cout << ");" << endl;
    }


    if(strat[minY][minX] == "marmura")
    {
        cout  << " - it's " ;
        SetConsoleTextAttribute(handle, 2);
        cout << strat[minX][minY];
        SetConsoleTextAttribute(handle, 7);
        cout << "(";
        SetConsoleTextAttribute(handle, 2);
        cout << char(35);
        SetConsoleTextAttribute(handle, 7);
        cout << ");" << endl;
    }


    if(strat[minY][minX] == "bazalt")
    {
        cout  << " - it's " ;
        SetConsoleTextAttribute(handle, 14);
        cout << strat[minX][minY];
        SetConsoleTextAttribute(handle, 7);
        cout << "(";
        SetConsoleTextAttribute(handle, 14);
        cout << char(206);
        SetConsoleTextAttribute(handle, 7);
        cout << ");" << endl;
    }

    if(strat[minY][minX] == "piatra")
    {
        cout  << " - it's " ;
        SetConsoleTextAttribute(handle, 8);
        cout << strat[minX][minY];
        SetConsoleTextAttribute(handle, 7);
        cout << "(";
        SetConsoleTextAttribute(handle, 8);
        cout << char(30);
        SetConsoleTextAttribute(handle, 7);
        cout << ");" << endl;
    }
    cout << endl;
}


void local_minimum_areas(string **strat, int **teren)
{

    for(int i=0; i<n -(n%3); i+=3)
        for(int j=0; j<m-(m%3); j+=3)
            find_minimum(teren, strat, i, j);
    system("pause");
}


float find_AV_height_of_cover(string rock, int **teren, string **strat)
{

    float AV=0;
    int count_of_areas=0;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(strat[i][j] == rock)
            {
                AV+=teren[i][j];
                count_of_areas++;
            }

    return AV/count_of_areas;
}


void order_rocks(string **strat)
{


    int general_num_of_strats = 10;
    int num_of_strats = 0;

    string strat_types [general_num_of_strats];
    int strat_types_num [general_num_of_strats];

    for(int i=0; i<general_num_of_strats; i++)
    {
        strat_types[i] = "0";
        strat_types_num[i] = 0;
    }



    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            for(int k=0; k<general_num_of_strats; k++)
            {
                if(strat_types[k]=="0")
                {
                    strat_types[k]=strat[i][j];
                    strat_types_num[k]++;
                    k=general_num_of_strats;
                    num_of_strats++;
                }
                else if(strat_types[k]==strat[i][j])
                {
                    strat_types_num[k]++;
                    k=general_num_of_strats;
                }

            }



    //Сортировка вставками

    for(int i=1; i<num_of_strats; i++)
        for(int j=i; j>0; j--)
        {
            if(strat_types_num[j]<strat_types_num[j-1])
            {
                swap(strat_types_num[j], strat_types_num[j-1]);
                swap(strat_types[j], strat_types[j-1]);
            }
        }



    for(int i=0; i<num_of_strats; i++)
    {
        cout << strat_types[i] << " - " << strat_types_num[i] << endl;
    }

    system("pause");
}


void find_lines_with_same_rock(string** strat, int** teren)
{

    fstream f;

    f.open("RociTip.txt", ios::out);

     bool flag = true;

     int lines_n=0;

    for(int i=0; i<n; i++)
    {
        flag = true;
        for(int j=0; j<m-1; j++)
        {
            if(strat[i][j]!=strat[i][j+1]) flag = false;
        }
        if(flag)
        {
            for(int j=0; j<m; j++)
                f << teren[i][j] << " ";
            f << endl;

            f<<"(";
            for(int j=0; j<m; j++)
                f << strat[i][j] << " ";
            f << ")" << endl;

            lines_n++;

        }
    }

    cout << "File \"RociTip.txt\" was created and opened successfully!\n    In file was written " << lines_n << " line(s)..." << endl;
    f.close();

    system("pause");
}


void find_path(int **teren, string **strat, int ya, int xa)
{

    int ymax, xmax;
    find_max_high(teren, ymax, xmax);

    if(teren[ya][xa] != teren[ymax][xmax]) //We'll check if it is not exit. Otherwise we will never find the exit
        teren[ya][xa] = -1; //I was here. It will be useful if I will decide to go up, or left (I should down or right)


    /*
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++)
                    cout << setw(3) << teren[i][j];
                cout << endl;
            }

            cout << endl;
    */



    if(teren[ya][xa] == teren[ymax][xmax])  //if the exit has found
    {
        flag = true;
        cout << "\nYes! Alpynist can reach the highest point... "<< endl;
        cout << "\nThis pont's on [" << ya << "; " << xa << "], it's " << teren[ya][xa] << " m in high..." << endl;
    }

    //if we are out of bounds at the moment
    if(ya >= n || ya < 0) return;
    if(xa >= m || xa < 0) return;

    //ortogonal moving (right and down)
    if((xa+1)<m && !flag && teren[ya][xa+1] == teren[ymax][xmax]) find_path(teren, strat, ya, xa+1);
    else if((xa+1)<m && !flag && teren[ya][xa+1]<5 && (strat[ya][xa+1] != "granit" || strat[ya][xa+1] != "marmura" || strat[ya][xa+1] != "piatra") && teren[ya][xa+1]!=-1) //0 - (xa+1)<n &&... - We are looking if our next stem wont be out of bounds1 - if exit was not found; 2 - next step we are going to do is not a wall; 3- if next step we are going to do was not made once (was I here or not)
        find_path(teren, strat, ya, xa+1);

    if((ya+1)<n && !flag && teren[ya+1][xa] == teren[ymax][xmax]) find_path(teren, strat, ya+1, xa);
    else if((ya+1)<n && !flag && teren[ya+1][xa]<5 && (strat[ya+1][xa] != "granit" || strat[ya+1][xa] != "marmura" || strat[ya+1][xa] != "piatra") && teren[ya+1][xa]!=-1)
        find_path(teren, strat, ya+1, xa);

    //Diagonal moving (right-down and left-down)

    if((ya+1)<n && (xa+1)<m && !flag && teren[ya+1][xa+1] == teren[ymax][xmax]) find_path(teren, strat, ya+1, xa+1);
    else if((ya+1)<n && (xa+1)<m && !flag && teren[ya+1][xa+1]<5 && (strat[ya+1][xa+1] != "granit" || strat[ya+1][xa+1] != "marmura" || strat[ya+1][xa+1] != "piatra") && teren[ya+1][xa+1]!=-1)
        find_path(teren, strat, ya+1, xa+1);

    if((ya+1)<n && (xa-1)>=0 && !flag && teren[ya+1][xa-1] == teren[ymax][xmax]) find_path(teren, strat, ya+1, xa-1);
    else if((ya+1)<n && (xa-1)>=0 && !flag && teren[ya+1][xa-1]<5 && (strat[ya+1][xa-1] != "granit" || strat[ya+1][xa-1] != "marmura" || strat[ya+1][xa-1] != "piatra") && teren[ya+1][xa-1]!=-1)
        find_path(teren, strat, ya+1, xa-1);




    //ortogonal moving (up and left)

    if((ya-1)>=0 && !flag && teren[ya-1][xa] == teren[ymax][xmax]) find_path(teren, strat, ya-1, xa);
    else if((ya-1)>=0 && !flag && teren[ya-1][xa]<5 && (strat[ya-1][xa] != "granit" || strat[ya-1][xa] != "marmura" || strat[ya-1][xa] != "piatra") && teren[ya-1][xa]!=-1)
        find_path(teren, strat, ya-1, xa);

    if((xa-1)>=0 && !flag && teren[ya][xa-1] == teren[ymax][xmax]) find_path(teren, strat, ya, xa-1);
    else if((xa-1)>=0 && !flag && teren[ya][xa-1]<5 && (strat[ya][xa-1] != "granit" || strat[ya][xa-1] != "marmura" || strat[ya][xa-1] != "piatra") && teren[ya][xa-1]!=-1)
        find_path(teren, strat, ya, xa-1);

    //diagonal moving (up-right and up-left)

    if((ya-1)>=0 && (xa+1)<m && !flag && teren[ya-1][xa+1] == teren[ymax][xmax]) find_path(teren, strat, ya-1, xa+1);
    else if((ya-1)>=0 && (xa+1)<m && !flag && teren[ya-1][xa+1]<5 && (strat[ya-1][xa+1] != "granit" || strat[ya-1][xa+1] != "marmura" || strat[ya-1][xa+1] != "piatra") && teren[ya-1][xa+1]!=-1)
        find_path(teren, strat, ya-1, xa+1);

    if((ya-1)>=0 && (xa-1)>=0 && !flag && teren[ya-1][xa-1] == teren[ymax][xmax]) find_path(teren, strat, ya-1, xa-1);
    else if((ya-1)>=0 && (xa-1)>=0 && !flag && teren[ya-1][xa-1]<5 && (strat[ya-1][xa-1] != "granit" || strat[ya-1][xa-1] != "marmura" || strat[ya-1][xa-1] != "piatra") && teren[ya-1][xa-1]!=-1)
        find_path(teren, strat, ya-1, xa-1);



    //writing path
    if(flag)
    {
        path[c++]=ya;
        path[c++]=xa;
    }
}

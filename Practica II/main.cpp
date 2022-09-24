#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "Functions.h"

using namespace std;

int n, m;

int Smax = INT_MIN;
int Y1max, X1max, Y2max, X2max;


void menu(int option, int**teren, string **strat)
{
    const int lines=9;

    system("cls");
    draw_a_map(strat, teren);

    string menu[lines] = {"1.Insert new column or a row;",
                          "2.Delete a column or a row;",
                          "3.Determine the coordinates (row number and column number) of the local minimum areas 3x3;",
                          "4.Determine the average altitude of areas entered from keyboard;",
                          "5.Display a list of individual breeds of the territory in ascending order of their number in the territory;",
                          "6.Create the text file RociTip.txt, in which will be copied lines of from file Munte.in, which represent only areas with the same type of rock;",
                          "7.Determine in the network of the terrain plan a rectangle of maximum area containing only areas of altitude not less than the real number H;",
                          "8.Resolve the alpinist's problem",
                          "9.Exit"
                         };

    cout<<"\nWhat you would like to do?" << endl;
    for(int i=0; i<lines; i++)
    {
        if(i == option-1)
        {
            SetConsoleTextAttribute(handle, 2);
            cout << menu[i] << endl;
            SetConsoleTextAttribute(handle, 7);
        }
        else
        {
            cout << menu[i] << endl;
        }
    }
}

bool possibleSolution(int **teren, int i, int j, int k, int q, float H)
{

    bool flag = true;

    if(i>k) swap(i,k);
    if(j>q) swap(j,q);


    for(int p=i; p<=k; p++)
        for(int y=j; y<=q; y++)
            if(teren[p][y]<H) flag = false;

    return flag;
}


void processingSolution(int **teren, int i, int j, int k, int q)
{

    if(i>k) swap(i,k);
    if(j>q) swap(j,q);


    int a = (k-i)+1;
    int b = (q-j)+1;

    if((a*b) > Smax)
    {
        Smax = a*b;
        Y1max = i;
        X1max = j;
        Y2max = k;
        X2max = q;
    }

}



int main()
{

    string where;
    string what;

    //Чтение фанных из файла Munte.in
    fstream f("Munte.in", ios::in);

    f >> n;
    f >> m;

    int **teren = new int *[n];
    for(int i=0; i<n; i++)
        teren[i] = new int[m];




    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            f >> teren[i][j];
    f.close();


    //Чтение фанных из файла Roci.in
    f.open("Roci.in", ios::in);

    string **strat = new string *[n];
    for(int i=0; i<n; i++)
        strat[i] = new string[m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            f >> strat[i][j];

    f.close();



    int option=1;
    int key;
    int **teren_copy = new int*[n];
    for(int i=0; i<n; i++)
        teren_copy[i] = new int[m];




    do
    {
        menu(option, teren, strat);

        do
        {
            key = getch();
            if(key == 72 and option>1)
            {
                option--;
                menu(option, teren, strat);
            }

            if(key == 80 and option<9)
            {
                option++;
                menu(option, teren, strat);
            }
            //72 - up; 80 - down
            //49-57 == 1 - 9

        }
        while(key!=13);



        string rock;

        switch(option)
        {

        case 1:
            system("cls");
            cout << "What you would like to insert (a column or a row)?\n> ";
            cin >> what;

            if(what == "row" || what == "Row" || what == "ROW")
                cout << "Where exactly you would like to insert a " << what << " (north or south)?\n>";
            else
                cout << "Where exactly you would like to insert a " << what << " (east or west)?\n>";
            cin >> where;

            Insert_col_row(where, teren, strat);
            break;

        case 2:
            system("cls");
            cout << "\nWhat you would like to exclude (a column or a row)?\n> ";
            cin >> what;
            if(what == "row" || what == "Row" || what == "ROW")
                cout << "\nWhere exactly you would like to exclude a " << what << " (north or south)?\n> ";
            else
                cout << "\nWhere exactly you would like to exclude a " << what << " (east or west)?\n> ";
            cin >> where;


            Exclude_col_row(where, teren, strat);
            break;

        case 3:
            system("cls");
            draw_a_map(strat, teren);
            cout << endl;
            local_minimum_areas(strat, teren);
            break;

        case 4:
            system("cls");

            cout << "Input type of covering, which average height you would like to find:\n(nisip podzol pietris granit marmura bazalt piatra)" << endl;
            cout << "> ";
            cin >> rock;

            cout << " Average height of " << rock << " = " << find_AV_height_of_cover(rock, teren, strat) << endl;
            system("pause");

            break;

        case 5:
            system("cls");

            order_rocks(strat);
            break;

        case 6:
            system("cls");

            find_lines_with_same_rock(strat, teren);

            break;

        case 7:
            system("cls");

            X1max = 0;
            X2max = 0;
            Y1max = 0;
            Y2max = 0;
            Smax = 0;

            draw_a_map(strat, teren);

            cout << endl;

            float H;

            cout << "Input H's value (minimal area hight)" << endl;
            cout << "H = ";
            cin >> H;
            cout << endl;

            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    if(teren[i][j]>=H)
                    {
                        for(int k=0; k<n; k++)
                            for(int q=0; q<m; q++)
                                if(teren[k][q]>=H)
                                {
                                    if(possibleSolution(teren, i, j, k, q, H)) processingSolution(teren, i, j, k, q);
                                }

                    }



            cout << "point (" << Y2max << ";" << X1max << ") (" << Y1max << ";" << X2max << ") - " << Smax << " m2" << endl;

            system("pause");

            break;

        case 8:
            system("cls");

            int xa, ya;

            cout << "Input coordinates xa and ya:" << endl;
            cout << "xa = ";
            cin >> xa;
            cout << "ya = ";
            cin >> ya;

            system("cls");

            draw_alpinists_map(strat, teren, xa, ya);


            flag=false;

            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    teren_copy[i][j] = teren[i][j];

            c=0;

            find_path(teren_copy, strat, ya, xa);

            if(!flag) cout << "\nNo. Alpynist cant reach the highest point...";
                               else
                {
                    cout << "\nPath: " << endl;
                    for(int i=c-1; i>=0; i-=2)
                        cout << "[" << path[i-1] << ", " << path[i] << "] ";

                    cout << endl;
                }




            system("pause");
            break;

        case 9:
            system("cls");
            Thanks_for_using();
            //cout << "Thank's for using!" << endl;
            break;

        default:
            system("cls");
            cout<<"Select an option from menu!\n"<< endl;
            system("pause");
        }


    }
    while(option!=9);



    for(int i=0; i<n; i++)
    {
        delete [] teren[i];
        delete [] strat[i];
    }

    delete [] teren;
    delete [] strat;

    return 0;
}

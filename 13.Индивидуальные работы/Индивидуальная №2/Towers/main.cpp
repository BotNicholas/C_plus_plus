#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

struct plate
{
    int h;
    int x;
    int y;
}I[100], PrevPlate;

int answer[100];
int counter=0;

int n;
int Sum = 0;

bool ExistElement()
{
    for(int i=0; i<n; i++)
        if(I[i].h>0 && I[i].x>0 && I[i].y>0) return true;
    return false;
}

void SelectElement(int &x)
{
    int xm = 0;

//    int maxy=0, maxx=0;
//    for(int i=1; i<n; i++)
//    if(I[i].x>maxx and I[i].y > maxy)
//    {
//        xm=i;
//        maxx = I[i].x;
//        maxy = I[i].y;
//    }

    for(int i=0; i<n; i++)
    if(I[i].h!=0)
    {
        xm=i;
        break;
    }


    for(int i=xm+1; i<n; i++)
    {
        if((I[i].x >= I[xm].x && I[i].y >= I[xm].y ) && (I[i].h >= I[xm].h))
            xm = i;
        else if((I[i].x >= I[xm].y && I[i].y >= I[xm].x) && (I[i].h >= I[xm].h))
            xm = i;
    }

    if((I[xm].x <= PrevPlate.x && I[xm].y <= PrevPlate.y) || (I[xm].x <= PrevPlate.y && I[xm].y <= PrevPlate.x))
    {
        x = xm;
        answer[counter] = x;
        PrevPlate.x = I[xm].x;
        PrevPlate.y = I[xm].y;
        PrevPlate.h = I[xm].h;
        counter++;
    }
    else
    {
        I[xm].h = 0; //-|
        I[x].x = 0; //  > to esti rto oznaciaet cito mi rassmotreli etu platu i ona ne podhodit pod uze ulozennie
        I[x].y = 0; // -|
    }
}


void IncludeElement(int x)
{
    //if(I[x].h!=0) - ne nuzno tak kak ia obnuliaiu i h, i x, i y => oni uze rassmotrenni => oni bolshe ne budut ucitivatsia
    Sum+=I[x].h;

    I[x].h = 0;
    I[x].x = 0;
    I[x].y = 0;
 }


 void sorting(int *A, int n) //prinimaet adres na pervii element massiva, to esti vector
 {
     for(int i=0; i<n-1; i++)
     {
         int minimal = i;

        for(int j = i+1; j<n; j++)
        if(A[j]<A[minimal]) minimal = j;

         swap(A[minimal], A[i]);
     }
 }

int main()
{
    fstream f("turturi.in", ios::in);
    fstream of("turturi.out", ios::out);

    if(!f.is_open()) cout << "File can not be red!" << endl;
    else
    {
        int j=0;
        f >> n;

        while(!f.eof())
        {
            f >> I[j].x >> I[j].y >> I[j].h;
            j++;
        }

        cout << n << endl;
        for(int i=0; i<n; i++)
            cout << I[i].x << " " << I[i].y << " " << I[i].h << endl;

        int Plate;
        //PrevPlate.h = INT_MAX;
        PrevPlate.x = INT_MAX;
        PrevPlate.y = INT_MAX;

        while(ExistElement())
        {
            SelectElement(Plate);
            IncludeElement(Plate);
        }

        cout << "\nMaximal hight with such plates = " << Sum << endl;

        cout << "\nThe way of tower constructing: " << endl;
        for(int i=0; i<counter; i++)
            cout << answer[i] << ", ";

        cout << endl;


        sorting(answer, counter); //answer - hranit adres pervogo elementa

        cout << "\nIt is next plates: " << endl;
        for(int i=0; i<counter; i++)
            cout << answer[i] << ", ";

        cout << endl;

        of << "Maximal hight with such plates = " << Sum;

    }
    return 0;
}

//void SelectElement(int &x)
//{
//    lastA = INT_MIN;
//    lastH = INT_MIN;
//    int xm;
//    for(int i=0; i<n; i++)
//    {
//        //cout << "\n\t" << i << " iteration;\n\n";
//        if((I[i].h!=0) && (I[i].x*I[i].y == lastA) && (I[i].h > lastH))
//            {
//                //cout << endl << I[i].x*I[i].y << " == " << lastA << "( last h = " << lastH << " )"<< endl;
//                lastH = I[i].h;
//                xm = i;
//                //cout << "I\'ve chosen " << i+1 << " plate with h = " << lastH << endl;
//            }
//            else if((I[i].h!=0) && (I[i].x*I[i].y) > lastA)
//            {
//                //cout << "I\'ve chosen " << i+1 << " plate!";
//                lastA = I[i].x * I[i].y;
//                lastH = I[i].h;
//                xm = i;
//            }
//        }
//
//    //I[xm].h = 0;
//    x = xm;
//}










//void SelectElement(int &x)
//{
//    int xm = 0;
//    int H = I[xm].h;
//    int V = INT_MIN;
//    //int A = I[xm].x * I[xm].y;
////    int A = INT_MAX;
//
//    for(int i=0; i<n; i++)
//    {
//        if((I[i].x*I[i].y*I[i].h) > V)
//        {
//            cout << "\nOld V = " << V << " - " << xm+1 << endl;
//            V = I[i].x * I[i].y;
//            cout << "New V = " << V << " - " << xm+1 << endl << endl;
//            xm = i;
//        }
////        else
////        if((I[i].x*I[i].y) == A)
////        {
////            if(I[i].h>H)
////            {
////                H = I[i].h;
////                xm = i;
////            }
////        }
//
//    }
//    x = xm;
//    I[xm].h = 0;
//    cout << "xm = " << xm+1 << " V= " << V << endl;
//
//
////        if((I[i].h > I[xm].h))  // i = 1 - Так как мы предположили что х - первый элемент - максимальный   || (I[i].x < lasty)       || ((I[i].x<lasty) && (I[i].y<lastx))
////            xm = i;
////    if(I[xm].x <= lastx && I[xm].y < lasty)
////    {
////        x = xm;
////        lastx = I[xm].x;
////        lasty = I[xm].y;
////    }
////    else
////        if(I[xm].x <= lasty && I[xm].y < lastx)
////        {
////            x = xm;
////            lastx = I[xm].y;
////            lasty = I[xm].x;
////        }
////    else I[xm].h = 0;
////
////    cout << "\nMaximal element " << xm << "(" << xm+1 << ")"<< endl;
////    cout << "\nlastX " << lastx << " lastY " << lasty << endl;
//
//
//
//
//
//
////        cout << "I\'ve selected " << x << " element x - " << I[x].x << " y - " << I[x].y << endl;
////        cout << "\nlastX = " << lastx << " lastY = " << lasty << endl;
//}









//void SelectElement(int &x)
//{
//    int xm = 0;
//
//    for(int i=1; i<n; i++)
//        if((I[i].h > I[xm].h) && (I[i].x <= lastx) && (I[i].y <= lasty) )  // i = 1 - Так как мы предположили что х - первый элемент - максимальный   || (I[i].x < lasty)       || ((I[i].x<lasty) && (I[i].y<lastx))
//        {
//            xm = i;
//            lastx = I[xm].x;
//            lasty = I[xm].y;
//        }
//        else if((I[i].h > I[xm].h) && (I[i].x <= lasty) && (I[i].y <= lastx) )
//        {
//            xm = i;
//            lastx = I[xm].y;
//            lasty = I[xm].x;
//        }
//    x = xm;
//        cout << "I\'ve selected " << x << " element x - " << I[x].x << " y - " << I[x].y << endl;
//        cout << "\nlastX = " << lastx << " lastY = " << lasty << endl;
//}

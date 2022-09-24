#include<iostream>
#include <limits.h>

using namespace std;

struct Tree
{
    int info;
    Tree *left, *right;
}*T;

Tree *CreateTree()
{
    Tree *r;
    int ch;
    cout<<"Input info"<<endl;
    cin>>ch;
    if(ch==0) //Â òîì ñëó÷âàå, åñëè ïîòîìîê == NULL
        return NULL;
    else
    {
        r=new Tree;
        r->info = ch;
        cout<<"Input the left child of "<<ch<<": ";
        r->left=CreateTree();
        cout<<"Input the right child of "<<ch<<": ";
        r->right=CreateTree();
        return r;
    }
}

void MaximalElement(Tree *T, int &m)
{
    if (T!=NULL)
    {
        if( ((T->left == NULL) and (T->right == NULL)) and (T->info > m) )
        {
            m = T->info;
        }

        MaximalElement(T->left, m);
        MaximalElement(T->right, m);
    }
}

void NumbMax(Tree *T, int M, int &I)
{
    if (T!=NULL)
    {
        if( ((T->left == NULL) and (T->right == NULL)) and (T->info ==  M) )
        {
            I++;
        }

        NumbMax(T->left, M, I);
        NumbMax(T->right, M, I);
    }
}

void MinimalElement(Tree *T, int &minimum)
{
    if(T != NULL)
    {
        if((T->info < minimum)&&( (T->left == NULL) and (T->right == NULL))) minimum = T->info;

        MinimalElement(T->left, minimum);
        MinimalElement(T->right, minimum);
    }
}

void NumbOfMinimal(Tree *T, int minimum, int &I)
{
    if(T!=NULL)
    {
        if((T->info == minimum)&&( (T->left == NULL) and (T->right == NULL))) I++;

        NumbOfMinimal(T->left, minimum, I);
        NumbOfMinimal(T->right, minimum, I);
    }
}

void ShowTree(Tree *T, int level)
{

    if(T!=NULL)
    {
        ShowTree(T->left, level+1);
        for(int i=0; i<level; i++)
            cout<<"        ";
        cout<<T->info <<endl << endl;
        ShowTree(T->right, level+1);
    }
}

void LavelsOfTree(Tree *T, int level, int &I)
{
    if(T!=NULL)
    {
        if(level>I)
        I = level;
        LavelsOfTree(T->left, level+1, I);
        LavelsOfTree(T->right, level+1, I);
    }
}

/*
void LavelsOfTree(Tree *T, int level, int &I)
{
    if(T!=NULL)
    {
        level++;
        if(level>I)
        I = level;
        LavelsOfTree(T->left, level, I);
        LavelsOfTree(T->right, level, I);
    }
}
*/


int main()
{
    int i = 0;
    int ch;
    int maximal = INT_MIN;
    int minimal = INT_MAX;
    do
    {
        cout << "\n0.Exit;" << endl;
        cout << "1.Create a tree;" << endl;
        cout << "2.Print tree's leaf maximal value and the number of leafs, which contain this value;" << endl;
        cout << "3.Print tree's leaf minimal value and the number of leafs, which contain this value (it can be equal to 0);" << endl;
        cout << "4.Print number of tree's levels." << endl;
        cout << ">> ";
        cin >> ch;
        cout << endl;

    switch(ch)
        {
        case 1:
            {
                cout<<"Input nodes of tree. To finish input - input 0"<<endl;
                T=CreateTree();
                cout << endl;
                ShowTree(T,0);
                break;
            }

        case 2:
            {
                i = 0;
                MaximalElement(T, maximal);
                NumbMax(T, maximal, i);
                cout << "Maximal element - " << maximal << "; It can be meted " << i << " times..." << endl;
                break;
            }
        case 3:
            {
                i = 0;
                MinimalElement(T, minimal);
                NumbOfMinimal(T, minimal, i);
                cout << "Minimal element - " << minimal << "; It can be meted " << i << " times..." << endl;
                break;
            }
        case 4:
            {
                int lev = 0;
                LavelsOfTree(T, lev, i);
                cout << "This tree has " << i << "(" << i+1 << ") levels." << endl;
                break;
            }
        case 0:
            {
                cout << "Thank you for using!!!" << endl;
                break;
            }
        }
    }
    while(ch != 0);


    return 0;
}


//1 35 68 42 0 28 0 0 25 0 78 85 0 0 0 64 57 0 33 0 0 0 - for test
//1 35 68 42 0 28 0 0 25 0 78 85 12 0 6 0 0 0 0 64 57 0 33 0 0 0 - for test

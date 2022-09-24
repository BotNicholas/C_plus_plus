#include <iostream>
using namespace std;

struct List
{
    int info;
    List *next;
};

void CreateList(List *&bg)
{
    int i=1;
    List *cr, *prv;
    cout << "\nInput List elements. 666 - to finish)" << endl;
    do
    {
        cr = new List;
        cout << i++ << "\'st element: ";
        cin >> cr->info;
        cr->next = NULL;
        if(bg==NULL)
            bg = cr;
        else if(cr->info != 666)
            prv->next = cr;

        prv = cr;
    }
    while(cr->info!=666);
}

void ShowList(List *bg, int i)
{
    List *cr = bg;
    if(bg==NULL)
        cout << "\nThe list is empty!!!!!" << endl;
    else
    {
        cout << "\nThe " << i << "\'st List elements: " << endl;

        while(cr!=NULL)
        {
            cout << cr->info << " ";
            cr = cr->next;
        }
    }
    cout << endl;
}

void CompareLists(List *&list1, List *&list2)
{
    List *cr, *prv;
    List *cr2, *prv2;
    int len1=0, len2=0;
    bool TheyAreSimilar = true;

    cr = list1;
    cr2 = list2;

    if(list1==NULL)
        cout << "\nList 1 is empty!!!" << endl;
    else if(list2==NULL)
        cout << "\nList 2 is empty!!!" << endl;
    else
    {
        while(cr!=NULL)
        {
            len1++;
            cr=cr->next;
        }

        while(cr2!=NULL)
        {

            len2++;
            cr2=cr2->next;
        }

        if(len1!=len2)
            cout << "\nThis lists have different lengths!!!!!" << endl;
        else
        {
            cr = list1;
            cr2 = list2;

            while(cr!=NULL)
            {
                if(cr->info == cr2->info)
                    TheyAreSimilar = true;
                else
                {
                    TheyAreSimilar = false;
                    break;
                }

                cr = cr->next;
                cr2 = cr2->next;
            }

            if(TheyAreSimilar) cout << "\nThis Lists are similar!!!!!" << endl;
            else cout << "\nThis lists are not similar!!!!!!" << endl;

        }
    }

}

int main()
{
    List *L1, *L2; //like *bg1, *bg2
    L1 = NULL;
    L2 = NULL;

    CreateList(L1);
    CreateList(L2);

    int i=1;

    ShowList(L1, i);
    i++;
    ShowList(L2, i);

    CompareLists(L1, L2);

}

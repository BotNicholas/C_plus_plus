#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
using namespace std;

struct List
{
    char surname[20];
    int age;
    char number[10];
    List *next;
};

int pn = 10;

List* Create()
{
    int i=0;
    List *bg, *cr, *prv;

    bg = NULL;

    do
    {
        cout<<endl;
        cr = new List;
        cout << i+1 << "'th person's surname: ";
        cin >> cr->surname;
        cout << i+1 << "'th person's age: ";
        cin >> cr->age;
        cout << i+1 << "'th person's phone number: ";
        cin >> cr->number;

        cr->next = NULL; //cr->next = nullptr;

        if(bg==NULL)
            bg = cr;
        else
            prv->next = cr;
        prv = cr;
        i++;
    }
    while(i<pn);
    cout << endl;
    return bg;
}

void Show(List* bg)
{
    List *cr;
    int i=0;

    cr = bg;
    if(bg==NULL)
        cout << "\nList is empty!!!"<< endl;
    else
        while(cr!=NULL)
        {
            cout << i+1 << "'s person surname: " << cr->surname << endl << i+1 << "'s person age: " << cr->age << endl << i+1 << "'s person Phone number: " << cr->number << endl << endl;
            cr = cr->next;
            i++;
        }
}

List* DeleteBySurname(List *bg)
{
    char SSurname[20];
    List *cr, *prv;
    int i=0;
    int j=0;

    if(bg==NULL)
        cout << "\nList is empty!!!"<< endl;
    else
    {
        cout << "Input surname to delete: ";
        cin >> SSurname;

        cr = bg;
        while(cr!=NULL)
        {
            if(!strcmp(SSurname, cr->surname))
                break;
            i++;
            cr = cr->next;
        }

        cr = bg;
        prv = bg;
        if(i==0)
        {
            bg = bg->next;
            delete cr;
            cout << "Deleting is successfull!!!" << endl;
        }
        else
        {
            while(cr!=NULL)
            {
                if(j==i)
                {
                    break;
                }
                //else
                prv = cr;
                cr = cr->next;
                j++;
            }
            if(cr==NULL)
                cout << "This list doesn't have such person!" <<endl;
            else
            {
                prv->next = cr->next;
                delete cr;
                cout << "Deleting is successfull!!!" << endl;
            }
        }
    }
    return bg;
}

void ShowFive(List* bg)
{
    int i=0;
    List *cr;

    cr = bg;

    if(bg==NULL)
        cout << "The list is empty!!!" << endl;
    else
        while(i<5)
        {
            cout << i+1 << "'s person surname: " << cr->surname << endl << i+1 << "'s person age: " << cr->age << endl << i+1 << "'s person Phone number: " << cr->number << endl << endl;
            cr = cr->next;
            i++;
        }
}

void ShowEvenPoz(List* bg)
{
    int i=1;
    List* cr;

    cr = bg;

    if(bg == NULL)
        cout << "The list is empty!!!" << endl;
    else
        while(cr!=NULL)
        {
            if(i%2 == 0)
                cout << i << "'s person surname: " << cr->surname << endl << i << "'s person age: " << cr->age << endl << i << "'s person Phone number: " << cr->number << endl << endl;
            cr = cr->next;
            i++;
        }
}

//------------------------------------

void ShowAdults(List* bg)
{
    int i=0;
    List *cr;
    bool is_more_twenty = false;

    cr = bg;

    if(bg==NULL)
        cout << "The list is empty!!!" << endl;
    else
        while(cr!=NULL)
        {
            if(cr->age > 20)
            {
                cout << i+1 << "'s person surname: " << cr->surname << endl << i+1 << "'s person age: " << cr->age << endl << i+1 << "'s person Phone number: " << cr->number << endl << endl;
                is_more_twenty = true;
            }
            cr = cr->next;
            i++;
        }

    if(!is_more_twenty)
        cout << "There aren't persons? whose age is >20!!!" << endl;
}


int FindID(List* bg)
{
    char surname_to_find[20];
    List *cr;
    int i=0;
    bool P_is_found = false;

    cr=bg;

    if(bg==NULL)
        cout << "The list is empty!!!" << endl;
    else
    {
        cout << "Input Surname to find: ";
        cin >> surname_to_find;

        while(cr!=NULL)
        {
            if(!strcmp(surname_to_find, cr->surname))
            {
                P_is_found = true;
                cout << surname_to_find << "'s ID = " << i+1 << endl;
                return i;
            }
            i++;
            cr=cr->next;
        }

        if(!P_is_found)
        cout << "Such person doesn't exist!!!" << endl;
    }
    return 0;
}


int main()
{
    List *L1 = NULL;
    int ch;
    int P_ID;

    do
    {
        system("cls");

        cout << "0.Exit" << endl;
        cout << "1.Create a list for 10 persons" << endl;
        cout << "2.Show a list" << endl;
        cout << "3.Delete person by surname" << endl;
        cout << "4.Show first 5 list elements" << endl;
        cout << "5.Show even List elements" << endl;
        cout << "6.Show person's surnames, whose age >20" << endl;
        cout << "7.Show person's ID, by entering surname" << endl;

        cout << "Make a choice: ";
        cin >> ch;

        system("cls");

        switch(ch)
        {
        case 1:
        {
            L1 = Create();
            system("pause");
            break;
        }
        case 2:
        {
            Show(L1);
            system("pause");
            break;
        }
        case 3:
        {
            L1 = DeleteBySurname(L1);
            system("pause");
            break;
        }
        case 4:
        {
            ShowFive(L1);
            system("pause");
            break;
        }
        case 5:
        {
            ShowEvenPoz(L1);
            system("pause");
            break;
        }
        case 6:
        {
            ShowAdults(L1);
            system("pause");
            break;
        }
        case 7:
        {
            P_ID = FindID(L1);
            system("pause");
            break;
        }
        case 0:
        {
            cout << "\nThanks for using!!! " << endl;
            system("pause");
            break;
        }
        }

    }
    while(ch!=0);

    return 0;
}

#include <iostream>
#include <cstdlib>
using namespace std;

struct Stack
{
    int reg_n;
    string station;
    int year;
    string carriages_type;
    float carrying;

    string owner_Name;
    string owner_Surname;
    string owner_Father_name;
    string owner_Adres;
    string owner_Phone_n;

    Stack *prv;
};

int i=0;

void AddElement(Stack **S) // or Stack &*S
{
    Stack *cr = new Stack;

    cout << "Input " << i+1 << "'th carriage's registration number: ";
    cin >> cr->reg_n;
    cout << "Input " << i+1 << "'th carriage's registration station: ";
    cin >> cr->station;
    do
    {
        cout << "Input " << i+1 << "'th carriage's building year: ";
        cin >> cr->year;
    } while(cr->year < 1960 || cr->year > 2000);//while(!(cr->year >= 1960 && cr->year <= 2000)); //  or while(cr->year < 1960 || cr->year > 2000);

    cout << "Input " << i+1 << "'th carriage's type: ";
    cin >> cr->carriages_type;
    cout << "Input " << i+1 << "'th carriage's carrying: ";
    cin >> cr->carrying;

    cout << "\tInput info about carriage's owner: " << endl;

    cout << "Input " << i+1 << "'th carriage's owner name: ";
    cin >> cr->owner_Name;
    cout << "Input " << i+1 << "'th carriage's owner surname: ";
    cin >> cr->owner_Surname;
    cout << "Input " << i+1 << "'th carriage's owner father name: ";
    cin >> cr->owner_Father_name;
    cout << "Input " << i+1 << "'th carriage's owner adres: ";
    cin >> cr->owner_Adres;
    cout << "Input " << i+1 << "'th carriage's owner phone number: ";
    cin >> cr->owner_Phone_n;

    i++;

    /*
    if(*S==NULL)
        *S=cr;
    */

    cr->prv = *S;
    *S = cr;
}

void Show(Stack *S)
{
    int j=i;
    Stack *cr = S;
    if(S==NULL)
        cout << "Stack is empty!!!!" << endl;
    else
        while(cr!=NULL)
        {
            cout << "\tInfo about " << j << "'th carriage: " << endl;
            cout << j << "'th carriage's registration number: " << cr->reg_n << endl;
            cout << j << "'th carriage's registration station: " << cr->station << endl;
            cout << j << "'th carriage's building year: " << cr->year << endl;
            cout << j << "'th carriage's type: " << cr->carriages_type << endl;
            cout << j << "'th carriage's carrying: " << cr->carrying << endl;

            cout << "\n\tInfo about " << j << "'th carriage's owner: " << endl;

            cout << j << "'th carriage's owner name: " << cr->owner_Name << endl;
            cout << j << "'th carriage's owner surname: " << cr->owner_Surname << endl;
            cout << j << "'th carriage's owner father name: " << cr->owner_Father_name << endl;
            cout << j << "'th carriage's owner adres: " << cr->owner_Adres << endl;
            cout << j << "'th carriage's owner phone number: " << cr->owner_Phone_n << endl << endl;

            cout << "-------------------------------------------------------------" << endl << endl;


            j--;
            cr = cr->prv;
        }
}


void DeleteElement(Stack &*S) // ÷òîáû ïîòîì íå ïèñàòü *S... Òåæå ñàìûå ññûëêè, íî íå ñ ïåðåìåííûìè, à ñ óêàçàòåëÿìè........
{
    Stack *cr = S;
    if(S==NULL)
        cout << "Stack is empty!!!!!" << endl;
    else
    {
        S=S->prv;
        delete cr;
        i--;
        cout << "The element has been deleted successfully!!!" << endl;
    }
}


int main()
{
    Stack *S1=NULL;
    int ans;

    do
    {
        system("cls");
        cout << "0.Exit;" << endl;
        cout << "1.Add a carriage (add to end);" << endl;
        cout << "2.Delete a carriage (delete the last one);" << endl;
        cout << "3.Show." << endl;
        cout << ">> ";
        cin >> ans;

        switch(ans)
        {
        case 0:
        {
            system("cls");
            cout << "Thank you for using!!!" << endl;
            system("pause");
            break;
        }
        case 1:
        {
            AddElement(&S1);
            break;
        }
        case 2:
        {
            system("cls");
            DeleteElement(S1);
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            Show(S1);
            system("pause");
            break;
        }
        }
    }
    while(ans!=0);

    return 0;
}

#include <iostream>
#include <cstdlib>
using namespace std;

struct Queue
{
    char info;
    int priority;
    Queue *next;
}*first, *last;

int i=0;

void AddElement()
{
    Queue *cr = new Queue;
    Queue *cr2 = first;
    Queue *prv = first;
    i++;
    cout << "Input " << i << "'th queue's element info(a letter): ";
    cin >> cr->info;
    cout << "Input " << i << "'th queue's element priority: ";
    cin >> cr->priority;
    cr->next = NULL;

    if(first == NULL)
    {
        first = cr;
        last = cr;
    }
    else
    {
        while(cr2!=NULL)
        {
            if(cr2->priority > cr->priority) // òàê êàê èç âñåõ ýëåìåíòîâ ñ îäèíâêîâûì ïðèîðèòåòèì, íîâûé äîëæåí áûòü ïîñëåäíèì(ñðåäè ýëåìåíòîâ ñ òàêèì æå ïðèîðèòåòîì)
                break;
            prv = cr2;
            cr2 = cr2->next;
        }

        cr->next = cr2;
        prv->next = cr;

        /*
        last->next = cr;
        last = cr;
        */
    }
}

void Show()
{
    int j=1;
    Queue *cr = first; //Ñâÿçü ýëåìåíòîâ èéäåò îò ïåðâîãî ýëåìåíòà ê ïîñëåäíåìóÁ à íå îò ïîñëåäíåãî ê ïåðâîìó => Òû ïåðåáåðàåøü ýëåìåíòû íå ñ ïîñëåäíåãî, à ñ ïåðâîãî
    if(first == NULL)
        cout << "The queue is empty!!!!" << endl;
    else
    {
        while(cr!=NULL)
        {
            cout << j << "'st queue element's info: " << cr->info << endl;
            cout << j << "'st queue element's priority: " << cr->priority << endl;
            cr = cr->next;
            j++;
            cout << endl;
        }
    }

}

void ExtractElement()
{
    Queue *cr = first;
    if(first == NULL)
        cout << "The queue is empty!!!" << endl;
    else
    {
        first = first->next;
        delete cr;
        i--;
        cout << "The element has been deleted successfully!!!!" << endl;
    }
}



int main()
{
    first = NULL;

    int ans;

    do
    {
        system("cls");
        cout << "0.Exit;" << endl;
       // cout << "1.Create a queue;" << endl;
        cout << "1.Add an element in the queue;" << endl;
        cout << "2.Delete an element from queue;" << endl;
        cout << "3.Show queue's elements." << endl;
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
            system("cls");
            AddElement();
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            ExtractElement();
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            Show();
            system("pause");
            break;
        }
        }

    }
    while(ans!=0);
    return 0;
}

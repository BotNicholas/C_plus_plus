//v eilerovom cicle cislo reber == razmeru grafa, i cajdaia stepeni rebra cetnaia =>
#include <iostream>
using namespace std;

const int n = 5;

bool IsEiler(int A[n][n], int *N, int s)
{
    if(s<=n) return false;


    //Delaiu copiiu, tak kak budu obnuliati dalee
    int B[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            B[i][j] = A[i][j];


    //proveriaiu, sviazani li oni drig s drugom
    for(int i=0; i<s-1; i++)
        if((A[N[i]][N[i+1]] != 1) || (A[N[i]][N[i+1]] == 1 && N[i]==N[i+2])) //tak kak v matritse smeznosti i stroki i stolbci otveciaiut za tocki, to peresecenie etih tocek pokazivaiet, esti li mezdu nimi sviazi. Naprimer esli hociu proveriti sviazi mezdu 2 i 5 vershinami, to takoi zapiriu ia viberaiu 2-iu stroku (t.e. 2-iu tociku) i smotriu sviazana li ona s 5-i tocikoi (to esti eto A[2][5]). (to ze samoie esli prosmatrivati ne po strokam i stoldtam, a po stolbtsam i strokam)
            return false;



        int Gsize = 0;
        int angles = 0;

    //dlia togo, citobi poscitati razmer grafa mne nado poscitati cislo sviazei dlia kajdogo uzla, to esti idti "kvadratom" (ot tocki 0,0 (a,a/b,b/c,c...) vniz/vpravo <- takim obrazom ia poscitaiu cislo reber "othodiashih ot vershini a,a/b,b/c,c...")
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            Gsize+=A[i][j];


    //cout << "Graph size = " << Gsize << endl;


    //scitaiu cislo reber v zadannoi posledovatelnost vershin
    for(int i=0; i<s-1; i++)
        if((A[N[i]][N[i+1]] != 1)) // esli mezdu etimi dvumia tockami esti sviazi, to v matrice smeznosti na ih peresecenii budet 1 => oni sviazani => esti rebro
        return false;
        else if(A[N[i]][N[i+1]] == 1) angles++;

        //cout << "Angles = " << angles << endl;

    if(angles!=Gsize) return false; // proveriaem esli cislo zadannih reber == razmeru grafa (tak kak v eilerivom cisle cislo reber == razmeru grafa)



    //proveriaiu riabra na povtori
    for(int i=0; i<s-1; i++) //posledniuiu ne proveriaiu, tak kak ne s cem ee sravnivati
    {
        //cout << endl << N[i] << " with " << N[i+1] << endl;
        //cout << endl << "B[N[i]][N[i+1]] = " << B[N[i]][N[i+1]] << endl;
        if((B[N[i]][N[i+1]] == 1)) //esti li sviazi mezdu etimi dvumia tocicami, i esli est, to obnuliaiu - to esti mi ih "prosmotreli"
            B[N[i]][N[i+1]] = 0;
        else return false; // inace, esli == 0, to eto oznaciaet, cito mi eshio raz prosmatrivaem uze prosmotrennoie rebro
    }

    //proveriaiu cicl li eto
    if(N[0] == N[s-1]) return true;
        else return false;

}

int main()
{

    int Amatr[n][n] = {{0, 1, 1, 1, 1},
                       {1, 0, 1, 1, 1},
                       {1, 1, 0, 1, 1},
                       {1, 1, 1, 0, 1},
                       {1, 1, 1, 1, 0}};

    int s;

    do
    {
        cout << "Input how many nodes you have: ";
        cin >> s;
    } while(s<=n);


    int Nods[s];

    cout << "\nInput ", s, " nodes: ";
    for(int i=0; i<s; i++)
    {
        cout << "Nods[" << i << "] = ";
        cin >> Nods[i];
    }

    cout << "\nThe Adjacency matrix: " << endl;
    for(int i=0; i<n; i++, cout << endl)
        for(int j=0; j<n; j++)
            cout << Amatr[i][j] << " ";


    cout << "\nThis way is a Eiler\'s cycle - " << boolalpha << IsEiler(Amatr, Nods, s) << endl;

    return 0;
}

//    int Amatr[n][n] = {{0, 1, 1, 0, 0, 1},
//                       {1, 0, 0, 0, 1, 1},
//                       {1, 0, 0, 1, 0, 1}, // [0][2] == 1 and [2][3] == 1 and [0][0] == 0 ili mozno bilo bi N[0] == N[s-1]
//                       {0, 0, 1, 0, 0, 0},
//                       {0, 1, 0, 0, 0, 1},
//                       {1, 1, 1, 0, 1, 0}};






//int Amatr[n][n] = {{0, 1, 1, 1, 1},
//                       {1, 0, 1, 1, 1},
//                       {1, 1, 0, 1, 1},
//                       {1, 1, 1, 0, 1},
//                       {1, 1, 1, 1, 0}};


#include <iostream>
//#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class Retea {
    int n;
    double p=rand()%10/100.0;
    int adiacenta[10][10];

public:
    Retea(int noduri) {
        n = noduri;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adiacenta[i][j] = 0;
    }

    void adaugaLegatura(int a, int b) {
        adiacenta[a][b] = 1;
        adiacenta[b][a] = 1;
    }

    void TrimitePachet(int sursa, int destinatie) {
        int vizitat[10] = {0};
        int parinte[10];
        int coada[10];
        int st = 0, dr = 0;

        for(int i = 0; i < n; i++)
            parinte[i] = -1;


        coada[dr++] = sursa;
        vizitat[sursa] = 1;

        while(st < dr) {
            int curent = coada[st++];

            if(curent == destinatie)
                break;

            for(int i = 0; i < n; i++) {
                if(adiacenta[curent][i] == 1 && !vizitat[i]) {
                    vizitat[i] = 1;
                    parinte[i] = curent;
                    coada[dr++] = i;
                }
            }
        }

        if(!vizitat[destinatie]) {
            cout << "Nu exista drum intre " << sursa << " si " << destinatie << endl;
            return;
        }


        int drum[10];
        int lungime = 0;
        int nod = destinatie;

        while(nod != -1) {
            drum[lungime++] = nod;
            nod = parinte[nod];
        }

        int pierderi=0;
        cout << "Pachet trimis pe ruta: ";
        for(int i = lungime - 1; i >= 0; i--) {
            cout << drum[i];
            if(i != 0) cout << " -> ";
            pierderi++;
        }
        cout << endl;
        cout<<"Pachetul a fost trimis cu pierderi de "<<ceil((1-pow(1-p, pierderi))*100)<<"%"<<endl;
    }




    void afiseaza() {
        for(int i = 0; i < n; i++) {
            cout << "Nodul " << i << " este conectat cu: ";
            for(int j = 0; j < n; j++)
                if(adiacenta[i][j] == 1) cout << j << " ";

            cout << endl;
        }
    }
};


int main() {

    srand(time(NULL));

    cout<<"=============================================Simulator de retea=============================================";
    cout<<endl;
    cout<<"Acest program simuleaza o retea de calculatoare, permitand crearea de noduri stergerea lor si transmiterea de date"<<endl;
    cout<<"Tastati 1 pentru a incepe sau 0 pentru a iesi:";
    int z;
    cin>>z;
    for (int i=0;i<50;i++)
        cout<<endl;
    switch (z) {
        case 1:{
            int x;
            cout<<"Introduceti numarul de noduri:";
            cin>>x;
            cout<<endl;
            Retea *retea = new Retea(x);

            while(true) {
                for (int i=0;i<50;i++)
                    cout<<endl;
                cout<<"Introducrti 1 pentru a crea legaturi"<<endl;
                cout<<"Introduceti 2 pentru a afisa legaturile"<<endl;
                cout<<"Introducrti 3 pentru a trimite pachet"<<endl;
                cout<<"Introducrti 4 pentru a iesi"<<endl;

                int y;

                cin>>y;

                switch (y) {
                    case 1:
                        for (int i = 0; i < 50; i++)
                            cout << endl;

                        int x1, x2;

                        cout << "Pentru a crea un nod introduceti doua adrese strict mai mici de "
                             << x << " si mai mari sau egale cu 0\n";
                        cout << "Pentru a iesi tastati -1 -1\n";

                        while (true) {
                            cin >> x1 >> x2;

                            if (x1 == -1 && x2 == -1)
                                break;

                            if (x1 < 0 || x2 < 0 || x1 >= x || x2 >= x || x1 == x2) {
                                cout << "Eroare: Valoarea introdusa nu poate fi nod. Incercati din nou.\n";
                                continue;
                            }

                            retea->adaugaLegatura(x1, x2);
                    }
                        break;

                    case 2:
                        for (int i=0;i<50;i++)
                            cout<<endl;
                        int ex;
                        cout<<"Legaturile create sunt:"<<endl;
                        retea -> afiseaza();
                        cout<<endl;
                        cout<<"Pentru a iesi tastati orice valoare";
                        cin>>ex;
                        break;
                    case 3:
                        for (int i=0;i<50;i++)
                            cout<<endl;
                        cout<<"Pentru a trimite un pachet introduceti sursa si destinatorul\n";
                        A:
                        cout<<"Sursa:";
                        int sursa, destinator;
                        cin>>sursa;
                        cout<<"Introduceti destinatorul:";
                        cin>>destinator;
                        cout<<endl;
                        retea -> TrimitePachet(sursa,destinator);
                        cout<<endl;
                        cout<<"Pentru a trimite un alt pachet introduce 1 in caz contrar reveniti la programul principal:";
                        cin>>ex;
                        if (ex==1) goto A;
                        else break;

                    case 4:
                        return 2;
                }
                }
            }
        case 0:
            return 1;

    }

    // Retea r(6);
    //
    // r.adaugaLegatura(0,1);
    // r.adaugaLegatura(1,2);
    // r.adaugaLegatura(1,3);
    // r.adaugaLegatura(2,3);
    // r.adaugaLegatura(3,4);
    // r.adaugaLegatura(4,5);
    //
    // r.TrimitePachet(0,2);

    return 0;
}

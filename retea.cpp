#include <iostream>
//#include <cstdlib>
#include <ctime>
#include <cmath>
#include "ReteaC.h"
#include <windows.h>

using namespace std;

void loading() {
    cout << "Loading";
    for(int i = 0; i < 5; i++) {
        Sleep(500);
        cout << "\rLoading\a";
        for(int j = 0; j <= i; j++)
            cout << ".";
        cout.flush();
    }
    cout << endl;
}

int main() {

    srand(time(NULL));

    cout<<"=============================================Simulator de retea=============================================";
    cout<<endl;
    cout<<"Acest program simuleaza o retea de calculatoare, permitand crearea de noduri stergerea lor si transmiterea de date"<<endl;
    cout<<"Tastati 1 pentru a incepe sau 0 pentru a iesi:";
    int z;
    cin>>z;
    loading();
    for (int i=0;i<50;i++)
        cout<<endl;
    switch (z) {
        case 1:{
            int x;
            cout<<"Introduceti numarul de noduri:";
            cin>>x;
            cout<<endl;
            ReteaC retea(x);

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
                        cout << "Pentru a iesi tastati 0 0\n";

                        while (true) {
                            cin >> x1 >> x2;

                            if (x1 == 0 && x2 == 0)
                                break;

                            if (x1 < 0 || x2 < 0 || x1 >= x || x2 >= x || x1 == x2) {
                                cout << "Eroare: Valoarea introdusa nu poate fi nod. Incercati din nou.\n";
                                continue;
                            }

                            retea.verificare(x1,x2);
                            retea.adaugaLegatura(x1, x2);
                    }
                        break;
                    case 2:
                        for (int i=0;i<50;i++)
                            cout<<endl;
                        int ex;
                        cout<<"Legaturile create sunt:"<<endl;
                        retea.afiseaza();
                        cout<<endl;
                        cout<<"Pentru a sterge legaturi introduceti 1 in caz contrar introduceti 0 sa iesiti\n"
                              "Daca alegeti sa stergeti introduceti cele doua noduri pe care doriti sa le stergeti, spre exemplu 0 1.\nDaca nodul exista veti primi un mesaj de confirmare in caz contrar eroare"<<endl;
                        cin>>ex;
                        while (ex!=0) {
                            int a,b;
                            cin>>a>>b;
                            retea.stergereNod(a,b);
                            retea.afiseaza();
                            cout<<"Daca mai doriti sa stergeti un nod introduceti 1, in caz contrar pentru a iesi inttroduceti 0:";
                            cin>>ex;
                        }
                        break;
                    case 3:
                        for (int i=0;i<50;i++)
                            cout<<endl;
                        cout<<"Pentru a trimite un pachet introduceti sursa si destinatorul\n";
                        int sursa, destinator;
                        do {
                            cout<<"Sursa:";
                            cin>>sursa;
                            cout<<"Introduceti destinatorul:";
                            cin>>destinator;

                            if(sursa < 0 || destinator < 0 || sursa >= x || destinator >= x) {
                                cout << "Adrese invalide!\n";
                                ex=1;
                                continue;
                            }

                            cout<<endl;
                            retea.TrimitePachet(sursa,destinator);
                            cout<<endl;
                            cout<<"Pentru a trimite un alt pachet introduce 1 in caz contrar introduceti orice valoare pentru\na reveni la programul principal:";
                            cin>>ex;
                        }while(ex==1);
                        break;

                    case 4:
                        return 2;
                }
                }
            }
        case 0:
            return 1;

    }



    return 0;
}

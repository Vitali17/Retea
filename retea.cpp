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

    cout<<"==============Simulator de retea==============";
    cout<<endl;
    int x;
    cout<<"Introduceti numarul de noduri:";
    cin>>x;
    cout<<endl;
    Retea *retea = new Retea(x);

    while(true) {

        cout<<"Introducrti 1 pentru a crea legaturi"<<endl;
        cout<<"Introduceti 2 pentru a afisa legaturile"<<endl;
        cout<<"Introducrti 3 pentru a trimite pachet"<<endl;

        int y;

        cin>>y;

        switch (y) {
            case 1:
                int x1,x2;
                cout<<"Pentru a crea un nod introduceti doua adrese care sa fie strict mai mici de "<<x<<" si mai mari sau egal cu 0";
                cout<<endl;
                cout<<"Pentru a iesi tastati -1 -1"<<endl;
                cin>>x1>>x2;
                while (x1 >= 0 && x2>=0) {
                    retea->adaugaLegatura(x1,x2);
                    A:
                    cin>>x1>>x2;
                    if (x1>=x || x2>=x) {
                        cout<<"Eroare: Valoarea introdusa nu poate fi nod introduceti alta valoare";
                        cout<<endl;
                        goto A;
                    }
                }
                break;
            case 2:
                retea -> afiseaza();
                break;
        }

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

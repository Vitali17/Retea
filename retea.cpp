#include <iostream>
using namespace std;

class Retea {
    int n;
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

        cout << "Pachet trimis pe ruta: ";
        for(int i = lungime - 1; i >= 0; i--) {
            cout << drum[i];
            if(i != 0) cout << " -> ";
        }
        cout << endl;
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
    Retea r(6);

    r.adaugaLegatura(0,1);
    r.adaugaLegatura(1,2);
    r.adaugaLegatura(1,3);
    r.adaugaLegatura(2,3);
    r.adaugaLegatura(3,4);
    r.adaugaLegatura(4,5);

    r.TrimitePachet(0,5);

    return 0;
}

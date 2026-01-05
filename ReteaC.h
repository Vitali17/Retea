
#ifndef C___RETEAC_H
#define C___RETEAC_H

#include <windows.h>

class ReteaC {
    int n;
    double p=rand()%10/100.0;
    int adiacenta[10][10];

public:
    ReteaC(int noduri) {
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
            std::cout << "Nu exista drum intre " << sursa << " si " << destinatie << std::endl;
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
        std::cout << "Pachet trimis pe ruta: ";
        for(int i = lungime - 1; i >= 0; i--) {
            std::cout << drum[i];
            if(i != 0) std::cout << " -> ";
            pierderi++;
        }
        std::cout << std::endl;
        std::cout<<"Pachetul a fost trimis cu pierderi de "<<ceil((1-pow(1-p, pierderi))*100)<<"%"<<std::endl;
    }




    void afiseaza() {
        for(int i = 0; i < n; i++) {
            std::cout << "Nodul " << i << " este conectat cu: ";
            for(int j = 0; j < n; j++)
                if(adiacenta[i][j] == 1) std::cout << j << " ";

            std::cout << std::endl;
        }
    }

    void verificare(int nod1, int nod2) {
        if (adiacenta[nod1][nod2]==1 || adiacenta[nod2][nod1]==1) std::cout<<"Exista nodul "<<nod1<<"-->"<<nod2<<std::endl;
    }

    void stergereNod(int nod1, int nod2) {
        if (adiacenta[nod1][nod2]==1 || adiacenta[nod2][nod1]==1) {
            std::cout << "Nodul "<<nod1<<"-->"<<nod2<<" urmeaza sa fie sters\n";
            Sleep(2000);
            std::cout << "Nodul a fost sters\n\n";
            adiacenta[nod2][nod1]=0;
            adiacenta[nod1][nod2]=0;
        }
        else std::cout<<"Eroare:Nodul nu exista\n\n";
    }
};


#endif //C___RETEAC_H

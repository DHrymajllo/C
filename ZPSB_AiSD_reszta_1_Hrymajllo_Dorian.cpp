#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void reszta_obl(int reszta, int* nominaly, int* tab, int* jaki_nom, int ilosc_nom){
    for(int i=0; i < ilosc_nom; i++){
        for(int j=0; j < reszta; j++){
            if(tab[j]!=INT_MAX){
                int nowa_reszta = j + nominaly[i];
                int nowa_ilosc = tab[j]+1;
                if((nowa_reszta <= reszta) && (nowa_ilosc < tab[nowa_reszta])){
                    tab[nowa_reszta] = nowa_ilosc;
                    jaki_nom[nowa_reszta]=nominaly[i];
                }
            }
        }
    }
    if(tab[reszta]==INT_MAX){
        cout << "\nNie da sie wyplacic kwoty !" << endl;
    }
    else{
        int tmp_reszta=reszta;
        cout << "\nUzyte nominaly: " << endl;
        while(tmp_reszta!=0){
            int ileRazy = tmp_reszta / jaki_nom[tmp_reszta];
            cout << jaki_nom[tmp_reszta] << " zl: " << "x" << ileRazy << endl;
            tmp_reszta-=ileRazy * jaki_nom[tmp_reszta];
        }
        cout << "\nLiczba wykorzystanych monet: " << tab[reszta] << endl;
    }
}

int main(){
    int reszta, ilosc;
    cout << "Reszta do wydania: ";
    cin >> reszta;
    while(reszta <= 0){
        cout << "Reszta nie moze byc (mniejsza niz/rowna) 0 !" << endl;
        cin >> reszta;
    }
    cout << "Podaj liczbe nominalow: ";
    cin >> ilosc;
    while(ilosc <= 0){
        cout << "Ilosc nie moze byc (mniejsza niz/rowna) 0 !" << endl;
        cin >> ilosc;
    }
    int* nominaly = new int [ilosc];
    int* jaki_nom = new int [reszta+1];
    int* tab = new int[reszta+1];
    for(int i=0; i<reszta+1; i++){tab[i]=INT_MAX;} tab[0]=0;
    for(int i=0; i<ilosc; i++){
        cout << "nominal " << i+1 << ": ";
        cin >> nominaly[i];
    }
    sort(nominaly, nominaly + ilosc);
    reszta_obl(reszta,nominaly,tab,jaki_nom,ilosc);
    return 0;
}

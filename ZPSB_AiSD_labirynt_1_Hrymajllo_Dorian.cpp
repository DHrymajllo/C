#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>

const int LabiryntSzerokosc = 15;
const int LabiryntWysokosc = 15;
const char Sciana = '#';
const char PrzestrzenWolna = ' ';
const char ZnakSciezki = '$';
COORD PunktStartowy;
COORD PunktKoncowy;


using namespace std;
char Labirynt[LabiryntWysokosc][LabiryntSzerokosc+1] = {
"######## ######",
"#             #",
"#### ##### ## #",
"# #   #    #  #",
"# # # ###### ##",
"# # #      # ##",
"# # # #### #  #",
"# # #   #  ## #",
"#   ###### ## #",
"# #     #     #",
"# ##### # ### #",
"#   #     #   #",
"# ### ####### #",
"#             #",
"###############",
};

void PokazSciezke(){
    for(int i = 0; i < LabiryntWysokosc; i++){
        for(int j = 0; j < LabiryntSzerokosc;j++){
            cout << Labirynt[i][j];
        }
        cout << endl;
    }
}
void Rozwiazanie(){
	Labirynt[PunktStartowy.Y][PunktStartowy.X] = ZnakSciezki;
    if(Labirynt[PunktStartowy.Y - 1][PunktStartowy.X] != Sciana && Labirynt[PunktStartowy.Y - 1][PunktStartowy.X ] != ZnakSciezki && PunktStartowy.Y > PunktKoncowy.Y){
        PunktStartowy.Y--;
    }
    else if(Labirynt[PunktStartowy.Y + 1][PunktStartowy.X] != Sciana && Labirynt[PunktStartowy.Y + 1][PunktStartowy.X ] != ZnakSciezki && PunktStartowy.Y < PunktKoncowy.Y){
	    PunktStartowy.Y++;
    }
	else if(Labirynt[PunktStartowy.Y][PunktStartowy.X - 1] != Sciana && Labirynt[PunktStartowy.Y][PunktStartowy.X - 1] != ZnakSciezki && PunktStartowy.X > PunktKoncowy.X){
        PunktStartowy.X--;
    }
    else if(Labirynt[PunktStartowy.Y][PunktStartowy.X + 1] != Sciana && Labirynt[PunktStartowy.Y][PunktStartowy.X + 1] != ZnakSciezki && PunktStartowy.X < PunktKoncowy.X){
    	PunktStartowy.X++;
    }
    else if(Labirynt[PunktStartowy.Y - 1][PunktStartowy.X] != Sciana && Labirynt[PunktStartowy.Y - 1][PunktStartowy.X ] != ZnakSciezki){
        PunktStartowy.Y--;
    }
    else if(Labirynt[PunktStartowy.Y + 1][PunktStartowy.X] != Sciana && Labirynt[PunktStartowy.Y + 1][PunktStartowy.X ] != ZnakSciezki){
	    PunktStartowy.Y++;
    }
    else if(Labirynt[PunktStartowy.Y][PunktStartowy.X - 1] != Sciana && Labirynt[PunktStartowy.Y][PunktStartowy.X - 1] != ZnakSciezki){
        PunktStartowy.X--;
    }
    else if(Labirynt[PunktStartowy.Y][PunktStartowy.X + 1] != Sciana && Labirynt[PunktStartowy.Y][PunktStartowy.X + 1] != ZnakSciezki){
    	PunktStartowy.X++;
    }
    Labirynt[PunktStartowy.Y][PunktStartowy.X] = ZnakSciezki;
}
int main(){
	PokazSciezke();
	cout << "\nPodaj wspolrzedne [WEJSCIA] X i Y: \n";
    do{
    cout << "X=";
	cin >> PunktStartowy.X;
	cout << "Y=";
	cin >> PunktStartowy.Y;
	if(Labirynt[PunktStartowy.Y][PunktStartowy.X] == Sciana){
        cout << "\nBledne wspolrzedne(Sciana)! Sprobuj jeszcze raz!" << endl;
        }
    }while(Labirynt[PunktStartowy.Y][PunktStartowy.X] == Sciana);
	cout << "\nPodaj wspolrzedne [WYJSCIA] X i Y: \n";
    do{
    cout << "X=";
	cin >> PunktKoncowy.X;
	cout << "Y=";
	cin >> PunktKoncowy.Y;
	if(Labirynt[PunktKoncowy.Y][PunktKoncowy.X] == Sciana){
        cout << "\nBledne wspolrzedne(Sciana)! Sprobuj jeszcze raz!" << endl;
        }
    }while(Labirynt[PunktKoncowy.Y][PunktKoncowy.X] == Sciana);
	const clock_t begin_time = clock();
	while(PunktStartowy.X != PunktKoncowy.X || PunktStartowy.Y != PunktKoncowy.Y){
        Rozwiazanie();
        system("CLS");
        PokazSciezke();
	}
        cout << "\n---------------------------------------------";
        cout << "\nCzas: " << float(clock()-begin_time)/CLOCKS_PER_SEC << " sek/milisek" << endl;
}

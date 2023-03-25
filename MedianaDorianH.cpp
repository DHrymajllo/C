#include <iostream>
#include <algorithm>
#include <windows.h>
#include <time.h>

using namespace std;

double mediana(double* tab, int n){
	sort(tab, tab + n);
	if (n % 2 == 0) {
		return (tab[n / 2 - 1] + tab[n / 2]) / 2;
	} else {
		return tab[(n - 1) / 2];
	}
}

int main(){
	int n, x, y;
	char w;
	cout << "Jak chcesz generowac tablice? a=Automatycznie | m=Manualnie" << endl;
	do{
	cout << "[a/m]: ";
	cin >> w;
	DWORD t1, t2; //Definicja zmiennych do liczenia czasu
    t1=GetTickCount(); // Rozpoczecie zliczania czasu po wpisaniu opcji wyboru wypelniania tablic(w)
    cout << endl;
    if(w=='a'){
    srand(time(NULL));
    cout << "Podaj ile elementow ma tablica\nn = ";
	cin >> n;
	cout << "Podaj przedzial\nod "<
	cin >> x;
	cout << "do ";
	cin >> y;
	double* tab = new double[n];
    cout << endl;
	cout << "Podaj elementy:\n";
    for(int i = 0; i < n; i++){
        tab[i]=x + rand()%(y - x + 1);
        cout << i+1 << " element: ";
        cout << tab[i] << endl;
    }
    cout << endl;
    sort(tab, tab + n);
    cout << "Tablica uporzadkowana: ";
    for(int i = 0; i < n; i++){
        cout << tab[i] << " ";
    }
    cout << endl;
	cout << "Mediana wynosi: " << mediana(tab, n) << endl;
	t2=GetTickCount() - t1;
    cout << "Czas wykonania algorytmu: " << t2 << "ms" << endl;
	return 0;
    }
    if(w=='m'){
	cout << "Podaj ile elementow ma tablica\nn = ";
	cin >> n;
	double* tab = new double[n];
    cout << endl;
	cout << "Podaj elementy:\n";
	for(int i = 0 ; i < n; i++){
        cout << i+1 << " element: ";
		cin >> tab[i];
    }
    cout << endl;
    sort(tab, tab + n);
    cout << "Tablica uporzadkowana: ";
    for(int i = 0; i < n; i++){
        cout << tab[i] << " ";
    }
    cout << endl;
	cout << "Mediana wynosi: " << mediana(tab, n) << endl;
    t2=GetTickCount() - t1; //Algorytm obliczajacy czas w ms
    cout << "Czas wykonania algorytmu: " << t2 << "ms" << endl; //Wyswietlenie czasu w ms
	return 0;
	}
	cout << "Tylko [a/m]! Sproboj jeszcze raz\n";
	}while(w != 'a' || w != 'm');
}

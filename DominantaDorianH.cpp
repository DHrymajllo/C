#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>
#include <algorithm>

using namespace std;

vector<double>dominanta1(double tab[], int n){
   int maks=0;
   int licz=0;
   int nowa;
   vector<double>dominanta;
   for(int i=0; i<n; i++){
      licz=0;
      for(int j=i+1; j<n; j++){
         if(tab[i]==tab[j])
            licz++;
      }
      if(licz>maks){
         dominanta.clear();
         maks=licz;
         dominanta.push_back(tab[i]);
      }
      if(licz == maks){
         for(int j=0;j<dominanta.size(); j++){
            nowa=1;
            if(dominanta.at(j) == tab[i]){
                nowa=0;
                break;
            }
         }
         if(nowa)
            dominanta.push_back(tab[i]);
      }
   }
   if(dominanta.size() == n)
      dominanta.clear();
   return dominanta;
}
int main(void){
	double tab[100];
	int n, x, y;
	char w;
	cout << "Jak chcesz generowac tablice? a=Automatycznie | m=Manualnie" << endl;
	do{
	cout << "[a/m]: ";
	cin >> w;
	DWORD t1, t2;
    t1=GetTickCount();
    cout << endl;
    srand(time(NULL));
    cout << "Podaj ile elementow ma tablica\nn = ";
	cin >> n;
    cout << endl;
    if(w=='a'){
        cout << "Podaj przedzial\nod "<
        cin >> x;
        cout << "do ";
        cin >> y;
    	cout << "Podaj elementy:\n";
    for(int i = 0; i < n; i++){
        tab[i]=x + rand()%(y - x + 1);
        cout << i+1 << " element: ";
        cout << tab[i] << endl;
     }
    }
    if(w=='m'){
        cout << "Podaj elementy:\n";
    for(int i = 0; i < n; i++){
        cout << i+1 << " element: ";
		cin >> tab[i];
     }
    }
    cout << endl;
    sort(tab, tab + n, greater < int >() );
    cout << "Tablica uporzadkowana: ";
    for(int i = 0; i < n; i++){
        cout << tab[i] << " ";
    }
    cout << endl;
    vector<double>dom=dominanta1(tab, n);
    cout << "Dominanta: ";
	for(int i = 0 ; i < dom.size(); i++){
        cout << dom.at(i) << " ";
    }
	cout << endl;
	t2=GetTickCount() - t1;
    cout << "Czas wykonania algorytmu: " << t2 << "ms" << endl;
	return 0;
	}while(w != 'a' || w != 'm');
}

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct osoba{
	string klucz;
	int brelok;
	osoba *wskaznik;
	osoba();
};

osoba::osoba(){
	wskaznik = 0;
}

struct wykaz{
	osoba *pierwszy;
	void insert(string klucz, int brelok, wykaz *dane);
	void usun(string klucz, wykaz *dane);
	int find(string klucz);
	void pokaz ();
	wykaz();
};


wykaz::wykaz(){
	pierwszy = 0;
}

void wykaz::pokaz(){
	osoba *t = pierwszy;
	while(t){
		cout << t->klucz << "(" << t->brelok << ")" << endl;
		t=t->wskaznik;
	}
}

int wykaz::find(string klucz){
	osoba *t = pierwszy;
	int prawda = 0;
	while (t){
		if(klucz == t->klucz){
			prawda = 1;
		}
		t=t->wskaznik;
	}
	return prawda;
}

void wykaz::usun (string klucz, wykaz *dane){
	if(dane->find(klucz) == 1){
		int nr, i = 1;
		osoba *t = pierwszy;
		while (t){
			if(klucz == t->klucz){
				nr = i;
			}
			t=t->wskaznik;
			i++;
		}

		if (nr==1){
			osoba *t = pierwszy;
			pierwszy = t->wskaznik;
			delete t;
		}

		else if (nr>=2)	{
			int j = 1;

			osoba *t = pierwszy;

			while (t){
				if ((j+1)==nr) break;

				t = t->wskaznik;
				j++;
			}

			if (t->wskaznik->wskaznik==0){
				delete t->wskaznik;
				t->wskaznik = 0;
			}
			else {
				osoba *deleted = t->wskaznik;
				t->wskaznik = t->wskaznik->wskaznik;
				delete deleted;
			}
		}
	}
	else{
		cout << "zmienna nie istnieje!" << endl;
	}
}

void wykaz::insert(string klucz, int brelok, wykaz *dane){
	if(dane->find(klucz) == 0){
		osoba *nowy = new osoba;
		nowy->klucz = klucz;
		nowy->brelok = brelok;

		if(pierwszy==0){
			pierwszy = nowy;
		}
		else{
			osoba *t = pierwszy;
			while (t->wskaznik){
				t = t->wskaznik;
			}

			t->wskaznik = nowy;
		}
	}
	else{
		cout << "zmienna juz istnieje" << endl;
	}
}



int main()
{
	wykaz *dane = new wykaz;
	cout << "----------------\n(nr) -> brelok\n----------------\n";
    srand(time(NULL));
    int brelok;
    brelok = rand()%(100-14+0);
	dane->insert("Dorian", brelok, dane);
	brelok++;
	dane->insert("Julia", brelok, dane);
    brelok++;
    dane->insert("xyz", brelok, dane);
    brelok++;
    dane->insert("zyx", brelok, dane);
    brelok++;
    dane->insert("yyx", brelok, dane);
    brelok++;
    dane->insert("yxz", brelok, dane);
    brelok++;
    dane->insert("yzx", brelok, dane);
    brelok++;
    dane->insert("xzy", brelok, dane);
    brelok++;
    dane->insert("xyy", brelok, dane);
    brelok++;
    dane->insert("xzz", brelok, dane);
    brelok++;
    dane->insert("zzx", brelok, dane);
    brelok++;
    dane->insert("zxy", brelok, dane);
    brelok++;
    dane->insert("Hrymajllo", brelok, dane);
    brelok++;
	dane->insert("Glazek", brelok, dane);
	brelok++;
	dane->pokaz();
    cout << "\n------------------------------------------\nWyszukiwanie elementow o kluczach znanych\n------------------------------------------\n";
	dane->find("Dorian");
    dane->find("Julia");
    dane->find("Hrymajllo");
    dane->find("Glazek");
	cout << "\n-----------------------------------------\nUsuwanie elementow z kluczami ustalonymi\n-----------------------------------------\n";
	dane->usun("Dorian", dane);
	dane->usun("Hrymajllo", dane);
	dane->usun("Julia", dane);
	dane->usun("Glazek", dane);
	dane->pokaz();
	return 0;
}

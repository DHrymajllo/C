#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void SprawdzeniePodzielnosci(int n)
{
    const clock_t begin_time = clock();
    int start, end, czas;
    start = time(NULL);
    int i,p,lp,g;
    bool t;
    lp = 0;
    p = 2;
    while(p <= n)
    {
        t = true;
        g = sqrt(p);
        for(i = 2; i <= g; i++)
            if(p % i == 0)
            {
                t = false;
                break;
            }

        if(t)
        {
            cout << p << " ";
            lp++;
        }
        p++;
    }
    cout << endl;
    cout << "\nCzas: " << float(clock()-begin_time)/CLOCKS_PER_SEC << " sek/milisek";
}

void SitoEratostenesa(int n)
{
    const clock_t begin_time = clock();
    int start, end, czas;
    start = time(NULL);
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++){
       if (prime[p])
          cout << p << " ";
    }
    cout << "\n\nCzas: " << float(clock()-begin_time)/CLOCKS_PER_SEC << " sek/milisek";
}

void SitoLiniowe(int n)
{
  const clock_t begin_time = clock();
  int start, end, czas;
  start = time(NULL);
  unsigned int i, p, q, x;
  bool * S;

  S = new bool [ n + 1 ];
  for( i = 2; i <= n; i++ ) S [ i ] = true;
  p = 2;
  while( p * p <= n )
  {
    q = p;
    while( p * q <= n )
    {
      x = p * q;
      while( x <= n )
      {
        S [ x ] = false;
        x *= p;
      }
      while( !S [ ++q ] );
    }
    while( !S [ ++p ] );
  }
  for( i = 2; i <= n; i++ ) if( S [ i ] ) cout << i << " ";
  cout << endl;
  delete [ ] S;
  cout << "\nCzas: " << float(clock()-begin_time)/CLOCKS_PER_SEC << " sek/milisek\n";
}

int main()
{
    int n;
    cout << "Podaj gorna granice: ";
    do{
    cin >> n;
    if(n<2){
    cout << "Granica musi byc wieksza od 1!: ";
    }
    }while(n<2);
    cout << endl;
    cout << "1.Sprawdzenie podzielnosci: \n";
    SprawdzeniePodzielnosci(n);
    cout << endl;
    cout << "---------------------------------------------\n";
    cout << "2.Sito Eratostenesa: \n";
    SitoEratostenesa(n);
    cout << endl;
    cout << "---------------------------------------------\n";
    cout << "3.Sito Liniowe: \n";
    SitoLiniowe(n);
    cout << "---------------------------------------------\n";
    return 0;
}

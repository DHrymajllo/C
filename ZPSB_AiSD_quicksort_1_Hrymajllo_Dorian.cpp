#include <algorithm>
#include <iostream>
#include <time.h>

using namespace std;

void quickSort(int a[], int size);
void quickSort(int a[], int left, int right);
void choosePivot(int a[], int left, int right);
int partition(int a[], int left, int right);
void print(const int a[], int left, int right);

int main(){
   int w; // 0/1 -> bool ma wieksza tendencje do krzaczenia sie...
   cout << "Czy tablica ma zostac wygenerowana losowo?" << endl;
   do{
   cout << "[1->Tak | 0->Nie]: ";
   cin >> w;
   }while(w<0 || w>1); // 0/1
   cout << endl;
   int n;
   cout << "Ile elementow ma zawierac tablica?" << endl;
   cout << "a[wielkosc]: ";
   cin >> n;
   int a[n];
   if(w==0){
   for (int i = 0; i < n; ++i){
        cout << "Element numer #" << i << ": ";
        cin >> a[i];
     }
   }
   else{
    srand(time(NULL));
    int X=-1000, Y=1000;
    for (int i = 0; i < n; ++i){
        a[i] = X + rand() % (Y - X + 1);
     }
   }
   cout << "----------------------------------------------\n"<
   cout << "Tablica do posortowania: \n";
   print(a, 0, n - 1);
   cout << endl;
   cout << "----------------------------------------------\n";
   quickSort(a, n);
   cout << "----------------------------------------------\n"<
   cout << "Posortowana tablica: \n";
   print(a, 0, n - 1);
   cout << "\n----------------------------------------------\n";
}

void quickSort(int a[], int size) {
   quickSort(a, 0, size - 1);
}

void quickSort(int a[], int left, int right) {
   if ((right - left) >= 1) {
      choosePivot(a, left, right);
      int pivotIndex = partition(a, left, right);
      quickSort(a, left, pivotIndex -  1);
      quickSort(a, pivotIndex + 1, right);
   }
}

void choosePivot(int a[], int left, int right) {
   int pivotIndex = (right + left) / 2;
   int temp;
   temp = a[pivotIndex];
   a[pivotIndex] = a[right];
   a[right] = temp;
}

int partition(int a[], int left, int right) {
   int zamiany=1, porownania=1;
   int pivot = a[right];
   int temp;
   int storeIndex = left;
   cout << "\nPiwot: " <<">" << pivot << "<" << endl;
   for (int i = left; i < right; ++i) {
      if (a[i] < pivot) {
         if (i != storeIndex) {
            print(a, left, right);
            temp = a[i];
            a[i] = a[storeIndex];
            a[storeIndex] = temp;
            cout << "|" << a[i] << "|" << "=>";
            cout << "|" << a[storeIndex] << "|";
            cout << endl;
         }
         ++storeIndex; ++zamiany; ++porownania;
      }
   }
    print(a, left, right);
    cout << "|" << a[storeIndex] << "|" << "=>";
    cout << "|" << a[storeIndex + 1, right] << "|";
    cout << endl;
   a[right] = a[storeIndex];
   a[storeIndex] = pivot;
   print(a, left, storeIndex - 1);
   cout << a[storeIndex] << " ";
   print(a, storeIndex + 1, right);
   cout << "|" << a[storeIndex] << "|";
    ++porownania;
   cout << endl;
   cout << "Zamian: " << zamiany << endl;
   cout << "Porownan: " << porownania << endl;
   return storeIndex;
}

void print(const int a[], int left, int right) {
   for (int i = left; i <= right; ++i) {
      cout << a[i] << " ";
    }
}

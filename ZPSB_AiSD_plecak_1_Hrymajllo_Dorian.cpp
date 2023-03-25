#include <bits/stdc++.h>
#include <windows.h>
#include <iostream>

using namespace std;

int n;
void Sort1(float* weight, float* price, int* amount, int* index2);
void Strategy1(int* index, float* weight2, float* price2, int* amount2, int n, float capacity);
void Sort2(float* weight, float* price, int* amount, int* index2);
void Strategy2(int* index, float* weight2, float* price2, int* amount2, int n, float capacity);
void Sort3(float* weight, float* price, int* amount, int* index2);
void Strategy3(int* index, float* weight2, float* price2, int* amount2, int n, float capacity);

int main() {
int i = 0;
float capacity;
cout << "Pojemnosc plecaka: ";
cin >> capacity;
cout << endl;
cout << "Ile masz przedmiotow?: ";
cin >> n;
cout << endl;
int* index = new int[n];
float* price2 = new float[n];
float* weight2 = new float[n];
int* amount2 = new int[n];
while(i < n){
cout << "Przedmiot " << i+1 << ": ";
index[i] = i+1;
cin >> price2[i] >> weight2[i] >> amount2[i];
i++;
}
Strategy1(index, weight2, price2, amount2, n, capacity);
Strategy2(index, weight2, price2, amount2, n, capacity);
Strategy3(index, weight2, price2, amount2, n, capacity);
system("pause");
return 0;
}

void Sort1(float* weight, float* price, int* amount, int* index2){
for(int i = 0; i < n - 1; i++) {
for(int j = 0; j < n - i - 1; j++){
if(price[j] <= price[j + 1]){
swap(weight[j], weight[j + 1]);
swap(price[j], price[j + 1]);
swap(amount[j], amount[j + 1]);
swap(index2[j], index2[j + 1]);
}}}
}

void Strategy1(int* index, float* weight2, float* price2, int* amount2, int n, float capacity) {
float wex = 0;
float prz = 0;
const clock_t begin_time = clock();
cout << "\n+++Strategia 1+++\n";
int* q = new int[n];
float* w = new float[n];
float* e = new float[n];
int* r = new int[n];
for(int i = 0; i < n; i++){
q[i] = index[i];
w[i] = price2[i];
e[i] = weight2[i];
r[i] = amount2[i];
}
Sort1(e, w, r, q);
cout << "-----------------\n";
for(int i = 0; i < n; i++) {
int Search = capacity / e[i];
if(Search > r[i]){
Search = r[i];
}
capacity -= Search * e[i];
wex += Search * w[i];
prz += Search * e[i];
if(capacity >= 0) {
cout << "|" << q[i] << "| ---> |" << Search << "|" << endl;
}
else{return;}
}
cout << "-----------------";
cout << "\nWartosc plecaka: " << wex;
cout << "\nPoziom upakowania: " << prz;
cout << "\nCzas: " << float(clock()-begin_time)/CLOCKS_PER_SEC << " sek/milisek" << endl;
}

void Sort2(float* weight, float* price, int* amount, int* index2){
for(int i = 0; i < n - 1; i++){
for(int j = 0; j < n - i - 1; j++){
if(weight[j] <= weight[j - 1]){
swap(weight[j], weight[j - 1]);
swap(price[j], price[j - 1]);
swap(amount[j], amount[j - 1]);
swap(index2[j], index2[j - 1]);
}}}
}

void Strategy2(int* index, float* weight2, float* price2, int* amount2, int n, float capacity) {
float wex = 0;
float prz = 0;
const clock_t begin_time = clock();
cout << "\n+++Strategia 2+++\n";
int* t = new int[n];
float* y = new float[n];
float* u = new float[n];
int* o = new int[n];
for(int i = 0; i < n; i++){
t[i] = index[i];
y[i] = price2[i];
u[i] = weight2[i];
o[i] = amount2[i];
}
Sort2(u, y, o, t);
cout << "-----------------\n";
for(int i = 0; i < n; i++){
int Search = capacity / u[i];
if (Search > o[i]){
Search = o[i];
}
capacity -= Search * u[i];
wex += Search * y[i];
prz += Search * u[i];
if(capacity >= 0){
cout << "|" << t[i] << "| ---> |" << Search << "|" << endl;
}
else{return;}
}
cout << "-----------------";
cout << "\nWartosc plecaka: " << wex;
cout << "\nPoziom upakowania: " << prz;
cout << "\nCzas: " << float(clock()-begin_time)/CLOCKS_PER_SEC << " sek/milisek" << endl;
}

void Sort3(float* weight, float* price, int* amount, int* index2){
for(int i = 0; i < n - 1; i++){
for(int j = 0; j < n - i - 1; j++){
if(price[j] / weight[j] <= price[j - 1] / weight[j + 1]){
swap(weight[j], weight[j + 1]);
swap(price[j], price[j + 1]);
swap(amount[j], amount[j + 1]);
swap(index2[j], index2[j + 1]);
}}}
}

void Strategy3(int* index, float* weight2, float* price2, int* amount2, int n, float capacity) {
float wex = 0;
float prz = 0;
const clock_t begin_time = clock();
cout << "\n+++Strategia 3+++\n";
int* p = new int[n];
float* a = new float[n];
float* s = new float[n];
int* d = new int[n];
for(int i = 0; i < n; i++){
p[i] = index[i];
a[i] = price2[i];
s[i] = weight2[i];
d[i] = amount2[i];
}
Sort3(s, a, d, p);
cout << "-----------------\n";
for(int i = 0; i < n; i++){
int Search = capacity / s[i];
if(Search > d[i]){
Search = d[i];
}
capacity -= Search * s[i];
wex += Search * a[i];
prz += Search * s[i];
if(capacity >= 0) {
cout << "|" << p[i] << "| ---> |" << Search << "|" << endl;
}
else{return;}
}
cout << "-----------------";
cout << "\nWartosc plecaka: " << wex;
cout << "\nPoziom upakowania: " << prz;
cout << "\nCzas: " << float(clock()-begin_time)/CLOCKS_PER_SEC << " sek/milisek\n\n";
}

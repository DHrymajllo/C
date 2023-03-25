#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	//----------------------//
    /**/double UfNoSc=0.5;/**/
    //----------------------//
	system("color 4");int rtg,pr1,i=0,wybor,fdgfghmmn=0;cout<<"Ile koszykow ? | rekom.4|: ";cin>> rtg; cout<<"Ile roznych produktow ? |rekom. 4|: "; cin>> pr1; string pro1[pr1];
    cout<<"Lista produktow: "<<"\n";do{cout<<"Produkt #"<< i+1 << ": ";cin>> pro1[i]; i++;
	}while(i<pr1);int od1,do1; cout<<"Ile produktow na koszyk?" <<"\n";cout<<"od: "; cin>>od1; cout<<"do: "; cin>> do1; int kop[rtg][do1]; int fgh, eest;
	srand(time(NULL)); int sert[rtg]; for(int i=0; i<rtg; i++){fgh=od1+rand()%(do1-od1+1); sert[i]=fgh; for(int j=0; j<sert[i]; j++){
    eest=0+rand()%((pr1-1)-0+1);;kop[i][j]=eest;}}cout<<"Czy wyswietlic liste towarow (1 - tak, 0 - nie)?: "; cin>> wybor; if(wybor==1){ int restc; for(int i=0; i<rtg; i++)
    {cout<<"Koszyk "<<i+1<< ": " <<"\n";for(int j=0;j<sert[i];j++){ restc=kop[i][j]; cout<<pro1[restc] << " ";} cout<<"\n";}}int vfh;int c1[pr1];int restc; for(int i=0; i<pr1; i++){
    vfh=0; for(int k=0;k<rtg; k++){for(int p=0; p<sert[k]; p++){restc=kop[k][p]; if(restc==i){ vfh++; break;}}} c1[i]=vfh;}
	cout<<"\nC1"<<"\n";for(int i=0; i<pr1; i++){if(c1[i]!=0){cout<<pro1[i] << "=" << c1[i] <<"\n";}}
	int hyit_h[pr1][pr1]; for(int i=0; i<pr1; i++){ hyit_h[i][i]=0;}bool jhhf=0; int restcL2; int restcL2gfseccc; int restcL2bvbd; int hyit_h_dcbfghoo=0; int hyit_h_fdfhbbb=1;
	for(hyit_h_dcbfghoo; hyit_h_dcbfghoo<pr1; hyit_h_dcbfghoo++){if(hyit_h_fdfhbbb >= pr1){ hyit_h_fdfhbbb=hyit_h_dcbfghoo+1; } for(hyit_h_fdfhbbb; hyit_h_fdfhbbb<pr1; hyit_h_fdfhbbb++){
    vfh=0;for(int i=0; i<rtg; i++){ jhhf=0; restcL2=-1; if(sert[i] >= 2){ for(int j=0; j<sert[i]; j++){ if(kop[i][j]==hyit_h_dcbfghoo && jhhf==0 || kop[i][j]==hyit_h_fdfhbbb && jhhf==0){
    jhhf=1;restcL2=kop[i][j];}else if(kop[i][j]==hyit_h_fdfhbbb && kop[i][j] != restcL2 && jhhf==1 || kop[i][j]==hyit_h_dcbfghoo && kop[i][j] != restcL2 && jhhf==1){
    jhhf=0;restcL2=-1; vfh++;break;}}}} hyit_h[hyit_h_dcbfghoo][hyit_h_fdfhbbb]=vfh;} hyit_h_fdfhbbb++;} cout<<"\nC2"<<"\n";
	int hyit_h_i=0;int hyit_h_j=1;for(hyit_h_i; hyit_h_i<pr1; hyit_h_i++){ if(hyit_h_j >= pr1){ hyit_h_j=hyit_h_i+1;}for(hyit_h_j; hyit_h_j<pr1; hyit_h_j++){if(hyit_h[hyit_h_i][hyit_h_j] != 0){ cout<<pro1[hyit_h_i] << " -> " << pro1[hyit_h_j] << "=" << hyit_h[hyit_h_i][hyit_h_j] <<"\n";
    }}hyit_h_j++;}int hterlk[pr1][pr1][pr1];for(int i=0; i<pr1; i++){ hterlk[i][i][i]=0;}bool jhhf1=0,jhhf2=0,jhhf3=0; int restcfdvbn_1,restcfdvbn_2,restcfdvbngfseccc,restcfdvbnbvbd,restcfdvbncvetru;
	for(int dcbfghoo=0;dcbfghoo<pr1; dcbfghoo++){ for(int fdfhbbb=dcbfghoo+1; fdfhbbb<pr1; fdfhbbb++){for(int rqqethb=fdfhbbb+1; rqqethb<pr1; rqqethb++){
    vfh=0;for(int i=0;i<rtg;i++){jhhf1=0;jhhf2=0;restcfdvbn_1=-1;restcfdvbn_2=-1; if(sert[i] >= 3){ for(int j=0; j<sert[i]; j++){
    if(kop[i][j]==dcbfghoo && jhhf1==0 && jhhf2==0 || kop[i][j]==fdfhbbb && jhhf1==0 && jhhf2==0 || kop[i][j]==rqqethb && jhhf1==0 && jhhf2==0){
    jhhf1=1;restcfdvbn_1=kop[i][j];}else if(kop[i][j]==fdfhbbb && kop[i][j] != restcfdvbn_1 && jhhf1==1 && jhhf2==0 || kop[i][j]==dcbfghoo && kop[i][j] != restcfdvbn_1 && jhhf1==1 && jhhf2==0 || kop[i][j]==rqqethb && kop[i][j] != restcfdvbn_1 && jhhf1==1 && jhhf2==0){
    jhhf1=0;jhhf2=1;restcfdvbn_2=kop[i][j];}else if(kop[i][j]==rqqethb && kop[i][j] != restcfdvbn_1 && kop[i][j] != restcfdvbn_2 && jhhf1==0 && jhhf2==1 || kop[i][j]==dcbfghoo && kop[i][j] != restcfdvbn_1 && kop[i][j] != restcfdvbn_2 && jhhf1==0 && jhhf2==1 || kop[i][j]==fdfhbbb && kop[i][j] != restcfdvbn_1 && kop[i][j] != restcfdvbn_2 && jhhf1==0 && jhhf2==1){
    jhhf1=0; jhhf2=0;restcfdvbn_1=-1;restcfdvbn_2=-1;vfh++;break;}}}}hterlk[dcbfghoo][fdfhbbb][rqqethb]=vfh;}}}cout<<"\nC3"<<"\n"; for(int i=0; i<pr1; i++){ for(int j=i+1; j<pr1; j++){ for(int h=j+1; h<pr1; h++){ if(hterlk[i][j][h] != 0){ cout<<pro1[i] << " + " << pro1[j] << " -> " << pro1[h] << "=" << hterlk[i][j][h] <<"\n";}}}}
    for(int i=0; i<pr1;i++){for(int j=i+1;j<pr1;j++){for(int h=j+1; h<pr1; h++){ if((double)hterlk[i][j][h]/(double)rtg >= UfNoSc){ cout<<pro1[i] << " + " << pro1[j] << " -> " << pro1[h] << " (" << ((double)hterlk[i][j][h]/(double)rtg)*100 << "%)" <<"\n";
    fdgfghmmn++;}}}}if(fdgfghmmn==0){cout<<"/////////////////////////////////////\nZalozenia nie pasuja do ufnosci\n/////////////////////////////////////\n";}
}

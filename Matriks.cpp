#include<iostream>
using namespace std;
int main(){
    int baris, kolom, i, j, obe, baris_1, baris_2;
    float matriks[10][10], x, matriksTemp[10][10];
    char pilihan;
    cout<<"PROJECT ALJABAR LINIER ELEMENTER"<<endl; cout<<endl;
    cout<<"Max baris: 10 & Max kolom: 10"<<endl; cout<<endl;
    do{//Input baris dan kolom
        cout<<"Masukkan banyaknya baris: "; cin>>baris;
        cout<<"Masukkan banyaknya kolom: "; cin>>kolom;
        cout<<endl;
        if (baris<=10 && kolom<= 10 && baris>0 && kolom>0){break;
        } else {cout<<"Input salah!"<<endl;cout<<endl;}
    } while (baris>10 || kolom>10 || baris<1 || kolom<1);

    for(i=0; i<baris; i++){//Input matriks
        for(j=0; j<kolom; j++){
            cout<<"Input baris "<<i+1<<" dan kolom "<<j+1<<" : ";
            cin>>x;
            matriks[i][j]=x;}
        }
    cout<<endl;

    cout<<"Matriks: "<<endl;
    for(i=0; i<baris; i++){//Output matriks
        for(j=0; j<kolom; j++){
            cout<<" "<<matriks[i][j];}
        cout<<endl;}
    cout<<endl;
    do{//OBE atau skip
        cout<<"Apakah anda ingin melakukan OBE? (y/n) ";
        cin>>pilihan;
        if(pilihan!='y'&&pilihan!='n'){
            cout<<"Input salah!"<<endl;}
    } while (pilihan!='y'&&pilihan!='n');
    cout<<endl;

    switch(pilihan){//OBE atau nggak?
        case 'y':
            do{//Operasi OBE
                cout<<"Operasi Baris Elementer"<<endl;
                cout<<"1 -- Operasi menukar baris"<<endl;
                cout<<"2 -- Operasi mengalikan baris dengan bilangan"<<endl;
                cout<<"3 -- Operasi menambahkan baris dengan kelipatan baris lain"<<endl;
                do{//Input pilihan OBE
                    cout<<"Operasi mana yang ingin Anda lakukan? "; cin>>obe;
                } while (obe<1||obe>3);
                cout<<endl;
                switch(obe){//OBE
                    case 1:
                        cout<<"Baris mana yang ingin ditukar?"<<endl;
                        do{
                            cout<<"Baris 1: "; cin>>baris_1;
                            if (baris_1>baris){cout<<"Input salah!"<<endl;}
                        } while (baris_1>baris);
                        do{
                            cout<<"Baris 2: "; cin>>baris_2;
                            if (baris_2>baris){cout<<"Input salah!"<<endl;}
                        } while (baris_2>baris);
                        for(i=0; i<kolom; i++){
                            matriksTemp[baris_1-1][i] = matriks[baris_1-1][i];
                            matriks[baris_1-1][i] = matriks[baris_2-1][i];
                            matriks[baris_2-1][i] = matriksTemp[baris_1-1][i];}
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                }
                for(i=0; i<baris; i++){//Output matriks
                    for(j=0; j<kolom; j++){
                        cout<<" "<<matriks[i][j];}
                    cout<<endl;}
                cout<<endl;
                do{
                    cout<<"Apakah anda ingin melakukan OBE lagi? (y/n)";
                    cin>>pilihan;
                    if(pilihan=='n'){break;}
                }while(pilihan!='y' && pilihan !='n');
                cout<<endl;
            }while(pilihan=='y');
            break;
        case 'n':
            cout<<"Terima kasih"<<endl;
            break;
    }
}

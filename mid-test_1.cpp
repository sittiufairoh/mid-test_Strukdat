/*
Program		: mid-test_1
Nama		: Sitti Ufairoh Azzahra
NPM			: 140810180002
Deskripsi	: UTS Praktikum Struktur Data
Tanggal		: 24 April 2019
*/

#include <iostream>
using namespace std;

struct ElmtList{
	int no;
	char namaMkn[30];
	int Jumlah,Harga;
	ElmtList* next;
};

typedef ElmtList* pointer;
typedef pointer List;

void createList (List& First){
	First = NULL;
}

void createElement (pointer& pBaru){
	pBaru = new ElmtList;
	cout << "No		: "; cin>>pBaru->no;
	cout << "Nama Makanan	: "; cin.ignore(); cin.getline(pBaru->namaMkn,30);
	cout << "Harga		: "; cin>>pBaru->Harga;
	pBaru->Jumlah = 0;
	pBaru->next = NULL;
}

void insertLast (List& First, pointer pBaru){
	if (First==NULL){
		First = pBaru;
	}
	else {
		pointer last = First;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void traversal (List First){
    pointer pBantu;
    if(First==NULL){
        cout<<"next"<<endl;
    }
    else{
        pBantu=First;
        cout << "\n--------------------------------------" << endl;
		cout<< "No    Nama Makanan   Jumlah     Harga"<<endl;
		cout << "--------------------------------------" << endl;
        do{
            cout<<pBantu->no<<"    "<<pBantu->namaMkn<<"    "<<pBantu->Jumlah<<"       "<<pBantu->Harga<<endl;
            pBantu=pBantu->next;
        }
        while(pBantu!=NULL);
    }
}

void linearSearch (List First,int key, int& status, pointer pCari){
	status=0;
	pCari = First;
	while (status==0 && pCari!=NULL){
		if(key == pCari->no){
			status=1;
		}
		else{
			pCari = pCari->next;
		}
	}
}

void update (List& First){
	pointer pBantu;
	pBantu = First;
	
	while(pBantu!=NULL){
        cout<<"Nama Makanan "<<pBantu->namaMkn<<endl;
        cout<<"Jumlah Pesanan : "; cin>>pBantu->Jumlah;
        cout<<endl;
        pBantu=pBantu->next;
    } 
}

/*
void sortAsc(List& First){
    for(int i=0; i<6; i++){
        pointer pBantu = First;
        while(pBantu->next != NULL){
            if (pBantu->Jumlah < pBantu->next->Jumlah) {
                swap(pBantu->no, pBantu->next->no);
                swap(pBantu->namaMkn, pBantu->next->namaMkn);
                swap(pBantu->Jumlah, pBantu->next->Jumlah);
                swap(pBantu->Harga, pBantu->next->Harga);
            }
            pBantu = pBantu->next;
        }
    }
}
*/

int main(){
	List First;
	pointer p, pCari;
	int n;
	char key[20];
	
	cout<< "Jumlah yang dipesan	: "; cin>>n;
	
	createList(First);
	traversal(First);
	for(int i=0;i<n;i++){
        system("cls");
        cout<<"\nPesanan ke - "<<i+1<<endl;
        createElement(p);
        insertLast(First,p);
        traversal(First);
    }cout<<endl;
    
    cout << "\n======UPDATE JUMLAH======" <<endl;
    update(First);
    cout << "\n***********************" << endl;
    cout<< "SETELAH DI UPDATE" << endl;
    cout << "***********************" << endl;
    /*sortAsc(First);*/
    traversal(First);
    
    
}

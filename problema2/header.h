#pragma once
#include<iostream>
#include <string>
#include<vector>
#include<iomanip>
#include<sstream>
using namespace std;

//structura hashtable generic
template <typename Key, typename Content>
struct hashtable{
    Key key;
    Content cont;
    hashtable* next;
};

//tipul de date folosit pentru a descrie continutul unei carti din biblioteca
struct carte{
    hashtable<string,string> *HT;
    //N
    int nr_definitii;
    //M
    bool is_borrowed;
    int size;
    float rating;
    int purchase;
};

//tipul de date folosit pentru biblioteca
struct biblioteca{
    hashtable<string,carte> *HT;
    //N
    int nr_carti;
    //M
    int size;
};

//tipul de date folosit pentru a tine cont de fiecare user in parte
struct imprumuturi{
    //hastableul corespunde (nume de care,numarul de zile de imprumut) pe 
    //care le salvez din functia borrow
    hashtable<string,int> *HT;
    //N
    int nr_imprumuturi;
    //M
    int size;
    bool are_carte;
    bool banned;
    int puncte;
};

//tipul de date folosit pentru baza de date a userilor
struct user_DB{
    hashtable<string,imprumuturi> *HT;
    int nr_useri;
    int size;
};

//aceasta structura va fi folosita pentru a construi score-boardurile
struct record_data{
    string nume;
    float scor;
    int purchase;
};


template <typename Key, typename Content>
hashtable<Key,Content>* Init_Hash(int size){
    hashtable<Key,Content>* HT=new hashtable<Key,Content>[size];
    for (int i = 0; i < size; i++) {
            HT[i].next = 0;
        }
    return HT;
}

template <typename Key, typename Content>
void Free_Hash(int size, hashtable<Key, Content>* &HT) {
    for (int i = 0; i < size; i++) {
        while (HT[i].next) {
            hashtable<Key, Content>* temp = HT[i].next;
            HT[i].next = temp->next;
            delete temp;
        }
    }
    delete[] HT;
}

//functie Polynomial Hashing
template <typename T>
int hash_Func(T key, int size) {
    long long int hash_val = 0;
    for (int i = 0; i < key.length(); ++i) {
    char c = key[i];
    hash_val = hash_val * 23 + c; 
}
    if(size==1)
        return 1;
    else
        return hash_val % (size-1);
}


//functie Put din barem
template <typename Key, typename Content>
void add_value(Key new_key,Content new_cont,hashtable<Key,Content>* &HT,int size){
    int index=hash_Func<Key>(new_key,size);
    hashtable<Key,Content>* p=&HT[index];
    hashtable<Key,Content>* new_entry=new hashtable<Key,Content>;
    new_entry->key=new_key;
    new_entry->cont=new_cont;
    new_entry->next=0;
    if(!p){
        p=new_entry;
    }
    else{
    while(p && p->next){
        p=p->next;
    }
    p->next=new_entry;
    }
}

//mecanismul de resize
template <typename Key, typename Content>
void resize(hashtable<Key,Content>* &HT, int size){
    int d_size=size*2;
    hashtable<Key,Content>* TEMP = Init_Hash<Key,Content>(d_size);
    for(int i=0;i<size;i++){
        hashtable<Key,Content>* p=&HT[i];
        while(p){
        Key temp_key=p->key;
        Content temp_cont=p->cont;
        add_value<Key,Content>(temp_key,temp_cont,TEMP,d_size);
        p=p->next;
        }
    }
     Free_Hash(size,HT);
     HT=TEMP;
}


template <typename Key, typename Content>
void afisare(hashtable<Key,Content>* HT, int size){
    for(int i = 0; i < size; i++){
        hashtable<Key,Content>* p = &HT[i];
        while(p != nullptr){
            cout << p->cont << " ";
            p = p->next;
        }
        cout << endl;
    }
}

//Remove(key) din barem
template <typename Key, typename Content>
void remove_key(Key find_key, hashtable<Key, Content>*& HT, int size) {
    int index = hash_Func<Key>(find_key, size);
    hashtable<Key, Content>* p = &HT[index];
    if (p && p->key == find_key) {
        HT[index] = *(p->next);  
        delete p;  
    } else {
        while (p && p->next && p->next->key != find_key) {
            p = p->next;
        }
        if (p && p->next) { 
            hashtable<Key, Content>* temp = p->next;
            p->next = temp->next;
            delete temp; 
        }
    }
}


//Get(Key) din barem
template <typename Key, typename Content>
Content* get_content(Key key, hashtable<Key, Content>* &ht, int size) {
    int index = hash_Func<Key>(key, size);
    hashtable<Key, Content>* p = &ht[index];
    while (p) {
        if (p->key == key) {
            return &(p->cont);
        }
        p = p->next;
    }
    return nullptr;
}

//Has_Key din barem
template <typename Key,typename Content>
bool check_key(Key key,hashtable<Key,Content>* HT,int size){
    int index=hash_Func<Key>(key,size);
        hashtable<Key,Content>* p = &HT[index];
        if(p && p->key==key){
            return 1;
        }
        else{
        while(p){
            if(p->key==key)   return 1;
            p = p->next;
        }
        }
    return 0;
}

//Functii de init pentru tipurile de date

carte* init_carte(int size){
    carte *noua_carte=new carte;
    noua_carte->nr_definitii=0;
    noua_carte->size=size;
    noua_carte->purchase=0;
    noua_carte->rating=0;
    noua_carte->purchase=0;
    noua_carte->is_borrowed=0;
    noua_carte->HT=Init_Hash<string,string>(size);
    return noua_carte;
}

biblioteca* init_biblioteca(int size){
    biblioteca *BIBLIO=new biblioteca;
    BIBLIO->size=size;
    BIBLIO->nr_carti=0;
    BIBLIO->HT=Init_Hash<string,carte>(size);
    return BIBLIO;
}

imprumuturi* init_borrow(int size){ 
    imprumuturi *borrow=new imprumuturi; 
    //N
    borrow->nr_imprumuturi=0;
    //M
    borrow->size=size;
    borrow->puncte=100;
    borrow->are_carte=0;
    borrow->banned=0;
    borrow->HT=Init_Hash<string,int>(size);
    return borrow;
};

user_DB* init_USERS(int size){ 
    user_DB *users=new user_DB; 
    //N
    users->nr_useri=0;
    //M
    users->size=size;
    users->HT=Init_Hash<string,imprumuturi>(size);
    return users;
};

//Functiile de resize specializate pe tipuri de date
void resize_carte(carte* &C){
    resize<string,string>(C->HT,C->size);
    int n=C->size;
    C->size=n*2;
}

void resize_biblioteca(biblioteca* &B){
    resize<string,carte>(B->HT,B->size);
    int n=B->size;
    B->size=n*2;
}

void resize_useri(user_DB* &U){
    resize<string,imprumuturi>(U->HT,U->size);
    int n=U->size;
    U->size=n*2;
}

void resize_imprumuturi(imprumuturi* &usr){
    resize<string,int>(usr->HT,usr->size);
    int n=usr->size;
    usr->size=n*2;
}


void RMV_BOOK(biblioteca* &B,string nume){
    if(check_key<string,carte>(nume,B->HT,B->size)){
    carte *C=get_content<string,carte>(nume,B->HT,B->size);
    Free_Hash<string,string>(C->size,C->HT);
    remove_key<string,carte>(nume,B->HT,B->size);
    B->nr_carti--;
    }
    else{
    cout<<"The book is not in the library."<<endl;
    }
}

void ADD_BOOK(biblioteca* &B,string nume,int size){
    //verificam daca exista
    if(!check_key<string,carte>(nume,B->HT,B->size)){
    carte *c=init_carte(size); 
    string temp1,temp2;
    for(int i=0;i<size;i++){
            cin>>temp1>>temp2;
             add_value<string,string>(temp1,temp2,c->HT,size);
    }
    add_value<string,carte>(nume,*c,B->HT,B->size);
    c->nr_definitii=size;
    B->nr_carti++;
    //verificam daca intalneste conditiile de resize
    if(float(B->nr_carti/B->size)>1){
        resize_biblioteca(B);
    }
    }
    //updatam  cartea daca exista deja 
    else{
            RMV_BOOK(B,nume);
            ADD_BOOK(B,nume,size);
    }
}


void GET_DEF(biblioteca* &B,string key1,string key2){
    if(check_key<string,carte>(key1,B->HT,B->size)){
    carte *C=get_content<string,carte>(key1,B->HT,B->size);
    if(check_key<string,string>(key2,C->HT,C->size)){
        cout<<*(get_content<string,string>(key2,C->HT,C->size))<<endl;
    }
    else{
         cout<<"The definition is not in the book."<<endl;
    }
    }
    else{
         cout<<"The book is not in the library."<<endl;
    }

}

void GET_BOOK(biblioteca* &B,string key1){
    if(check_key<string,carte>(key1,B->HT,B->size)){
    carte *C=get_content<string,carte>(key1,B->HT,B->size);
    cout<<"Name: "<<key1<<" Rating: "<< fixed << setprecision(3) <<C->rating<<" Purchase: "<<C->purchase<<endl;
    cout.unsetf(ios::fixed);
    }
    else{
         cout<<"The book is not in the library."<<endl;
    }

}

void ADD_DEF(biblioteca* &B,string key1,string def1,string def2){
       if(check_key<string,carte>(key1,B->HT,B->size)){
            carte *C=get_content<string,carte>(key1,B->HT,B->size);
            if(check_key<string,string>(def1,C->HT,C->size)){
                remove_key<string,string>(def1,C->HT,C->size);}
            add_value<string,string>(def1,def2,C->HT,C->size);
            C->nr_definitii++;
             if(float(C->nr_definitii/C->size)>1){
             resize_carte(C);
             }
    }
    else{
         cout<<"The book is not in the library."<<endl;
    }
}

void RMV_DEF(biblioteca* &B,string key1,string key2){
    if(check_key<string,carte>(key1,B->HT,B->size)){
    carte *C=get_content<string,carte>(key1,B->HT,B->size);
    if(check_key<string,string>(key2,C->HT,C->size)){
        remove_key<string,string>(key2,C->HT,C->size);
        C->nr_definitii--;
    }
    else{
         cout<<"The definition is not in the book."<<endl;
    }
    }
    else{
         cout<<"The book is not in the library."<<endl;
    }
}

void ADD_USER(user_DB* &USR,string key){
    if(!check_key<string,imprumuturi>(key,USR->HT,USR->size)){
    imprumuturi *borrow=init_borrow(3);
    add_value<string,imprumuturi>(key,*borrow,USR->HT,USR->size);
    USR->nr_useri++;
    if(USR->nr_useri/USR->size>=1){
        resize_useri(USR);
    }
    }
    else
    cout<<"This user is already registered!"<<endl;
}

void BORROW(user_DB* &U,biblioteca* &B,string username,string bookname,int days){
    if(!check_key<string,imprumuturi>(username,U->HT,U->size)){
        cout<<"You are not registered yet!"<<endl;
    }
    else{
            imprumuturi *user=get_content<string,imprumuturi>(username,U->HT,U->size);
            if(user->banned){
                cout<<"You are banned from this library!"<<endl;
            }
            else{
            if(user->are_carte){
                cout<<"You have already borrowed a book."<<endl;
            }
            else{
                if(!check_key<string,carte>(bookname,B->HT,B->size)){
                    cout<<"Book is not in the library."<<endl;
                }
                else{
                    if(check_key<string,int>(bookname,user->HT,user->size)){
                        //nu e ceruta sa se specifice "this book" in barem dar nu e gresita
                        cout<<"You have already borrowed this book"<<endl;
                    }
                    else{
                  carte *book=get_content<string,carte>(bookname,B->HT,B->size);
                    if(book->is_borrowed){
                        cout<<"The book is borrowed."<<endl;
                    }
                    else{
                        add_value<string,int>(bookname,days,user->HT,user->size);
                        user->nr_imprumuturi++;
                        if(float(user->nr_imprumuturi/user->size)>1){
                            resize_imprumuturi(user);
                             }          
                        //reisze
                        book->is_borrowed=1;
                        user->are_carte=1;
                    }
                    }
                }
            }
            }
    }
}

void RETURN(user_DB* &U,biblioteca* &B,string username,string bookname,int days_since_borrow,int given_rating){
    imprumuturi *user=get_content<string,imprumuturi>(username,U->HT,U->size);
    if(user->banned){
        cout<<"You are banned!"<<endl;
        if(!check_key<string,int>(bookname,user->HT,user->size)){
                cout<<"You didn't borrow this book!"<<endl;
            }
            else{
                carte *book=get_content<string,carte>(bookname,B->HT,B->size); 
                //setez variabilele bool coresp              
                book->is_borrowed=0;
                book->rating+=given_rating;
                book->purchase++;
                user->are_carte=0;
                //scot cartea din inventarul userului si modific size-ul ht-ului
                remove_key<string,int>(bookname,user->HT,user->size);
              //  user->size--;
            }
    }
    else{
        if(!check_key<string,int>(bookname,user->HT,user->size)){
                cout<<"You didn't borrow this book!"<<endl;
            }
            else{
                carte *book=get_content<string,carte>(bookname,B->HT,B->size); 
                //setez variabilele bool
                user->are_carte=0;              
                book->is_borrowed=0;
                book->rating+=given_rating;
                book->purchase++;
                //iau termenul limita de return din hashtabelul userului
                int *days_promised=get_content<string,int>(bookname,user->HT,user->size);
                //verific daca e mai mare sau egal cu data la care a fost intoarsa cartea
                if(*days_promised>=days_since_borrow)
                //daca da ii dau bonus puncte diferenta dintre zile
                    user->puncte=user->puncte+(*days_promised)-days_since_borrow;
                    else
                        if(*days_promised<days_since_borrow)
                        //in caz contrar ii scad diferenta dintre zile * 2
                         user->puncte=user->puncte+2*((*days_promised)-days_since_borrow);
                if(user->puncte<=0){
                    cout<<"The user "<<username<<" has been banned!"<<endl;
                    user->banned=1;
                }
                remove_key<string,int>(bookname,user->HT,user->size);
               // user->size--;

            }
    }
}

void LOST(user_DB* &U,biblioteca* &B,string username,string bookname){
      imprumuturi *user=get_content<string,imprumuturi>(username,U->HT,U->size);             
                user->puncte=user->puncte-50;
                if(user->puncte<=0){
                    cout<<"The user "<<username<<" has been banned"<<endl;
                    user->banned=1;
                }
                user->are_carte=0;
                remove_key<string,int>(bookname,user->HT,user->size);
              //  user->size--;
                RMV_BOOK(B,bookname);

}

//functii pentru prelucrarea listelor cu scoruri
void display_data(record_data *A,int size){
    for(int i=0;i<size;i++){
        if(A[i].scor>0)
        cout<<A[i].nume<<" "<<A[i].scor<<endl;
    }
}

void sort_data(record_data *A,int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(A[i].scor>A[j].scor){
                swap(A[i],A[j]);
            }
            else
            if(A[i].scor==A[j].scor && A[i].nume.compare(A[j].nume)<1){
                swap(A[i],A[j]);
            }
        }
    }
}

void sort_data_book(record_data *A,int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(A[i].scor<A[j].scor){
                //sortam in functie de scor
                swap(A[i],A[j]);
            }
            else{
            if(A[i].scor==A[j].scor && A[i].purchase>A[j].purchase){
                //in functie de purchare, daca scorul e egal
            swap(A[i],A[j]);
            }
            else{
                //in functie de ordine alfabetica, pt ca pot face asta cu stringuri in C++
                if(A[i].scor==A[j].scor && A[i].purchase>A[j].purchase && A[i].nume.compare(A[j].nume)<1)
                swap(A[i],A[j]);
            }
            }
        }
    }
}

//functiile rulate la inchiderea programului
void get_book_scores(biblioteca* B){
    int total_carti = B->nr_carti;
    record_data* RECORD = new record_data[total_carti];
    int contor = 0;
    for (int i = 0; i < B->size; i++) {
        hashtable<string,carte>* HT = &B->HT[i];
        while(HT!=nullptr) {
                if(HT->key!=""){
                RECORD[contor].nume = HT->key;
                if(HT->cont.rating!=0 && HT->cont.purchase!=0){
                RECORD[contor].scor = HT->cont.rating/HT->cont.purchase;
                HT->cont.rating=HT->cont.rating/HT->cont.purchase;
                }
                else
                RECORD[contor].scor=0;
                contor++;
                }
                HT=HT->next;
        }
    }
    cout<<"Books Ranking:"<<endl;
    sort_data_book(RECORD,total_carti);
    for(int i=0;i<total_carti;i++)
    GET_BOOK(B,RECORD[i].nume);
    delete[] RECORD;
}

void get_user_scores(user_DB* U){
    int total_useri = U->nr_useri;
    record_data* RECORD = new record_data[total_useri];
    int contor = 0;
    for (int i = 0; i < U->size; i++) {
        hashtable<string,imprumuturi>* HT = &U->HT[i];
        while(HT!=nullptr) {
                if(HT->key!=""){
                RECORD[contor].nume = HT->key;
                RECORD[contor].scor = HT->cont.puncte;
                contor++;
                }
                HT=HT->next;
        }
    }
    cout<<"User's Ranking:"<<endl;
    sort_data(RECORD,total_useri);
    display_data(RECORD,total_useri);
    delete[] RECORD;
}

void sterge_biblioteca(biblioteca* &B) {
    for (int i = 0; i < B->size; i++) {
        hashtable<string,carte>* HT = &B->HT[i];
        while(HT!=nullptr) {
                Free_Hash<string,string>(HT->cont.size,HT->cont.HT);
                HT=HT->next;
        }
    }
    Free_Hash<string,carte>(B->size,B->HT);
}

void sterge_useri(user_DB* &U) {
    for (int i = 0; i < U->size; i++) {
        hashtable<string,imprumuturi>* HT = &U->HT[i];
        while(HT!=nullptr) {
                Free_Hash<string,int>(HT->cont.size,HT->cont.HT);
                HT=HT->next;
        }
    }
    Free_Hash<string,imprumuturi>(U->size,U->HT);
}

void interpret(string COMMAND, string arg1, string arg2,string arg3,string arg4, biblioteca* &B,user_DB* &U) {
    if (COMMAND == "ADD_BOOK") {
		ADD_BOOK(B, arg1,stoi(arg2));
	}
	else
	if (COMMAND == "GET_BOOK") {
		GET_BOOK(B, arg1);
	}
	else
		if (COMMAND == "RMV_BOOK") {
			RMV_BOOK(B, arg1);
		}
		else
			if (COMMAND == "ADD_DEF") {
				ADD_DEF(B, arg1, arg2,arg3);
			}
			else
				if (COMMAND == "GET_DEF") {
					GET_DEF(B, arg1, arg2);
				}
				else
					if (COMMAND == "RMV_DEF") {
						RMV_DEF(B,arg1,arg2);
					}
					else
						if (COMMAND == "ADD_USER") {
							ADD_USER(U,arg1);
						}
						else
							if (COMMAND == "BORROW") {
								BORROW(U,B,arg1,arg2,stoi(arg3));
							}
							else
								if (COMMAND == "RETURN") {
									RETURN(U,B,arg1,arg2,stoi(arg3),stoi(arg4));
								}
								else
									if (COMMAND == "LOST") {
										LOST(U,B,arg1,arg2);
									}
							            else
										 cout <<"Invalid command. "<<COMMAND<<" Please try again." << endl;
}

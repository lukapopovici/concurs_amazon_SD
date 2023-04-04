#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<sstream>
using namespace std;

struct carte {
	int nr;
	string TYPE;
};
struct pachet {
	carte data;
	pachet* spate, * fata;
};
struct deck {
	pachet* P;
	deck* spate, * fata;
};
//functie sa interpretez comenzile loate din main
void interpret(string COMMAND, int arg1, int arg2, deck*& DECK);
//functii pentru ADD_DECK
void ADD(deck*& DECK, int n);
void add_deck(deck*& DECK, pachet*& PACHET);
//pentru a verifica daca un card citit este valid
bool valid(carte CARTE);
//DECK_NUMBER
int deck_number(deck* DECK);
//DECK_LEN
int deck_len(deck* DECK, int n);
//functia care citeste valorile unei carti inatine sa fie adaugata
void add_carte(pachet*& l, carte& n);
//functie care sa printeze pachetul
void print_pachet(pachet* l);
pachet* citire_Pachet(int n);
//DEL_DECK
void del_deck(deck*& DECK, int n);
//SHOW_ALL
void show_deck(deck* DECK);
//SHOW_DECK
void show_nth_deck(deck* DECK, int n);
//functii pentru DEL_CARD
void del_card(deck*& DECK, int n, int m);
void sterge_din_pachet(pachet*& PACHET, int n);
//functii pentru REVERSE_DECK
void rev_card(deck*& DECK, int n);
void reverse(pachet*& PACHET);
//functii pentru ADD_CARDS
void adaug_la_pachet(pachet*& PACHET, int n);
void add_carti_la_n(deck*& DECK, int n, int numar);
//functii pentru SHUFFLE_DECK
void shuffle_la_n(deck*& DECK, int n);
void shuffle(pachet*& PACHET, int n);
//functii pentru SORT_DECK
void sort_at_n(deck*& DECK, int n);
bool verifica_greater(carte X, carte Y);
int getPrio(string S);
void sort(pachet*& l);
void add_carte_sorted(pachet*& l, carte n);
//functii pentru SPLIT_DECK
void split(deck*& DECK, int n, int split_index);
pachet* split_list(pachet*& PACHET, int n);
//functii pentru MERGE_DECK
void merge(deck*& DECK, int index1, int index2);
pachet* merge_pachete(pachet* P1, pachet* P2, int n);
pachet* pointer_la_pachet(deck* D, int n);
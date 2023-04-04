#include "Header.h"
void ADD(deck*& DECK, int n) {
	pachet* PACHET = 0;
	PACHET = citire_Pachet(n);
	add_deck(DECK, PACHET);
}
void add_deck(deck*& DECK, pachet*& PACHET) {
	deck* TEMP = new deck;
	TEMP->P = PACHET;
	TEMP->fata = NULL;
	TEMP->spate = NULL;
	if (DECK == NULL)
		DECK = TEMP;
	else {
		deck* f = DECK;
		while (f && f->fata != NULL)
			f = f->fata;
		TEMP->spate = f;
		f->fata = TEMP;
	}
}
void show_deck(deck* DECK) {
	int i = 0;
	while (DECK) {
		cout << "DECK " << i << endl;
		print_pachet(DECK->P);
		DECK = DECK->fata;
		i++;
	}
}
void add_carte(pachet*& l, carte& n) {
	pachet* d = new pachet;
	d->data = n;
	d->fata = NULL;
	d->spate = NULL;
	if (l == NULL)
		l = d;
	else {
		pachet* f = 0;
		f = l;
		while (f->fata != NULL)
			f = f->fata;
		d->spate = f;
		f->fata = d;

	}
}
void add_carte_sorted(pachet*& l, carte n) {
	pachet* d = new pachet;
	d->data = n;
	d->fata = NULL;
	d->spate = NULL;
	if (l == NULL)
		l = d;
	else {
		if (l && !verifica_greater(d->data, l->data)) {
			//cout << "compar" << d->data.nr << " cu " << l->data.nr << verifica_greater(d->data, l->data) << endl;
			l->spate = d;
			d->fata = l;
			l = d;
		}
		else {
			pachet* f = 0;
			f = l;
			while (f->fata && verifica_greater(d->data,f->fata->data)) {
				//cout << "compar1" << d->data.nr << " cu " << f->data.nr << verifica_greater(d->data, l->data) << endl;
				f = f->fata;
			}
			d->spate = f;
			d->fata = f->fata;

			if (f->fata) {
				f->fata->spate = d;
			}
			f->fata = d;
		}
	}
}
void sort(pachet*& l) {
	pachet* TEMP = 0;
	TEMP = 0;
	while (l) {
		add_carte_sorted(TEMP, l->data);
		l = l->fata;
	}
	l = TEMP;
}
void print_pachet(pachet* l) {
		while (l) {
			cout << l->data.nr << " " << l->data.TYPE << endl;
			//if(l->fata)
			//cout << l->spate->data.nr << " " << l->spate->data.TYPE << endl;
			l = l->fata;
		}
}
int deck_number(deck* DECK) {
	int i = 0;
	if (DECK) {
		while (DECK) {
			i++;
			DECK = DECK->fata;
		}
	}
	return i;
}
int deck_len(deck* DECK, int n) {
	if (n <= deck_number(DECK) && n >= 1) {
		int i = 1;
		while (i != n) {
			DECK = DECK->fata;
			i++;
		}
		i = 1;
		pachet* TEMP = 0;
		TEMP = DECK->P;
		while (TEMP && TEMP->fata) {
			i++;
			TEMP = TEMP->fata;
		}
		return i;
	}
	else
		cout << "The provided index is out of bounds for the deck list.";
	return -1;
}
void shuffle(pachet*& PACHET, int n) {
	pachet* prima_jum = 0;
	pachet* jum2 = 0;
	int i = 0;
	prima_jum = PACHET;
	while (i != n / 2) {
		PACHET = PACHET->fata;
		i++;
	}
	if (PACHET->spate)
		PACHET->spate->fata = NULL;
	PACHET->spate = NULL;
	jum2 = PACHET;
	while (PACHET->fata) {
		PACHET = PACHET->fata;
	}
	PACHET->fata = prima_jum;
	prima_jum->spate = PACHET;

	PACHET = jum2;

}
int getPrio(string S) {
	if (S == "TREFLA")
		return 1;
	if (S == "CARO")
		return 2;
	if (S == "CUPA")
		return 3;
	if (S == "PICA")
		return 4;
}
bool verifica_greater(carte X, carte Y) {
	if (X.nr > Y.nr)
		return 1;
	else
		if (X.nr > Y.nr && getPrio(X.TYPE) > getPrio(Y.TYPE)) {
			return 1;
		}
		else
			return 0;
}

void sort_at_n(deck*& DECK, int n) {
	if (!(n <= deck_number(DECK) && n >= 1)) {
		cout << "The provided index is out of bounds for the deck list." << endl;
	}
	else
	{
		int i = 1;
		deck* f = 0;
		f = DECK;
		while (i != n) {
			f = f->fata;
			i++;
		}
		sort(f->P);
	}
}
void shuffle_la_n(deck*& DECK, int n) {
	if (!(n <= deck_number(DECK) && n >= 1)) {
		cout << "The provided index is out of bounds for the deck list." << endl;
	}
	else
	{
		int i = 1;
		deck* f = 0;
		f = DECK;
		while (i != n) {
			f = f->fata;
			i++;
		}
		int len = deck_len(DECK, n);
		shuffle(f->P, len);

	}
}
void del_deck(deck*& DECK, int n) {
	if (n < 1 || n > deck_number(DECK)) {
		cout << "The provided index is out of bounds for the deck list."<<endl;
		return;
	}
	if (n == 1) {
		DECK = DECK->fata;
		if (DECK)
			DECK->spate = NULL;
	}
	else {
		deck* f = DECK;
		int i = 1;
		while (i != n) {
			f = f->fata;
			i++;
		}
		f->spate->fata = f->fata;
		if (f->fata)
			f->fata->spate = f->spate;
		delete f;
	}
}
void show_nth_deck(deck* DECK, int n) {
	if (n <= deck_number(DECK) && n >= 1) {
		int i = 1;
		while (i != n) {
			DECK = DECK->fata;
			i++;
		}
		print_pachet(DECK->P);
	}
	else
		cout << "The provided index is out of bounds for the deck list.";
}
pachet* citire_Pachet(int n) {
	pachet* d = new pachet;
	int n_temp = n;
	d = 0;
	carte temp;
	while (n) {
		cin >> temp.nr >> temp.TYPE;
		while (!valid(temp)) {
			cout << "The provided card is not a valid one" << endl;
			cin >> temp.nr >> temp.TYPE;
		}
		add_carte(d, temp);
		n--;
	}
	cout << "The deck was successfully created with " << n_temp << " cards." << endl;
	return d;
}
void sterge_din_pachet(pachet*& PACHET, int n) {
	if (n == 1) {
		PACHET = PACHET->fata;
		if (PACHET)
			PACHET->spate = NULL;
	}
	else {
		pachet* f = PACHET;
		int i = 1;
		while (i != n) {
			f = f->fata;
			i++;
		}
		f->spate->fata = f->fata;
		if (f->fata)
			f->fata->spate = f->spate;
		delete f;
	}
}
pachet* split_list(pachet*& PACHET, int n) {
	pachet* TEMP = new pachet;
	TEMP = PACHET;
	int j = 0;
	while (j != n) {
		TEMP = TEMP->fata;
		j++;
	}
	if (TEMP->spate)
		TEMP->spate->fata = NULL;
	TEMP->spate = NULL;
	return TEMP;
}
void split(deck*& DECK, int n, int split_index) {
	if (!(n <= deck_number(DECK) && n >= 1)) {
		cout << "The provided index is out of bounds for the deck list." << endl;
	}
	else {
		if (split_index > deck_len(DECK, n) || split_index < 1)
			cout << "The provided index is out of bounds for the "<<n<<" deck." << endl;
		else {
			if (split_index == 1 || split_index == deck_len(DECK, n))
				cout << "Nu poate fi facut nimic" << endl;
			else
			{
				int i = 1;
				deck* f = 0;
				f = DECK;
				while (i != n) {
					f = f->fata;
					i++;
				}
				pachet* TEMP = new pachet;
				TEMP = split_list(f->P, split_index);
				deck* d = new deck;
				d->P = TEMP;
				d->fata = f->fata;
				if (f->fata) {
					f->fata->spate = d;
				}
				f->fata = d;
				d->spate = f;
			}
		}
	}
}
void del_card(deck*& DECK, int n, int m) {
	if (!(n <= deck_number(DECK) && n >= 1)) {
		cout << "The provided index is out of bounds for the deck list." << endl;
	}
	else
		if (!(m >= 1 && m <= deck_len(DECK, n))) {
			cout << "The provided index is out of bounds for deck " << n << endl;
		}
		else
		{
			int i = 1;
			deck* f = 0;
			f = DECK;
			while (i != n) {
				f = f->fata;
				i++;
			}
			sterge_din_pachet(f->P, m);
		}
}
bool valid(carte CARTE) {
	int truth1 = 0, truth2 = 0;
	if (CARTE.nr >= 1 && CARTE.nr <= 14)
		truth1 = 1;
	if (CARTE.TYPE == "PICA" || CARTE.TYPE == "CUPA" || CARTE.TYPE == "CARO" || CARTE.TYPE == "TREFLA")
		truth2 = 1;
	return truth1 * truth2;

}
void reverse(pachet*& PACHET) {
	pachet* TEMP = 0;
	pachet* TERM = 0;
	TEMP = NULL;
	TERM = PACHET;
	while (TERM) {
		TEMP = TERM->spate;
		TERM->spate = TERM->fata;
		TERM->fata = TEMP;
		TERM = TERM->spate;
	}
	if (TEMP) {
		PACHET = TEMP->spate;
	}
}
void rev_card(deck*& DECK, int n) {
	if (!(n <= deck_number(DECK) && n >= 1)) {
		cout << "The provided index is out of bounds for the deck list." << endl;
	}
	else
	{
		int i = 1;
		deck* f = 0;
		f = DECK;
		while (i != n) {
			f = f->fata;
			i++;
		}
		reverse(f->P);

	}
}
void adaug_la_pachet(pachet*& PACHET, int n) {
	pachet* TEMP = new pachet;
	TEMP = PACHET;
	while (TEMP->fata) {
		TEMP = TEMP->fata;
	}
	carte d;
	while (n) {
		cin >> d.nr >> d.TYPE;
		while (!valid(d)) {
			cout << "The provided card is not a valid one" << endl;
			cin >> d.nr >> d.TYPE;
		}
		add_carte(TEMP, d);
		n--;
	}
}
void add_carti_la_n(deck*& DECK, int n, int numar) {
	if (!(n <= deck_number(DECK) && n >= 1)) {
		cout << "The provided index is out of bounds for the deck list." << endl;
	}
	else
	{
		int i = 1;
		deck* f = 0;
		f = DECK;
		while (i != n) {
			f = f->fata;
			i++;
		}
		adaug_la_pachet(f->P, numar);
		cout << "The cards were successfully added to deck" << " " << n << endl;

	}
}

pachet* merge_pachete(pachet* P1, pachet* P2, int n) {
	pachet* RET = new pachet;
	RET = NULL;
	int i = 0;
	while (i != n + 1 && (P1 || P2)) {
		if (!P1) {
			while (P2) {
				add_carte(RET, P2->data);
				P2 = P2->fata;
			}
		}
		else {
			if (!P2) {
				while (P1) {
					add_carte(RET, P1->data);
					P1 = P1->fata;
				}
			}
			else {
				if (i % 2 == 1) {
					add_carte(RET, P1->data);
					P1 = P1->fata;
				}
				else
					if (i % 2 == 0) {
						add_carte(RET, P2->data);
						P2 = P2->fata;
					}
			}
		}
		i++;
	}
	return RET;
}
void merge(deck*& DECK, int index1, int index2) {
	if (index1<1 || index2<1 || index1> deck_number(DECK) || index1> deck_number(DECK)) {
		cout << "The provided index is out of bounds for the deck list." << endl;
	}
	else {
		pachet* P1 = 0;
		pachet* P2 = 0;
		P1 = pointer_la_pachet(DECK, index1);
		P2 = pointer_la_pachet(DECK, index2);
		int index_max = deck_len(DECK, index1) + deck_len(DECK, index2);
		pachet* REZ = 0;
		REZ = merge_pachete(P1, P2, index_max);
		//daca vreau sa sterg, spre exemplu, deckurile 5 si 3, daca o sterg pe 3 inainte fie 
		//o sa sterg fostul deck 6, cum deck 5 pe care il voiam sters devine 4, fie
		//lista de deckuri avea doar 5 elemente si imi da eroare de index.
		del_deck(DECK, max(index1, index2));
		del_deck(DECK, min(index1, index2));
		add_deck(DECK, REZ);
	}
}

pachet* pointer_la_pachet(deck* D, int n) {
	int i = 1;
	pachet* TEMP = new pachet;
	while (i != n) {
		D = D->fata;
		i++;
	}
	TEMP = D->P;
	return TEMP;
}
//imi pare rau pentru monstrul asta, dar nu pot folosi switch cu un string :(
//maxim puteam sa nu folosesc elseuri.
void interpret(string COMMAND, int arg1, int arg2, deck*& DECK) {

	if (COMMAND == "ADD_DECK") {
		ADD(DECK, arg1);
	}
	else
		if (COMMAND == "DEL_DECK") {
			del_deck(DECK, arg1);
		}
		else
			if (COMMAND == "DEL_CARD") {
				del_card(DECK, arg1, arg2);
			}
			else
				if (COMMAND == "ADD_CARDS") {
					add_carti_la_n(DECK, arg1, arg2);
				}
				else
					if (COMMAND == "DECK_NUMBER") {
						cout << deck_number(DECK);
					}
					else
						if (COMMAND == "DECK_LEN") {
							cout << deck_len(DECK, arg1);
						}
						else
							if (COMMAND == "SHUFFLE_DECK") {
								shuffle_la_n(DECK, arg1);
							}
							else
								if (COMMAND == "MERGE_DECKS") {
									merge(DECK, arg1, arg2);
								}
								else
									if (COMMAND == "SPLIT_DECK") {
										split(DECK, arg1, arg2);
									}
									else
										if (COMMAND == "REVERSE_DECK") {
											rev_card(DECK, arg1);
										}
										else
											if (COMMAND == "SHOW_DECK") {
												show_nth_deck(DECK, arg1);
											}
											else
												if (COMMAND == "SHOW_ALL") {
													show_deck(DECK);
												}
												else
													if (COMMAND == "SORT_DECK") {
														sort_at_n(DECK, arg1);
													}
													else
														cout << "Invalid command. Please try again." << endl;
}
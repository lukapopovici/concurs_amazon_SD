#### Nume: Popovici Luka
#### Grupa: 1111B

# Titlu:Pachet de carti

### Descriere:
Programul se deschide cu un prompt in care pot fi introduse comenzile din enunt.Argumentul 1 si 2 pentru functii sunt setate la fiecare citire. 
Daca un argument nu e citit, el este setat ca 0, si oricum nu va fi apelat.<br>
Original voiam sa declar o coada statica in care sa salvez argumentele la fiecare citire, dar am optat sa folosesc biblioteca vector, deoarece nu
doresc sa fac evaluarea codului mai grea declarand alte structuri in afara de cele cerute in mod explicit de problema.
Legat de uzul functiilor, as vrea sa vorbesc doar de SHUFFLE_DECK, MERGE_DECK, SPLIT_DECK si SORT_DECK. In opinia mea, restul comenzilor nu trebuie explicate deoarece sunt bazate pe algoritmi explicati foarte bine la curs (Si da, ma duc la curs).<br>
Inainte, vreau sa comentez asupra secventei:<br>
<code>
	{
		int i=1;
		deck* f = 0;
		f = DECK;
		while (i != n) {
			f = f->fata;
			i++;
		}
  </code>
O folosesc in functia in care apelez lista de liste prin referinta sa ajung la lista din interiorul ei(pachetul de carti), pe care lucrez folosind o functie care ia 
un parametru de tip pachet in antet. (functie(f->P)).Mai jos voi descrie algoritmii pe care ii aplic dupa ce iterez pana la pachetul dorit.<br><br>
SHUFFLE-DECK:<br><br>
	Interez pana la jumatatea pachetului pana ajung la elementul n/2, unde n este nr de carti din pachet.de acolo schimb pointerul de la elem n/2+1
in spate spre NULL,pe cel de la 2/n din fata sa arate spre NULL, si leg pointerul de la poz N sa arate spre inceput.<br><br>
MERGE_DECK:<br><br>
	Creez un nou pachet folosind elementele a 2 pachete (adresele carora le iau ca argumente in alta functie).Initializez un element i si il contorizez.
Pachetul din care inserez urmatoarea carte in noul meu pachet va depinde de paritatea lui (si de starea pachetelor in caz ca le termin de parcurs).La final inserez
pachetul creat dupa ce le sterg pe cele 2 folosite in creerea lui.<br><br>
SPLIT_DECK:<br><br>
	Dupa ce ajung la pachetul dorit, il iterez pana la indexul de split.Dupa, voi sterge legatura de la elementele dinaintea lui (cu pozitia<index_split)
 si salvez lista obtinuta intr-un element de tip pachet numit TEMP. Dupa, voi insera la pozitia curenta din elementul de tip deck (la care am iterat deja) un 
nou element care are ca date pachetul TEMP.<br><br>
SORT_DECK<br><br>
	Voi lua un pachet de carti nesortat si voi crea un nou element de tip pachet din elementele lui.Voi itera prin cartie pachetului original si voi construi noul pachet tinand cont de valoarea lor.Daca un element e mai mic decat capul listei, il voia dauga la cap. In caz contrar, iterez pana gasesc un element mai mare sau ajung la sfarsit si il voi insera acolo.Dupa, voi lua pointerul de la elementul de tip deck care arata spre pachetul original si il voi schimba sa arate spre noul pachet creat. <br>
### Comentarii asupra temei:

Am dealocat memorie doar in functiile de stergere. E posibil sa pierd memorie pe undeva. <br>
De asemenea, mi-am schimbat conventiile de numire pentru functii in mijlocul proiectului.Dar sper sa nu fie o problema.<br>
<br>
<br>
### Resurse / Bibliografie:<br> 
https://www.geeksforgeeks.org/stringstream-c-applications/<br>
https://cplusplus.com/reference/vector/vector/<br>
Cursul de SD


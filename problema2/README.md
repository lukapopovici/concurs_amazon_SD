**Nume:Popovici Luka**
**Grupă:1111B**

## Titlu tema
    Baza de date a unei biblioteci
### Descriere:

Baza de date e formata de 2 hashtabeluri de hashtabeluri. Una din ele e cea de useri, care tine cont de datele utilizatorilor bibliotecii,
si cealalta este a bibliotecii propriu zis, care tine cont de cari. 
Felul in care ajung la informatii pentru prima baza de date este
    Numele utlizatorului(cheie)-> Datele utlizatorului(content) + Lista lui de carti (nume,data de imprumut)
iar pentru a doua baza de date
    Numele cartii(cheie)-> Date despre care(content)+ lista cu sinonime(cuvant,sinonim).

Functia de hashin implementata este Polunomial Hashing de gradul 13.Gradul a fost ales aleatoriu.
Am ales aceasta functie deoarece stiam ca tipul cheilor va fi string cu max 20 de caractere, algoritmul e relativ usor de implementat si de inteles,
si in general e foarte eficinet.A trebuit sa o retusez totusi pentru a evita divizia cu 0 in cazul in care hashtabelul meu are size 1.

Nu consider ca e necesar sa explic felul in care merg functiile,doar sa mentionez ca la functia de RETURN voi lua in calcul recenzia unui utilizator banat.

Cele 2 fisiere de test atasate testeaza toate comenzile in diferite scenarii.In prima puteti observa ce se intampla cand am un utilizator care gaseste un mod
sa fure carti,iar in a doua puteti observa cum un utilizator uitic este banat din cauza unei intarzieri, precum si felul in care usnt ordonate umele cu scoruri similare.Pe langa acestea, puteti vedea ca functiile pt definitii merg uns, la fel ca mecanismul de resize.

### Comentarii asupra temei:

* Crezi că ai fi putut realiza o implementare mai bună? Cu singuranta,dar sunt tanar si mai am timp sa invat.
* Ce ai invățat din realizarea acestei teme? Sa fac long long int intodeauna la functie de hashing sa nu risc sa imi iau overflow sa imi dea o pozitie negativa.
A fost distractiv de debuguit.
* Alte comentarii 
        Daca e problema cu dealocarea memoriei,pe Linux rulat pe cmd nu imi apare nimic.    
### (Opțional) Resurse / Bibliografie:

    Stack Overflow

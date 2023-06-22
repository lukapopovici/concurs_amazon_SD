#### Nume: Popovici Luka
#### Grupa: 1111B


# Titlu tema: Baza de date
### Descriere:

Baza de date e formata de 2 hashtabeluri de hashtabeluri. Una din ele e cea de useri, care tine cont de datele utilizatorilor bibliotecii,
si cealalta este a bibliotecii propriu zis, care tine cont de cari. 
Felul in care ajung la informatii pentru prima baza de date este: <br>
<code>Numele utlizatorului(cheie)-> Datele utlizatorului(content) + Lista lui de carti (nume,data de imprumut)<br>
    </code>
iar felul in care ajung la informatie in a doua baza de date este:<br>
<code>Numele cartii(cheie)-> Date despre care(content)+ lista cu sinonime(cuvant,sinonim).
</code>
Functia de hashin implementata este [Polynomial Hashing](https://codeforces.com/blog/entry/100027) (gradul a fost ales aleatoriu).
Am ales aceasta functie deoarece stiam ca tipul cheilor va fi string cu max 20 de caractere, algoritmul e relativ usor de implementat si de inteles,
si in general e foarte eficinet.A trebuit sa o retusez totusi pentru a evita divizia cu 0 in cazul in care hashtabelul meu are size 1.

Nu consider ca e necesar sa explic felul in care merg functiile,doar sa mentionez ca la functia de RETURN voi lua in calcul recenzia unui utilizator banat.

Cele 2 fisiere de test atasate testeaza toate comenzile in diferite scenarii.In prima puteti observa ce se intampla cand am un utilizator care gaseste un mod sa fure carti,iar in a doua puteti observa cum un utilizator uitic este banat din cauza unei intarzieri, precum si felul in care sunt ordonate cartile cu scoruri similare. 

Am structurat programul original ca fiecare utilizator sa poata imprumuta mai multe carti simultan (deoarece nu am citit atent enuntul), motiv pentru care cartile imprumutate de un user sunt reprezentate ca un hashtable.

### Comentarii asupra temei:

* Crezi că ai fi putut realiza o implementare mai bună? <br>Cu singuranta,dar sunt tanar si mai am timp sa invat.
* Ce ai invățat din realizarea acestei teme?<br>Sa fac long long int intodeauna la functie de hashing sa nu risc sa imi iau overflow sa imi dea o pozitie negativa.<br>
<strong>A fost distractiv de debuguit.</strong>

### (Opțional) Resurse / Bibliografie:
    Stack Overflow

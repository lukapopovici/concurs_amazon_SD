#include "header.h"


int main() {
    biblioteca* B=init_biblioteca(2);
    user_DB* U=init_USERS(2);
    string line;
    vector<string> comenzi;

    while (getline(cin, line) && line != "EXIT") {
        stringstream ss(line);
        string comanda;
        while (ss >> comanda) {
            comenzi.push_back(comanda);
        }
        string arg1="",arg2="",arg3="",arg4="";
        if (comenzi.size() >= 2)
            arg1 = comenzi[1];
        if (comenzi.size() >= 3)
            arg2 = comenzi[2];
        if (comenzi.size() >= 4)
            arg3 = comenzi[3];
        if (comenzi.size() == 5)
            arg4 = comenzi[4];
        if(!comenzi.empty())
        interpret(comenzi[0], arg1, arg2,arg3,arg4,B,U);


        comenzi.clear();
    }
    //comenzile de afisare a scorurilor
    get_book_scores(B);
    get_user_scores(U);
    //dealocarea memoriei
    sterge_biblioteca(B);
    sterge_useri(U);
    delete B;
    delete U;
    cout<<"Program terminat!"<<endl;
    return 0;
}
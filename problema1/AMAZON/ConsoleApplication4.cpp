#include "Header.h"

int main() {
    deck* d = 0;
    string line;
    vector<string> comenzi;

    while (getline(cin, line) && line != "EXIT") {
        stringstream ss(line);
        string comanda;
        while (ss >> comanda) {
            comenzi.push_back(comanda);
        }
        int arg1=0, arg2 = 0;
        if (comenzi.size() >= 2)
            arg1 = stoi(comenzi[1]);
        if (comenzi.size() == 3)
            arg2 = stoi(comenzi[2]);
        if(!comenzi.empty())
        interpret(comenzi[0], arg1, arg2, d);


        comenzi.clear();
    }
    delete d;
    return 0;
}
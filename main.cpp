#include <iostream>
#include <fstream>
#include <cstring>
#include "string"
#include "cost.h"

using namespace std;

int main() {

    ifstream pfile;
    pfile.open("cost.txt");
    char str[100];

    struct Cost summ;
    summ.hrn = 0;
    summ.kop = 0;

    while (pfile.getline(str, 100)) {
        cout << str << "\n";

        string tokens[3];

        char* next_token1 = NULL;
        char* token = strtok_r(str, " ", &next_token1);
        int i = 0;

        while (token != NULL) {
            tokens[i] = token;
            token = strtok_r(NULL, " ", &next_token1);
            i++;
        }

        if (i < 3) {
            cout << "Invalid input format: " << str << endl;
            continue;
        }

        struct Cost a;
        a.hrn = stoi(tokens[0]);
        a.kop = stoi(tokens[1]);
        int col = stoi(tokens[2]);
        summ = sum(mult(a, col), summ);
    }

    cout << "Total cost: ";
    to_str(summ);
    cout << "Rounded cost: ";
    to_str(c_round(summ));
    pfile.close();

}
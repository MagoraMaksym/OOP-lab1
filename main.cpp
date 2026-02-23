#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "cost.h"

using namespace std;

int main() {
    ifstream pfile("cost.txt");
    if (!pfile.is_open()) {
        cout << "Помилка: файл не знайдено!" << endl;
        return 1;
    }

    Cost total_sum = {0, 0};
    string line;

    while (getline(pfile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string product_name;
        
        getline(ss, product_name, ',');

        int h, k, q;
        string temp;

        ss >> h >> temp >> k >> temp; 
        
        if (ss.peek() == ',' || ss.peek() == ' ') ss.ignore();
        
        ss >> q >> temp; 

        cout << "" << product_name << " Сума: " << h << "грн " << k << "коп x " << q << endl;

        total_sum.add_item(h, k, q);
    }

    cout << "Загальна сума: ";
    total_sum.print();

    total_sum.round_to_10();
    cout << "Після заокруглення (<5->0, >=5->10): ";
    total_sum.print();

    pfile.close();
    return 0;
}

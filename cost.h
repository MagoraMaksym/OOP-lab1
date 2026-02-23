#ifndef COST_H
#define COST_H

#include <iostream>
#include <string>

struct Cost {
    int hrn;
    int kop;

    void add_item(int h, int k, int count) {
        int total_kop = (h * 100 + k) * count;
        this->hrn += total_kop / 100;
        this->kop += total_kop % 100;

        if (this->kop >= 100) {
            this->hrn += this->kop / 100;
            this->kop %= 100;
        }
    }

    void round_to_10() {
        int last_digit = this->kop % 10;
        if (last_digit < 5) {
            this->kop -= last_digit;
        } else {
            this->kop += (10 - last_digit);
        }

        if (this->kop >= 100) {
            this->hrn += 1;
            this->kop = 0;
        }
    }

    void print() {
        std::cout << hrn << " грн " << (kop < 10 ? "0" : "") << kop << " коп" << std::endl;
    }
};

#endif

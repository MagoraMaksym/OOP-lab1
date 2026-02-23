#include "cost.h"

void Cost::add(Cost other) {
    this->kop += other.kop;
    this->hrn += other.hrn + (this->kop / 100);
    this->kop %= 100;
}

void Cost::multiply(int quantity) {
    int total_kop = (this->hrn * 100 + this->kop) * quantity;
    this->hrn = total_kop / 100;
    this->kop = total_kop % 100;
}

void Cost::roundTo5() {

    int remainder = this->kop % 5;
    if (remainder < 3) {
        this->kop -= remainder;
    } else {
        this->kop += (5 - remainder);
    }

    if (this->kop >= 100) {
        this->hrn += 1;
        this->kop = 0;
    }
}

void Cost::display() const {
    std::cout << hrn << " грн " << (kop < 10 ? "0" : "") << kop << " коп" << std::endl;
}

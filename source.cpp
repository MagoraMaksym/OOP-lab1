#include <iostream>
#include "cost.h"
using namespace std;

struct Cost sum(struct Cost a, struct Cost b){
    struct Cost result;
    result.kop = a.kop + b.kop;
    result.hrn = a.hrn + b.hrn;

    if (result.kop >= 100){
        result.hrn += 1;
        result.kop = result.kop - 100;
    }
    return result;
}

struct Cost mult(struct Cost a, int b){
    struct Cost result;
    result.kop = a.kop * b;
    result.hrn = a.hrn * b;

    if (result.kop >= 100){
        result.hrn += (result.kop / 100);
        result.kop = result.kop % 100;
    }
    return result;
}

struct Cost c_round(struct Cost a){
    struct Cost result;
    result.hrn = a.hrn;
    result.kop = a.kop;
    if (a.kop % 10 >= 5){
        result.kop = (a.kop/10) * 10 + 10;
    }
    else{
        result.kop = (a.kop/10) * 10;
    }

    if (result.kop >= 100){
        result.hrn = result.hrn + 1;
        result.kop = result.kop - 100;
    }
    return result;


}

void to_str(struct Cost a){
    cout << a.hrn << " hrn " << a.kop << " kop" << endl;
}
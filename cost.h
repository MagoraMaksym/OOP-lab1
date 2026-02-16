#ifndef USER_H
#define USER_H
using namespace std;

struct Cost {
    int hrn;
    short int kop;

};

struct Cost sum(struct Cost a, struct Cost b);
struct Cost mult(struct Cost a, int b);
struct Cost c_round(struct Cost a);
void to_str(struct Cost a);
#endif
using namespace std;

#ifndef TOKENAIZER_TOKENAIZER_H
#define TOKENAIZER_TOKENAIZER_H

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <list>
#include <vector>

class tokenaizer {
    char* s; // исходная строка
    int len_s; // длина исходной строки (для перегрузки <<)

    list <int> len; // список, хранящий номера и длины токенов

    char del[512]; // набор разделителей
    int len_del; //кол-во разделителей
public:
    tokenaizer(char* a, int len);
    ~tokenaizer();
    char* initialize(char* filename);
    char* spl(tokenaizer a);
    friend ostream& operator << (ostream&, const tokenaizer&);
};

#endif //TOKENAIZER_TOKENAIZER_H

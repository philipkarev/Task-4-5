using namespace std;

#ifndef TOKENAIZER_TOKENAIZER_H
#define TOKENAIZER_TOKENAIZER_H

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <list>

class tokenaizer{
    char* s; // исходная строка
    int len_s; // длина исходной строки (для перегрузки <<)
    list <int> len; // список, хранящий номера и длины токенов
    char* del; // набор разделителей
public:
    tokenaizer(char* a, int len);

    friend ostream& operator << (ostream&, const tokenaizer&);
};

#endif //TOKENAIZER_TOKENAIZER_H

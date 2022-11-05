#ifndef TOKENAIZER_TOKENAIZER_H
#define TOKENAIZER_TOKENAIZER_H

#include <iostream>
#include <fstream>

#include <cstring>
#include <string>

#include <list>
#include <iterator>
#include <vector>

#include "list.h"

using namespace std;

class tokenaizer {
    char del[512]; // набор разделителей
    int len_del; //кол-во разделителей
    int c_del = 0; // проверка, был ли задан набор разделителей

    char* s; // исходная строка
    int len_s = 0; // длина исходной строки

    char** ss; // массив массивов char (это и есть разбитая строка)
    int num_toc; // кол-во токенов
    int c_spl = 0; // переменная-счётчик для проверки, делилась ли строка (иначе мы не сможем использовать некоторые методы)

    char* t = nullptr; // некоторый конкретный токен
    int c_t = 0; // переменная-счётчик, чтобы понять вызывался ли метод get_token

//    list <int> len; // список, хранящий номера и длины токенов (не понимаю, зачем он нужен, это же неудобно)
//    vector <int> v; // вектор, хранящий номера и длины токенов (так, например, удобнее)

    List lst; // список, хранящий номера и длины токено
public:
    tokenaizer(char* a, int len);
    ~tokenaizer();

    void initialize(char* filename);
    int spl(); // разбить строку на подстроки
    int numbtoc(); // получить количество токенов
    int iterator(int n); // просмотр, начиная с n-ого токена
    char* get_token(int n); // получить токен с номером n (нумерация с нуля)
    int change_del(char*, int l); // поменять набор разделителей в строке
};

#endif //TOKENAIZER_TOKENAIZER_H

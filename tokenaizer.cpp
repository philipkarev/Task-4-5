#include "tokenaizer.h"

tokenaizer::tokenaizer(char *a, int len) {

    //cout << "Called constructor" << endl;

    if (len <= 0) {
        cout << "Error: invalid value of len" << endl;
    } else {
        len_s = len;

        s = new char[len_s];
        for (int i = 0; i < len_s; ++i)
            s[i] = a[i];

        ss = new char *[len_s];
        for (int i = 0; i < len_s; ++i)
            ss[i] = new char[len_s];

    }
}

tokenaizer::~tokenaizer() {

    //cout << "Called destructor" << endl;

    if (len_s <= 0) {
        cout << "Error: invalid value of len" << endl;
    } else {

        delete[] s;

        for (int i = 0; i < len_s; ++i)
            delete[] ss[i];
        delete[] ss;

        delete[] t;
    }
}

void tokenaizer::initialize(char* filename) {

    //string path = "delim.txt";

    ++c_del;

    ifstream fin;
    fin.open(filename);

    if (!fin.is_open()) {
        cout << "[initialize]Error: could not open the file." << endl;
    } else {

        //cout << "file is open" << endl;

        char ch;
        int i = 0;

        while (fin.get(ch)) {
            del[i] = ch;
            ++i;
        }
        del[i+1] = '\0';
        len_del = i;
        if (len_del <= 1) {
            cout << "[initialize]File with separators is empty." << endl;
            c_del = -1;
        }
    }

    fin.close();
    exit(1);
}

int tokenaizer::spl() {

    if (c_spl > 0){
        cout << "[spl]Error. String already splitted." << endl;
        return -1;
    }

    if (c_del <= 0){
        cout << "[spl]Error: problems with separators" << endl;
        return -1;
    }

    ++c_spl;

    if (len_s == 0){
        cout << "error" << endl;
        return -1;
    }
    char* pch = strtok (s, del);

    int k = 0;

    list <int> :: iterator  it = len.begin();

    cout << "\n-------------\nPrint tokens:\n";

    while (pch != NULL) { // пока есть лексемы
        size_t j = 0;
        for (j = 0; j < strlen(pch); ++j) {
            ss[k][j] = pch[j];
            cout << ss[k][j];
        }
        cout << "\n";

        v.push_back((int)j);

        len.insert(it, (int)j);
        it++;

        pch = strtok (NULL, del);
        ++k;
    }
    cout << "-------------" << endl;

    num_toc = k; // вообще, их k + 1

    return 0;
}

int tokenaizer::numbtoc() {

    if (c_spl <= 0){
        cout << "[numbtoc]The string was not split. Number of tokens = 1" << endl;
        return 1;
    }

    if (c_del <= 0){
        cout << "[numbtoc]Error: problems with separators." << endl;
        return -1;
    }

    cout << "\n----------------\nNumber of tokens\n" << num_toc << "\n----------------"<< endl;
    return num_toc + 1;
}

int tokenaizer::iterator(int n) {

    if (num_toc < n){
        cout << "[iterator] Error: invalid value of n." << endl;
        return -1;
    }

    if (c_del <= 0){
        cout << "[iterator]Error: problems with separators" << endl;
        return -1;
    }

    if (c_spl <= 0){
        cout << "[iterator]The string was not split." << endl;
        return -1;
    }

    cout << "\n--------------------------------------------------------\n";
    cout << "The iterator called. You can view tokens starting from " << n << endl;

    for (int i = n; i < num_toc; ++i) {
        for (int j = 0; j < v[i]; ++j)
            cout << ss[i][j];
        cout << endl;
    }
    cout << "--------------------------------------------------------\n";

    return 0;
}

char* tokenaizer::get_token(int n){

    if (num_toc < n){
        cout << "[get_token] Error: invalid value of n." << endl;
        return NULL;
    }

    if (c_del <= 0){
        cout << "[get_token]Error: problems with separators" << endl;
        return NULL;
    }

    if (c_spl <= 0){
        cout << "[get_token]The string was not split." << endl;
        return NULL;
    }

    cout << "\n-----------------------\nGet token with number " << n << endl;

    if (c_t > 0) // проверяем, вызывался ли уже этот метод
        delete [] t; // если да, очистим память

    t = new char[v[n]]; // выделяем память под t

    for (int i = 0; i < v[n]; ++i) // заполняем t
        t[i] = ss[n][i];

    c_t++;

    for (int i = 0; i < v[n]; ++i) // выводим, чем заполнили t
        cout << t[i];

    cout << "\n-----------------------\n";
    return t;
}

int tokenaizer::change_del(char* st, int l){

    if (l <= 0){
        cout << "[change_del] Error: invalid value of n." << endl;
        return -1;
    }

    cout << "\n------------------\nSeparators changed" << endl;

    int i;
    for (i = 0; i < l; ++i)
        del[i] = st[i];
    del[i+1] = '\0';

    for (int j = 0; j < l; ++j)
        cout << del[j];

    cout << "\n------------------\n";

    return 0;
}

/*int split(char* st, char* d, int lS, int lD){
    for (int i = 0; i < lS; ++i) {
        for (int j = 0; j < lD; ++j) {
            if (d[j] == st[i]){
                continue;
            }

        }
    }
}*/

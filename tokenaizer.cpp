#include "tokenaizer.h"

tokenaizer::tokenaizer(char *a, int len) {

    this -> len_s = len;

    s = new char [len];
    for (int i = 0; i < len; ++i)
        s[i] = a[i];
}

char* tokenaizer::initialize(char* filename) {

    string path = "delim.txt";

    ifstream fin;
    fin.open(filename);

    if (!fin.is_open()) {
        cout << "error: could not open the file" << endl;
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
        if (len_del == 0)
            cout << "File with separators is empty" << endl;
    }

    fin.close();

    return del;
}

tokenaizer::~tokenaizer() {

    delete[] s;
}

/*char* tokenaizer::spl(tokenaizer a) {

    vector <char> v;
    //char str[] = "Особенности национальной рыбалки - художественный, комедийный фильм.";

    int i = 0;
    v[i] = strtok (a.s," ,.-");

    while (v[i] != NULL) {
        ++i;
        v[i] = strtok (NULL, " ,.-");
    }
    return 0;

}*/

ostream& operator << (ostream &stream, const tokenaizer& s) {

    for (int i = 0; i < s.len_s - 1; i++)
        stream << s.s[i];

    return stream;
}

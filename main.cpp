#include "tokenaizer.h"

int main() {

    /*char s[] = "Hello, Wor,l,d!";
    char *str = strtok(s, ",");
    cout << "\n" << str << "\n";
    str = strtok(NULL, ",");
    cout << str << "\n";
    str = strtok(NULL, ",");
    cout << str << "\n";
    str = strtok(NULL, ",");
    cout << str << "\n";*/

    char str1[] = "Hello, World!"; // cout << strlen(str1) << endl; cout << str1[12] << endl;

    //char str2[3]; str2[0] = 1; str2[1] = 2; cout << str2[2] << endl;

    tokenaizer obj(str1, strlen(str1)+1);
    //cout << obj;

    /*string path = "delim.txt";

    ifstream fin;
    fin.open(path);

    if (!fin.is_open()) {
        cout << "error: could not open the file" << endl;
    } else {
        cout << "file is open" << endl;
        char ch;
        while (fin.get(ch[i]))
            cout << ch;
    }

    fin.close();*/



    /*char str[] = "Hello world!";
    cout << str << endl;
    for (size_t i = 0; i < strlen(str); ++i)
        cout << str[i];
    cout << "\n";
    vector <string> v(2);
    v[0] = "Hello"; v[1] = " "; v.push_back("world"); v.push_back("!");
    //int i = size.v();
    //for (size_t i = 0; i < size.v( ); ++i)
        //cout << v[i] << endl;*/
    //char path[] = "delim.txt";
    //char* razd = obj.initialize(path);

    return 0;
}

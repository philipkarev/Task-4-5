#include "tokenaizer.h"
#include "list.h"

int main() {

    char string1[] = "Hello, world! My name is Philip.";
    char string2[] = "lMP";

    char name[] = "delim.txt";

    tokenaizer x(string1, (int)strlen(string1)+1);
    x.initialize(name);
    x.spl(); x.spl(); x.spl();
    x.numbtoc(); x.numbtoc();
    x.iterator(0); x.iterator(3); x.iterator(100);
    x.get_token(1); x.get_token(100);

    x.change_del(string2, 0);
    x.change_del(string2, (int)strlen(string2)+1);
    x.spl();

    tokenaizer y(string2, (int)strlen(string2)+1);
    y.initialize(name);
    y.spl();

    char string3[] = "   ";
    tokenaizer z(string3, (int)strlen(string3)+1);
    z.initialize(name);
    z.spl();
    z.get_token(2);
    z.numbtoc();

    char string4[] = "";
    tokenaizer w(string3, (int)strlen(string4)+1);
    w.initialize(name);
    w.spl();


    /*List lst;

    lst.push_back(5);
    lst.push_back(7);
    lst.push_back(9);

    cout << "lst.get_size() = " << lst.get_size() << endl;
    cout << "lst[2] = " << lst[2] << endl;

    for (int i = 0; i < lst.get_size(); ++i)
        cout << lst[i] << endl;

    lst.pop_front(); lst.pop_front();
    for (int i = 0; i < lst.get_size(); ++i)
        cout << lst[i] << endl;

    lst.push_back(5);
    lst.push_back(7);
    lst.push_back(9);
    cout << "lst.get_size() = " << lst.get_size() << endl;

    lst.clear();
    cout << "lst.get_size() = " << lst.get_size() << endl;*/

    return 0;
}

#include "tokenaizer.h"

int main() {

    char string1[] = "Hello, world! My name is Philip.";
    char string2[] = "aaaaaaaaaaaaaaaaaaaaaa";

    char name[] = "delim.txt";

    tokenaizer x(string1, (int)strlen(string1));
    x.initialize(name); return 0;
    x.spl(); x.spl();
    x.numbtoc(); return 0;
    x.iterator(0); x.iterator(3); x.iterator(100);
    x.get_token(1); x.get_token(100);

    x.change_del(string2, 0);
    return 0;

    tokenaizer y(string2, (int)strlen(string2));
    y.initialize(name);
    y.spl();

    char string3[] = "   ";
    tokenaizer z(string3, (int)strlen(string3));
    z.initialize(name);
    z.spl();
    cout << "before 28" << endl;
    z.get_token(2);
    cout << "after 28" << endl;
    z.numbtoc();

    return 0;
}

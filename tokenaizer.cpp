#include "tokenaizer.h"

tokenaizer::tokenaizer(char *a, int len) {

    this -> len_s = len;

    for (int i = 0; i < len; ++i)
        s[i] = a[i];
}

ostream& operator << (ostream &stream, const tokenaizer& s) {

    for (int i = 0; i < s.len_s - 1; i++)
        stream << s.s[i];

    return stream;
}

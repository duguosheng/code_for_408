#include "kmp.h"
using namespace std;

int main(void) {
    SqString str1("abbaaababaa");
    SqString str2("babaa");
    cout << IndexKMP(str1, str2);
}
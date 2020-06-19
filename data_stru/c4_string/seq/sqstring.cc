#include "sqstring.h"

#include <cstring>
using namespace std;

SqString::SqString() : length(0) {
    memset(ch, 0, sizeof(ch));
}

SqString::SqString(const char* s) : SqString() {
    for (int i = 0;; ++i) {
        if (s[i] == '\0' || i > MAX_SIZE - 1)
            break;
        ch[i] = s[i];
        ++length;
    }
}

SqString::SqString(const string& s) : SqString(s.c_str()) {}

bool SqString::Empty() const {
    if (Length())
        return false;
    return true;
}

size_t SqString::Length() const {
    return length;
}

char SqString::At(int n) const {
    return ch[n - 1];
}

void SqString::Assign(const char* s) {
    for (int i = 0;; ++i) {
        if (s[i] == '\0' || i > MAX_SIZE - 1)
            break;
        ch[i] = s[i];
        ++length;
    }
}

int SqString::Compare(const SqString& s) {
    //逐个比较
    for (int i = 0; i < Length() && i < s.Length(); ++i) {
        if (ch[i] > s.At(i + 1))
            return 1;
        else if (ch[i] < s.At(i + 1))
            return -1;
    }
    //全部相等,比较长度
    if (Length() > s.Length())
        return 1;
    else if (Length() < s.Length())
        return -1;
    else
        return 0;
}
SqString SqString::SubString(int pos, int len) {
    char* sub = ch + pos - 1;
    return SqString(sub);
}

int SqString::Index(SqString sub) {
    //后续利用Kmp实现
    return 0;
}

char& SqString::operator[](size_t n) {
    cout << "n=" << n;
    return ch[n - 1];
}

const char& SqString::operator[](size_t n) const {
    return ch[n - 1];
}

SqString& SqString::operator+=(const SqString& rhs) {
    size_t i;
    for (i = 1; i <= rhs.Length(); ++i) {
        if (i + length > MAX_SIZE)
            break;
        cout << "i2:" << i << " " << rhs[i] << endl;
        // ch起始下标为0,rhs起始下标为1
        ch[i - 1 + length] = rhs[i];
    }
    length += i;
    return *this;
}

bool SqString::operator==(const SqString& rhs) {
    if (Compare(rhs) == 0)
        return true;
    return false;
}
bool SqString::operator!=(const SqString& rhs) {
    if (Compare(rhs) != 0)
        return true;
    return false;
}
bool SqString::operator<(const SqString& rhs) {
    if (Compare(rhs) > 0)
        return true;
    return false;
}
bool SqString::operator>(const SqString& rhs) {
    if (Compare(rhs) < 0)
        return true;
    return false;
}

void SqString::Clear() {
    memset(ch, 0, sizeof(ch));
    length = 0;
}

SqString operator+(const SqString& lhs, const SqString& rhs) {
    SqString sum = lhs;
    sum += rhs;
    return sum;
}

ostream& operator<<(ostream& os, const SqString& item) {
    for (size_t i = 1; i <= item.Length(); ++i)
        os << item[i];
    return os;
}
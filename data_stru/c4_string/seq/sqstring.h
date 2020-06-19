/**
 * @author: GodSon
 * @date: 2020-06-17 17:10:21
 * @lasttime: 2020-06-17 17:15:19
 * @description: 串的顺序存储.第一个元素的下标为1,为了实现书中的KMP
 */

#ifndef SQSTRING_H
#define SQSTRING_H
#include <iostream>
#include <string>

#define MAX_SIZE 1000

class SqString {
    friend SqString operator+(const SqString& lhs, const SqString& rhs);
    friend std::ostream& operator<<(std::ostream& os, const SqString& item);

public:
    SqString();
    SqString(const char* s);
    SqString(const std::string& s);
    std::size_t Length() const;        //长度
    bool Empty() const;                //判空
    char At(int n) const;              //获取元素
    void Assign(const char* s);        //赋值,太长截断
    int Compare(const SqString& str);  //比较
    //返回从第pos个字符起，长度为len的子串
    SqString SubString(int pos, int len);
    int Index(SqString sub);  //找寻子串位置
    void Clear();             //清空

    //定义下标运算符
    char& operator[](std::size_t n);
    const char& operator[](std::size_t n) const;
    //赋值运算符
    SqString& operator+=(const SqString& rhs);
    //关系运算符
    bool operator==(const SqString& rhs);
    bool operator!=(const SqString& rhs);
    bool operator<(const SqString& rhs);
    bool operator>(const SqString& rhs);

private:
    char ch[MAX_SIZE];   //字符
    std::size_t length;  //长度
};

SqString operator+(const SqString& lhs, const SqString& rhs);
std::ostream& operator<<(std::ostream& os, const SqString& item);
#endif
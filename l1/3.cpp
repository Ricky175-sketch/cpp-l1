#include <iostream>

using namespace std;

#define offset(TYPE,MEMBER) ((long)&((TYPE *)0)->MEMBER)

#pragma pack(push)
#pragma pack(2) // ָ��������1�ֽڶ���
struct A
{
    short var;
    int var1;
    long var2;
    char var3;
    string s;
};
#pragma pack(pop)

int main3()
{
    string s;
    A ex1;

    // ����ṹ����ÿ��������ƫ�Ƶ�ַ
    cout << offset(A, var) << endl;
    cout << offset(A, var1) << endl;
    cout << offset(A, var2) << endl;
    cout << offset(A, var3) << endl;
    cout << offset(A, s) << endl;
    cout << sizeof(ex1) << endl;

    cout << alignof(A) << endl; // ���ص�ǰ�������ֽڶ��뷽ʽ

    return 0;
}
#include <iostream>

using namespace std;
using ptr = int*;
using pptr = int**;
using std::cout;
using std::endl;

int main() {
    int a = 5;
    int b = 10;
    ptr p1 = &a;
    pptr p2 = &p1;
    ptr p3 = p1;
    ptr* p4 = &p1;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "*p2: " << *p2 << endl;
    cout << "p3: " << p3 << endl;
    cout << "*p3: " << *p3 << endl;
    cout << "p4: " << p4 << endl;
    cout << "*p4: " << *p4 << endl;
}
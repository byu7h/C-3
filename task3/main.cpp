#include "MyArray.h"
#include <iostream>
using namespace std;

int main() {
    // 1. 基础测试
    MyArray A(3);
    A.set(0, 6);
    A.set(1, 8);
    A.set(2, 9);

    MyArray B(3);
    B.set(0, 3);
    B.set(1, 2);
    B.set(2, 4);

    cout << "A = ";
    A.display();
    cout << endl;

    cout << "B = ";
    B.display();
    cout << endl;

    MyArray M = A.merge(B);
    cout << "A merge B = ";
    M.display();
    cout << endl;

    MyArray Add = A.add(B);
    cout << "A + B = ";
    Add.display();
    cout << endl;

    MyArray Sub = A.subtract(B);
    cout << "A - B = ";
    Sub.display();
    cout << endl;

    MyArray Mul = A.multiply(B);
    cout << "A * B = ";
    Mul.display();
    cout << endl;

    MyArray Div = A.divide(B);
    cout << "A / B = ";
    Div.display();
    cout << endl;

    // 2. 深拷贝测试
    MyArray E = A;
    E.set(0, 100);
    cout << "After E = A; E.set(0, 100):" << endl;
    cout << "A = ";
    A.display();
    cout << endl;
    cout << "E = ";
    E.display();
    cout << endl;

    // 3. 长度不一样测试（题目要求的部分）
    cout << "\n--- 长度不一致测试 ---" << endl;
    
    MyArray C(3);
    C.set(0, 1);
    C.set(1, 2);
    C.set(2, 3);

    MyArray D(2);
    D.set(0, 4);
    D.set(1, 5);

    cout << "C = ";
    C.display();
    cout << endl;

    cout << "D = ";
    D.display();
    cout << endl;

    // 这里触发 Warning 提示，并且只计算前2个元素
    MyArray CD = C.add(D);
    cout << "C + D = ";
    CD.display();
    cout << endl;

    return 0;
}

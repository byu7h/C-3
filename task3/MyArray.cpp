#include "MyArray.h"
#include <iostream>
using namespace std;

MyArray::MyArray() : p(nullptr), N(0) {
}

MyArray::MyArray(int n, int value) : p(nullptr), N(0) {
    if (n < 0) {
        cout << "Error: negative size, create empty array" << endl;
        return;
    }

    if (n == 0) {
        return;
    }

    N = n;
    p = new int[N];
    for (int i = 0; i < N; i++) {
        p[i] = value;
    }
}

MyArray::MyArray(const MyArray& other) : p(nullptr), N(other.N) {
    if (N > 0) {
        p = new int[N];
        for (int i = 0; i < N; i++) {
            p[i] = other.p[i];
        }
    }
}

MyArray::~MyArray() {
    delete[] p;
    p = nullptr;
    N = 0;
}

int MyArray::size() const {
    return N;
}

int MyArray::get(int index) const {
    if (index < 0 || index >= N) {
        cout << "Error: index out of range" << endl;
        return 0;
    }
    return p[index];
}

void MyArray::set(int index, int value) {
    if (index < 0 || index >= N) {
        cout << "Error: index out of range" << endl;
        return;
    }
    p[index] = value;
}

void MyArray::display() const {
    cout << "{";
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << p[i];
    }
    cout << "}";
}

MyArray MyArray::merge(const MyArray& other) const {
    MyArray result(N + other.N);

    for (int i = 0; i < N; i++) {
        result.p[i] = p[i];
    }
    for (int i = 0; i < other.N; i++) {
        result.p[N + i] = other.p[i];
    }

    return result;
}

MyArray MyArray::add(const MyArray& other) const {
    int m = (N < other.N) ? N : other.N;

    if (N != other.N) {
        cout << "Warning: different sizes (" << N << " vs "
             << other.N << "), use the shorter one" << endl;
    }

    MyArray result(m);
    for (int i = 0; i < m; i++) {
        result.p[i] = p[i] + other.p[i];
    }
    return result;
}

MyArray MyArray::subtract(const MyArray& other) const {
    int m = (N < other.N) ? N : other.N;

    if (N != other.N) {
        cout << "Warning: different sizes (" << N << " vs "
             << other.N << "), use the shorter one" << endl;
    }

    MyArray result(m);
    for (int i = 0; i < m; i++) {
        result.p[i] = p[i] - other.p[i];
    }
    return result;
}

MyArray MyArray::multiply(const MyArray& other) const {
    int m = (N < other.N) ? N : other.N;

    if (N != other.N) {
        cout << "Warning: different sizes (" << N << " vs "
             << other.N << "), use the shorter one" << endl;
    }

    MyArray result(m);
    for (int i = 0; i < m; i++) {
        result.p[i] = p[i] * other.p[i];
    }
    return result;
}

MyArray MyArray::divide(const MyArray& other) const {
    int m = (N < other.N) ? N : other.N;

    if (N != other.N) {
        cout << "Warning: different sizes (" << N << " vs "
             << other.N << "), use the shorter one" << endl;
    }

    MyArray result(m);
    for (int i = 0; i < m; i++) {
        if (other.p[i] == 0) {
            cout << "Warning: division by zero at index " << i
                 << ", result set to 0" << endl;
            result.p[i] = 0;
        } else {
            result.p[i] = p[i] / other.p[i];
        }
    }
    return result;
}

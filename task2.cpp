#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

class Triangle {
private:
    double a;
    double b;
    double c;

    bool validSide(double s) const { return s > 0; }

public:
    Triangle(double a = 1, double b = 1, double c = 1) : a(1), b(1), c(1) {
        if (validSide(a) && validSide(b) && validSide(c)) {
            this->a = a; this->b = b; this->c = c;
        } else {
            cout << "Invalid side(s), set to 1" << endl;
        }
    }

    void Init(double a, double b, double c) {
        if (validSide(a) && validSide(b) && validSide(c)) {
            this->a = a; this->b = b; this->c = c;
        } else {
            cout << "Invalid side(s), set to 1" << endl;
            this->a = 1; this->b = 1; this->c = 1;
        }
    }

    bool isTriangle() const {
        if (!validSide(a) || !validSide(b) || !validSide(c)) return false;
        return a + b > c && a + c > b && b + c > a;
    }

    double getSideA() const { return a; }
    double getSideB() const { return b; }
    double getSideC() const { return c; }

    void setSideA(double a) { if (validSide(a)) this->a = a; else cout << "Invalid side A" << endl; }
    void setSideB(double b) { if (validSide(b)) this->b = b; else cout << "Invalid side B" << endl; }
    void setSideC(double c) { if (validSide(c)) this->c = c; else cout << "Invalid side C" << endl; }

    double perimeter() const { return a + b + c; }

    double area() const {
        if (!isTriangle()) {
            cout << "Error: cannot form a triangle" << endl;
            return 0;
        }
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    int typeTriangle() const {
        if (!isTriangle()) return 0;
        
        double x = a, y = b, z = c;
        if (x > z) swap(x, z);
        if (y > z) swap(y, z);

        double eps = 1e-6;
        if (fabs(x * x + y * y - z * z) < eps) return 1;      // 直角
        else if (x * x + y * y > z * z) return 2;             // 锐角
        else return 3;                                        // 钝角
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "Sides: " << a << " " << b << " " << c << endl;
        if (!isTriangle()) {
            cout << "Error: cannot form a triangle" << endl;
            return;
        }
        const char* typeNames[] = {"不构成三角形", "直角三角形", "锐角三角形", "钝角三角形"};
        cout << "Perimeter: " << perimeter() << endl;
        cout << "Area: " << area() << endl;
        cout << "Type: " << typeNames[typeTriangle()] << endl;

        // 选做提高要求：等腰/等边判断
        double eps = 1e-6;
        if (fabs(a - b) < eps && fabs(b - c) < eps) {
            cout << "Special: 等边三角形" << endl;
        } else if (fabs(a - b) < eps || fabs(a - c) < eps || fabs(b - c) < eps) {
            cout << "Special: 等腰三角形" << endl;
        }
    }
};

int main() {
    double a, b, c;
    cout << "输入三边: ";
    cin >> a >> b >> c;

    Triangle t(a, b, c);
    t.display();

    return 0;
}

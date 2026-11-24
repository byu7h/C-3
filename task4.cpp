#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

class Point {
private:
    double x;
    double y;
    double z;

public:
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    void Init(double x, double y, double z) {
        this->x = x; this->y = y; this->z = z;
    }

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }

    void display() const {
        cout << fixed << setprecision(2) << "(" << x << ", " << y << ", " << z << ")";
    }

    // 对比用的成员函数
    double distanceTo(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        double dz = z - other.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    // 友元函数声明
    friend double euclideanDistance(const Point& a, const Point& b);
    friend double manhattanDistance(const Point& a, const Point& b);
    friend double chebyshevDistance(const Point& a, const Point& b);
    friend Point midpoint(const Point& a, const Point& b);
    
    // 提高要求：点到原点的欧氏距离
    friend double euclideanDistance(const Point& p);
};

// 友元函数类外实现
double euclideanDistance(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

double manhattanDistance(const Point& a, const Point& b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y) + fabs(a.z - b.z);
}

double chebyshevDistance(const Point& a, const Point& b) {
    double dx = fabs(a.x - b.x);
    double dy = fabs(a.y - b.y);
    double dz = fabs(a.z - b.z);
    return max({dx, dy, dz}); // C++11 初始化列表
}

Point midpoint(const Point& a, const Point& b) {
    return Point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0, (a.z + b.z) / 2.0);
}

// 友元函数重载：点到原点
double euclideanDistance(const Point& p) {
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

int main() {
    double x1, y1, z1, x2, y2, z2;
    cout << "输入A点坐标: ";
    cin >> x1 >> y1 >> z1;
    cout << "输入B点坐标: ";
    cin >> x2 >> y2 >> z2;

    Point A(x1, y1, z1);
    Point B(x2, y2, z2);

    cout << "A = "; A.display(); cout << endl;
    cout << "B = "; B.display(); cout << endl;
    
    cout << fixed << setprecision(2);
    cout << "Euclidean distance: " << euclideanDistance(A, B) << endl;
    cout << "Manhattan distance: " << manhattanDistance(A, B) << endl;
    cout << "Chebyshev distance: " << chebyshevDistance(A, B) << endl;
    
    cout << "Midpoint: ";
    midpoint(A, B).display();
    cout << endl;

    // 对比测试成员函数与友元函数
    cout << "Member function A.distanceTo(B): " << A.distanceTo(B) << endl;

    // 提高要求重载测试
    cout << "A to origin (Overloaded): " << euclideanDistance(A) << endl;

    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

    bool isLeap(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int y, int m) const {
        static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && isLeap(y)) return 29;
        if (m >= 1 && m <= 12) return days[m];
        return 0;
    }

    bool isValid(int y, int m, int d) const {
        if (y < 1 || m < 1 || m > 12 || d < 1) return false;
        return d <= daysInMonth(y, m);
    }

public:
    Date(int y = 1900, int m = 1, int d = 1) : year(1900), month(1), day(1) {
        if (isValid(y, m, d)) {
            year = y;
            month = m;
            day = d;
        } else {
            cout << "Invalid date, set to 1900-01-01" << endl;
        }
    }

    void Init(int y, int m, int d) {
        if (isValid(y, m, d)) {
            year = y; month = m; day = d;
        } else {
            cout << "Invalid date, set to 1900-01-01" << endl;
            year = 1900; month = 1; day = 1;
        }
    }

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

    void setYear(int y) {
        if (y >= 1 && isValid(y, month, day)) year = y;
        else cout << "Invalid year, ignored" << endl;
    }
    void setMonth(int m) {
        if (isValid(year, m, day)) month = m;
        else cout << "Invalid month, ignored" << endl;
    }
    void setDay(int d) {
        if (isValid(year, month, d)) day = d;
        else cout << "Invalid day, ignored" << endl;
    }

    void display() const {
        cout << setfill('0') << setw(4) << year << "-"
             << setw(2) << month << "-"
             << setw(2) << day << setfill(' ');
    }

    int calWeekday() const {
        int y = year;
        int m = month;
        int d = day;
        if (m == 1 || m == 2) {
            m += 12;
            y--;
        }
        int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
        if (w < 0) w += 7;
        return w;
    }

    // 提高要求
    bool isLeapYear() const { return isLeap(year); }
    
    void nextDay() {
        if (day < daysInMonth(year, month)) {
            day++;
        } else {
            day = 1;
            if (month < 12) month++;
            else { month = 1; year++; }
        }
    }
};

int main() {
    int y, m, d;
    cout << "输入: ";
    cin >> y >> m >> d;

    Date date(y, m, d);
    const char* weekdays[] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};

    cout << "Date: ";
    date.display();
    cout << "\nWeekday: " << weekdays[date.calWeekday()] << endl;

    // 选做提高要求测试
    cout << "--- 提高要求测试 ---" << endl;
    cout << "Is Leap Year: " << (date.isLeapYear() ? "Yes" : "No") << endl;
    date.nextDay();
    cout << "Next Day: ";
    date.display();
    cout << endl;

    return 0;
}

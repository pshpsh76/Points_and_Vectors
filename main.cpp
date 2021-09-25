#include <iostream>
#include <cmath>

using namespace std;

class Point{
private:
    int x, y;
public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    int get_x() const {
        return x;
    }
    int get_y() const {
        return y;
    }
    void set_x(int _x) {
        x = _x;
    }
    void set_y(int _y) {
        y = _y;
    }
    Point operator+(const Point& b) const {
        return Point(x + b.get_x(), y + b.get_y());
    }
    Point operator-(const Point& b) const {
        return Point(x - b.get_x(), y - b.get_y());
    }
    Point operator*(int c) const {
        return Point(x * c, y * c);
    }
    int operator*(const Point& b) const {
        return x * b.get_x() + y * b.get_y();
    }
    int operator&&(const Point& b) const {
        return x * b.get_y() - y * b.get_x();
    }
    int len() const {
        return x * x + y * y;
    }
    double angle(const Point& b) const {
        return atan2(*this && b, *this * b);
    }
    bool operator==(const Point& b) const {
        return x == b.get_x() && y == b.get_y();
    }
    bool operator!=(const Point& b) const {
        return x != b.get_x() || y != b.get_y();
    }
    friend ostream& operator<<(ostream&, const Point&);
};

ostream& operator<<(ostream& out, const Point& a) {
    out << a.x << ' ' << a.y;
    return out;
}

int main() {
    int x, y;
    cout << "Input the coordinates of the first vector:" << endl;
    cin >> x >> y;
    Point a(x, y);
    cout << "Input the coordinates of the second vector:" << endl;
    cin >> x >> y;
    Point b(x, y);
    cout << "Input the new coordinates of the first vector:" << endl;
    cin >> x >> y;
    a.set_x(x);
    a.set_y(y);
    cout << "Sum vector: " << a + b << endl;
    cout << "Difference vector: " << a - b << endl;
    cout << "First vector multiplied by 2: " << a * 2 << endl;
    cout << "Dot product of two vectors: " << a * b << endl;
    cout << "Skew product of two vectors: " << (a && b) << endl;
    cout << "Squared length of the first vector: " << a.len() << endl;
    cout << "Angle between vectors: " << a.angle(b) << endl;
    cout << "Two vectors are equal: " << (a == b) << endl;
    cout << "Two vectors are not equal: " << (a != b) << endl;
}
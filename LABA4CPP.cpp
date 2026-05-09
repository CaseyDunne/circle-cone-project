#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

class Circle {
protected:
    double radius;
public:
    Circle(double r) {
        if (r > 0) {
            radius = r;
        }
        else {
            radius = 1;
            cout << "Радиус должен быть положительным. Установлено значение 1." << endl;
        }
    }

    double area() const {
        const double PI = M_PI;
        return PI * radius * radius;
    }

    double getRadius() const {
        return radius;
    }
};

class Cone : public Circle {
private:
    double height;

public:
    Cone(double r, double h) : Circle(r) {
        if (h > 0) {
            height = h;
        }
        else {
            height = 1;
            cout << "Высота должна быть положительной. Установлено значение 1." << endl;
        }
    }

    double volume() const {
        return (1.0 / 3.0) * area() * height;
    }

    double getHeight() const {
        return height;
    }

    double lateralArea() const {
// Аргументы гарантированно положительны благодаря конструктору
        double l = sqrt(radius * radius + height * height);
        return M_PI * radius * l;
}
};

double inputPositive(const string& message) {
    double value;
    do {
        cout << message;
        cin >> value;
        if (value <= 0) {
            cout << "Значение должно быть положительным! Попробуйте снова." << endl;
        }
    } while (value <= 0);
    return value;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "--- Площадь кольца ---" << endl;

    double outerRadius = inputPositive("Введите внешний радиус кольца: ");
    double innerRadius = inputPositive("Введите внутренний радиус кольца: ");

    while (innerRadius >= outerRadius) {
        cout << "Внутренний радиус должен быть меньше внешнего! Попробуйте снова." << endl;
        innerRadius = inputPositive("Введите внутренний радиус кольца: ");
    }

    Circle outerCircle(outerRadius);
    Circle innerCircle(innerRadius);

    double ringArea = fabs(outerCircle.area() - innerCircle.area());
    cout << "Площадь кольца: " << ringArea << endl << endl;

    cout << "--- Объём конуса и ребро куба ---" << endl;

    double coneRadius = inputPositive("Введите радиус основания конуса: ");
    double coneHeight = inputPositive("Введите высоту конуса: ");

    Cone cone(coneRadius, coneHeight);

    double coneVolume = cone.volume();
    cout << "Объём конуса: " << coneVolume << endl;

    double cubeEdge = cbrt(coneVolume);
    cout << "Ребро куба, имеющего такой же объём: " << cubeEdge << endl << endl;

    cout << "Done" << endl;
    return 0;
}
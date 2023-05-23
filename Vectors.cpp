#include <iostream>

class Vektor
{
private:
    double xAxis;
    double yAxis;
    double zAxis;

public:
    Vektor() : xAxis(0.0), yAxis(0.0), zAxis(0.0) {}

    Vektor(double x, double y, double z) : xAxis(x), yAxis(y), zAxis(z) {}

    double getXAxis()
    {
        return xAxis;
    }

    double getYAxis()
    {
        return yAxis;
    }

    double getZAxis()
    {
        return zAxis;
    }

    void setXAxis(double x)
    {
        xAxis = x;
    }

    void setYAxis(double y)
    {
        yAxis = y;
    }

    void setZAxis(double z)
    {
        zAxis = z;
    }

    Vektor operator+(const Vektor &other)
    {
        double x = xAxis + other.xAxis;
        double y = yAxis + other.yAxis;
        double z = zAxis + other.zAxis;
        return Vektor(x, y, z);
    }

    Vektor operator-(const Vektor &other)
    {
        double x = xAxis - other.xAxis;
        double y = yAxis - other.yAxis;
        double z = zAxis - other.zAxis;
        return Vektor(x, y, z);
    }

    Vektor operator*(double scalar)
    {
        double x = xAxis * scalar;
        double y = yAxis * scalar;
        double z = zAxis * scalar;
        return Vektor(x, y, z);
    }

    friend std::ostream &operator<<(std::ostream &os, const Vektor &vec)
    {
        os << "(" << vec.xAxis << ", " << vec.yAxis << ", " << vec.zAxis << ")";
        return os;
    }
};

int main()
{
    Vektor v2(2, 1, 3);

    std::cout << v2 << std::endl;

    return 0;
}

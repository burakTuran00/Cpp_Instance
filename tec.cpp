#include <iostream>
using namespace std;

constexpr auto PI = 3.1415;

class Sekil
{
    int type;

protected:
    double deger;

public:
    string name = "Sekil";

    Sekil() : deger(0.0) {}       // Default Constructor
    Sekil(double d) : deger(d) {} // Overloaded Constructor

    void setDeger(double deger)
    {
        this->deger = deger;
    }
    double getDeger()
    {
        return this->deger;
    }
};

class Kare : public Sekil
{
public:
    Kare() : Sekil() {}          // Default Constructor
    Kare(double d) : Sekil(d) {} // Overloaded Constructor
    double alanHesapla()
    {
        return (deger * deger);
    }
};

class Daire : public Sekil
{
public:
    Daire() : Sekil() {}
    Daire(int d) : Sekil(d) {}
    double alanHesapla()
    {
        return (PI * deger * deger);
    }
};

int main()
{
    Kare kare(10.1); // Call Overload ctor
    kare.name = "Kare";
    cout << kare.name << " Kenar = " << kare.getDeger() << " cm" << endl;
    cout << kare.name << " Alani = " << kare.alanHesapla() << " cm�" << endl;

    Daire daire; // Call Default ctor
    daire.name = "Daire";
    daire.setDeger(10.1);
    cout << daire.name << " Y.Cap = " << daire.getDeger() << " cm" << endl;
    cout << daire.name << " Alani = " << daire.alanHesapla() << " cm�" << endl;

    return 0;
}
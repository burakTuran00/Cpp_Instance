#include <iostream>
using namespace std;

class Friend
{
private:
    int xVal, yVal;

public:
    Friend(int i = 0, int j = 0) : xVal(i), yVal(j) {}
    friend int sum(Friend &f);
};

int sum(Friend &f)
{
    return (f.xVal + f.yVal);
}

int main(int argc, char *argv[])
{
    Friend f1;
    cout << "sum(f1) = " << sum(f1) << endl;

    Friend f2(4, 16);
    cout << "sum(f2) = " << sum(f2) << endl;

    return 0;
}
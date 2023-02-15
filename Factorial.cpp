#include <iostream>

int Fac(int number);

int main()
{
    int number;

    std::cout << "Enter a Number: ";
    std::cin >> number;

    std::cout << "Factorial of This Number is " << Fac(number) << std::endl;

    return 0;
}

int Fac(int number)
{
    if (number > 1)
    {
        return number * Fac(number - 1);
    }
}

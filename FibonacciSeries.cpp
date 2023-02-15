#include <iostream>

void Fib(int number);

int main()
{
    int number;

    std::cout << "Nunber: ";
    std::cin >> number;

    Fib(number);

    return 0;
}
void Fib(int number)
{
    int a = 0, b = 1, nextTerm = 0;

    while (a < number)
    {
        std::cout << nextTerm << " ";
        a = b;
        b = nextTerm;
        nextTerm = a + b;
    }
}

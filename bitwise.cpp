#include <iostream>

int main()
{
    int temperatures[10];
    int amount = 0;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Enter an number: ";
        std::cin >> temperatures[i];

        amount += temperatures[i];
    }

    float mean = amount / 10;

    std::cout << "Mean: " << mean << std::endl;

    return 0;
}
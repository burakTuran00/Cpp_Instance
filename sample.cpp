#include <iostream>
#include <cmath>
#include <limits>
#include <string>

int main()
{
    double num;
    int counter = 0;
    bool isPrime = true;
    const double max = 18446744073709551616; // 2^64 or 2^64-1

    try
    {
        std::cout << "Enter a positive integer (0 to quit): ";
        std::cin >> num;

        while (num != 0)
        {
            if (num < 0)
            {
                std::cout << "Invalid input. Please enter a positive integer: ";
                std::cin >> num;
                continue;
            }
            else if (num == 1)
            {
                std::cout << "1 is neither prime nor composite." << std::endl;
                std::cout << "Enter a positive integer (0 to quit): ";
                std::cin >> num;
                continue;
            }
            else if (num == 2)
            {
                std::cout << "2 is the smallest and only even prime number." << std::endl;
                std::cout << "Enter a positive integer (0 to quit): ";
                std::cin >> num;
                continue;
            }
            else if (num > max)
            {
                // std::cout << "The number is too large!";
                throw(num);
            }

            for (int i = 2; i <= sqrt(num); ++i)
            {
                ++counter;

                if ((int)num % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
            {
                std::cout << num << " is a prime number. (1 *  " << num << ") . ";
            }
            else
            {
                std::cout << num << " is a composite number. ( 2 * " << (num / 2) << ") . ";
            }

            std::cout << "The Amount of Loop is " << counter << std::endl;
            counter = 0;
            isPrime = true;
            std::cout << "Enter a positive integer (0 to quit): ";
            std::cin >> num;
        }
    }
    catch (double n)
    {
        std::cout << n << std::endl;
    }

    return 0;
}

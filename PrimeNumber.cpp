#include <iostream>
#include <cmath>

int main()
{
    int number;
    bool isPrime = true;
    int loopingNumber = 0;

    do
    {
        std::cout << "Enter a number: ";
        std::cin >> number;

        if (number == 0)
        {
            std::cout << "Entered Zero, left the loop!" << std::endl;
            number == 0;
            break;
        }
        else if (number == 1)
        {
            std::cout << "One is not a primary and composite number" << std::endl;
            continue;
        }
        else if (number == 2)
        {
            std::cout << "2 is the smallest even prime number that is also an odd number." << std::endl;
            continue;
        }
        else if (number < 0)
        {
            std::cout << "Please enter positive number or Enter 0 to exit: " << std::endl;
            continue;
        }
        else
        {
            for (int i = 2; i <= sqrt(number); i++)
            {

                if (number % i == 0)
                {
                    loopingNumber++;
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime)
        {
            std::cout << "It's a prime number and Amount of Looping is " << loopingNumber << std::endl;
        }
        else
        {
            std::cout << "It's a composite number and Amount of Looping is  " << loopingNumber << std::endl;
        }

    } while (number != 0);

    return 0;
}
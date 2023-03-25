#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>

// We need some libraries to use some functions.
using namespace std;

int main()
{
    bool condition = true;

    while (condition)
    {
        std::cout << "Enter an expression in the form a op b or press ESC to exit: "; // Get input from user.
        std::string input;
        std::getline(cin, input);

        if (GetAsyncKeyState(VK_ESCAPE)) // If we press the ESC key, Then we'll abandon in the loop.
        {
            condition = false;
            std::cout << "You did press the (ESC) key." << std::endl;
            break;
        }

        istringstream iss(input); // This function'll separate the input.
        int a, b;
        char op;

        if (iss >> a >> op >> b && iss.eof())
        {
            switch (op) // We'll compare the op for processing.
            {

            case '+':
                std::cout << a << " + " << b << " = " << (a + b) << std::endl;
                break;

            case '-':
                std::cout << a << " - " << b << " = " << (a - b) << std::endl;
                break;

            case '*':
                std::cout << a << " * " << b << " = " << (a * b) << std::endl;
                break;

            case '/':
                if (b == 0) // If b is equals to 0. like a / 0. This'll give us error message.
                {
                    std::cout << "Cannot divide by zero, please try again" << std::endl;
                    break;
                }
                std::cout << a << " / " << b << " = " << (a / b) << std::endl;
                break;

            case '%':
                if (b == 0) // If b is equals to 0. like a % 0. This'll give us error message.
                {
                    std::cout << "Cannot divide by zero, please try again" << std::endl;
                    break;
                }
                std::cout << a << " % " << b << " = " << (a % b) << std::endl;
                break;

            default:
                std::cout << "Invalid operator" << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid input, please try again" << std::endl;
        }
    }

    return 0;
}

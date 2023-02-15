#include <iostream>

struct User
{
    std::string username;
    std::string password;
    bool isAlive = true;
};

int main()
{
    User user_1;

    std::cout << "Username: ";
    std::getline(std::cin, user_1.username);

    std::cout << "Password: ";
    std::getline(std::cin, user_1.password);

    if (user_1.username == "qwerty" && user_1.password == "qwerty")
    {
        std::cout << "Correct!\n";
    }
    else
    {
        std::cout << "Incorrect!";
    }

    return 0;
}
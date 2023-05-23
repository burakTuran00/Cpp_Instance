#include <string>

// Bu fonksiyon, bir input'un veri tipini bulur.
std::string getDataType(std::string input)
{
    bool isInteger = true;
    bool isFloat = true;
    bool isChar = true;

    // Verinin içinde sadece rakam veya eksi işareti varsa, bu bir integer'dır.
    for (char c : input)
    {
        if (!isdigit(c) && c != '-')
        {
            isInteger = false;
            break;
        }
    }

    // Verinin içinde en az bir nokta varsa, bu bir float'tur.
    for (char c : input)
    {
        if (c == '.')
        {
            isFloat = true;
            break;
        }
        if (!isdigit(c))
        {
            isFloat = false;
            break;
        }
    }

    // Verinin uzunluğu 1 ise ve içeriği bir karakter ise, bu bir char'dır.
    if (input.length() == 1 && isalpha(input[0]))
    {
        isChar = true;
    }
    else
    {
        isChar = false;
    }

    // Veri tipini belirle.
    if (isInteger)
    {
        return "integer";
    }
    else if (isFloat)
    {
        return "float";
    }
    else if (isChar)
    {
        return "char";
    }
    else
    {
        return "string";
    }
}

int main()
{
    std::string input;
    std::cin >> input;

    std::string dataType = getDataType(input);

    std::cout << "Input'un veri tipi: " << dataType << std::endl;

    return 0;
}

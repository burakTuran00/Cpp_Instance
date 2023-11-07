#include <iostream>

int main()
{
    int value = 5;
    int *ptr = &value;

    std::cout << "Addres of Value=" << ptr << std::endl;
    std::cout << "Addres of Pointer=" << &ptr << std::endl;
    std::cout << "Value of Value=" << *ptr++ << std::endl;

    int array[3] = {1, 2, 3};
    int *ptrA = array;

    std::cout << array[0] << "\t" << array[1] << "\t" << array[2] << std::endl;
    *ptrA = 10;
    std::cout << array[0] << "\t" << array[1] << "\t" << array[2] << std::endl;
    *ptrA++ = 12;
    std::cout << array[0] << "\t" << array[1] << "\t" << array[2] << std::endl;
    *ptrA = 6;
    std::cout << array[0] << "\t" << array[1] << "\t" << array[2] << std::endl;
    return 0;
}
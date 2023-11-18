#include <iostream>
#include <array>

int main()
{
    int array[5] = {1, 3, 5, 7, 9};
    int *ptr = array;

    *ptr++; // read next element
    std::cout << *ptr << std::endl;

    *--ptr; // read previous element
    *ptr++;
    ++*ptr;
    (*ptr)++;
    ++(*ptr);
    std::cout << *ptr << std::endl;

    return 0;
}
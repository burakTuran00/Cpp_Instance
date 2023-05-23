#include <iostream>
#include <string>
using namespace std;

int main()
{

    int i = 0;
    int arr[] = {0, -1, 1, -2, 2, -3, 3, -4, 4, -5, 5};
    do
    {
        if (arr[i] == 0)
            cout << arr[i] << " ";
        else if (arr[i] > 1)
            cout << (arr[i] - arr[i - 1]) << " ";
        i++;
    } while (i < sizeof(arr) / sizeof(arr[0]));
    return 0;
}

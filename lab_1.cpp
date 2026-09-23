#include <iostream>
#include <windows.h>

void fillArray(int (&arr)[10])
{
    std::cout << "Введите 10 чисел ->\n";

    for (int& x : arr)
    {
        std::cin >> x;
    }
}

void printArray(const int (&arr)[10])
{
    for (auto x : arr)
    {
        std::cout<< x << " ";
    }
}

void swapElements(int (&arr)[10], int num1, int num2)
{
    std::swap(arr[num1], arr[num2]);
}
 




void multiplyByTwo(int (&arr)[10])
{
    for (int& x : arr)
    {
        x *= 2;
    }
}




int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int arr[10];

    fillArray(arr);

    std::cout << "Вот такой массив ";
    printArray(arr);

    std::cout << std::endl;

    swapElements(arr, 0, 1);
    std::cout << "После обмена: ";
    printArray(arr);




    std::cout << std::endl;
    multiplyByTwo(arr);
    std::cout << "Результат после умножения на 2: ";
    printArray(arr);




    return 0;

}

#include <iostream>
#include <windows.h>
using namespace std;


/** 
 * @struct SafeArray 
 * @brief Хранит динамический массив и его размер.
 */


struct SafeArray
{
    int* data;
    int size;
};


/**
 * @brief Создаёт динамический массив.
 * @param size Размер массива.
 * @return Структура SafeArray с выделенной памятью.
 */

SafeArray createArray(int size)
{
    SafeArray arr;

    arr.data = new int[size]{};
    arr.size = size;

    return arr;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size{};
    
    cout << "Введите размер массива: ";
    cin >> size;
    
    SafeArray myArr = createArray(size);
    
    return 0;
}



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

/**
 * @brief Возвращает ссылку на элемент массива.
 * @param arr Массив SafeArray.
 * @param index Индекс элемента.
 * @return Ссылка на элемент массива или на переменную-заглушку.
 */

int& getElement(SafeArray& arr, int index)
{
    static int errorValue = 0;

    if (index < 0 || index >= arr.size) //фун возв ссылку даже если индекс неверный. при прав инд возвр ссылку на эл массива
    {
        cout << "Ошибка: индекс вне границ массива\n";
        return errorValue;
    }

    return arr.data[index];
}







int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size{};
    
    cout << "Введите размер массива: ";
    cin >> size;
    
    SafeArray myArr = createArray(size);
    getElement(myArr, 2) = 999; //myArr.data[2] = 999;возвращает ссылку
    
    return 0;
}


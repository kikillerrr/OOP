
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


/**
 * @brief Выводит элементы безопасного массива.
 * @param arr Константная ссылка на SafeArray.
 */

void printSafe(const SafeArray& arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        cout << arr.data[i] << ' ';
    }

    cout << '\n';
}

/**
 * @brief Изменяет размер динамического массива.
 * @param arr Массив SafeArray, размер которого нужно изменить.
 * @param M Новый размер массива.
 */

void reSizeArray(SafeArray& arr, int M)
{
    if (M < arr.size) //типо если новый размео меньше старого то выводим сначла эл которые будуь удалены.
    {
        cout << "Удаленные элементы: ";

        for (int i = M; i < arr.size; i++)
        {
            cout << arr.data[i] << ' ';
        }

        cout << '\n';
    }

    int* newData = new int[M]{}; //если новый размер болььше создаем . автоматически делает новые эл =0

    int limit = (arr.size < M) ? arr.size : M;

    for (int i = 0; i < limit; i++) //копируем старые эл
    {
        newData[i] = arr.data[i];
    }

    delete[] arr.data; // старя память освобождаетсяяя

    arr.data = newData;  //указатель начинает указывать на новый массив
    arr.size = M;
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
    
    cout << "Массив: ";
    printSafe(myArr);

    int newSize{};
    cout << "Введите новый размер массива: ";
    cin >> newSize;

    reSizeArray(myArr, newSize);

    cout << "Массив после изменения размера: ";
    printSafe(myArr);
    

    delete[] myArr.data;
    return 0;

}


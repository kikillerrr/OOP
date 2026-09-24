#include <iostream>
#include <windows.h>
using namespace std;


/**
 * @brief Функция заполняет массив элементами
 * @param arr Указатель на массив
 * @param n Количество элементов массива
 */ 
void fillArray(int* arr, int n)
{
    cout << "Введите элементы массива: ";
    for (int i{}; i < n; i++)
    {
        cin >> arr[i];
    }
}

/**
 * @brief Функция выводит массив на экран
 * @param arr Указатель на массив
 * @param size размер массива
 */
void printArray(int* arr, int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}


/**
 * @brief Функция ищет первое отрицательное число
 * @param arr Указатель на массив
 * @param size размер массива
 */
void process(int*& arr, int& size) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        int* newarr = new int[index];

        for (int i = 0; i < index; i++) {
            newarr[i] = arr[i];
        }

        delete[] arr;

        arr = newarr;
        size = index;
    }
}

/**
 * @brief основная функция где устанавливается размер массива N, выделяется динамическая память под массив arr
 * @param n размер массива N
 */ 
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int n;
    cout << "Введите размер массива N ";
    cin >> n;
    int* arr = new int[n];
    fillArray(arr,n);
    cout << endl;
    process(arr, n);
    printArray(arr, n);

    delete[] arr;
    arr = nullptr;

    return 0;



}
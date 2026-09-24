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
void process(int*& arr,int size){
    for (int i = 0; i < size; i++){
        if (arr [i] < 0){
            cout << "Первое отрицательное число" << arr[i] << endl;
        }
    }
}

/**
 * @brief основная функция где устанавливается размер массива N, выделяется динамическая память под массив arr
 * @param n размер массива N
 */ 
int main()
{
    int n;
    cout << "Введите размер массива N ";
    cin >> n;
    int* arr = new int[n];
    fillArray(arr,n);
    printArray(arr, n);
    cout << endl;
    process(arr, n);


}
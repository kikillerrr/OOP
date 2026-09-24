#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

/**
 * @brief Выделяет память под двумерный динамический массив.
 * @param rows Количество строк (студентов).
 * @param cols Количество столбцов (оценок).
 * @return Указатель на созданный двумерный массив.
 */
int** allocateMatrix(int rows, int cols)
{
    int** matrix{new int*[rows]{}};

    for (int row{}; row < rows; row++)
    {
        matrix[row] = new int[cols]{};
    }

    return matrix;
}

/**
 * @brief Выполняет программу.
 * @return 0 при успешном завершении.
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int rows{};
    int cols{};

    cout << "Студенты: ";
    cin >> rows;

    cout << "Оценки: ";
    cin >> cols;

    int** matrix {allocateMatrix(rows, cols)};

    return 0;
}


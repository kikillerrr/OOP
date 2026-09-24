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
 * @brief Заполняет двумерный массив оценками с клавиатуры.
 * @param matrix Указатель на двумерный динамический массив.
 * @param rows Количество строк (студентов).
 * @param cols Количество столбцов (оценок).
 */
void fillMatrix(int** matrix, int rows, int cols)
{
    cout << "Введите оценки:\n";

    for (int i{}; i < rows; ++i)
    {
        for (int j{}; j < cols; ++j)
        {
            cout << "Студент " << i + 1
                 << ", оценка " << j + 1 << ": ";

            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, string title = "Matrix")
{
    cout << title << '\n';

    const int cellWidth = 3; /// Ширина одной ячейки: пробел + цифра + пробел

    if (showBorders)
    {

        const int borderLen = 1 + cols * cellWidth; /// Длина верхней и нижней горизонтальной линии

        for (int symbol{}; symbol < borderLen; symbol++) // Верхняя граница
            cout << '*';
        cout << '\n';

        for (int row{}; row < rows; row++) // Строки с числами
        {
            cout << '*';
            for (int col{}; col < cols; col++)
            {
                cout << ' ' << matrix[row][col];

                int digits = to_string(matrix[row][col]).size(); // Добиваем пробелами до ширины ячейки
                for (int s{}; s < cellWidth - digits - 1; s++)
                    cout << ' ';
            }
            cout << "*\n";
        }

        for (int symbol{}; symbol < borderLen; symbol++) // Нижняя граница
            cout << '*';
        cout << '\n';
    }
    else
    {
        for (int row{}; row < rows; row++)
        {
            for (int col{}; col < cols; col++)
            {
                cout << matrix[row][col] << ' ';
            }
            cout << '\n';
        }
    }
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

    cout << "Кол-во студентов: ";
    cin >> rows;

    cout << "Кол-во оценок: ";
    cin >> cols;

    int** matrix {allocateMatrix(rows, cols)};
    fillMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols, true, "\n Оценки");

    printMatrix(matrix, rows, cols, false, "\n без рамки");

    return 0;
}

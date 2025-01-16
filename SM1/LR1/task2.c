//В двумерном массиве вещественных чисел посчитать количество неотрицательных элементов.

#include <stdio.h>

int main() {
int rows, cols; // переменные для количества строк и столбцов
int i, j;// переменные для итерации по массиву

    // Ввод размеров двумерного массива
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    double array[rows][cols]; // объявление двумерного массива вещественных чисел

    // Ввод элементов массива
    printf("Enter the elements of the array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%lf", &array[i][j]);// & используется для получения адреса
        }
    }

    // Подсчет количества неотрицательных элементов
    int count = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (array[i][j] >= 0) {
                count++; // увеличение счетчика, если элемент неотрицательный
            }
        }
    }

    // Вывод результата
    printf("The number of non-negative elements in the array is: %d\n", count);

    return 0; // завершение программы
}

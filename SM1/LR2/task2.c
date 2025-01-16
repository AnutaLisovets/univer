//В каждом столбце выполнить циклический сдвиг на один элемент.


#include <stdio.h>
#include <stdlib.h>

// Функция для заполнения двумерного массива натуральными числами
void fillArray(int **array, int rows, int cols) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array[i][j]);
        }
    }
}

// Функция для вывода двумерного массива
void printArray(int **array, int rows, int cols) {
    printf("Массив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

// Функция для выполнения циклического сдвига вниз в каждом столбце
void cyclicShiftDown(int **array, int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        // Сохраняем последний элемент столбца
        int temp = array[rows - 1][j];
        // Сдвигаем элементы столбца вниз
        for (int i = rows - 1; i > 0; i--) {
            array[i][j] = array[i - 1][j];
        }
        // Переносим последний элемент на верхнюю позицию
        array[0][j] = temp;
    }
}

int main() {
    int rows, cols;

    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    // Выделение памяти для двумерного массива
    int **array = malloc(rows * sizeof(int *));
    if (array == NULL) {
        perror("Ошибка выделения памяти");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        array[i] = malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            perror("Ошибка выделения памяти");
            return 1;
        }
    }

    // Заполнение массива
    fillArray(array, rows, cols);

    // Вывод начального массива
    printf("\nНачальный массив:\n");
    printArray(array, rows, cols);

    // Выполнение циклического сдвига вниз
    cyclicShiftDown(array, rows, cols);

    // Вывод изменённого массива
    printf("\nМассив после циклического сдвига вниз:\n");
    printArray(array, rows, cols);

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}


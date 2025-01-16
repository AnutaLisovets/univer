//Заполнить элементы двумерного массива натуральными числами. Из каждой нечётной (нумерация начинается с 0) строки удалить минимальный элемент.


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Функция для удаления минимального элемента из каждой нечётной строки
void removeMinFromOddRows(int ***array, int rows, int *cols) {
    for (int i = 1; i < rows; i += 2) { // Проходим по нечётным строкам
        int minIndex = 0;
        int minValue = INT_MAX;

        // Находим минимальный элемент и его индекс
        for (int j = 0; j < cols[i]; j++) {
            if ((*array)[i][j] < minValue) {
                minValue = (*array)[i][j];
                minIndex = j;
            }
        }

        // Сдвигаем элементы влево для удаления минимального
        for (int j = minIndex; j < cols[i] - 1; j++) {
            (*array)[i][j] = (*array)[i][j + 1];
        }

        // Уменьшаем размер строки
        cols[i]--;

        // Реаллоцируем строку
        (*array)[i] = realloc((*array)[i], cols[i] * sizeof(int));
        if ((*array)[i] == NULL && cols[i] > 0) {
            perror("Ошибка перераспределения памяти");
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    int rows, *cols;

    printf("Введите количество строк: ");
    scanf("%d", &rows);

    // Выделение памяти для массива указателей и размеров строк
    int **array = malloc(rows * sizeof(int *));
    cols = malloc(rows * sizeof(int));
    if (array == NULL || cols == NULL) {
        perror("Ошибка выделения памяти");
        return 1;
    }

    // Ввод количества столбцов для каждой строки и выделение памяти
    for (int i = 0; i < rows; i++) {
        printf("Введите количество элементов в строке %d: ", i + 1);
        scanf("%d", &cols[i]);

        array[i] = calloc(cols[i], sizeof(int));
        if (array[i] == NULL) {
            perror("Ошибка выделения памяти");
            return 1;
        }
    }

    // Заполнение массива
    fillArray(array, rows, cols[0]);

    // Вывод начального массива
    printf("\nНачальный массив:\n");
    printArray(array, rows, cols[0]);

    // Удаление минимального элемента из каждой нечётной строки
    removeMinFromOddRows(&array, rows, cols);

    // Вывод изменённого массива
    printf("\nМассив после удаления минимального элемента из нечётных строк:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
    free(cols);

    return 0;
}

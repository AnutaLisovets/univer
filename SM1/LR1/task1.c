//Заполнить массив первыми членами последовательности Фибоначчи (последовательности, в которой первые два члена равны 1, а каждый следующий равен сумме двух предыдущих).
#include <stdio.h>
#define MAX_SIZE 100  // Максимальный размер массива

// Функция для заполнения массива последовательностью Фибоначчи
void fillFibonacciArray(int array[], int size) {
    if (size >= 1) array[0] = 1; // Первый элемент
    if (size >= 2) array[1] = 1; // Второй элемент
    for (int i = 2; i < size; i++) {
        array[i] = array[i - 1] + array[i - 2]; // Каждый элемент равен сумме двух предыдущих
    }
}

// Функция для вывода массива
void printArray(int array[], int size) {
    printf("Fibonacci sequence:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[MAX_SIZE];
    int size;

    printf("Enter the number of Fibonacci elements to generate (1 to %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Please enter a value between 1 and %d.\n", MAX_SIZE);
        return 1; // Завершаем программу с кодом ошибки
    }

    fillFibonacciArray(array, size);  // Заполняем массив числами Фибоначчи
    printArray(array, size);         // Выводим массив

    return 0;
}

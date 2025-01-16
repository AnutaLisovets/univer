//Найти количество одинаковых элементов в одномерном массиве, заполненном вещественными числами.

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100  // Максимальный размер массива

// Функция для ввода массива
void inputArray(double array[], int size) {
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &array[i]);
    }
}

// Функция для вывода массива
void printArray(double array[], int size) {
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", array[i]);
    }
    printf("\n");
}

// Функция для подсчета одинаковых элементов в массиве
int countIdenticalElements(double array[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // Сравниваем элементы с точностью до 6 знаков после запятой
            if (fabs(array[i] - array[j]) < 1e-6) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int size = 0;
    double array[MAX_SIZE];
    int choice;
    char repeat = 'y';

    do {
        printf("Menu:\n");
        printf("1. Set size of array\n");
        printf("2. Input array elements\n");
        printf("3. Output array\n");
        printf("4. Count identical elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Ввод размерности массива
                printf("Enter the number of elements in the array (1 to %d): ", MAX_SIZE);
                scanf("%d", &size);
                if (size < 1 || size > MAX_SIZE) {
                    printf("Invalid size! Please enter a value between 1 and %d.\n", MAX_SIZE);
                    size = 0;  // Сбрасываем размер массива в 0, если размер некорректен
                }
                break;

            case 2:
                if (size == 0) {
                    printf("Please set the size of the array first.\n");
                } else {
                    // Ввод элементов массива
                    inputArray(array, size);
                }
                break;

            case 3:
                if (size == 0) {
                    printf("Please set the size of the array first.\n");
                } else {
                    // Вывод массива
                    printArray(array, size);
                }
                break;

            case 4:
                if (size == 0) {
                    printf("Please set the size of the array first.\n");
                } else {
                    // Подсчет одинаковых элементов
                    int identicalCount = countIdenticalElements(array, size);
                    printf("Number of identical elements: %d\n", identicalCount);
                }
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

        // Повторяем вопрос о продолжении только после выполнения задания
        printf("Would you like to perform another operation? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

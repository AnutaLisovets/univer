//Найти сумму чисел, встречающихся в тексте (соседние цифры считать как одно число).

#include <stdio.h>
#include <ctype.h> // Для функции isdigit()

// Функция для подсчета суммы чисел в строке
int sumOfNumbers(const char *str) {
    int sum = 0; // Сумма чисел
    int num = 0; // Текущее число

    for (int i = 0; str[i] != '\0'; i++) { // Перебираем все символы строки
        if (isdigit(str[i])) { // Если символ - цифра
            num = num * 10 + (str[i] - '0'); // Собираем число
        } else {
            if (num > 0) { // Если было собрано число
                sum += num; // Добавляем число в сумму
                num = 0; // Сбрасываем текущую переменную для следующего числа
            }
        }
    }

    // После цикла проверяем, если остался не добавленный номер
    if (num > 0) {
        sum += num; // Добавляем остаток числа
    }

    return sum;
}

int main() {
    char str[100];

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);

    int result = sumOfNumbers(str);
    printf("Сумма чисел в строке: %d\n", result);

    return 0;
}


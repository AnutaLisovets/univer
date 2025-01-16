//Дана строка, в которой слова разделены одним или несколькими пробелами (знаки пунктуации отсутствуют). Определить количество слов в строке.


#include <stdio.h>

// Функция для определения количества слов в строке
int countWords(char *str) {
    int count = 0; // Счётчик слов
    int inWord = 0; // Флаг нахождения в слове

    for (int i = 0; str[i] != '\0'; i++) { // Пока текущий символ строки не является нулевым символом
        if (str[i] != ' ') { // Если текущий символ не пробел
            if (i == 0 || str[i - 1] == ' ') { // Если это первый символ или после пробела
                count++;  // Начинается новое слово
            }
        }
    }

    return count;
}

// Проверка ввода строки
void inputString(char *str, int maxLength) {
    while (1) {
        printf("Введите строку (макс. длина %d): ", maxLength - 1);
        fgets(str, maxLength, stdin); // stdin -  указатель на поток ввода с клавиатуры

        // Проверка на пустую строку
        int isEmpty = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] != ' ' && str[i] != '\n') {
                isEmpty = 0;
                break;
            }
        }

        if (!isEmpty) {
            // Удаляем символ новой строки, если он есть
            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] == '\n') {
                    str[i] = '\0';
                    break;
                }
            }
            return;
        } else {
            printf("Ошибка: строка не должна быть пустой. Попробуйте снова.\n");
        }
    }
}

int main() {
    char str[100];  // Массив для строки
    inputString(str, 100);

    int wordCount = countWords(str);

    printf("Количество слов: %d\n", wordCount);
    return 0;
}


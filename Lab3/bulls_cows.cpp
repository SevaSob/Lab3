/*
 * bulls_cows.cpp — реализация модуля игры "Быки и коровы".
 *
 * Лабораторная работа №3, задание №3.
 */

#include "bulls_cows.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

/*
 * Генерация секретного числа.
 * Цифры перебираются случайным образом, при этом повторы отбрасываются,
 * поэтому все DIGITS цифр получаются различными.
 */
void generateSecret(int secret[DIGITS])
{
    bool used[10];
    for (int i = 0; i < 10; i++)
        used[i] = false;

    int filled = 0;
    while (filled < DIGITS) {
        int digit = rand() % 10;
        if (!used[digit]) {
            used[digit] = true;
            secret[filled] = digit;
            filled++;
        }
    }
}

/*
 * Разбор пользовательского ввода.
 * Ввод считается некорректным, если:
 *   - введено не ровно DIGITS символов;
 *   - среди символов есть нецифровые;
 *   - какая-либо цифра повторяется (иначе подсчёт коров был бы неоднозначен).
 */
bool parseGuess(const std::string& text, int guess[DIGITS])
{
    if ((int)text.size() != DIGITS)
        return false;

    bool used[10];
    for (int i = 0; i < 10; i++)
        used[i] = false;

    for (int i = 0; i < DIGITS; i++) {
        if (text[i] < '0' || text[i] > '9')
            return false;
        int digit = text[i] - '0';
        if (used[digit])
            return false;
        used[digit] = true;
        guess[i] = digit;
    }
    return true;
}

/* Подсчёт "быков": совпадение цифры и её позиции. */
int countBulls(const int secret[DIGITS], const int guess[DIGITS])
{
    int bulls = 0;

    for (int i = 0; i < DIGITS; i++) {
        if (secret[i] == guess[i])
            bulls++;
    }
    return bulls;
}

/*
 * Подсчёт "коров": цифра присутствует в загаданном числе, но стоит
 * на другом месте. Так как и в секрете, и в варианте все цифры различны,
 * каждой угаданной цифре соответствует ровно одно совпадение.
 */
int countCows(const int secret[DIGITS], const int guess[DIGITS])
{
    int cows = 0;

    for (int i = 0; i < DIGITS; i++) {
        if (secret[i] == guess[i])
            continue;               /* это бык, коров здесь не считаем */
        for (int j = 0; j < DIGITS; j++) {
            if (secret[j] == guess[i]) {
                cows++;
                break;
            }
        }
    }
    return cows;
}

/*
 * Подпрограмма угадывания: цикл ввода и оценки вариантов
 * продолжается до тех пор, пока пользователь не угадает число.
 */
int playGame(int secret[DIGITS])
{
    int tries = 0;
    int guess[DIGITS];
    std::string text;

    while (true) {
        std::cout << "Ваш вариант: ";
        if (!(std::cin >> text)) {
            /* ввод завершён (Ctrl+Z / конец файла) — выходим из цикла */
            std::cout << std::endl << "Ввод завершён." << std::endl;
            return tries;
        }

        if (!parseGuess(text, guess)) {
            std::cout << "Некорректный ввод: нужно " << DIGITS
                      << " различных цифр." << std::endl;
            continue;                 /* попытка не засчитывается */
        }

        tries++;
        int bulls = countBulls(secret, guess);
        int cows  = countCows(secret, guess);

        std::cout << bulls << " бык(ов) и " << cows << " коров(а)." << std::endl;

        if (bulls == DIGITS) {
            std::cout << "Число отгадано!" << std::endl;
            return tries;
        }
    }
}

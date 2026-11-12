/*
 * bulls_cows.h — интерфейс модуля игры "Быки и коровы".
 *
 * Модуль выделен в отдельные файлы (раздельная компиляция):
 *   bulls_cows.h  — объявления функций;
 *   bulls_cows.cpp — реализация функций;
 *   main.cpp      — главная программа, которая использует модуль.
 *
 * Лабораторная работа №3, задание №3.
 */

#ifndef BULLS_COWS_H
#define BULLS_COWS_H

#include <string>

/* Количество цифр в загаданном числе */
const int DIGITS = 4;

/*
 * Генерация секретного числа: DIGITS различных цифр,
 * первая из которых не равна нулю (как в обычной записи числа).
 */
void generateSecret(int secret[DIGITS]);

/*
 * Разбор строки, введённой пользователем.
 * Возвращает true, если строка состоит ровно из DIGITS различных цифр,
 * иначе false (guess при этом не изменяется).
 */
bool parseGuess(const std::string& text, int guess[DIGITS]);

/*
 * Число "быков": цифра угадана и при этом находится на своём месте.
 */
int countBulls(const int secret[DIGITS], const int guess[DIGITS]);

/*
 * Число "коров": цифра угадана, но находится не на своём месте.
 */
int countCows(const int secret[DIGITS], const int guess[DIGITS]);

/*
 * Подпрограмма угадывания: играет с пользователем до полного угадывания.
 * Возвращает количество сделанных попыток (не считая ошибочный ввод).
 */
int playGame(int secret[DIGITS]);

#endif /* BULLS_COWS_H */

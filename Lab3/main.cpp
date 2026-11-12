/*
 * main.cpp — главная программа лабораторной работы №3, задание №3.
 *
 * Игра "Быки и коровы". Компьютер загадывает число из четырёх различных
 * цифр, пользователь пытается его угадать, получая подсказки в виде
 * количества "быков" и "коров".
 *
 * Вся игровая логика вынесена в отдельный модуль bulls_cows
 * (файлы bulls_cows.h и bulls_cows.cpp) — это и есть раздельная компиляция.
 */

#include "bulls_cows.h"

#include <clocale>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(NULL));

    int secret[DIGITS];

    if (argc >= 2) {
        /*
         * Если задан аргумент командной строки, он используется как
         * загаданное число. Это нужно для воспроизводимого примера
         * работы программы, приведённого в отчёте.
         */
        if (!parseGuess(argv[1], secret)) {
            cout << "Некорректное загаданное число." << endl;
            return 1;
        }
    } else {
        generateSecret(secret);
    }

    cout << "Игра \"Быки и коровы\"." << endl;
    cout << "Загадано число из " << DIGITS << " различных цифр." << endl;
    cout << "Называйте варианты, пока не прозвучит \"4 быка(ов)\"." << endl;
    cout << endl;

    int tries = playGame(secret);

    cout << endl;
    cout << "Число отгадано за " << tries << " попыток(и)." << endl;

    return 0;
}

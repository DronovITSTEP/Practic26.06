#pragma once
#include <iostream>

using namespace std;

#define X 'X'
#define O 'O'

char firstPlayer[50];
char secondPlayer[50];
int nF = 0, nS = 0;

//ввод имени игрока
void EnterName() {
        cout << "Введите имя первого игрока: ";
        cin >> firstPlayer;

        cout << "Введите имя второго игрока: ";
        cin >> secondPlayer;
}
//выбор символа
void ChoiceChar() {
    char c;
        cout << "За какой символ играет игрок " << firstPlayer
        << "? (X или O)";
        cin >> c;
        (c == 'X') ? nF = 1 : nS = 1;
}

//меню игры
void menu() {
    char c;
    bool flag = true;
    do {
        cout << "Игра \"Крестики - нолики\"\n\n";
        cout << "1. Ввести имя игрока" << firstPlayer 
             << " / " << secondPlayer << "\n";
        cout << "2. Выбор символа (крестик или нолик)\n";
        cout << "3. Выход из игры\n";
        cin >> c;
        switch (c)
        {
        case '1':
            EnterName();
            system("cls");
            break;
        case '2':
            ChoiceChar();
            flag = false;
            break;
        case '3':
            exit(0);
            break;
        }
   } while (c != '3' && flag);
}
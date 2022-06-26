#pragma once
#include <iostream>

using namespace std;

#define X 'X'
#define O 'O'

char firstPlayer[50];
char secondPlayer[50];
int nF = 0, nS = 0;

//���� ����� ������
void EnterName() {
        cout << "������� ��� ������� ������: ";
        cin >> firstPlayer;

        cout << "������� ��� ������� ������: ";
        cin >> secondPlayer;
}
//����� �������
void ChoiceChar() {
    char c;
        cout << "�� ����� ������ ������ ����� " << firstPlayer
        << "? (X ��� O)";
        cin >> c;
        (c == 'X') ? nF = 1 : nS = 1;
}

//���� ����
void menu() {
    char c;
    bool flag = true;
    do {
        cout << "���� \"�������� - ������\"\n\n";
        cout << "1. ������ ��� ������" << firstPlayer 
             << " / " << secondPlayer << "\n";
        cout << "2. ����� ������� (������� ��� �����)\n";
        cout << "3. ����� �� ����\n";
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
#include <iostream>

#include "Main_Menu.h"

/*
//макросы
#define SIZE_ARRAY 5
#define SQR(X) (X)*(X)
#define CUBE(X) SQR(X)*(X)
*/
using namespace std;

/*
//перегрузка ф-и
int summa(int a, int b) {
    return a + b;
}
double summa(double a, double b) {
    return a * b;
}

int summa(int a, int b, int c, int d) {
    return a + b + c + d;
}
*/

/*
// вставка функции
inline void show(int arr[], int s) {
    for (int i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
*/

/*
//шаблон функции
template <typename T, typename T1>
T summa(T a, T b, T1 c) {
    T1 num;
    cout << c;
    return a + b;
}
*/

char board[3][3];
//отображение поля
void show() {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1;
        for (int j = 0; j < 3; j++) {
                cout << "|" << board[i][j];
        }
        cout << "|\n";
    }
}

//ход игрока
void stepPlayer(int i) {
    int c1, c2;
    do {
        cout << "Выберете значение по горизонтале: ";
        cin >> c1;
        cout << "Выберете значение по вертикале: ";
        cin >> c2;
        if (c1 > 3 || c2 > 3) { 
            cout << "Неверное значение\n"; 
            continue;
        }
        if (c1 < 0 || c2 < 0) {
            cout << "Неверное значение\n";
            continue;
        }
        if (board[c1-1][c2-1] == 'X' || board[c1-1][c2-1] == 'O') {
            cout << "Клетка занята. Выбирете другую клетку\n";
        }
    } while (board[c1-1][c2-1] != '_');
    i ? board[--c1][--c2] = X : board[--c1][--c2] = O;
    show();
}

//условия победы (довести до ума)
bool win() {
    //по горизонтали
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] 
        && board[0][0] != '_')return false;
    if (board[1][0] == board[1][1] && board[1][1] == board[1][2]
        && board[1][0] != '_')return false;
    if (board[2][0] == board[2][1] && board[2][1] == board[2][2]
        && board[2][0] != '_')return false;

    //по вертикали
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0]
        && board[0][0] != '_')return false;
    if (board[0][1] == board[1][1] && board[1][1] == board[2][1]
        && board[0][1] != '_')return false;
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2]
        && board[0][2] != '_')return false;

    //по диагонали
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
        && board[0][0] != '_') return false;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]
        && board[0][2] != '_') return false;

    return true;
}

int main()
{
    setlocale(LC_ALL, "");
    menu();
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '_';
        }
    }
    show();
    while (win() && count != 9) {
        cout << "Ход игрока " << firstPlayer << endl;
        stepPlayer(nF);
        if (!win()) {
            cout << "Игрок " << firstPlayer << " победил!\n";
            break;
        }
        count++;
        if (count == 9) { 
            cout << "Ничья!";
            break;
        }
        cout << "Ход игрока " << secondPlayer << endl;
        stepPlayer(nS);
        if (!win()) { 
            cout << "Игрок " << secondPlayer << " победил!\n";
            break; 
        }
        count++;
        if (count == 9) cout << "Ничья!";
    
    }
}





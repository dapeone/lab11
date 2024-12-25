#include <iostream>
using namespace std;

int main() {
  string input;
  int lenght = 0, x, y, X, Y;

  int arrayX[81];
  int arrayY[81];

  string array[11][11]; // Создаем игровое поле

  // создаём границы
  for (int j = 0; j < 11; ++j) {
    array[0][j] = "#";
  }
  for (int j = 0; j < 11; ++j) {
    array[10][j] = "#";
  }
  for (int i = 1; i < 10; ++i) {
    array[i][0] = "#";
  }
  for (int i = 1; i < 10; ++i) {
    array[i][10] = "#";
  }

  // определяем стартовое положение змеи
  arrayX[lenght] = 5;
  arrayY[lenght] = 5;
  lenght += 1;

  srand(time(NULL));
  x = rand() % 8 + 1;
  y = rand() % 8 + 1;

  array[x][y] = "*";


  while (arrayX[0] != 0 and arrayY[0] != 0 and arrayX[0] != 10 and arrayY[0] != 10) {
    cin >> input;

    X = arrayX[0];
    Y = arrayY[0];

    if (input == "w") {      
      arrayX[0] -= 1;
    }

    else if (input == "s") {
      arrayX[0] += 1;
    }

    else if (input == "a") {
      arrayY[0] -= 1;
    }

    else if (input == "d") {
      arrayY[0] += 1;
    }


      
    if (arrayX[0] == x and arrayY[0] == y) {
      lenght += 1;
        
      for (int i = lenght; i > 2; --i) {
        arrayX[i - 1] = arrayX[i - 2];
        arrayY[i - 1] = arrayY[i - 2];
      }

      arrayX[1] = X;
      arrayY[1] = Y;
      
        
      for (int i = 0; i < lenght; ++i) {
        while (x == arrayX[i] and y == arrayY[i]) {
          srand(time(NULL));
          x = rand() % 8 + 1;
          y = rand() % 8 + 1;
          i = 0;
        }
      }
        
      array[x][y] = "*";
    }

    else {
      
      for (int i = lenght; i > 2; --i) {
        arrayX [i - 1] = arrayX [i - 2];
        arrayY [i - 1] = arrayY [i - 2];
      }
        
      if (lenght > 1) {
        arrayX[1] = X;
        arrayY[1] = Y;
      }
    }

    for (int i = 1; i < lenght; ++i) {
      if (arrayX[0] == arrayX[i] and arrayY[0] == arrayY[i]) {
        cout << "GAME OVER";
        return 0;
      }
    }

    for (int i = 0; i < lenght; ++i) {
      array [arrayX[i]][arrayY[i]] = "O";
    }
    cout << "SCORE" << "   " << lenght - 1 << endl;
      for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
          if (array[i][j] != "#"  and array[i][j] != "O" and array[i][j] != "*") {
            cout << " ";
          }
          else {
            cout << array[i][j];
          }
        }
        cout << endl;
      }

    for (int i = 0; i < 11; ++i) {
      for (int j = 0; j < 11; ++j) {
        if (array[i][j] != "#" and array[i][j] != "*") {
          array[i][j] = " ";
        }
      }
    }
      

  }
  if (lenght == 89) {
    cout << "Vin";
  }
  else {
    cout << "Game over";
  }
}
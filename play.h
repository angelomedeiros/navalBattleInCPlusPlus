#include <iostream>
#include <ctime>
#include <string>

#define ROW 10
#define COL 10

using namespace std;

void createBoard(char board[ROW][COL], char mask[ROW][COL]) {

  for ( int row = 0; row < ROW; row++ ) {
    for ( int col = 0; col < COL; col++ ) {
      board[row][col] = 'W';
      mask[row][col] = '*';
    }
  }

}

void showMatrix(char matrix[ROW][COL]) {
  for ( int row = 0; row < ROW; row++ ) {
    for ( int col = 0; col < COL; col++ ) {
      cout << matrix[row][col] << " ";
    }
    cout << "\n";
  }
}

void showMask(char mask[ROW][COL], char board[ROW][COL], bool showBoard) {
  
  cout << "Class of Ship  |  Size  | Char\n";
  cout << "Carrier        |   5    |  C\n";
  cout << "Battleship     |   4    |  B\n";
  cout << "Cruiser        |   3    |  c\n";
  cout << "Submarine      |   3    |  s\n";
  cout << "Destroyer      |   2    |  d\n\n";

  showMatrix(mask);

  if ( showBoard ) {
    showMatrix(board);
  }

}

void insertShip (char board[ROW][COL]) {

  int maxAmount = 10;
  int amount = 0;

  while ( amount < maxAmount ) {

    int rowRand = rand() % maxAmount;
    int colRand = rand() % maxAmount;
    
    if ( board[rowRand][colRand] == 'W' ) {
      board[rowRand][colRand] = 'c';
      amount++;
    }

  }

}

void verifyAttempt(char board[ROW][COL], int rowPlayed, int columnPlayed, int *score, string *message) {

  switch ( board[rowPlayed][columnPlayed] ) {
    case 'c':
      *score = *score + 1;
      *message = "You got a shot in a Cruiser\n";
      break;
    case 'W':
      *message = "You got a shot in the Water\n";
      break;
  }

}

void play() {

  srand( (unsigned) time(NULL) );

  char board[ROW][COL], mask[ROW][COL];

  int rowPlayed, columnPlayed, score = 0;

  bool runningGame = true;

  string message = "Welcome to the game!\n";

  createBoard(board, mask);
  insertShip(board);

  while ( runningGame ) {
    
    clearScreen();

    showMask(mask, board, true);

    cout << "\nScore: " << score << "\n";
    cout << "\n" << message;

    cout << "\nEnter a row: ";
    cin >> rowPlayed;

    cout << "Enter a column: ";
    cin >> columnPlayed;

    rowPlayed--;
    columnPlayed--;

    mask[rowPlayed][columnPlayed] = board[rowPlayed][columnPlayed];

    verifyAttempt(board, rowPlayed, columnPlayed, &score, &message);

  }  

}
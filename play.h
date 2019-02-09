#include <iostream>

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
  
  showMatrix(mask);

  if ( showBoard ) {
    showMatrix(board);
  }

}

void play() {  

  char board[ROW][COL], mask[ROW][COL];

  int rowPlayed, columnPlayed;
  bool runningGame = true;

  createBoard(board, mask);

  while ( runningGame ) {
    
    clearScreen();

    showMask(mask, board, true);

    cout << "\nEnter a row: ";
    cin >> rowPlayed;

    cout << "Enter a column: ";
    cin >> columnPlayed;

    mask[rowPlayed][columnPlayed] = board[rowPlayed][columnPlayed];

  }  

}
#include <iostream>
#include <ctime>
#include <string>

#define ROW 10
#define COL 10
#define MAXAMOUNT 40

using namespace std;

void menu();

void createBoard(char board[ROW][COL], char mask[ROW][COL]) {

  for ( int row = 0; row < ROW; row++ ) {
    for ( int col = 0; col < COL; col++ ) {
      board[row][col] = 'W';
      mask[row][col] = '*';
    }
  }

}

void showMatrix(char matrix[ROW][COL]) {

  char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
  char white[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };
  char yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };

  cout << "    0 1 2 3 4 5 6 7 8 9\n";
  cout << "    ▼ ▼ ▼ ▼ ▼ ▼ ▼ ▼ ▼ ▼\n";
  for ( int row = 0; row < ROW; row++ ) {
    cout << row << " ▶ ";
    for ( int col = 0; col < COL; col++ ) {      
      switch ( matrix[row][col] ) {
        case 'W':
          cout << blue << matrix[row][col] << white << " ";
          break;
        case 'c':
          cout << yellow << matrix[row][col] << white << " ";
          break;
        default:
          cout << white << matrix[row][col] << white << " ";
          break;  
      }
    }
    cout << "\n";
  }
}

void showMask(char mask[ROW][COL], char board[ROW][COL], bool showBoard) {
  
  /*
  cout << "Class of Ship  |  Size  | Char\n";
  cout << "Carrier        |   5    |  C\n";
  cout << "Battleship     |   4    |  B\n";
  cout << "Cruiser        |   3    |  c\n";
  cout << "Submarine      |   3    |  s\n";
  cout << "Destroyer      |   2    |  d\n\n"; */

  showMatrix(mask);

  if ( showBoard ) {
    showMatrix(board);
  }

}

void insertShip (char board[ROW][COL]) {

  int maxAmount = MAXAMOUNT;
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

void verifyAttempt(char board[ROW][COL], int rowPlayed, int columnPlayed, int *score, string *message, int *attempt) {

  switch ( board[rowPlayed][columnPlayed] ) {
    case 'c':
      *score = *score + 1;
      *message = "You got a shot in a Cruiser\n";
      break;
    case 'W':
      *message = "You got a shot in the Water\n";
      *attempt = *attempt - 1;
      break;
  }

}

void play(string playerName) {

  srand( (unsigned) time(NULL) );

  char board[ROW][COL], mask[ROW][COL];

  int rowPlayed, columnPlayed, score = 0, attempt = 20;

  string message = "Welcome " + playerName + " to the game!\n";

  createBoard(board, mask);
  insertShip(board);

  while ( attempt != 0 ) {
    
    clearScreen();

    showMask(mask, board, false);

    cout << "\nScore: " << score << "\n";
    cout << "\nRemaining attempts " << attempt << "\n";
    cout << "\n" << message;

    cout << "\nEnter a row: ";
    cin >> rowPlayed;

    cout << "Enter a column: ";
    cin >> columnPlayed;

    mask[rowPlayed][columnPlayed] = board[rowPlayed][columnPlayed];

    verifyAttempt(board, rowPlayed, columnPlayed, &score, &message, &attempt);

  }

  clearScreen();

  if ( score == MAXAMOUNT ) {
    cout << "You win!\n";
  } else {
    cout << "You lose!\n";
  }

  char playAgain;

  cout << "\nChoice an option " << playerName << "... \n\n";
  cout << "1 - Play again\n";
  cout << "2 - Back to menu\n";
  cout << "3 - exit\n\n";
  cout << "Enter a option: ";
  cin >> playAgain;

  switch (tolower(playAgain)) {
    case '1':
      play(playerName);
      break;
    case '2':
      clearScreen();
      menu();
      break;
    default:
      break;
  }

}
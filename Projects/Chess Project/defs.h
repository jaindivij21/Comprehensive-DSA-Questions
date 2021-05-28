//
// Created by Divij Jain on 07-06-2020.
//

#ifndef CHESS_PROJECT_DEFS_H
#define CHESS_PROJECT_DEFS_H

#include <cstdio>
#include <iostream>
#include <conio.h>
#include <algorithm>

using namespace std;

// global variables
int totalMoves = 0;
char turnOf = 'W'; // tells which color's turn it is!
string tempPiece;
char nameOfThePiece;
int a, b;
int c, d;
int rowDelta, colDelta;
int columnOffset;
int rowOffset;
int columnOffset2;
int rowOffset2;
int kingColumn = 0;
int kingRow = 0;
int tempVariable = 100;
char oppColor;

// indexes of  piece which checked
int checkPieceRow;
int checkPieceColumn;

// initializing functions
void initializeBoard();

void printBoard();

void move();

void alternateTurn();

bool statusOfNewPos(int newRank, int newFile, int oldRank, char oldFile);

int allowPlay();

bool legalityOfMove(int newRank, int newFile, int oldRank, char oldFile);

bool isItCheckMate();

void isKingDead();
int whiteKing = 0;
int blackKing = 0;

int validityOfMove(int newRank, int newFile, int oldRank, char oldFile);

void extractArrayPos(char file, int rank);

bool isItCheck();

bool canKingMove();

bool checkAtSpecificPosition(int i, int j);

bool canIntervene();

bool canCut();

int rowIndex = 0;
int columnIndex = 0;
int biggerRowIndex;
int biggerColumnIndex;
int smallerRowIndex;
int smallerColumnIndex;

int biggerRowIndex2;
int biggerColumnIndex2;
int smallerRowIndex2;
int smallerColumnIndex2;

void playGame(string player1, string player2, char player1color, char player2color);

//structure for a piece for every square on the board
struct piece
{
    string name;
    char color;
    char file;
    int rank;
    bool ifPresent; // if a square doesnt have a piece it will be false
};

// chessboard initialized of datatype piece
piece chessBoard[8][8];

// board initialization
void initializeBoard()
{

    // black
    chessBoard[0][0].name = "bR";
    chessBoard[0][0].color = 'B';
    chessBoard[0][0].file = 'A';
    chessBoard[0][0].rank = 1;
    chessBoard[0][0].ifPresent = true;

    chessBoard[0][1].name = "bH";
    chessBoard[0][1].color = 'B';
    chessBoard[0][1].file = 'B';
    chessBoard[0][1].rank = 1;
    chessBoard[0][1].ifPresent = true;

    chessBoard[0][2].name = "bB";
    chessBoard[0][2].color = 'B';
    chessBoard[0][2].file = 'C';
    chessBoard[0][2].rank = 1;
    chessBoard[0][2].ifPresent = true;

    chessBoard[0][3].name = "bQ";
    chessBoard[0][3].color = 'B';
    chessBoard[0][3].file = 'D';
    chessBoard[0][3].rank = 1;
    chessBoard[0][3].ifPresent = true;

    chessBoard[0][4].name = "bK";
    chessBoard[0][4].color = 'B';
    chessBoard[0][4].file = 'E';
    chessBoard[0][4].rank = 1;
    chessBoard[0][4].ifPresent = true;

    chessBoard[0][5].name = "bB";
    chessBoard[0][5].color = 'B';
    chessBoard[0][5].file = 'F';
    chessBoard[0][5].rank = 1;
    chessBoard[0][5].ifPresent = true;

    chessBoard[0][6].name = "bH";
    chessBoard[0][6].color = 'B';
    chessBoard[0][6].file = 'G';
    chessBoard[0][6].rank = 1;
    chessBoard[0][6].ifPresent = true;

    chessBoard[0][7].name = "bR";
    chessBoard[0][7].color = 'B';
    chessBoard[0][7].file = 'H';
    chessBoard[0][7].rank = 1;
    chessBoard[0][7].ifPresent = true;

    for (int i = 1; i < 2; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char temp = 65 + j;
            chessBoard[i][j].name = "bP";
            chessBoard[i][j].color = 'B';
            chessBoard[i][j].file = temp;
            chessBoard[i][j].rank = i;
            chessBoard[i][j].ifPresent = true;
        }
    }

    // white
    chessBoard[7][0].name = "wR";
    chessBoard[7][0].color = 'W';
    chessBoard[7][0].file = 'A';
    chessBoard[7][0].rank = 8;
    chessBoard[7][0].ifPresent = true;

    chessBoard[7][1].name = "wH";
    chessBoard[7][1].color = 'W';
    chessBoard[7][1].file = 'B';
    chessBoard[7][1].rank = 8;
    chessBoard[7][1].ifPresent = true;

    chessBoard[7][2].name = "wB";
    chessBoard[7][2].color = 'W';
    chessBoard[7][2].file = 'C';
    chessBoard[7][2].rank = 8;
    chessBoard[7][2].ifPresent = true;

    chessBoard[7][3].name = "wQ";
    chessBoard[7][3].color = 'W';
    chessBoard[7][3].file = 'D';
    chessBoard[7][3].rank = 8;
    chessBoard[7][3].ifPresent = true;

    chessBoard[7][4].name = "wK";
    chessBoard[7][4].color = 'W';
    chessBoard[7][4].file = 'E';
    chessBoard[7][4].rank = 8;
    chessBoard[7][4].ifPresent = true;

    chessBoard[7][5].name = "wB";
    chessBoard[7][5].color = 'W';
    chessBoard[7][5].file = 'F';
    chessBoard[7][5].rank = 8;
    chessBoard[7][5].ifPresent = true;

    chessBoard[7][6].name = "wH";
    chessBoard[7][6].color = 'W';
    chessBoard[7][6].file = 'G';
    chessBoard[7][6].rank = 8;
    chessBoard[7][6].ifPresent = true;

    chessBoard[7][7].name = "wR";
    chessBoard[7][7].color = 'W';
    chessBoard[7][7].file = 'H';
    chessBoard[7][7].rank = 8;
    chessBoard[7][7].ifPresent = true;

    for (int i = 6; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char temp = 65 + j;
            chessBoard[i][j].name = "wP";
            chessBoard[i][j].color = 'W';
            chessBoard[i][j].file = temp;
            chessBoard[i][j].rank = i;
            chessBoard[i][j].ifPresent = true;
        }
    }

    // making ifPresent as false for all the other squares and printing -- there
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chessBoard[i][j].ifPresent = false;
            chessBoard[i][j].name = "--";
        }
    }
}

// printing the chess board on the console
void printBoard()
{
    cout
        << "                             A                       B                       C                       D                       E                       F                       G                       H             "
        << "\n"
        << endl;
    cout
        << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
        << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout << "         1       #          " << chessBoard[0][0].name << "           #          " << chessBoard[0][1].name
         << "           #          " << chessBoard[0][2].name << "           #          " << chessBoard[0][3].name
         << "           #          " << chessBoard[0][4].name << "           #          " << chessBoard[0][5].name
         << "           #          " << chessBoard[0][6].name << "           #          " << chessBoard[0][7].name
         << "           #  " << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout
        << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
        << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout << "         2       #          " << chessBoard[1][0].name << "           #          " << chessBoard[1][1].name
         << "           #          " << chessBoard[1][2].name << "           #          " << chessBoard[1][3].name
         << "           #          " << chessBoard[1][4].name << "           #          " << chessBoard[1][5].name
         << "           #          " << chessBoard[1][6].name << "           #          " << chessBoard[1][7].name
         << "           #  " << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout
        << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
        << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout << "         3       #          " << chessBoard[2][0].name << "           #          " << chessBoard[2][1].name
         << "           #          " << chessBoard[2][2].name << "           #          " << chessBoard[2][3].name
         << "           #          " << chessBoard[2][4].name << "           #          " << chessBoard[2][5].name
         << "           #          " << chessBoard[2][6].name << "           #          " << chessBoard[2][7].name
         << "           #  " << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout
        << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
        << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout << "         4       #          " << chessBoard[3][0].name << "           #          " << chessBoard[3][1].name
         << "           #          " << chessBoard[3][2].name << "           #          " << chessBoard[3][3].name
         << "           #          " << chessBoard[3][4].name << "           #          " << chessBoard[3][5].name
         << "           #          " << chessBoard[3][6].name << "           #          " << chessBoard[3][7].name
         << "           #  " << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout
        << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
        << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout << "         5       #          " << chessBoard[4][0].name << "           #          " << chessBoard[4][1].name
         << "           #          " << chessBoard[4][2].name << "           #          " << chessBoard[4][3].name
         << "           #          " << chessBoard[4][4].name << "           #          " << chessBoard[4][5].name
         << "           #          " << chessBoard[4][6].name << "           #          " << chessBoard[4][7].name
         << "           #  " << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout
        << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
        << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout << "         6       #          " << chessBoard[5][0].name << "           #          " << chessBoard[5][1].name
         << "           #          " << chessBoard[5][2].name << "           #          " << chessBoard[5][3].name
         << "           #          " << chessBoard[5][4].name << "           #          " << chessBoard[5][5].name
         << "           #          " << chessBoard[5][6].name << "           #          " << chessBoard[5][7].name
         << "           #  " << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout
        << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
        << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout << "         7       #          " << chessBoard[6][0].name << "           #          " << chessBoard[6][1].name
         << "           #          " << chessBoard[6][2].name << "           #          " << chessBoard[6][3].name
         << "           #          " << chessBoard[6][4].name << "           #          " << chessBoard[6][5].name
         << "           #          " << chessBoard[6][6].name << "           #          " << chessBoard[6][7].name
         << "           #  " << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout
        << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
        << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout << "         8       #          " << chessBoard[7][0].name << "           #          " << chessBoard[7][1].name
         << "           #          " << chessBoard[7][2].name << "           #          " << chessBoard[7][3].name
         << "           #          " << chessBoard[7][4].name << "           #          " << chessBoard[7][5].name
         << "           #          " << chessBoard[7][6].name << "           #          " << chessBoard[7][7].name
         << "           #  " << endl;
    cout
        << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
        << endl;
    cout
        << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
        << endl;
    cout << "\n\n"
         << endl;
}

// extracting the array index from given file and rank of a chessboard
void extractArrayPos(char file, int rank)
{
    // e.g A 1 == rowIndex = 0 & columnIndex = 0
    rowIndex = rank - 1;
    columnIndex = file - 65;
}

// change turn after every ply
void alternateTurn()
{
    if (totalMoves == 0)
        turnOf = 'W';
    else
        turnOf = (turnOf == 'W') ? 'B' : 'W';
}

// function to execute move from one location to another
void move()
{
    string pieceToMove;
    char newPositionFile;
    int newPositionRank;
    char oldPositionFile;
    int oldPositionRank;

    do
    {
        do
        {
            cout << "Enter the ";
            if (turnOf == 'W')
            {
                cout << "White";
            }
            else
            {
                cout << "Black";
            }
            cout << " piece to move (e.g. 'bP')" << endl;
            cin >> pieceToMove;
            cout << "Enter its old position (e.g. 'D 3')" << endl;
            cin >> oldPositionFile >> oldPositionRank;

            extractArrayPos(oldPositionFile, oldPositionRank);

            if ((turnOf == 'W' && chessBoard[rowIndex][columnIndex].color == 'W') ||
                (turnOf == 'B' && chessBoard[rowIndex][columnIndex].color == 'B'))
            {
                if (chessBoard[rowIndex][columnIndex].name != pieceToMove)
                {
                    cout << "ERROR! Input Position doesnt match with the piece!"
                         << "\n\n"
                         << endl;
                    continue;
                }
                break;
            }
            else
            {
                cout << "ERROR! Move the piece of your colour"
                     << "\n\n"
                     << endl;
            }

        } while (true);

        cout << "Enter new position (e.g. 'D 5')" << endl;
        cin >> newPositionFile >> newPositionRank;
        extractArrayPos(newPositionFile, newPositionRank); // rowIndex columnIndex

        // check the validity of the move and status of destination square
        bool ifValid2 = statusOfNewPos(rowIndex, columnIndex, oldPositionRank, oldPositionFile);
        if (ifValid2 == false)
        {
            cout << "Your  piece already present there!" << endl;
        }
        extractArrayPos(newPositionFile, newPositionRank);
        int ifValid1 = validityOfMove(rowIndex, columnIndex, oldPositionRank, oldPositionFile);
        if (ifValid1 == 0)
        {
            cout << "ERROR! This move is not legal!" << endl;
        }
        if (ifValid1 == -1)
        {
            cout << "ERROR! The move is Out Of Bounds!" << endl;
        }
        // only proceed to moving if the move is valid(inside the chessboard), legal(regarding the specific pieces) and status of destinaiton is ok(its either empty or piece of other color is present)
        if (ifValid1 && ifValid2)
        {
            break;
        }
        else
        {
            cout << "ERROR! Not a valid Move"
                 << "\n\n"
                 << endl;
        }
    } while (true);

    extractArrayPos(oldPositionFile, oldPositionRank); ///////////////////////////////////////////// can be removed
    char tempColor = chessBoard[rowIndex][columnIndex].color;

    extractArrayPos(newPositionFile, newPositionRank);
    // we get new values in variables rowIndex and columnIndex
    chessBoard[rowIndex][columnIndex].name = pieceToMove;
    chessBoard[rowIndex][columnIndex].file = newPositionFile;
    chessBoard[rowIndex][columnIndex].rank = newPositionRank;
    chessBoard[rowIndex][columnIndex].ifPresent = true;
    chessBoard[rowIndex][columnIndex].color = tempColor;

    extractArrayPos(oldPositionFile, oldPositionRank);
    chessBoard[rowIndex][columnIndex].name = "--";
    chessBoard[rowIndex][columnIndex].ifPresent = false;
    chessBoard[rowIndex][columnIndex].file = oldPositionFile;
    chessBoard[rowIndex][columnIndex].rank = oldPositionRank;

    totalMoves++;
}

// function to move from one location to another and cut the piece of opposite colour
bool statusOfNewPos(int newRank, int newFile, int oldRank, char oldFile)
{

    // check the status of new position
    if (!chessBoard[newRank][newFile].ifPresent) // its empty
        return true;
    else // it isnt empty
    {
        extractArrayPos(oldFile, oldRank);
        if (chessBoard[newRank][newFile].color ==
            chessBoard[rowIndex][columnIndex].color) // it is the same colour as the piece you are moving
        {
            return false;
        }
        else // its not the same colour which means it can cut the other piece
            return true;
    }
}

// checks for the conditions required to play the game; if not satisfied game-over
int allowPlay()
{
    if (totalMoves == 100)
        return -1;
    if (isItCheckMate() == true)
        return 0;
    if (1)
    {
        isKingDead();
        if (whiteKing == 1 || blackKing == 1)
            return 2;
    }
    return 1;
}

// check for validity
int validityOfMove(int newRow, int newColumn, int oldRank, char oldFile) // newRow and newColumn are array indexes but oldRank and oldFile are RANK AND FILE respectively!
{
    // check if the new position is not outside the array
    if ((newRow >= 0 && newRow <= 7) && (newColumn >= 0 && newColumn <= 7))
    {
        // if yes, then check for the legality of the move
        if (legalityOfMove(newRow, newColumn, oldRank, oldFile))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

// checking the legality of the move wrt to the piece's rules and also check if something is blocking the way
bool legalityOfMove(int newRow, int newColumn, int oldRank, char oldFile)
{
    extractArrayPos(oldFile, oldRank); // NOW newRow, newColumn, rowIndex, columnIndex
    tempPiece = (chessBoard[rowIndex][columnIndex].name);

    if (tempPiece == "wP" || tempPiece == "bP")
    {
        nameOfThePiece = 'P';
    }
    if (tempPiece == "wR" || tempPiece == "bR")
    {
        nameOfThePiece = 'R';
    }
    if (tempPiece == "wH" || tempPiece == "bH")
    {
        nameOfThePiece = 'H';
    }
    if (tempPiece == "wB" || tempPiece == "bB")
    {
        nameOfThePiece = 'B';
    }
    if (tempPiece == "wQ" || tempPiece == "bQ")
    {
        nameOfThePiece = 'Q';
    }
    if (tempPiece == "wK" || tempPiece == "bK")
    {
        nameOfThePiece = 'K';
    }

    biggerRowIndex = max(rowIndex, newRow);
    biggerColumnIndex = max(columnIndex, newColumn);
    smallerRowIndex = min(rowIndex, newRow);
    smallerColumnIndex = min(columnIndex, newColumn);

    switch (nameOfThePiece)
    {

    // legality of pawns
    case 'P':
        if (chessBoard[rowIndex][columnIndex].color == 'W')
        {
            // if pawn is moving to an empty space; it can only move one space forward
            if (chessBoard[newRow][newColumn].ifPresent == false)
            {
                if (newRow == rowIndex - 1 && newColumn == columnIndex)
                    return true;
                else
                    return false;
            }
            // if pawn wants to cut someone
            else
            {
                if (newRow == rowIndex - 1)
                {
                    if (newColumn == columnIndex - 1 || newColumn == columnIndex + 1)
                        return true;
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        if (chessBoard[rowIndex][columnIndex].color == 'B')
        {
            // if pawn is moving to an empty space; it can only move one space forward
            if (chessBoard[newRow][newColumn].ifPresent == false)
            {
                if (newRow == rowIndex + 1 && newColumn == columnIndex)
                    return true;
                else
                    return false;
            }
            // if pawn wants to cut someone
            else
            {
                if ((newRow == rowIndex + 1 && newColumn == columnIndex - 1) ||
                    (newRow == rowIndex + 1 && newColumn == columnIndex + 1))
                    return true;
                else
                    return false;
            }
        }

    // legality of Rooks
    case 'R':
        // Rook moves in the same row
        if (newRow == rowIndex)
        {
            // now check if all the squares in bw source and destination are empty
            columnOffset = biggerColumnIndex - smallerColumnIndex;

            if (newColumn > columnIndex)
            {
                for (int i = 1; i < columnOffset; i++)
                {
                    if (chessBoard[newRow][columnIndex + i].ifPresent == true)
                        return false;
                }
                return true;
            }

            if (newColumn < columnIndex)
            {
                for (int i = 1; i < columnOffset; i++)
                {
                    if (chessBoard[newRow][columnIndex - i].ifPresent == true)
                        return false;
                }
                return true;
            }
        }

        // rook moves in the same column
        else if (newColumn == columnIndex)
        {
            // now check if all the squares in bw source and destinations are empty
            rowOffset = biggerRowIndex - smallerRowIndex;

            if (newRow > rowIndex)
            {
                for (int i = 1; i < rowOffset; i++)
                {
                    if (chessBoard[rowIndex + i][columnIndex].ifPresent == true)
                        return false;
                }
                return true;
            }

            if (newRow < rowIndex)
            {
                for (int i = 1; i < rowOffset; i++)
                {
                    if (chessBoard[rowIndex - i][columnIndex].ifPresent == true)
                        return false;
                }
                return true;
            }
        }
        else
            return false;

    // legality of Horse
    case 'H':
        // for horse we dont need to check the path towards the destination square
        // also we already have checked if the destination square is empty or not using statusOfNewPos Function

        // it moves one column and two rows away
        if ((newColumn == columnIndex + 1) || (newColumn == columnIndex - 1))
        {
            if ((newRow == rowIndex + 2) || (newRow == rowIndex - 2))
            {
                return true;
            }
        }
        // it moves one row and two columns away
        if ((newColumn == columnIndex + 2) || (newColumn == columnIndex - 2))
        {
            if ((newRow == rowIndex + 1) || (newRow == rowIndex- 1))
            {
                return true;
            }
        }
        // some other movement
        return false;

    // legality of bishop
    case 'B':
        // it moves diagonally
        // make sure it moves diagonally
        if (biggerRowIndex - smallerRowIndex == biggerColumnIndex - smallerColumnIndex)
        {
            // checking if squares in the way are unoccupied
            if (newRow < rowIndex && newColumn < columnIndex)
            {
                a = rowIndex - 1;
                b = columnIndex - 1;
                while (a != newRow && b != newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a--;
                    b--;
                }
                return true;
            }
            if (newRow < rowIndex && newColumn > columnIndex)
            {
                a = rowIndex - 1;
                b = columnIndex + 1;
                while (a != newRow && b != newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a--;
                    b++;
                }
                return true;
            }
            if (newRow > rowIndex && newColumn < columnIndex)
            {
                a = rowIndex + 1;
                b = columnIndex - 1;
                while (a != newRow && b != newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a++;
                    b--;
                }
                return true;
            }
            if (newRow > rowIndex && newColumn > columnIndex)
            {
                a = rowIndex + 1;
                b = columnIndex + 1;
                while (a != newRow && b != newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a++;
                    b++;
                }
                return true;
            }
        }
        // if it doesn't move diagonal
        else
            return false;

    // legality of Queen
    case 'Q':
        // if queen moves in same row
        if (newRow == rowIndex)
        {
            // now check if all the squares in bw source and destination are empty
            columnOffset = biggerColumnIndex - smallerColumnIndex;

            if (newColumn > columnIndex)
            {
                for (int i = 1; i < columnOffset; i++)
                {
                    if (chessBoard[newRow][columnIndex + i].ifPresent == true)
                        return false;
                }
                return true;
            }

            if (newColumn < columnIndex)
            {
                for (int i = 1; i < columnOffset; i++)
                {
                    if (chessBoard[newRow][columnIndex - i].ifPresent == true)
                        return false;
                }
                return true;
            }
        }

        // if queen moves in the same column
        else if (newColumn == columnIndex)
        {
            // now check if all the squares in bw source and destinations are empty
            rowOffset = biggerRowIndex - smallerRowIndex;

            if (newRow > rowIndex)
            {
                for (int i = 1; i < rowOffset; i++)
                {
                    if (chessBoard[rowIndex + i][columnIndex].ifPresent == true)
                        return false;
                }
                return true;
            }

            if (newRow < rowIndex)
            {
                for (int i = 1; i < rowOffset; i++)
                {
                    if (chessBoard[rowIndex - i][columnIndex].ifPresent == true)
                    {
                        return false;
                    }
                }
                return true;
            }
        }

        // if queen moves diagonally
        // make sure it moves diagonal
        else if (biggerRowIndex - smallerRowIndex == biggerColumnIndex - smallerColumnIndex)
        {
            // checking if squares in the way are unoccupied
            if (newRow < rowIndex && newColumn < columnIndex)
            {

                a = rowIndex - 1;
                b = columnIndex - 1;
                while (a != newRow && b != newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a--;
                    b--;
                }
                return true;
            }
            if (newRow < rowIndex && newColumn > columnIndex)
            {

                a = rowIndex - 1;
                b = columnIndex + 1;
                while (a != newRow && b != newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a--;
                    b++;
                }
                return true;
            }
            if (newRow > rowIndex && newColumn < columnIndex)
            {
                a = rowIndex + 1;
                b = columnIndex - 1;
                while (a != newRow && b != newColumn)
                {

                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a++;
                    b--;
                }
                return true;
            }
            if (newRow > rowIndex && newColumn > columnIndex)
            {
                a = rowIndex + 1;
                b = columnIndex + 1;
                while (a != newRow && b != newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a++;
                    b++;
                }
                return true;
            }
        }
        else
            return false;

    // legality of King
    case 'K':
        rowDelta = newRow - rowIndex;
        colDelta = newColumn - columnIndex;

        // since king moves just one step, no need to check for obstructions
        // the difference between the destination and the source must be bw -1 and 1 both included
        if (((rowDelta >= -1) && (rowDelta <= 1)) && ((colDelta >= -1) && (colDelta <= 1)))
            return true;
        else
            return false;
    }
}

//check if the king is dead
void isKingDead()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessBoard[i][j].ifPresent == true && chessBoard[i][j].name == "wK")
            {
                whiteKing = 2;
                i = j = 8;
                break;
            }
        }
    }
    if (whiteKing != 2)
        whiteKing = 1;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessBoard[i][j].ifPresent == true && chessBoard[i][j].name == "bK")
            {
                blackKing = 2;
                i = j = 8;
                break;
            }
        }
    }
    if (blackKing != 2)
        blackKing = 1;
}

// check for check mate
bool isItCheckMate()
{
    if (isItCheck() == true)
    {
        cout << "Its a CHECK! for"
             << " " << turnOf << "\n\n"
             << endl;

        // check if the king can move or not
        if (canKingMove() == true)
        {
            // king it can move
            return false;
        }
        // if king cannot move

        // king aur piece ke beech me koi nahi aa sakta
        if (canIntervene() == true)
        {
            // agar koi aa sakta hai
            return false;
        }
        // koi beech me aa sakta hai

        // can someone take out the piece that checked the king
        if (canCut() == true)
        {
            // agr koi hai aesa jo cut kar sakta hai
            return false;
        }
        // agr koi k=cut ni kar sakta

        return true;
    }
    // check for other conditions 2
    else
        return false;
}

// once its check if the king can change its position
bool canKingMove()
{
    // get the king coordinates i.e kingRow kingColumn

    // check for the king i.e if it can move anywhere on the board which place it not a check
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int extractedRank = kingRow + 1;
            char extractedFile = kingColumn + 65;

            // if there is some valid move
            if (validityOfMove(i, j, extractedRank, extractedFile) == 1 && statusOfNewPos(i, j, extractedRank, extractedFile) == true)
            {
                // if there is a valid move check if its also not another check position i.e king wont be checked at i and j also
                if (checkAtSpecificPosition(i, j) == true)
                {
                    continue;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                continue;
            }
        }
    }
    // checked for all possible movements for king and it can't move anywhere
    return false;
}

// if its a check at a specific condition
bool checkAtSpecificPosition(int i, int j)
{
    for (int m = 0; m < 8; m++)
    {
        for (int n = 0; n < 8; n++)
        {
            if ((chessBoard[m][n].ifPresent == true) && (chessBoard[m][n].color == oppColor))
            {
                int extractedRank = m + 1;
                char extractedFile = n + 65;

                if (validityOfMove(i, j, extractedRank, extractedFile) == 1)
                {
                    return true;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
    }
    return false;
}

// checks if any piece of the color being checked can come in between king and piece which checked
bool canIntervene()
{
    // we need coordinates of the king i.e kingRow and kingColumn
    // we need coordinates and the type of piece which checked i.e checkPieceRow and checkPieceColumn
    string pieceType = (chessBoard[checkPieceRow][checkPieceColumn].name).substr(1, 1);
    biggerRowIndex2 = max(checkPieceRow, kingRow);
    biggerColumnIndex2 = max(checkPieceColumn, kingColumn);
    smallerRowIndex2 = min(checkPieceRow, kingRow);
    smallerColumnIndex2 = min(checkPieceColumn, kingColumn);

    int extractedRank;
    char extractedFile;

    if (kingRow == checkPieceRow)
    {
        columnOffset2 = biggerColumnIndex2 - smallerColumnIndex2;

        if (kingColumn > checkPieceColumn)
        {
            for (int i = 1; i < columnOffset2; i++)
            {
                // checking for each turnOf color piece if it can come bw king and the piece
                for (int m = 0; m < 8; m++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        if (chessBoard[m][n].ifPresent == true && chessBoard[m][n].color == turnOf)
                        {
                            if (chessBoard[m][n].name == "wK" || chessBoard[m][n].name == "bK")
                            {
                                continue;
                            }
                            else
                            {
                                extractedRank = m + 1;
                                extractedFile = n + 65;
                                if (validityOfMove(kingRow, (checkPieceColumn + i), extractedRank, extractedFile) == true)
                                {
                                    return true;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                        else
                            continue;
                    }
                }
            }
            return false;
        }

        if (kingColumn < checkPieceColumn)
        {
            for (int i = 1; i < columnOffset2; i++)
            {
                // checking for each turnOf color piece if it can come bw king and the piece
                for (int m = 0; m < 8; m++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        if (chessBoard[m][n].ifPresent == true && chessBoard[m][n].color == turnOf)
                        {
                            if (chessBoard[m][n].name == "wK" || chessBoard[m][n].name == "bK")
                            {
                                continue;
                            }
                            else
                            {
                                extractedRank = m + 1;
                                extractedFile = n + 65;
                                if (validityOfMove(kingRow, (checkPieceColumn - i), extractedRank, extractedFile) == true)
                                {
                                    return true;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                        else
                            continue;
                    }
                }
            }
            return false;
        }
    }

    else if (kingColumn == checkPieceColumn)
    {
        rowOffset2 = biggerRowIndex2 - smallerRowIndex2;

        if (kingRow > checkPieceRow)
        {
            for (int i = 1; i < rowOffset2; i++)
            {
                // checking for each turnOf color piece if it can come bw king and the piece
                for (int m = 0; m < 8; m++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        if (chessBoard[m][n].ifPresent == true && chessBoard[m][n].color == turnOf)
                        {
                            if (chessBoard[m][n].name == "wK" || chessBoard[m][n].name == "bK")
                            {
                                continue;
                            }
                            else
                            {
                                extractedRank = m + 1;
                                extractedFile = n + 65;
                                if (validityOfMove((checkPieceRow + i), kingColumn, extractedRank, extractedFile) == true)
                                {
                                    return true;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                        else
                            continue;
                    }
                }
            }
            return false;
        }

        if (kingColumn < checkPieceColumn)
        {
            for (int i = 1; i < rowOffset2; i++)
            {
                // checking for each turnOf color piece if it can come bw king and the piece
                for (int m = 0; m < 8; m++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        if (chessBoard[m][n].ifPresent == true && chessBoard[m][n].color == turnOf)
                        {
                            if (chessBoard[m][n].name == "wK" || chessBoard[m][n].name == "bK")
                            {
                                continue;
                            }
                            else
                            {
                                extractedRank = m + 1;
                                extractedFile = n + 65;
                                if (validityOfMove((checkPieceRow - i), kingColumn, extractedRank, extractedFile) == true)
                                {
                                    return true;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                        else
                            continue;
                    }
                }
            }
            return false;
        }
    }

    else
    {
        if (kingRow < checkPieceRow && kingColumn < checkPieceColumn)
        {
            c = checkPieceRow - 1;
            d = checkPieceColumn - 1;
            while (c != kingRow && d != kingColumn)
            {
                for (int m = 0; m < 8; m++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        if (chessBoard[m][n].ifPresent == true && chessBoard[m][n].color == turnOf)
                        {
                            if (chessBoard[m][n].name == "wK" || chessBoard[m][n].name == "bK")
                            {
                                continue;
                            }
                            else
                            {
                                extractedRank = m + 1;
                                extractedFile = n + 65;
                                if (validityOfMove(c, d, extractedRank, extractedFile) == true)
                                {
                                    return true;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                c--;
                d--;
            }
            return false;
        }

        if (kingRow < checkPieceRow && kingColumn > checkPieceColumn)
        {
            c = checkPieceRow - 1;
            d = checkPieceColumn + 1;
            while (c != kingRow && d != kingColumn)
            {
                for (int m = 0; m < 8; m++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        if (chessBoard[m][n].ifPresent == true && chessBoard[m][n].color == turnOf)
                        {
                            if (chessBoard[m][n].name == "wK" || chessBoard[m][n].name == "bK")
                            {
                                continue;
                            }
                            else
                            {
                                extractedRank = m + 1;
                                extractedFile = n + 65;
                                if (validityOfMove(c, d, extractedRank, extractedFile) == true)
                                {
                                    return true;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                c--;
                d++;
            }
            return false;
        }

        if (kingRow > checkPieceRow && kingColumn < checkPieceColumn)
        {
            c = checkPieceRow + 1;
            d = checkPieceColumn - 1;
            while (c != kingRow && d != kingColumn)
            {
                for (int m = 0; m < 8; m++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        if (chessBoard[m][n].ifPresent == true && chessBoard[m][n].color == turnOf)
                        {
                            if (chessBoard[m][n].name == "wK" || chessBoard[m][n].name == "bK")
                            {
                                continue;
                            }
                            else
                            {
                                extractedRank = m + 1;
                                extractedFile = n + 65;
                                if (validityOfMove(c, d, extractedRank, extractedFile) == true)
                                {
                                    return true;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                c++;
                d--;
            }
            return false;
        }

        if (kingRow > checkPieceRow && kingColumn > checkPieceColumn)
        {
            c = checkPieceRow + 1;
            d = checkPieceColumn + 1;
            while (c != kingRow && d != kingColumn)
            {
                for (int m = 0; m < 8; m++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        if (chessBoard[m][n].ifPresent == true && chessBoard[m][n].color == turnOf)
                        {
                            if (chessBoard[m][n].name == "wK" || chessBoard[m][n].name == "bK")
                            {
                                continue;
                            }
                            else
                            {
                                extractedRank = m + 1;
                                extractedFile = n + 65;
                                if (validityOfMove(c, d, extractedRank, extractedFile) == true)
                                {
                                    return true;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                c++;
                d++;
            }
            return false;
        }
    }
}

// if the piece that checked king can be taken down
bool canCut()
{
    int extractedRank;
    char extractedFile;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessBoard[i][j].ifPresent == true && chessBoard[i][j].color == turnOf)
            {
                extractedRank = i + 1;
                extractedFile = j + 65;
                if (validityOfMove(checkPieceRow, checkPieceColumn, extractedRank, extractedFile) == true)
                {
                    return true;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
    }
    return false;
}

// checks for Check for current colour i.e turnOf colour
bool isItCheck()
{
    // working: find the coordinates of the king. then for every opposite color piece check validity/legality of piece to that destination!

    // coordinates of the king
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((chessBoard[i][j].name == "wK" || chessBoard[i][j].name == "bK"))
            {
                if (chessBoard[i][j].color == turnOf)
                {
                    kingRow = i;
                    kingColumn = j;
                }
            }
        }
    }

    // stores the opposite color
    oppColor = (turnOf == 'W') ? 'B' : 'W';
    // now for each piece of other color; check if they can reach the king
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((chessBoard[i][j].ifPresent == true) && (chessBoard[i][j].color == oppColor))
            {
                int extractedRank = i + 1;
                char extractedFile = j + 65;

                if (validityOfMove(kingRow, kingColumn, extractedRank, extractedFile) == 1)
                {
                    checkPieceRow = extractedRank - 1;
                    checkPieceColumn = extractedFile - 65;
                    return true;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
    }
    return false;
}

// MAIN FUNCTION
void playGame(string player1, string player2, char player1color, char player2color)
{
    // initialize the board
    initializeBoard();
    printBoard();

    // test conditions if the game is over or not
    while ((tempVariable = allowPlay()) == 1)
    {
        move();
        printBoard();
        alternateTurn(); // W-----B
    }

    // end results
    if (tempVariable == -1)
    {
        cout << "Exceeded 100 moves! Its a DRAW!" << endl;
    }
    if (tempVariable == 2)
    {
        if (whiteKing == 1)
            cout << "White King Died! Black Player WINS!" << endl;
        if (blackKing == 1)
            cout << "Black King Died! White Player WINS!" << endl;
    }
    if (tempVariable == 0)
    {
        char oppoColor;
        if (turnOf == 'W')
            oppoColor = 'B';
        else
            oppoColor = 'W';

        if (oppoColor == player1color)
            cout << "Check Mate! Player " << player1 << " WINS!" << endl;
        if (oppoColor == player2color)
            cout << "Check Mate! Player " << player2 << " WINS!" << endl;
    }
    cout << "Thanks for playing" << endl;
}

#endif //CHESS_PROJECT_DEFS_Hv 
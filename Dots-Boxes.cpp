#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Player.h"
using namespace std;

static char board[7][7];
Player p1;
Player p2;
void pTurn(int turn);
void printBoard();
void fill(int row, int column);
void check(int row, int column, int turn);
void checkLeft(int row, int column, int turn);
void checkRight(int row, int column, int turn);
void checkUp(int row, int column, int turn);
void checkDown(int row, int column, int turn);

int main(){
    for(int i=0; i<7; i+=2){
        for(int j=0; j<7; j+=2){
            if(i%2==0 && j%2==0){
                board[i][j]='O';
            }
        }
    }

    int turn=0;
    while(p1.getScore()+p2.getScore()<9){
        turn%=2;
        pTurn(turn);
        turn++;
    }
    
    printBoard();
    cout<< endl;
    
    if(p1.getScore()>p2.getScore()){
    	cout<< "Player 1 wins!!!\n";
	}
	else if(p2.getScore()>p1.getScore()){
		cout<< "Player 2 wins!!!\n";
	}

    return 0;
}

//functions
void pTurn(int turn){
    printBoard();
    cout << endl;

    if(!turn){
        cout<< "Player 1's turn";
    }
    else if(turn){
        cout<< "Player 2's turn";
    }

    int row, column;
    cout<< "\nEnter row:      ";
    cin>> row;
    cout<< "Enter column:     ";
    cin>> column;
    fill(row, column);
    check(row, column, turn);
}

//print function 
void printBoard(){
    system("CLS");
    cout<< "Player 1:   " << p1.getScore() << endl;
    cout<< "Player 2:   " << p2.getScore() << endl;
    cout<< "\n  ";
    for(int i=0; i<7; i++){
        cout<< i;
    }
    cout<< endl;

    for(int i=0; i<7; i++){
        cout<< i << " ";

        for(int j=0; j<7; j++){
            if(board[i][j]){
                cout<< board[i][j];
            }
            else{
                cout<< " ";
            }
        }
        cout<< endl;
    }
}

//fill function
void fill(int row, int column){
    if((row==0 || row==2 || row==4 || row==6) && (column==1 || column==3 || column==5)){
        board[row][column]='-';
    }
    else if((row==1 || row==3 || row==5) && (column==0 || column==2 || column==4 || column==6)){
        board[row][column]='|';
    }
}

//checking function
void check(int row, int column, int turn){
    char n;
    n='0'+(turn);
    if(row==0){
        checkDown(row, column, turn+1);
    }

    else if(row==2 || row==4){
        checkUp(row, column, turn+1);
        checkDown(row, column, turn+1);
    }

    else if(row==6){
        checkUp(row, column, turn+1);
    }
    
    if(column==0){
        checkRight(row, column, turn+1);
    }

    else if(column==2 || column==4){
        checkRight(row, column, turn+1);
        checkLeft(row, column, turn+1);
    }

    else if(column==6){
        checkLeft(row, column, turn+1);
    }
}

void checkLeft(int row, int column, int turn){

    if(board[row][column-2]=='|'){
        if(board[row-1][column-1]=='-'){
            if(board[row+1][column-1]=='-'){
                char n='0'+turn;
                board[row][column-1]=n;
                if(turn==1){
                    p1.setScore();
                }
                else if(turn==2){
                    p2.setScore();
                }
            }
        }
    }
}

void checkRight(int row, int column, int turn){
    if(board[row][column+2]=='|'){
        if(board[row-1][column+1]=='-'){
            if(board[row+1][column+1]=='-'){
                char n='0'+turn;
                board[row][column+1]=n;
                if(turn==1){
                    p1.setScore();
                }
                else if(turn==2){
                    p2.setScore();
                }
            }
        }
    }
}

void checkUp(int row, int column, int turn){
    if(board[row-2][column]=='-'){
        if(board[row-1][column-1]=='|'){
            if(board[row-1][column+1]=='|'){
                char n='0'+turn;
                board[row-1][column]=n;
                if(turn==1){
                    p1.setScore();
                }
                else if(turn==2){
                    p2.setScore();
                }
            }
        }
    }
}

void checkDown(int row, int column, int turn){
    if(board[row+2][column]=='-'){
        if(board[row+1][column-1]=='|'){
            if(board[row+1][column+1]=='|'){
                char n='0'+turn;
                board[row+1][column]=n;
                if(turn==1){
                    p1.setScore();
                }
                else if(turn==2){
                    p2.setScore();
                }
            }
        }
    }
}
//end of checking function

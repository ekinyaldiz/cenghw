/*Ekin Yaldiz
 *ID: 2141372
 *N-Queen Problem: NxN Chess Board with N queens on it,
 *positioned in such a way that they are not able to attack each other.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//To create a dynamic zero NxN matrix
//Inspired by the lecture notes.

int **dynamicSquareMatrix(int N){
    int **matrix, i, j;
    matrix = (int**)malloc(sizeof(int *)*N);
    for (i=0;i<N;i++){
        matrix[i] = (int*)malloc(sizeof(int)*N);
        for (j=0;j<N;j++) {
            matrix[i][j] = 0;
        }
    }
    //Check point:
    return matrix;
}
//Given arguments represent
//The board, the size of the board and the position of the possible queen.
//Indices of row,col start from 0.
bool isSafe(int **board, int size, int row, int col) {
    int i,j;
    //Checking the left side of the row
    for(i=0; i<col; i++) {              //Note that, no need to check the columns, since
        if(board[row][i])               // we are not to yet have placed any queens on the column.
            return false;  
            }
    //Checking the upper-left diagonal
    for(i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
        if(board[i][j])
            return false;
    }
    //Checking the lower-left diagonal
    for(i=row+1, j=col-1;  i<size && j>=0; i++, j--) {
        if(board[i][j])
            return false;
    }
    return true;
}

void printBoard(int **board, int n) {
        int i,k;
        for(i=0; i<n; i++) {
            for(k=0; k<n; k++) {
                printf("%d ",board[i][k]);
            }
            printf("\n");
        }
        printf("\n\n");
}

/*
void insertQueen(int **board, int n, int row, int col) {
    //If we are to exceed the positions,
    //means we are out of probabilities.
    if((col==0) && (row==n))
    //If a solution is found
    if(col==n) {
        printBoard(board, n);
    }
    //If solution is not found within the column
    if(row==n) {
        int i=1;
        //Iterate until the nonzero element is found.
        do {
            row-=i;
        } while(!board[row][col-1]);

        board[row][col-1] = 0;
        return (insertQueen(board, n, row+1, col-1));
    }
    int i,j;
    if(isSafe(board, n, row, col)) {
        board[row][col] = 1;
        return insertQueen(board, n, 0, col+1);
    }
    else {
        row++; 
        return insertQueen(board, n, row, col);
    }
}
*/
int main() {
    int n, **board;
    bool a;
    printf("Enter the size of the chess board in integer value\n");
    scanf("%d",&n);
    if(n<4) {
        printf("There are no solutions for the given dimensions.\n");
        return 0;
    }
    board = dynamicSquareMatrix(n);
    printBoard(board, n);
//    insertQueen(board, n, 0, 0);
//TODO Free memory
}

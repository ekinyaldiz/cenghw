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

//Deletes the nonzero element off of the column and returns which row it was in
int refreshColumn(int **board, int n, int col) {
    int row=n-1;
    while(!board[row][col]) {
        row--;
    }
    board[row][col] = 0;
    return row;
}

void anotherQueen(int **board, int n, int row, int col) {
    if(row==n) {
        if(col==0) {    //Out of solutions nad backtracking
            return;
        }
        else {
            col--;
            while(!board[row-1][col]) { //We go upward until we find a nonzero element
                row--;
            }
            board[row-1][col] = 0;
            return anotherQueen(board, n, row, col); //Backtrack, try for the downer cell.
        }
    }
    //In this case a solution is found
    if(col==n) {
        printBoard(board, n);
        col--;
        refreshColumn(board, n, col);
        row = refreshColumn(board, n, col-1); //backtracking to find another solution
        if(row==n-1) {
            refreshColumn(board, n, col);
            col--;
            row = refreshColumn(board, n, col);
            return(anotherQueen(board, n, row+1, col));
        }
    
    }
    if(isSafe(board, n, row, col)) {
        board[row][col] = 1;         
        col++;
        return anotherQueen(board, n, 0, col);
    }
    else {
        row++;
        return anotherQueen(board, n, row, col);
    }
}
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
    anotherQueen(board, n, 0, 0);
//    insertQueen(board, n, 0, 0);
//TODO Free memory
}

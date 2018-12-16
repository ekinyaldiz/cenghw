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
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
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

int placeQueen(int **board, int pos, int n) {
    //Base Case 1:
    if(board[n-1][0] == 0) {
        if(j==n)
            printBoard() //TODO Prepare the printBoard function :D //Printboard one last time
            return 1;
        for(board[n-1][n-1] == 0)
    }
    //Checking possible positions within the row
    i=0; j=0;
    while(j<n) {
        if(isSafe) {
            matrix[i][j] = 1;
            i=0; j++;
            //continue
        }
        else {
            if(i<n-1)
            i++;
            else {  //Meaning we have come to EOL
            i=0; j++;
            }
        }
    }
    /*TODO if safe, place the queen then return itself with the next column
     * if NOT safe, renounce (lol) the last queen of its position.
     * Remember that these are all matrix manipulations. 
     * When reached the end of the board, if we do have a solution, we print.
     * If not we backtrack without any outputs whatsoever.
     */

}

int main() {
    int n, **matrix;
    bool a;
    printf("Enter the size of the chess board in integer value\n");
    scanf("%d",&n);
    matrix = dynamicSquareMatrix(n);
    a = isSafe(matrix, n,3,3);
    printf("%d",a);
//TODO Free memory
}

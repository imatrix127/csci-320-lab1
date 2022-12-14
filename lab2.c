#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "lab2.h"

int** sudoku_board;
int* worker_validation;

int** read_board_from_file(char* filename){
    FILE *fp = NULL;
    fp = fopen(filename,"r");

    if(fp == NULL){
        fprintf(stderr, "%s", "Cannot open File!");
    }

    int** board = (int**)malloc(sizeof(int*)*ROW_SIZE);

    // replace this comment with your code

    for( int row = 0; row < ROW_SIZE; row++){
        board[row] = (int*)malloc(sizeof(int)*COL_SIZE);

    }
    for(int i = 0; i < ROW_SIZE; i++){
        for(int k = 0; k < COL_SIZE; k++){
            //printf("Reading...");
            fscanf(fp, "%d%*c", &(board[i][k]));
            //printf("%d,%d  %d\n", i,k,board[i][k]);
        }
    }
    for(int i = 0; i < ROW_SIZE; i++){
        for(int k = 0; k < COL_SIZE; k++){
            //printf("Printing...");
            printf("%d ", board[i][k]);

        }
        printf("\n");
    }
    fclose(fp);
    return board;
}

void *validating_columns(void* parameters)
{
    param_struct *p = (param_struct*) parameters;

    int validate[COL_SIZE] = {0};
    int row = p -> starting_row;
    int column = p -> starting_col;

    //check for invalid values
    if (row != 0 || column > 8)
        {
            fprintf(stderr, "INVALID Column at row=%d, column=%d", row, column);
            pthread_exit(NULL);
        }
    //check for values 1-9
    for(int i = 0; i< 9; i++)
    {

        int board = sudoku_board[i][column];

        if (board > 9 || board < 1 || validate[board - 1]==1)
        {

            pthread_exit(NULL);
        }

        else{

            validate[board - 1] = 1;
        }
    }

    worker_validation[ 18 + column] = 1;
    pthread_exit(NULL);
}
void *validating_rows(void* parameters)
{
    param_struct *p = (param_struct*) parameters;

    int validate[ROW_SIZE] = {0};
    int row = p -> starting_row;
    int column = p -> starting_col;

    if (column != 0 || row > 8)
        {
            fprintf(stderr, "INVALID Column at row=%d, column=%d", row , column);
            pthread_exit(NULL);
        }

    for(int i = 0; i< 9; i++)
    {
        int board = sudoku_board[row][i];

        if (board > 9 || board < 1 || validate[board - 1]==1)
        {
            pthread_exit(NULL);
        }
        else{
            validate[board - 1] = 1;
        }
    }

    worker_validation[9 + row] = 1;
    pthread_exit(NULL);

}
void *valid_3x3(void* parameters)
{
    param_struct *p = (param_struct*) parameters;
    int validate[ROW_SIZE] = {0};
    int row = p -> starting_row;
    int col = p -> starting_col;

    if( row > 6 || col > 6 || row %3 != 0 || col %3 !=0){
        fprintf(stderr, "INVALID subsection at row=%d, column=%d", row, col);
        pthread_exit(NULL);
    }

    for(int i = row; i < row + 3; i++){
        //printf("row=%d",row);
        for(int k = col; k < col + 3; k++){
            printf("column=%d",col);
            int board = sudoku_board[i][k];
            printf("board made...\n");

            if (board > 9 || board < 1 || validate[board - 1]==1)
            {

                pthread_exit(NULL);
            }
            else{
                validate[board-1] = 1;
            }
        }
    }
    worker_validation[row + col / 3] = 1;
    pthread_exit(NULL);

}



int is_board_valid(){
    pthread_t* tid;  /* the thread identifiers */
    pthread_attr_t attr;
    param_struct* parameter;
    // replace this comment with your code

    int threadCounter = 0;
    worker_validation = (int*)malloc(sizeof(int)*NUM_OF_THREADS);

    tid = (pthread_t*)malloc(sizeof(int)*NUM_OF_THREADS);

    param_struct* param = (param_struct*)malloc(sizeof(param_struct)*NUM_OF_THREADS);
    for(int i = 0; i < ROW_SIZE; i++)
    {
        for(int j = 0; j < COL_SIZE; j++)
        {
            if(i%3 == 0 && j%3 == 0){
                printf("3x3 validating ... \n");
                //param_struct *worker3x3 = (param_struct*) malloc(sizeof(param_struct));
                param[threadCounter].starting_row = i;
                param[threadCounter].starting_col = j;
                pthread_create(&tid[threadCounter], NULL, valid_3x3, param);

            }
            if(i==0){
                //param_struct *workerColumn = (param_struct*) malloc(sizeof(param_struct));
                param[threadCounter].starting_row = i;
                param[threadCounter].starting_col = j;
                pthread_create(&tid[threadCounter], NULL,validating_columns,param);

            }
            if(j==0){
                //param_struct *workerRow = (param_struct*) malloc(sizeof(param_struct));
                param[threadCounter].starting_row = i;
                param[threadCounter].starting_col = j;
                pthread_create(&tid[threadCounter], NULL, validating_rows, param);

            }
            threadCounter++;


        }free(param);
    }

    for(int i = 0; i< NUM_OF_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    for (int i = 0; i<NUM_OF_THREADS; i++)
    {
        if(worker_validation[i] == 0){
            return 0;
        }

    }
    free(worker_validation);
    free(tid);
    return 1;
}


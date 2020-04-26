#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<unistd.h>
#include"arena.h"
#include"cell.h"
int **GameStep(int size, int **game){
    int **copy=copyArena(size,game);
    for(int i=0;i<size;i++){
        for (int j=0; j<size;j++){
            game[i][j]=cellSituation(i, j, size, copy);            
        }
    }
    return game;
}


void playGame(int size, int **arena){
    while(1){
        for(int i=0; i<size; i++){
            printf("\033[%d;4H",i+2);
            for(int j=0; j<size; j++){
                if(arena[i][j]==1){
                    printf("\033[104m  ");
                }else{
                    printf("\033[40m  ");
                }
            }
            printf("\n");
            }
        printf("\033[?25h");
        sleep(1);
        arena=GameStep(size, arena);
        }

}

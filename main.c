//
//  main.c
//  C Program
//
//  Created by Alf Martin B Selen on 12/09/2018.
//  Copyright © 2018 Alf Martin B Selen. All rights reserved.
//

#include <stdio.h>
//#include <stdbool.h>


//bool trueorfalse = false;
char data[9];
short int keepRunning = 1; //its a bool
int turn = 0;
//bool istrue = false;

short int Mac = 0;


void display(char input[9])
{
    if(Mac)
        system("clear");
    else
        system("cls");
    printf("T i c   T a c   T o e\nPlayer 1: X & Player 2: O\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(j != 2) printf("   %c   |", input[i*3+j]);
            else printf("   %c", input[i*3+j]);
        }
        if(i != 2) printf("\n---------------------\n");
        else printf("\n");
    }
}

int playerTurn()
{
    int numb = 0;
    printf("Input a number from 1 to 9:\n");
    scanf("%i", &numb);
    while(numb < 1 || numb > 9) {
        printf("Please input a number from 1 to 9:\n");
        scanf("%i", &numb);
    }
    while(data[numb-1] == 'X' || data[numb-1] == 'O') {
        printf("Please input a number from 1 to 9, not used yet:\n");
        scanf("%i", &numb);
    }
    
    return numb - 1;
}

void run()
{
    while(keepRunning == 1 && turn < 9){
    display(data);
    if(turn % 2 == 0) {
        data[playerTurn()] = 'X'; }
    else {
        data[playerTurn()] = 'O'; }
        
    
    if(checkWin() == 0)
    {
        break;
    }
    turn++;
    }
    display(data);
    if(checkWin() == 0)
    {
        if(turn % 2 == 0)
            printf("Player X won!\n");
        else
            printf("Player 0 won!\n");
    }
        printf("End of Game. . . Press enter to Quit\n");
    getchar();
    getchar();
}

int checkWin()
{
        //Horizontal
        if(data[0] == data[1] && data[0] == data[2] && data[0] != ' ') {
            return 0;
        }
        else if(data[3] == data[4] && data[3] == data[5] && data[3] != ' ') {
            return 0;
        }
        else if(data[6] == data[7] && data[6] == data[8] && data[6] != ' ') {
            return 0;
        }
    
        //Vertical
        else if(data[0] == data[3] && data[0] == data[6] && data[0] != ' ') {
            return 0;
        }
        else if(data[1] == data[4] && data[1] == data[7] && data[1] != ' ') {
            return 0;
        }
        else if(data[2] == data[5] && data[2] == data[8] && data[2] != ' ') {
            return 0;
        }
    
        //Diagonal
        else if(data[0] == data[4] && data[0] == data[8] && data[0] != ' ') {
            return 0;
        }
        else if(data[2] == data[4] && data[2] == data[6] && data[2] != ' ') {
            return 0;
        }
        else return 1;
}



int main() {
    if(system(NULL))
        Mac = 1;
    for (int i = 0; i < 9; i++) {
        data[i] = ' '; }
    run();
    return 0;
}

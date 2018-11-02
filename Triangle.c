//
//  main.c
//  Triangle
//
//  Created by Alf Martin B Selen on 08/10/2018.
//  Copyright © 2018 Alf Martin B Selen. All rights reserved.
//

#include <stdio.h>

// Global Variables
    int stars = 0;



int SimpleTriang()
{
    // First for loop is to print each line
    for(int i = 0; i < stars; i++)
    {
        // Secound loop is to print numb of stars on each line
        for(int j = i + 1; j > 0; j--)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

int ReverseTriang()
{
    for(int i = 1; i < stars + 1; i++)
    {
        for(int j = 0; j < stars - i; j++)
            printf(" ");
        for(int j = 0; j < i; j++)
            printf("*");
        
        printf("\n");
    }
    return 0;
}


int ShutDown()
{
    getchar();
    printf("Press enter to Quit: ");
    getchar();
    printf("Shutting down. . .");
    return 0;
}


int main(int argc, const char * argv[]) {
    
    // Input a numb to print stars
    printf("Numb of stars: ");
    scanf("%i", &stars);
    
    ReverseTriang();

    
    // Press enter to quit
    ShutDown();
    return 0;
}

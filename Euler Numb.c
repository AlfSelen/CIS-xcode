//
//  main.c
//  Eulers Number
//
//  Created by Alf Martin B Selen on 08/10/2018.
//  Copyright © 2018 Alf Martin B Selen. All rights reserved.
//

#include <stdio.h>
#include <math.h>
float divider = 1;
float euler = 1;
double divider2 = 1.0;
double euler2 = 1.0;



int Euler()
{
    printf("Euler is: %f, and steps is %d\n",euler, 1);
    //Loops through the iterations for compution eulers numb
    for(int i = 1; i < 10; i++)
    {
        //Increases the divider
        divider *= i;
        euler +=  1 / divider;
        printf("Euler is: %f, and steps is %d\n",euler,i + 1);
        //10 Iterations, and 6 decimals numbers is the most accurate
    }
    return 0;
}

//10000 Iterations give 3.14149, so three valid
void Pi() {
    double sum = 0;
    double pi;
    for(int i = 1; i < 10000; i++) {
        sum += (double) ( 1 / pow(i, 2));
        pi = sqrt(sum) * sqrt(6);
        printf("The iteration is %i and pi = %.20lf\n",i,pi);
    }
}

//10000 Iterations give 3.3425, so one valid
void Pi2() {
    double sum = 0;
    int neg = 1;
    //double pi;
    for(int i = 1; i <= 10000; i++) {
        sum += (double) 1 / (neg * (i + (2 * (i - 1))));
        neg *= -1;
        //printf("The iteration is %i and pi = %.20lf\n",i,sum * 4);
    }
    printf("The iteration is 100 and pi = %.20lf\n",sum * 4);
    
}

int Euler2()
{
    printf("Euler is: %f, and steps is %d\n",euler2, 1);
    //Loops through the iterations for compution eulers numb
    for(int i = 1; i < 60; i++)
    {
        //Increases the divider
        divider2 *= i;
        euler2 +=  1.0 / divider2;
        printf("Euler is: %.50lf, and steps is %d\n",euler2,i + 1);
    }
    //printf("Euler is: %.40lf, and steps is %d\n",euler2, 1000000);
    return 0;
    
    //18 Iterations, and 50 decimal numbers is the most accurate
}


int Prime()
{
    int n, i, flag = 0;
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    for(i = 3; i <= n/2; i+=2)
    {
        //printf("%i\n",i);
        // condition for nonprime number
        if(n%i == 0)
        {
            printf("%i\n",i);
            flag = 1;
            break;
        }
    }
    if (n == 1)
    {
        printf("1 is neither a prime nor a composite number.");
    }
    else
    {
        if (flag == 0)
            printf("%d is a prime number.\n", n);
        else
            printf("%d is not a prime number.\n", n);
    }
    return 0;
}






int main(int argc, const char * argv[]) {
    printf("Hello, World!\n");
    Pi2();
    //Euler();
    //Euler2();
    //getchar();
    //Prime();
    return 0;
}



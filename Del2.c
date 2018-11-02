//
//  main.c
//  Del 2 Innlevering
//
//  Created by Alf Martin B Selen on 16/10/2018.
//  Copyright © 2018 Alf Martin B Selen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

clock_t start_t, stop_t;
int myHand[5], myHandSorted[5], handInfo[5][2], colorInfo[4] = {0}; //39-51 Spades, 26-38 Hearts, 13-25 Diamonds, 0-12 Clubs Spar,Hjerter,Ruter,Kløver
char buffer[255], *mystring = "a nice string";
int handLenght = 0; //5, Max 5 diffrent cards
char *options[10] = {"Exit", "One pair", "Two pair", "Three of a kind", "Four of a kind", "House", "Straight","Flush", "Straight Flush", "Royal Straight Flush"};
short int Mac = 0;
time_t t;


int ikkeImplentert()
{
    printf("Beklager denne funksjonen er ikke implementert ennå.\n");
    return 0;
}

void vent()
{
    sleep(2);
}

int menyPrint()
{
    system("clear");
    for(int i = 0; i < 10; i++)
        printf("(Valg %i) : %s\n",i,options[i]);
    return 0;
}

void deal(int hand[])
{
    int deck[52];
    for(int i = 0; i < 52; i++)
        deck[i] = 0;
    for(int i = 0; i < 5; i++)
    {
        while(1) {
        int b = rand() % 52;
            if(deck[b] == 0) {
                deck[b] = 1;
                hand[i] = b;
                break;
}}}}


int getHandInfo() {
    for(int i = 0; i < 5; i++)
        handInfo[i][0] = -1;
    for(int i = 0; i < 5; i++)
        handInfo[i][1] = 0;
    for(int i = 0; i < 4; i++)
        colorInfo[i] = 0;
    handLenght = 0;
    
    for(int i = 0; i < 5; i++) {
        myHandSorted[i] = myHand[i] % 13;
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(handInfo[j][0] == -1) {
                handInfo[j][0] = myHand[i] % 13;
                handInfo[j][1]++;
                handLenght++;
                break;
            }
            else if(handInfo[j][0] == myHand[i] % 13) {
                handInfo[j][1]++;
                break;
            }
        }
    }
    //Color Info
    for(int i = 0; i < 5; i++)
    {
        if(myHand[i] / 13 >= 3)
            colorInfo[0]++;
        else if(myHand[i] / 13 >= 2)
            colorInfo[1]++;
        else if(myHand[i] / 13 >= 1)
            colorInfo[2]++;
        else
            colorInfo[3]++;
    }
    //Order Info
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(myHandSorted[j] > myHandSorted[i]) {
                int tmp = myHandSorted[i];         //Using temporary variable for storing last value
                myHandSorted[i] = myHandSorted[j];            //replacing value
                myHandSorted[j] = tmp;
            }
        }
    }
    return 0;
}

//Returns 1 if contains one pair
int pair() {
    if(handLenght > 3) {
    for(int i = 0; i < handLenght; i++) {
        if (handInfo[i][1] > 1 )
            return 1;
    } }
    return 0;
}
//Returns 1 if contains atleast two pair
int twoPair() {
    int pairs = 0;
    for(int i = 0; i < handLenght; i++) {
        if (handInfo[i][1] > 1)
            pairs++; }
    if(pairs > 1)
        return 1;
    return 0;
}

//Returns 1 if three of a kind
int threeOfAKind() {
    for(int i = 0; i < handLenght; i++) {
        if(handInfo[i][1] == 3)
            return 1;
    }
    return 0;
}
//Return 1 if four of a kind
int fourOfAKind() {
    for(int i = 0; i < handLenght; i++) {
        if(handInfo[i][1] == 4)
            return 1;
    }
    return 0;
}
//Return 1 if house
int house() {
    for(int i = 0; i < handLenght; i++) {
        if(handInfo[i][1] == 3) {
            for(int j = 0; j < handLenght; j++) {
                if(handInfo[j][1] == 2)
                    return 1;
            }
        }
    }
    return 0;
}
//Return 1 if straight
int straight() {
    //Checking first if Ace is one of the cards

    //Checking then if there are 5 cards in a straight
    int value = 0;
    for(int i = 0; i < 4; i++) {
        if(myHandSorted[i] + 1 == myHandSorted[i+1])
            value++;
    }
    if(value == 4)
        return 1;
    if(myHandSorted[0] == 0 &&
       myHandSorted[1] == 9 &&
       myHandSorted[2] == 10 &&
       myHandSorted[3] == 11 &&
       myHandSorted[4] == 12)
        return 1;
    return 0;
}
//Return 1 if flush
int flush() {
    for(int i = 0; i < 4; i++) {
        if(colorInfo[i] == 5)
            return 1;
    }
    return 0;
}
//Return 1 if flush and straight
int straightFlush() {
    if(straight() && flush())
        return 1;
    return 0;
}
//Return 1 if flush straight and highest card
int royalStraightFlush() {
    if(straight() && flush() && myHandSorted[4] == 12 && myHandSorted[0] == 0)
        return 1;
    return 0;
}

double probability(int a) {
    int hands, count = 0;
    printf("Enter how many hands do you want so simulate: ");
    scanf("%i",&hands);
    for(int i = 0; i < hands; i++) {
        deal(myHand);
        getHandInfo();
        switch(a) {
            case 1:
                count+= pair();
                break;
            case 2:
                count+= twoPair();
                break;
            case 3:
                count+= threeOfAKind();
                break;
            case 4:
                count+= fourOfAKind();
                break;
            case 5:
                count+= house();
                break;
            case 6:
                count+= straight();
                break;
            case 7:
                count+= flush();
                break;
            case 8:
                count+= straightFlush();
                break;
            case 9:
                count+= royalStraightFlush();
                break;
        }
    }
    printf("Ammount of equal is %i\n",count);
    if(hands > 0) {
        if(count == 0)
            return 0;
        else
            return (double) count / hands;
    }
    return 0;
    
}





void show() {
    for(int i = 0; i < 5; i++)
    {
        if(myHand[i] / 13 >= 3)
            printf("The %i card in the hand is: %i♠\n",i+1,(myHand[i] % 13)+1);
        else if( myHand[i] / 13 >= 2)
            printf("The %i card in the hand is: %i♥\n",i+1,(myHand[i] % 13)+1);
        else if(myHand[i] / 13 >= 1)
            printf("The %i card in the hand is: %i♦\n",i+1,(myHand[i] % 13)+1);
        else
            printf("The %i card in the hand is: %i♣\n",i+1,(myHand[i] % 13)+1);
    }
}



int main(int argc, const char * argv[]) {
    /* Intializes random number generator */
    srand((unsigned) time(&t));
    // Check if on mac
    if(system(NULL))
        Mac = 1;
    
    /* -- This is for debugging, the code should be fixed now, without any flaws...
    menyPrint();
    deal(myHand);
    myHand[0] = 0;
    myHand[1] = 12;
    myHand[2] = 11;
    myHand[3] = 10;
    myHand[4] = 8;
    getHandInfo();
    show();
    printf("Is royal: %i",straight());
    */
    
    
    while(1) {
    if(Mac)
        system("clear");
    else
        system("cls");
    menyPrint();
    deal(myHand);

        
        
    for(int i = 0; i < 5; i++) {
        myHandSorted[i] = myHand[i] % 13;
    }
    //getHandInfo();
    //show();
    
    int a;
    scanf("%i",&a);
    if(a == 0) {
        printf("Exiting\n");
        break;
    }
    else
        printf("The probability of %s is: %f\n",options[a],probability(a));
    vent();
    }
    
    
    return 0;
    
    

    
}

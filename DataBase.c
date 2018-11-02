//
//  main.c
//  CD_DatabaseEntry
//
//  Created by Alf Martin B Selen on 01/04/15.
//  Copyright (c) 2015 Alf Martin B Selen. All rights reserved.
//

#include <stdio.h>      // declares printf(), scanf() and fpurge().
#include <stdbool.h>    // declares bool.
#include <string.h>     // declares strcmp().
#include <stdlib.h>     // We'll need that later for malloc() and realloc().

struct CDDatabaseEntry
{
    char Artist[40];
    char Composer[40];
    char AlbumName[40];
    int TrackCount;
    bool isSampler;
};

// Global variables:
int gNumDatabaseEntries = 0;
struct CDDatabaseEntry* gDatabase = NULL;

//Functions:
void DoNewCommand();
void DoNewCommand() // DoNewCommand
{
    char YesOrNo;
    if( gDatabase == NULL)
    {
        gDatabase = malloc(sizeof(struct CDDatabaseEntry));
        if (gDatabase == NULL)
        {
            printf("ERROR: Couldn't create a new entry!\n");
            return;
        }
    }
    else
    {
        struct CDDatabaseEntry* newPtr = NULL;
        newPtr = realloc( gDatabase, (gNumDatabaseEntries + 1) *sizeof(struct CDDatabaseEntry));
        if (newPtr == NULL)
        {
            printf("ERROR: Couldn't create a new entry!\n");
            return;
        }
        gDatabase = newPtr;
    }
    gNumDatabaseEntries += 1;
    
    printf("Artist name: ");
    scanf("%39s", gDatabase [ gNumDatabaseEntries -1].Artist);
    fpurge(stdin);
    
    printf( "Composer: " );
    scanf( "%39s", gDatabase[ gNumDatabaseEntries -1 ].Composer );
    fpurge( stdin );
    
    printf( "Album Name: " );
    scanf( "%39s", gDatabase[ gNumDatabaseEntries -1 ].AlbumName );
    fpurge( stdin );
    
    printf( "No. of Tracks: " );
    scanf( "%d", &gDatabase[ gNumDatabaseEntries -1 ].TrackCount );
    fpurge( stdin );
    
    printf( "Sampler? (y/n): " );
    scanf( "%c", &YesOrNo );
    fpurge( stdin );
    
    gDatabase[ gNumDatabaseEntries -1 ].isSampler = (YesOrNo == 'y' || YesOrNo == 'Y');
    
}

void DoListCommand();
void DoListCommand() // DoListCommand
{
    int x = 0;
    if(gDatabase == NULL)
    {
        printf("There are no CDs in the database.\n");
        return;
    }
    
    while (x < gNumDatabaseEntries)
    {
        printf( "Artist Name: %s\n", gDatabase[ x ].Artist );
        printf( "Composer: %s\n", gDatabase[ x ].Composer );
        printf( "Album Name: %s\n", gDatabase[ x ].AlbumName );
        printf( "No. of Tracks: %d\n", gDatabase[ x ].TrackCount );
        if (gDatabase[ x ].isSampler)
            printf("\tThis CD is a sampler.\n");
        printf("\n");
            
        x += 1;
    }
}

void DoCleanUp( void );
void DoCleanUp( void )
{
    if (gDatabase != NULL)
    {
        free( gDatabase );
        gDatabase = NULL;
        gNumDatabaseEntries = 0;
    }
}

// Main loop:
//Fetches the doXXX functions.

int main()
{
    bool keepRunning;
    keepRunning = true;
    char userInput[11];
    
    while ( keepRunning == true )
    {
        printf( "Type NEW , LIST, or QUIT:\n> " );
        scanf( "%10s", userInput );
        fpurge( stdin );
        
        if( strcmp( userInput, "NEW" ) == 0 )
        {
            DoNewCommand();
        }
        else if( strcmp( userInput, "LIST" ) == 0 )
        {
            DoListCommand();
        }
        else if( strcmp( userInput, "QUIT" ) == 0 )
        {
            keepRunning = false; // We're finished.
        }
        else printf( "ERROR: Unknown command \"%s\"!\n\n", userInput );

    }
    DoCleanUp();
    return 0;
}








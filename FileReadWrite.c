//
//  main.c
//  File read write test
//
//  Created by Alf Martin B Selen on 16/10/2018.
//  Copyright © 2018 Alf Martin B Selen. All rights reserved.
//

#include <stdio.h>
//#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    fp = fopen("/Users/AlfSelen/Desktop/test.txt", "r");
    if (fp == NULL)
        return 1;
    
    while ((read = getline(&line, &len, fp)) != -1) {
        //printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
    }
    
    fclose(fp);
    getchar();
    return 0;
}

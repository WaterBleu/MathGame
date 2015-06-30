//
//  main.c
//  MathGame
//
//  Created by Jeff Huang on 2015-06-30.
//  Copyright (c) 2015 Jeff Huang. All rights reserved.
//

#include <stdio.h>
#include "MathGame.h"
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    struct Player p1;
    struct Player p2;
    initPlayer(&p1);
    initPlayer(&p2);
    
    printf("------------------------------------\n");
    printf("Weclome to the math game\n");
    printf("------------------------------------\n");
    printf("Please enter in the name of Player 1: ");
    fgets(p1.name, sizeof(p1.name)/sizeof(char), stdin);
    printf("Please enter in the name of Player 2: ");
    fgets(p2.name, sizeof(p2.name)/sizeof(char), stdin);
    printf("------------------------------------\n");

    while (p1.live != 0 && p2.live != 0){
        int ansP1 = generateQuestion(&p1);
        int ans;
        char userInput[5];
        scanf("%d", &ans);
        if(ansP1 != ans){
            liveLost(&p1);
            if(p1.live == 0){
                printf("Game Over! Live hits 0 for %s", p1.name);
                printf("Would you like to restart? (Yes to continue or Any phrase to quit)");
                scanf("%s", userInput);
                if (strstr(userInput,"Yes") != NULL) {
                    newGame(&p2, &p1);
                }
                else {
                    endGame(&p2, &p1);
                    break;
                }
            }
            else
                printf("Wrong!  Remaining live: %d for %s", p1.live, p1.name);
        }
        int ansP2 = generateQuestion(&p2);
        scanf("%d", &ans);
        if(ansP2 != ans){
            liveLost(&p2);
            if(p2.live == 0){
                printf("Game Over! Live hits 0 for %s", p2.name);
                printf("Would you like to restart? (Yes to continue or Any phrase to quit)");
                scanf("%s", userInput);
                if (strstr(userInput,"Yes") != NULL) {
                    newGame(&p1, &p2);
                }
                else {
                    endGame(&p1, &p2);
                    break;
                }
            }
            else
                printf("Wrong!  Remaining live: %d for %s", p2.live, p2.name);
        }
    }
    
    return 0;
}



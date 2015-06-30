//
//  MathGame.c
//  MathGame
//
//  Created by Jeff Huang on 2015-06-30.
//  Copyright (c) 2015 Jeff Huang. All rights reserved.
//

#include "MathGame.h"
#include <string.h>
#include <stdio.h>

void initPlayer(struct Player *p){
    //for(int i = 0; i < (unsigned)strlen(p.name); i++)
    //    p.name[i] = '\0';
    p->live = 3;
    p->score = 0;
}

int generateQuestion(struct Player *p){
    int sum;
    int n1;
    int n2;
    
    n1 = rand() % 21;
    n2 = rand() % 21;
    sum = n1 + n2;
    
    printf("Question for %s: What does %d plus %d equal? \n", p -> name, n1, n2);
    
    return sum;
}

void liveLost(struct Player *p){
    p -> live -= 1;
}

void newGame(struct Player *winner, struct Player *loser){
    winner -> live = 3;
    winner -> score += 1;
    loser -> live = 3;
    printScore(winner, loser);
}

void endGame(struct Player *winner, struct Player *loser){
    winner -> score += 1;
    printScore(winner, loser);
}

void printScore(struct Player *p1,struct Player *p2){
    printf("Current Standing: \n %d points for %s %d points for %s", p1 -> score, p1 -> name, p2 -> score, p2 -> name);
}
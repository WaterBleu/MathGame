//
//  MathGame.h
//  MathGame
//
//  Created by Jeff Huang on 2015-06-30.
//  Copyright (c) 2015 Jeff Huang. All rights reserved.
//

#ifndef __MathGame__MathGame__
#define __MathGame__MathGame__

#include <stdio.h>

#endif /* defined(__MathGame__MathGame__) */

struct Player{
    char name[30];
    int live;
    int score;
};

void initPlayer(struct Player *p);
void newGame(struct Player *winner, struct Player *loser);
void endGame(struct Player *winner, struct Player *loser);
void liveLost(struct Player *p);
void printScore(struct Player *p1, struct Player *p2);
int generateQuestion(struct Player *p);
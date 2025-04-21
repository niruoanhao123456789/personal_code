#pragma once
#define ROW 5
#define COL 5
#define NUM 5

//初始化棋盘
void initboard(char board[ROW][COL], int row, int col);

//打印棋盘
void Displayboard(char board[ROW][COL], int row, int col);

//玩家下棋
void Playermove(char board[ROW][COL], int row, int col);

//电脑下棋
void Computermove(char board[ROW][COL], int row, int col);

//判断输赢
//玩家赢#
//电脑赢*
//平局q
//继续c
char Iswin(char board[ROW][COL],int row,int col);

//玩家先手 0
//电脑先手 1
int whofirst();

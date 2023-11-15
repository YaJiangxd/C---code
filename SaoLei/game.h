#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            arr[i][j] = set;
        }
    }
}

void DisplayBoard(char arr[ROWS][COLS], int rows, int cols)
{
    int i, j;
    printf("-----------扫雷游戏-----------\n    ");
    for (i = 1; i <= rows; i++)
    {
        printf("[%d]", i);
    }
    printf("\n");

    for (i = 1; i <= rows; i++)
    {
        printf("[%d] ", i);
        for (j = 1; j <= cols; j++)
        {
            printf(" %c ", arr[i][j]);
        }
        printf("\n");
    }
    printf("-----------扫雷游戏-----------\n");
}

void SetMine(char arr[ROWS][COLS], int row, int col)
{
    int count = 10;
    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (arr[x][y] == '0')
        {
            arr[x][y] = '1';
            count--;
        }
    }
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
    int win = 0; // 找出非雷的个数
    int count = 10;
    while (win < rows * cols - count)
    {
        int x, y, boomcount, i, j;

        printf("请输入你想看的坐标 :>");
        scanf("%d%d", &x, &y);
        if (mine[x][y] == '1')
        {
            printf("你被炸死啦！\n游戏结束");
            DisplayBoard(mine, ROW, COL);
        }
        else
        {
            win++;
            boomcount = 0;
            for (i = x - 1; i < x + 1; i++)
            {
                for (j = x - 1; j < y + 1; j++)
                {
                    boomcount += mine[i][j] - '0';
                }
            }
            show[x][y] = boomcount + '0';
            DisplayBoard(show, ROW, COL);
        }
    }
    if (win == rows * cols - count)
    {
        printf("**********************");
        printf("****恭喜你扫雷成功!****");
        printf("**********************");
    }
}
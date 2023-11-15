#include "game.h"

void menu()
{
    printf("***********************************\n");
    printf("**********     1.play    **********\n");
    printf("**********     0.exit    **********\n");
    printf("***********************************\n");
}

void game()
{
    char mine[ROWS][COLS] = {0}; // 布置好的雷
    char show[ROWS][COLS] = {0}; // 排查出的雷
    /*  初始化  */
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    /*  展示界面  */
    DisplayBoard(show, ROW, COL);
    /*  设置雷  */
    SetMine(mine, ROW, COL);
    /*  玩家排查雷  */
    FindMine(mine, show, ROWS, COLS);
}

int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));

    do
    {
        menu();
        printf("请选择 :>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("开始扫雷！\n");
            game();
            break;
        case 0:
            printf("退出游戏！\n");
            break;
        default:
            printf("选择错误！\n");
            break;
        }
    } while (input);
}
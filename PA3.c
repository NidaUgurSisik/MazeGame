#include <stdio.h>
char mazegame[50][50];
int row, column, sum = 0, rf, cf;
void funcdraw();
int Funcud(int *next, int *rs, int *cs);
int Funclr(int *cs, int *rc, int *next);

int main()
{
    int next, r, c, rs, cs, placement = 1, commander = 1;
    char design, commands;
    scanf("%d %d", &row, &column);
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < column; c++)
            if (r == 0 || r == row - 1 || c == 0 || c == column - 1)
                mazegame[r][c] = '*';
            else
                mazegame[r][c] = ' ';
    }
    while (placement)
    {
        scanf("%c", &design);
        if (design == 's' || design == 'f' || design == 'b' || design == 'X' || design == '$')
        {
            scanf(" %d%d", &r, &c);
            switch (design)
            {
            case 's':
                mazegame[r][c] = 'O';
                rs = r, cs = c;
                break;
            case 'f':
                mazegame[r][c] = ' ';
                rf = r, cf = c;
                break;
            case 'b':
                mazegame[r][c] = '*';
                break;
            case 'X':
                mazegame[r][c] = 'X';
                break;
            case '$':
                mazegame[r][c] = '$';
                break;
            }
        }
        if (design == 'e')
        {
            scanf("%c%c", &design, &design);
            placement = 0;
        }
        if (design == 'q')
        {
            printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
            return 0;
        }
    }
    funcdraw();

    int ud, lr;
    int flag = 1;
    while (commander)
    {
        if ((scanf("%c", &commands)) == EOF)
        {
            commander = 0;
            flag = 0;
        }
        switch (commands)
        {
        case 'u':
            mazegame[rs][cs] = ' ';
            next = rs - 1;
            ud = Funcud(&next, &rs, &cs);
            break;
        case 'd':
            mazegame[rs][cs] = ' ';
            next = rs + 1;
            ud = Funcud(&next, &rs, &cs);
            break;
        case 'l':
            mazegame[rs][cs] = ' ';
            next = cs - 1;
            lr = Funclr(&cs, &rs, &next);
            break;
        case 'r':
            mazegame[rs][cs] = ' ';
            next = cs + 1;
            lr = Funclr(&cs, &rs, &next);
            break;
        case 'q':
            printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
            funcdraw();
            return 0;
            break;
        }
        if ((ud == 0) || (lr == 0))
            return 0;
    }
    if (!((rs == rf) && (cs == cf)) && flag == 0)
    {
        printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
        funcdraw();
    }
    return 0;
}
void funcdraw()
{
    int r, c;
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < column; c++)
        {
            printf("%c", mazegame[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}
int Funcud(int *next, int *rs, int *cs)
{
    if (mazegame[*next][*cs] == 'X')
    {
        printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
        mazegame[*rs][*cs] = 'O';
        funcdraw();
        return 0;
    }
    else if (mazegame[*next][*cs] == '*')
    {
        printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
        mazegame[*rs][*cs] = 'O';
        *next = *rs;
        funcdraw();
    }
    else if (mazegame[*next][*cs] == '$')
    {
        sum++;
        printf("YOU GOT 1 $.\n");
        mazegame[*rs][*cs] = ' ';
        mazegame[*next][*cs] = 'O';
        *rs = *next;
        funcdraw();
    }
    else if ((*next == rf) && (*cs == cf))
    {
        printf("CONGRATS! YOU GOT %d BONUS:)\n", sum);
        mazegame[*next][*cs] = 'O';
        funcdraw();
        return 0;
    }
    else if (mazegame[*next][*cs] == ' ')
    {
        mazegame[*rs][*cs] = ' ';
        mazegame[*next][*cs] = 'O';
        *rs = *next;
        funcdraw();
    }
}
int Funclr(int *cs, int *rs, int *next)
{
    if (mazegame[*rs][*next] == 'X')
    {
        printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
        mazegame[*rs][*cs] = 'O';
        funcdraw();
        return 0;
    }
    else if (mazegame[*rs][*next] == '*')
    {
        printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
        mazegame[*rs][*cs] = 'O';
        *next = *cs;
        funcdraw();
    }
    else if (mazegame[*rs][*next] == '$')
    {
        sum++;
        printf("YOU GOT 1 $.\n");
        mazegame[*rs][*cs] = ' ';
        mazegame[*rs][*next] = 'O';
        *cs = *next;
        funcdraw();
    }
    else if ((*next == cf) && (*rs == rf))
    {
        printf("CONGRATS! YOU GOT %d BONUS:)\n", sum);
        mazegame[*rs][*next] = 'O';
        funcdraw();
        return 0;
    }
    else if (mazegame[*rs][*next] == ' ')
    {
        mazegame[*rs][*cs] = ' ';
        mazegame[*rs][*next] = 'O';
        *cs = *next;
        funcdraw();
    }
}

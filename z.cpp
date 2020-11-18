 Implements Game of Fifteen (generalized to d x d)

#define _XOPEN_SOURCE 500

#include cs50.h
#include stdio.h
#include stdlib.h
#include unistd.h

 Constants
#define DIM_MIN 3
#define DIM_MAX 9
#define COLOR 033[32m

 Board
int board[DIM_MAX][DIM_MAX];

 Dimensions
int d;

 Prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
     Ensure proper usage
    if (argc != 2)
    {
        printf(Usage fifteen dn);
        return 1;
    }

     Ensure valid dimensions
    d = atoi(argv[1]);
    if (d  DIM_MIN  d  DIM_MAX)
    {
        printf(Board must be between %i x %i and %i x %i, inclusive.n,
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

     Open log
    FILE file = fopen(log.txt, w);
    if (file == NULL)
    {
        return 3;
    }

     Greet user with instructions
    greet();

     Initialize the board
    init();

     Accept moves until game is won
    while (true)
    {
         Clear the screen
        clear();

         Draw the current state of the board
        draw();

         Log the current state of the board (for testing)
        for (int i = 0; i  d; i++)
        {
            for (int j = 0; j  d; j++)
            {
                fprintf(file, %i, board[i][j]);
                if (j  d - 1)
                {
                    fprintf(file, );
                }
            }
            fprintf(file, n);
        }
        fflush(file);

         Check for win
        if (won())
        {
            printf(ftw!n);
            break;
        }

         Prompt for move
        int tile = get_int(Tile to move );

         Quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

         Log move (for testing)
        fprintf(file, %in, tile);
        fflush(file);

         Move if possible, else report illegality
        if (!move(tile))
        {
            printf(nIllegal move.n);
            usleep(500000);
        }

         Sleep thread for animation's sake
        usleep(50000);
    }

     Close log
    fclose(file);

     Success
    return 0;
}

 Clears screen using ANSI escape sequences
void clear(void)
{
    printf(033[2J);
    printf(033[%d;%dH, 0, 0);
}


 Greets player
void greet(void)
{
    clear();
    printf(WELCOME TO GAME OF FIFTEENn);
    usleep(2000000);
}

int startingvalue = 0;
int newvalue = 0;
int row[] = { 0 };
int column[] = { 0 };
int grid[DIM_MAX][DIM_MAX] = { {0},{0} };
int thirdtolastarray = 0;
int secondtolastarray = 0;
int thirdtolast = 0;
int secondtolast = 0;
int arrayvalue = 0;
 Initializes the game's board with tiles numbered 1 through dd - 1
 (i.e., fills 2D array with values but does not actually print them)
void init(void)
{
    startingvalue = d  d - 1;
    newvalue = startingvalue;
    if ((d % 2) == 1)
    {
        for (int i = 0; i  d; i++)
        {
            for (int j = 0; j  d; j++)
            {
                grid[i][j] = newvalue;
                printf(%i, newvalue);
                newvalue--;
            }
        }
    }
    else
    {
        for (int i = 0; i  (d - 1); i++)
        {
            for (int j = 0; j  d; j++)
            {
                grid[i][j] = newvalue;
                printf(%i, newvalue);
                newvalue--;
            }
        }
        thirdtolast = 2;
        secondtolast = 1;
        for (int j = 0; j  d; j++)
        {
            grid[d][j] = newvalue;
            arrayvalue = grid[d][j];
            if (arrayvalue == thirdtolast)
            {
                printf(%i, secondtolast);
                newvalue--;
            }
            else if (arrayvalue == secondtolast)
            {
                printf(%i, thirdtolast);
                newvalue--;
            }
            else
            {
                printf(%i, newvalue);
                newvalue--;
            }
        }
    }
}

 Prints the board in its current state
void draw(void)
{
    for (int i = 0; i  d; i++)
    {
        for (int j = 0; j  d; j++)
        {
            if (grid[i][j] = 9)
            {
                printf( );
                printf(%i, grid[i][j]);
            }
            else
            {
                printf(%i, grid[i][j]);
            }
            printf( );
        }
        printf(n);
    }
}

 If tile borders empty space, moves tile and returns true, else returns false
bool move(int tile)
{
     TODO
    return false;
}

 Returns true if game is won (i.e., board is in winning configuration), else false
bool won(void)
{
     TODO
    return false;
}
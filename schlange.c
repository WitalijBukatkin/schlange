#include <curses.h>
#include <time.h>
#include <stdlib.h>

int x[100], y[100];
int bx, by;
int score=0;
char cursor='v';

void malen(int st)
{
	move(0,0);
	init_pair(1, COLOR_RED, COLOR_WHITE);
	attron(COLOR_PAIR(1));
	printw("\n"
	" ############################################################################# \n"
	" #                                                                           # \n"
	" #                                                                           # \n"
	" #                                                                           # \n"
	" #                                                                           # \n"
	" #                                                                           # \n"
	" #                                                                           # \n"
	" #                                                                           # \n"
	" #                                                                           # \n"
    " #                                                                           # \n"
    " #                                                                           # \n"
    " #                                                                           # \n"
    " #                                                                           # \n"
    " #                                                                           # \n"
    " #                                                                           # \n"
    " #                                                                           # \n"
    " #                                                                           # \n"
    " #                                                                           # \n"
    " #                                                                           # \n"
    " #                                                                           # \n"
    " #                                                                           # \n"
    " ############################################################################# \n");

    switch(st)
    {
        case 0: move(4,8);
            printw("SCHLANGE");
            move(6,7);
            printw("--------->");
            move(8,7);
            printw("Press any key to start");
            move(9,7);
            printw("Exit ESC");
            move(9, 16);
            break;
        case 1: move(5,7);
            printw("Das Ende!");
            move(7,7);
            printw("Score %d",score);
            
            break;
        case 2:
            attroff(COLOR_PAIR(1));
            printw(" Score: %d\t\t\t\t\t\t      Press ESC to exit",score);
            init_pair(2, COLOR_GREEN, COLOR_WHITE);
            attron(COLOR_PAIR(2));
            
            move(bx,by);
            printw("x");  // barrier
            
            move(x[0],y[0]);
            printw("%c",cursor);
            
            for(int i=1; x[i]!=0 ; i++)
            {
                move(x[i],y[i]);
                printw("*");
                move(23,79);
            }
            attroff(COLOR_PAIR(1));
            refresh();
    }
}

int main()
{
    
    int xy=1; /* ↓ 1, ↑ 2, → 3, ← 4 */
    int lange=1;
    bool lplus=false;
    
    x[0]=4;x[1]=3;
    y[0]=12;y[1]=12;
    
    initscr();
	noecho();
	start_color();
	keypad(stdscr, 1);
	srand(time(NULL));

	malen(0);
	switch (getch())
    {
          case 27:
			endwin();
			return 0;
          default:
            break;
	}

	halfdelay(2);
	bx = 2 + rand() % 19;	by = 2 + rand() % 75;
	while(1)
	{
        malen(2);
        switch (getch())
        {
            case KEY_DOWN:
                xy=1;
                cursor='v';
                break;
            case KEY_UP:
                xy=2;
                cursor='^';
                break;
            case KEY_RIGHT:
                xy=3;
                cursor='>';
                break;
            case KEY_LEFT:
                xy=4;
                cursor='<';
                break;
            case 27:
                endwin();
                return 0;
                break;
        }
        switch(xy)
        {
            case 1:
                for(int i=lange; i!=0 ; i--)
                {
                    x[i]=x[i-1];
                    y[i]=y[i-1];
                }
                x[0]++;
                break;
            case 2:
                for(int i=lange; i!=0 ; i--)
                {
                    x[i]=x[i-1];
                    y[i]=y[i-1];
                }
                x[0]--;
                break;
            case 3:
                for(int i=lange; i!=0 ; i--)
                {
                    x[i]=x[i-1];
                    y[i]=y[i-1];
                }
                y[0]++;
                break;
		case 4:
                for(int i=lange; i!=0 ; i--)
                {
                    x[i]=x[i-1];
                    y[i]=y[i-1];
                }
                y[0]--;
	  }
	  for(int i=0; x[i]!=0 ; i++)
	  {
          if(x[i]==22 || y[i]==77 || x[i]==1 || y[i]==1)
          {
              halfdelay(100);
              malen(1);
              getch();
              endwin();
              return 0;
          }
		  if(x[i]==bx && y[i]==by)
		  {
            bx = 2 + rand() % 20;	by = 2 + rand() % 75;
			score++;
			if(lplus==false)
                lplus=true;
			else
            {
                lplus=false;
                lange++;
            }
		  }
       }
	}
}

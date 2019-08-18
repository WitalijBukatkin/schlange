#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int x[]={4 ,3 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int y[]={12,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int bx, by;
int xy=1; /* ↓ 1, ↑ 2, → 3, ← 4 */
int lange=1;
int langeplus=0;
int score=0;
int start=0;
char cursor='v';

void malen()
{
	move(0,0);
	init_pair(1, COLOR_RED, COLOR_WHITE);
	attron(COLOR_PAIR(1));
	printw("\n"
	" ######################## \n"
	" #                      # \n"
	" #                      # \n"
	" #                      # \n"
	" #                      # \n"
	" #                      # \n"
	" #                      # \n"
	" #                      # \n"
	" #                      # \n"
	" #                      # \n"
    " ######################## \n");

	if(start==0)
	{
		move(4,8);
		printw("SCHLANGE");
		move(6,7);
		printw("--------->");
		move(8,7);
		printw("Start KEY_DOWN");
        move(9,7);
		printw("Exit ESC");
		move(9, 16);
	}
	else
	{
	if(start==-1)
	{
		move(13,1);
		printw("\n");
		move(5,7);
		printw("Das Ende!");
		move(7,7);
		printw("Score %d ",score);
		
	}
	else
	{
	  attroff(COLOR_PAIR(1));
	  printw("\n"
	  " Score: %d               ",score);
	  init_pair(2, COLOR_GREEN, COLOR_WHITE);
	  attron(COLOR_PAIR(2));
	
	  move(bx,by);
	  printw("x");  // barrier
	  move(13,10);
	
	  move(x[0],y[0]);
	  printw("%c",cursor);
	  move(13,10);

	  for(int i=1; x[i]!=0 ; i++)
	  {
	    move(x[i],y[i]);
	    printw("*");
	    move(13,10);
	  }
	  attroff(COLOR_PAIR(1));
      refresh();
	}
	}
}

int main()
{
    initscr();
	noecho();
	start_color();
	keypad(stdscr, true);
	srand(time(NULL));

	malen();
	switch (getch())
    {
		  case KEY_DOWN:
			  start=1;
			  break;
		  case 27:
			endwin();
			return 0;
	}

	halfdelay(2);
	bx = 2 + rand() % 9;	by = 2 + rand() % 22;
	malen();
	while(1)
	{
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
          break;
	  }
	  malen();
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
	  for(int i=0; x[i]!=0 ; i++)
	  {
		if(x[i]==bx && y[i]==by)
		{
			bx = 2 + rand() % 9;	by = 2 + rand() % 22;
			score++;
			if(langeplus==0 || lange==40)
			{langeplus=1;}
			else
			{langeplus=0; lange++;}
		}
		if(x[i]==11 || y[i]==24 || x[i]==1 || y[i]==1)
		{
			halfdelay(100);
			start=-1;
			malen();
			getch();			
			endwin();
			return 0;
		}
	  }
	}
    endwin();
}


#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

void plotLine(int x0, int y0, int x1, int y1)
  {  
		int dx = abs(x1 - x0);
    int sx = (x0 < x1) ? 1 : -1 ;
    int dy = -abs(y1 - y0);
   	int  sy = (y0 < y1) ? 1 : -1;
    int error = dx + dy;
    while(1)
      { 
		 //  plot(x0, y0);
		 printf(" < x %d y %d >\n", x0, y0);
        if( x0 == x1 && y0 == y1)
			break;
        int e2 = 2 * error;
        if (e2 >= dy)
           { 
			   if(x0 == x1)
			   		break;
            error = error + dy;
            x0 = x0 + sx;
			}
       
        if (e2 <= dx)
           {
			    if (y0 == y1)
					break;
            	error = error + dx;
            	y0 = y0 + sy;
			}
		}

  }
  int main()
  {
	  plotLine(480,110,500,50);
  }
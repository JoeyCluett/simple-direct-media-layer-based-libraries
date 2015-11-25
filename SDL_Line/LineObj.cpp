//LineObj implementation file
//contains definitions of the LineObj
#include "LineObj.h"
#include <SDL/SDL.h>

Line::Line(Uint32 color, int startx, int starty, int endx, int endy){
    x1 = startx;
    y1 = starty;
    x2 = endx;
    y2 = endy;
}

Line::Line(void){
	;
}

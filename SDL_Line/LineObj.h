//LineObj header file
#ifndef LINEOBJ_1
#define LINEOBJ_1

class Line{
public:
    int x1;
    int y1;
    int x2;
    int y2;
    Uint32 color;
    Line(Uint32 color, int startx = 0, int starty = 0, int endx = 0, int endy = 0);
    Line(void);
};

#endif // LINEOBJ_1

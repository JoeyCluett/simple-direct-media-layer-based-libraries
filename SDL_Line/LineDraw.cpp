#include <math.h>
#include <SDL/SDL.h>
#include "LineDraw.h"

void LineDraw::draw(Line loon, SDL_Surface* surface, int lineWidth){
    Uint32 color =  SDL_MapRGB(surface->format, 255, 0, 0);
    Uint32 colors = SDL_MapRGB(surface->format, 255, 255, 255);

    SDL_Rect pixel;
    pixel.x = 0;
    pixel.y = 0;
    pixel.w = lineWidth;
    pixel.h = lineWidth;

    //float delX = SortDelta(loon.x2, loon.x1);
    float delY = SortDelta(loon.y2, loon.y1);
    int x1 = loon.x1; int x2 = loon.x2;
    int y1 = loon.y1; int y2 = loon.y2;
    //float delZ = delY / delX;
    float BEGIN;
    long double workVar;
    long double ADDBLOCK;

    if(delY > 0) {
        // x = f(y)
        for(BEGIN = ReturnLow(loon.y1, loon.y2); BEGIN <= ReturnHigh(loon.y1, loon.y2); BEGIN+= 0.05){
            ADDBLOCK = x2 - x1;
            ADDBLOCK /= (y2 - y1);
            ADDBLOCK *= y1;
            ADDBLOCK *= -1;
            workVar =  x2 - x1;
            workVar /= (y2 - y1);
            workVar *= BEGIN;
            workVar += x1;
            workVar += ADDBLOCK;
            pixel.y = BEGIN;
            pixel.x = workVar;
            if(lineWidth == 80)
                SDL_FillRect(surface, &pixel, color);
            if(lineWidth != 80)
                SDL_FillRect(surface, &pixel, loon.color);

        }
    } else {
        for(BEGIN = ReturnLow(loon.x1, loon.x2); BEGIN <= ReturnHigh(loon.x1, loon.x2); BEGIN++){
            pixel.y = loon.y1;
            pixel.x = BEGIN;
            if(lineWidth == 80)
                SDL_FillRect(surface, &pixel, color);
            if(lineWidth != 80)
                SDL_FillRect(surface, &pixel, loon.color);
        }
    }
    //SDL_Flip(surface);
}

int LineDraw::SortDelta(int x2, int x1){
    if(x2 > x1){
        return x2 - x1;
    } else if(x1 > x2){
        return x1 - x2;
    } else {
        return 0;
    }
}

int LineDraw::ReturnHigh(int i, int j){
    if(i == j){
        return i;
    } else if(i < j){
        return j;
    } else {
        return i;
    }
}

int LineDraw::ReturnLow(int i, int j){
    if(i == j){
        return j;
    } else if(i < j){
        return i;
    } else {
        return j;
    }
}

/*
 * tetris.cxx
 * 
 * Copyright 2021 César Chaussinand <cesar@charly>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <stdlib.h>
#include <SDL.h>
#include <cmath>
#include <vector>
#include <sstream>

int mar = 1;
int randmix = 0;

int iNb = 0;
int lNb = 0;
int jNb = 0;
int tNb = 0;
int oNb = 0;
int sNb = 0;
int zNb = 0;

class Framework{
public:
    // Contructor which initialize the parameters.
    Framework(int height_, int width_): height(height_), width(width_){
        SDL_Init(SDL_INIT_VIDEO);       // Initializing SDL as Video
        SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);      // setting draw color
        SDL_RenderClear(renderer);      // Clear the newly created window
        SDL_RenderPresent(renderer);    // Reflects the changes done in the
                                        //  window.
    }

    // Destructor
    ~Framework(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    
    void fill_shape(char shape, int rotation, int posX, int posY, int level, int unit){

/*=========================================================
		trace les pièces au dernier niveau
=========================================================*/

		if (level==0){
			if(shape=='o'){
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
				SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+2)*unit,posY*unit+mar);
				SDL_RenderDrawLine(renderer,(posX+2)*unit,posY*unit+mar,(posX+2)*unit,(posY+2)*unit);
				SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+2)*unit,posX*unit+mar,(posY+2)*unit);
				SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+2)*unit,posX*unit+mar,posY*unit+mar);
				SDL_RenderPresent(renderer);
				oNb = oNb + 1;				
			}
			
			else if(shape=='i'){
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
				if (rotation==0){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+1)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,posY*unit+mar,(posX+1)*unit,(posY+4)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+4)*unit,(posX)*unit+mar,(posY+4)*unit);
					SDL_RenderDrawLine(renderer,(posX)*unit+mar,(posY+4)*unit,(posX)*unit+mar,(posY)*unit+mar);
				}else if (rotation==1){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+4)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+4)*unit,posY*unit+mar,(posX+4)*unit,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+4)*unit,(posY+1)*unit,(posX)*unit+mar,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX)*unit+mar,(posY+1)*unit,(posX)*unit+mar,(posY)*unit+mar);
				}
				SDL_RenderPresent(renderer);
				iNb = iNb + 1;
			}
			
			else if(shape=='l'){
				SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
				if (rotation==0){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+1)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,posY*unit+mar,(posX+1)*unit,(posY+2)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+2)*unit+mar,(posX+2)*unit,(posY+2)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+2)*unit+mar,(posX+2)*unit,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+3)*unit,posX*unit+mar,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+3)*unit,posX*unit+mar,posY*unit+mar);
				}else if(rotation==1){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+3)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+3)*unit,posY*unit+mar,(posX+3)*unit,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+3)*unit,(posY+1)*unit,(posX+1)*unit,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+1)*unit,(posX+1)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+2)*unit,posX*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+2)*unit,posX*unit+mar,posY*unit+mar);
				}else if(rotation==2){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+2)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY)*unit+mar,(posX+2)*unit,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+3)*unit,(posX+1)*unit+mar,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit+mar,(posY+3)*unit,(posX+1)*unit+mar,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit+mar,(posY+1)*unit,posX*unit+mar,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+1)*unit,posX*unit+mar,posY*unit+mar);
				}else if(rotation==3){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+1)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY)*unit+mar,(posX+1)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+2)*unit,(posX-2)*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX-2)*unit+mar,(posY+2)*unit,(posX-2)*unit+mar,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX-2)*unit+mar,(posY+1)*unit+mar,(posX)*unit+mar,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+1)*unit+mar,posX*unit+mar,posY*unit+mar);
				}
				SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
				if (rotation==-1){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+1)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,posY*unit+mar,(posX+1)*unit,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+3)*unit,(posX-1)*unit+mar,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX-1)*unit+mar,(posY+3)*unit,(posX-1)*unit+mar,(posY+2)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX-1)*unit+mar,(posY+2)*unit+mar,posX*unit+mar,(posY+2)*unit+mar);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+2)*unit+mar,posX*unit+mar,posY*unit+mar);
				}else if(rotation==-2){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+3)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+3)*unit,posY*unit+mar,(posX+3)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+3)*unit,(posY+2)*unit,(posX+2)*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+2)*unit+mar,(posY+2)*unit,(posX+2)*unit+mar,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+2)*unit+mar,(posY+1)*unit,posX*unit+mar,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+1)*unit,posX*unit+mar,posY*unit+mar);
				}else if(rotation==-3){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+2)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY)*unit+mar,(posX+2)*unit,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+1)*unit,(posX+1)*unit,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+1)*unit,(posX+1)*unit,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+3)*unit,posX*unit+mar,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+3)*unit,posX*unit+mar,posY*unit+mar);
				}else if(rotation==-4){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+1)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,posY*unit+mar,(posX+1)*unit,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+1)*unit+mar,(posX+3)*unit,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+3)*unit,(posY+1)*unit+mar,(posX+3)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+3)*unit,(posY+2)*unit,posX*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+2)*unit,posX*unit+mar,posY*unit+mar);
				}
				SDL_RenderPresent(renderer);
				if(rotation<0){jNb = jNb + 1;}else{lNb = lNb + 1;}
			}
			
			else if(shape=='t'){
				SDL_SetRenderDrawColor(renderer, 255, 0, 255, 0);
				if (rotation==0){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+3)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+3)*unit,posY*unit+mar,(posX+3)*unit,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+3)*unit,(posY+1)*unit,(posX+2)*unit,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+1)*unit,(posX+2)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+2)*unit,(posX+1)*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit+mar,(posY+2)*unit,(posX+1)*unit+mar,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit+mar,(posY+1)*unit,posX*unit+mar,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+1)*unit,posX*unit+mar,posY*unit+mar);
				}else if (rotation==1){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+1)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,posY*unit+mar,(posX+1)*unit,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+3)*unit,posX*unit+mar,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX)*unit+mar,(posY+3)*unit,(posX)*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX)*unit+mar,(posY+2)*unit,(posX-1)*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX-1)*unit+mar,(posY+2)*unit,(posX-1)*unit+mar,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX-1)*unit+mar,(posY+1)*unit+mar,posX*unit+mar,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+1)*unit+mar,posX*unit+mar,posY*unit+mar);
				}else if (rotation==2){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+1)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,posY*unit+mar,(posX+1)*unit,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+1)*unit+mar,(posX+2)*unit,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+1)*unit+mar,(posX+2)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+2)*unit,(posX-1)*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX-1)*unit+mar,(posY+2)*unit,(posX-1)*unit+mar,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX-1)*unit+mar,(posY+1)*unit+mar,posX*unit+mar,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+1)*unit+mar,posX*unit+mar,posY*unit+mar);
				}else if (rotation==3){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+1)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,posY*unit+mar,(posX+1)*unit,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+1)*unit+mar,(posX+2)*unit,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+1)*unit+mar,(posX+2)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+2)*unit,(posX+1)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+2)*unit,(posX+1)*unit,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+3)*unit,posX*unit+mar,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+3)*unit,posX*unit+mar,posY*unit+mar);
				}
				SDL_RenderPresent(renderer);
				tNb = tNb + 1;
			}
			
			else if (shape=='s'){
				SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
				if(rotation==0){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+2)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,posY*unit+mar,(posX+2)*unit,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+1)*unit,(posX+1)*unit,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+1)*unit,(posX+1)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+2)*unit,(posX-1)*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX-1)*unit+mar,(posY+2)*unit,(posX-1)*unit+mar,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX-1)*unit+mar,(posY+1)*unit+mar,posX*unit+mar,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+1)*unit+mar,posX*unit+mar,posY*unit+mar);
				}else if (rotation==1){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+1)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,posY*unit+mar,(posX+1)*unit,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+1)*unit+mar,(posX+2)*unit,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+1)*unit+mar,(posX+2)*unit,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+3)*unit,(posX+1)*unit+mar,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit+mar,(posY+3)*unit,(posX+1)*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit+mar,(posY+2)*unit,posX*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+2)*unit,posX*unit+mar,posY*unit+mar);
				}
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
				if (rotation==-1){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+2)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,posY*unit+mar,(posX+2)*unit,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+2)*unit,(posY+1)*unit+mar,(posX+3)*unit,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+3)*unit,(posY+1)*unit+mar,(posX+3)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+3)*unit,(posY+2)*unit,(posX+1)*unit+mar,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit+mar,(posY+2)*unit,(posX+1)*unit+mar,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit+mar,(posY+1)*unit,posX*unit+mar,(posY+1)*unit);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+1)*unit,posX*unit+mar,posY*unit+mar);
				}else if (rotation==-2){
					SDL_RenderDrawLine(renderer,posX*unit+mar,posY*unit+mar,(posX+1)*unit,posY*unit+mar);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,posY*unit+mar,(posX+1)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX+1)*unit,(posY+2)*unit,(posX)*unit,(posY+2)*unit);
					SDL_RenderDrawLine(renderer,(posX)*unit,(posY+2)*unit,(posX)*unit,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX)*unit,(posY+3)*unit,(posX-1)*unit+mar,(posY+3)*unit);
					SDL_RenderDrawLine(renderer,(posX-1)*unit+mar,(posY+3)*unit,(posX-1)*unit+mar,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,(posX-1)*unit+mar,(posY+1)*unit+mar,posX*unit+mar,(posY+1)*unit+mar);
					SDL_RenderDrawLine(renderer,posX*unit+mar,(posY+1)*unit+mar,posX*unit+mar,posY*unit+mar);
				}
				SDL_RenderPresent(renderer);
				if(rotation<0){zNb = zNb + 1;}else{sNb = sNb + 1;}
			}
		}
		
/*==============================================================================================================
		pour chaque type de pièce, renvoi les fonctions correspondantes aux pièces la composant
==============================================================================================================*/		

		else{
			if(shape=='o'){
				//ici, tirer au sort les différentes décompositions possibles
				srand (time(NULL)+randmix);
				randmix = randmix + 1;
				
				int r;
				if (level>1){r = rand()%6;}else{r = rand()%4;}
				
				if(r==0){
					fill_shape('t',0,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('t',1,3+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('l',0,0+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('s',-1,1+posX*2,2+posY*2,level-1,unit/2);
				}else if(r==1){
					fill_shape('t',1,3+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('t',2,2+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('l',1,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('s',-2,1+posX*2,1+posY*2,level-1,unit/2);
				}else if(r==2){
					fill_shape('t',0,1+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('t',3,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('l',-1,3+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('s',0,1+posX*2,2+posY*2,level-1,unit/2);
				}else if(r==3){
					fill_shape('t',1,3+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('t',0,1+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('l',-4,0+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('s',1,0+posX*2,0+posY*2,level-1,unit/2);
				}else if(r==4){
					fill_shape('o',0,1+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',0,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',0,3+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('o',0,1+posX*2,2+posY*2,level-1,unit/2);
				}else if(r==5){
					fill_shape('o',0,0+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('i',1,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',1,0+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('o',0,2+posX*2,2+posY*2,level-1,unit/2);
				}
			}
			else if(shape=='l'){
				if(rotation==0){
					fill_shape('o',0,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('l',0,1+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('l',3,3+posX*2,4+posY*2,level-1,unit/2);
					fill_shape('i',0,0+posX*2,2+posY*2,level-1,unit/2);
				}
				else if(rotation==1){
					fill_shape('o',0,4+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',1,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('l',1,1+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',0,0+posX*2,1+posY*2,level-1,unit/2);
				}
				else if(rotation==2){
					fill_shape('o',0,2+posX*2,4+posY*2,level-1,unit/2);
					fill_shape('i',0,3+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('l',2,1+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',1,0+posX*2,0+posY*2,level-1,unit/2);
				}
				else if(rotation==3){
					fill_shape('o',0,-4+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('i',1,-2+posX*2,3+posY*2,level-1,unit/2);
					fill_shape('l',3,0+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',2,0+posX*2,0+posY*2,level-1,unit/2);
				}
				else if (rotation==-1){
					fill_shape('o',0,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',0,1+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('l',-1,0+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('l',-4,-2+posX*2,4+posY*2,level-1,unit/2);
				}
				else if (rotation==-2){
					fill_shape('o',0,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',1,2+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('l',-2,2+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',-1,5+posX*2,1+posY*2,level-1,unit/2);
				}
				else if (rotation==-3){
					fill_shape('o',0,0+posX*2,4+posY*2,level-1,unit/2);
					fill_shape('i',0,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('l',-3,1+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',-2,1+posX*2,0+posY*2,level-1,unit/2);
				}
				else if (rotation==-4){
					fill_shape('o',0,4+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('i',1,0+posX*2,3+posY*2,level-1,unit/2);
					fill_shape('l',-4,1+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',-3,0+posX*2,0+posY*2,level-1,unit/2);
				}
			}
			else if(shape=='i'){
				if(rotation==0){
/*					srand (time(NULL)+randmix);
					randmix = randmix + 1;
					int r = rand()%2;
				
					if(r==0){*/
						fill_shape('o',0,0+posX*2,0+posY*2,level-1,unit/2);
						fill_shape('i',0,1+posX*2,3+posY*2,level-1,unit/2);
						fill_shape('l',0,0+posX*2,5+posY*2,level-1,unit/2);
						fill_shape('l',-3,0+posX*2,2+posY*2,level-1,unit/2);
					/*}else{
						fill_shape('o',0,0+posX*2,0+posY*2,level-1,unit/2);
						fill_shape('i',0,0+posX*2,2+posY*2,level-1,unit/2);
						fill_shape('i',0,1+posX*2,2+posY*2,level-1,unit/2);
						fill_shape('o',0,0+posX*2,6+posY*2,level-1,unit/2);
					}*/
				}
				else if(rotation==1){
					fill_shape('o',0,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',1,3+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',1,2+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('l',-2,5+posX*2,0+posY*2,level-1,unit/2);
				}
			}else if(shape=='t'){
				if(rotation==0){
					fill_shape('o',0,2+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('i',1,1+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',1,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('l',-2,3+posX*2,0+posY*2,level-1,unit/2);
				}else if(rotation==1){
					fill_shape('o',0,-2+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('i',0,0+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',2,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('l',-1,1+posX*2,3+posY*2,level-1,unit/2);
				}else if(rotation==2){
					fill_shape('o',0,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',1,-1+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('l',3,3+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('l',-4,-2+posX*2,2+posY*2,level-1,unit/2);
				}else if(rotation==3){
					fill_shape('o',0,2+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('i',0,1+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',0,0+posX*2,3+posY*2,level-1,unit/2);
					fill_shape('l',-3,0+posX*2,0+posY*2,level-1,unit/2);
				}
			}else if(shape=='s'){
				if(rotation==0){
					fill_shape('o',0,2+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',1,-2+posX*2,3+posY*2,level-1,unit/2);
					fill_shape('l',3,0+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',2,0+posX*2,0+posY*2,level-1,unit/2);
				}else if(rotation==1){
					fill_shape('o',0,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',0,3+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('l',2,1+posX*2,3+posY*2,level-1,unit/2);
					fill_shape('l',1,0+posX*2,2+posY*2,level-1,unit/2);
				}else if(rotation==-1){
					fill_shape('o',0,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',1,2+posX*2,3+posY*2,level-1,unit/2);
					fill_shape('l',-4,3+posX*2,1+posY*2,level-1,unit/2);
					fill_shape('l',-3,2+posX*2,0+posY*2,level-1,unit/2);
				}else if(rotation==-2){
					fill_shape('o',0,0+posX*2,0+posY*2,level-1,unit/2);
					fill_shape('i',0,-2+posX*2,2+posY*2,level-1,unit/2);
					fill_shape('l',-3,-1+posX*2,3+posY*2,level-1,unit/2);
					fill_shape('l',-2,-1+posX*2,2+posY*2,level-1,unit/2);
				}
			}
		}
    	}
}
    
private:
    int height;     // Height of the window
    int width;      // Width of the window
    SDL_Renderer *renderer = NULL;      // Pointer for the renderer
    SDL_Window *window = NULL;      // Pointer for the window
};

int main(int argc, char * argv[]){

	int windowSize = 300;
	int lev = 0;
	
	if(argc==1){
		std::cout << "framwork [level] [window size] [margin]" << '\n';
	}
	if(argc>1){
		std::istringstream arg1(argv[1]);
		if (!(arg1 >> lev)) {
			std::cerr << "Invalid number: " << argv[1] << '\n';
		} else if (!arg1.eof()) {
			std::cerr << "Trailing characters after number: " << argv[1] << '\n';
		}
	}
	if(argc>2){
		std::istringstream arg2(argv[2]);
		if (!(arg2 >> windowSize)) {
			std::cerr << "Invalid number: " << argv[2] << '\n';
		} else if (!arg2.eof()) {
			std::cerr << "Trailing characters after number: " << argv[2] << '\n';
		}
	}
	if(argc>3){
		std::istringstream arg3(argv[3]);
		if (!(arg3 >> mar)) {
			std::cerr << "Invalid number: " << argv[3] << '\n';
		} else if (!arg3.eof()) {
			std::cerr << "Trailing characters after number: " << argv[3] << '\n';
		}
	}

    Framework fw(windowSize, windowSize);
	
 	fw.fill_shape('o',0,0,0,lev,(windowSize/2)-1);
 	
    SDL_Event event;
    
    std::cout << "Nombre de i : " << iNb << "\n";
    std::cout << "Nombre de o : " << oNb << "\n";
    std::cout << "Nombre de l : " << lNb << "\n";
    std::cout << "Nombre de j : " << jNb << "\n";
    std::cout << "Nombre de t : " << tNb << "\n";
    std::cout << "Nombre de s : " << sNb << "\n";
    std::cout << "Nombre de z : " << zNb << "\n";

    while(!(event.type == SDL_QUIT)){
        SDL_Delay(10);
        SDL_PollEvent(&event);
    }  
  
    return 1;
}

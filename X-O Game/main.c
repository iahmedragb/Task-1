#include "TicTac.h"

/*
 ============================================================================
 Name        : X-O Game
 Author      : Ahmed Ragab
 ========================================================
 *Implementation of a X-O game
 *User is allowed to play vs. computer (mode 1)
 *User is allowed to play vs. a player (mode 2)
 ============================================================================
*/
void main(){
        while(1){
                startgame();

        switch (gamemode){

        case '1' :
                    mode1();
                    game1();
                    break;

        case '2' :
                    mode2();
                    game2();
                    break;

        case '3' :
                    game3();
        }
        }
}

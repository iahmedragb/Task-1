#include "TicTac.h"

int gamescore=0;                 //initializing gamescore to 0
int turn=2,t=1;                 //initializing turn and time values to swap turns after ever turn

//Board slots
char bslot[]={'0','1','2','3','4','5','6','7','8','9'};     //Board slots marked from 1 to 9 starting from index [1] to [9]

//Main Menu screen where user choose a 1 player or 2 players game.
int startgame(){
                //start menu layout
                menu();
                //user input for game mode
                printf("\n Please Make Your Choice ( 1 or 2 or 3) : ");
                scanf(" %c",&gamemode);
                //check if the entry is a valid choice
        while (gamemode != '1' && gamemode != '2' && gamemode != '3'){

                menu();
                printf("                                      ==========   Invalid Value   ==========\n");
                printf(" Please Make Your Choice ( 1 or 2 or 3) : ");
                scanf(" %c",&gamemode);
                }
                return gamemode;
}
void menu(){
                //Main Menu Layout

                system("cls");

                if(gamescore==0){
                printf("\n\n                                      ==========   Main Menu   ==========\n\n");
                }else {
                printf("\n\n                                      ==========   Last Game   ==========\n\n");
                }
                board();

                printf("                                      ==========   Gamed Mode   ==========\n\n");
                printf("                                      1- Play Vs. Computer \n\n");
                printf("                                      2- Play Vs. A Friend \n\n");
                printf("                                      3- Quit \n\n");
}
void board(){
                //Board Layout slots
                printf("                                         _________ _________ _________\n");
                printf("                                        |         |         |         |\n");
                printf("                                        |    %c    |    %c    |    %c    |\n",bslot[1],bslot[2],bslot[3]);
                printf("                                        |_________|_________|_________|\n");
                printf("                                        |         |         |         |\n");
                printf("                                        |    %c    |    %c    |    %c    |\n",bslot[4],bslot[5],bslot[6]);
                printf("                                        |_________|_________|_________|\n");
                printf("                                        |         |         |         |\n");
                printf("                                        |    %c    |    %c    |    %c    |\n",bslot[7],bslot[8],bslot[9]);
                printf("                                        |_________|_________|_________|\n\n");
}
void mode1(){

                    menu();
                    //Player 1 choose his turn against computer
                    turnMode1();

                    if(pch1=='1'){
                            turn=2;
                            t=1;
                    }else if(pch1=='2'){
                            turn=1;
                            t=-1;
                    }
}
void turnMode1(){

                    //Player choose his turn
                    printf("\n\n                                        1- Play First       2- Play Second\n\n");
                    printf("Please Make Your Choice ( 1 or 2 ) : ");

                    scanf(" %c",&pch1);

                    while (pch1 != '1' && pch1 != '2'){

                    menu();
                    printf("                                      ==========   Invalid Value   ==========\n");
                    printf("\n                                        1- Play First       2- Play Second\n\n");
                    printf(" Please Make Your Choice ( 1 or 2 ) : ");

                    scanf(" %c",&pch1);
                    }

}
void game1(){
            newgame();                                //Clear the Board for a new game
            gamescore=0;                              //Reset the score to 0 for a new game
            for(int j=0 ; j<9 ; j++){                     //9 turns for 1-9 slots
            t=t*-1;
            layout1();
            turn=turn+t;                              //Interchange turns
            if(turn==1){
                    printf("\n\n                                        Your Turn: ");

                   playerMarkMode1();

                    slot();
                    }
            if(turn==2){

                    i= i==9 ? (i-2):(i+1);

            markpcsv();                 //Computer is stopping player from winning
            markpcwin();                //Computer prefer to win if it could
            markComputerCheck();        //Computer checks if the slot is free

            }
            mark();                     //Mark a slot with X or O according to the player turn

            gamecheck();                //Check for the winners
            }
            draw();                     //Games is a draw after 9 turns without a winner
}
void newgame(){
                    //Clear the board
                    for(int n=0; n<10 ; n++){

                    bslot[n]=' ';
                    }
                    board();
}
void layout1(){
                    //Game screen
                    system("cls");

                    printf("\n\n                                      ==========   Good Luck   ==========\n\n");

                    board();
}
void playerMarkMode1(){
                    char ichar;

                 scanf(" %c",&ichar);

            while (ichar=='0' || !isdigit(ichar)){
                    layout1();
                    printf("                                      ==========   Invalid Value   ==========\n");
                    printf("\n                                        Your Turn: ");

                    scanf(" %c",&ichar);
                    }
                    i=(int)ichar-48;
}
void slot(){
            char ichar;

            while (bslot[i] !=' '){

            system("cls");
            if(gamemode=='1'){
            layout1();
            printf("                                      ==========  Already Marked   ==========\n");
            printf("\n                               Please Mark A Different Square: ");

            scanf(" %c",&ichar);

            while (ichar=='0' || !isdigit(ichar)){
            layout1();
            printf("                                      ==========   Invalid Value   ==========\n");
            printf("\n                                        Your Turn: ");
            scanf(" %c",&ichar);
            }
            i=(int)ichar-48;
            }else if(gamemode=='2'){
            layout2();
            printf("                                      ==========  Already Marked   ==========\n");
            printf("\n                               Player %d Please Mark A Different Square: ",turn);

            scanf(" %c",&ichar);

            while (ichar=='0' || !isdigit(ichar)){
            layout1();
            printf("                                      ==========   Invalid Value   ==========\n");
            printf("\n                                        Your Turn: ");
            scanf(" %c",&ichar);
            }
            i=(int)ichar-48;
            }
}}
void markpcsv(){
                       int h;
                                    //win combination     123   456   789   /  147     258     369     /    159       357
                       for(h=1;h<8;h+=3){
                            if(bslot[h]==' ' && bslot[h+1]=='X' && bslot[h+2]=='X'){
                            i=h;
                            }
                            else if(bslot[h]=='X' && bslot[h+1]==' ' && bslot[h+2]=='X'){
                            i=h+1;
                            }
                            else if(bslot[h]=='X' && bslot[h+1]=='X' && bslot[h+2]==' '){
                            i=h+2;
                        }}
                        for(h=1;h<4;h++){
                            if(bslot[h]==' ' && bslot[h+3]=='X' && bslot[h+6]=='X'){
                            i=h;
                            }else if(bslot[h]=='X' && bslot[h+3]==' ' && bslot[h+6]=='X'){
                            i=h+3;
                            }
                            else if(bslot[h]=='X' && bslot[h+3]=='X' && bslot[h+6]==' '){
                            i=h+6;
                            }}
                        for(h=2;h<5;h+=2){
                            if(bslot[5-h]==' ' && bslot[5]=='X' && bslot[5+h]=='X'){
                            i=5-h;
                            }else if(bslot[5-h]=='X' && bslot[5]==' ' && bslot[5+h]=='X'){
                            i=5;
                            }else if(bslot[5-h]=='X' && bslot[5]=='X' && bslot[5+h]==' '){
                            i=5+h;
                            }}
}
void markpcwin(){
                          int h;
                                    //win combination     123   456   789   /  147     258     369     /    159       357
                       for(h=1;h<8;h+=3){
                            if(bslot[h]==' ' && bslot[h+1]=='O' && bslot[h+2]=='O'){
                            i=h;
                            }
                            else if(bslot[h]=='O' && bslot[h+1]==' ' && bslot[h+2]=='O'){
                            i=h+1;
                            }
                            else if(bslot[h]=='O' && bslot[h+1]=='O' && bslot[h+2]==' '){
                            i=h+2;
                        }}
                        for(h=1;h<4;h++){
                            if(bslot[h]==' ' && bslot[h+3]=='O' && bslot[h+6]=='O'){
                            i=h;
                            }else if(bslot[h]=='O' && bslot[h+3]==' ' && bslot[h+6]=='O'){
                            i=h+3;
                            }
                            else if(bslot[h]=='O' && bslot[h+3]=='O' && bslot[h+6]==' '){
                            i=h+6;
                            }}
                        for(h=2;h<5;h+=2){
                            if(bslot[5-h]==' ' && bslot[5]=='O' && bslot[5+h]=='O'){
                            i=5-h;
                            }else if(bslot[5-h]=='O' && bslot[5]==' ' && bslot[5+h]=='O'){
                            i=5;
                            }else if(bslot[5-h]=='O' && bslot[5]=='O' && bslot[5+h]==' '){
                            i=5+h;
                            }}
}
void markComputerCheck(){

            if(bslot[i] !=' '){                 //Checks if already marked slot for computer
                    i=1;
            while(bslot[i] !=' '){              //Change the marker to an unmarked slot
                i++;
            }
            }
}
void mark(){
            if(turn==1){
            bslot[i]='X';
            }else if(turn==2){
            bslot[i]='O';
            }
}
void gamecheck(){
                        int h;
        //win combination     123   456   789   /  147     258     369     /    159       357
                       for(h=1;h<8;h+=3){
                            if(bslot[h]=='X' && bslot[h+1]=='X' && bslot[h+2]=='X'){
                            gamescore=1;
                        }}
                        for(h=1;h<4;h++){
                            if(bslot[h]=='X' && bslot[h+3]=='X' && bslot[h+6]=='X'){
                            gamescore=1;
                        }}
                        for(h=2;h<5;h+=2){
                            if(bslot[5-h]=='X' && bslot[5]=='X' && bslot[5+h]=='X'){
                            gamescore=1;
                        }}

                        for(h=1;h<8;h+=3){
                            if(bslot[h]=='O' && bslot[h+1]=='O' && bslot[h+2]=='O'){
                            gamescore=2;
                        }}
                        for(h=1;h<4;h++){
                            if(bslot[h]=='O' && bslot[h+3]=='O' && bslot[h+6]=='O'){
                            gamescore=2;
                        }}
                        for(h=2;h<5;h+=2){
                            if(bslot[5-h]=='O' && bslot[5]=='O' && bslot[5+h]=='O'){
                            gamescore=2;
                        }}

                            if (gamescore !=0){
                                    endgame();
}}
void endgame(){
                   char ter='0';
                    if(gamescore==1){

                    screen1();
                    printf("\n\n                                     1-Yes    or 2-No : ");

                    scanf(" %c",&ter);

                    while (ter != '1' && ter != '2'){

                    screen1();
                    printf("                                      ==========   Invalid Value   ==========");
                    printf("\n\n                                     1-Yes    or 2-No : ");

                    scanf(" %c",&ter);
                    }

                    if(ter=='1'){
                        return;
                    }
                        game3();
                        exit(0);
                    }else if(gamescore==2){

                    screen2();
                    printf("\n\n                                     1-Yes    or 2-No : ");

                    scanf(" %c",&ter);

                    while (ter != '1' && ter != '2'){

                    screen2();
                    printf("                                      ==========   Invalid Value   ==========");
                    printf("\n\n                                     1-Yes    or 2-No : ");

                    scanf(" %c",&ter);
                    }

                    if(ter=='1'){
                        return;
                    }
                        game3();
                        exit(0);
                    }}
void screen1(){
                    system("cls");
                    printf("\n\n                                      ==========   Well Done !   ==========\n\n");
                    if(gamemode=='1'){
                    printf("\n                          Congratulations You Win\n");
                   }else if(gamemode=='2'){
                    printf("\n                          Congratulations %s\n",p1);
                    printf("\n                          Player 1 Won\n");
                   }
                    board();

                    printf("\n\n                                      ==========   Play Again ?   ==========\n\n");
}
void screen2(){
                    system("cls");
                   if(gamemode=='1'){
                    printf("\n\n                                      ==========   Game is Over    ==========\n\n");
                    printf("\n\n                                      ==========      You lose     ==========\n\n");
                   }else if(gamemode=='2'){
                    printf("\n\n                                      ==========   Well Done !   ==========\n\n");
                   printf("\n                          Congratulations %s\n",p2);
                   printf("\n                          Player 2 Won\n");
                   }
                    board();

                    printf("\n\n                                      ==========   Play Again ?   ==========\n\n");
}
void game3(){
            system("cls");

            printf("\n\n                                      ==========   See You Later   ==========\n\n");
}
void draw(){

                    char ter='0';
                    screen3();
                    printf("\n\n                                     1-Yes    or 2-No : ");
                    scanf(" %c",&ter);

                    while (ter != '1' && ter != '2'){

                    screen3();
                    printf("                                      ==========   Invalid Value   ==========");
                    printf("\n\n                                     1-Yes    or 2-No : ");

                    scanf(" %c",&ter);
                    }
                    if(ter=='1'){
                        return;
                    }
                        game3();

                        exit(0);
}
void screen3(){

                    system("cls");

                    printf("\n\n                                      ==========   It's A Draw   ==========\n\n");
                    board();
                    printf("\n\n                                      ==========   Play Again ?   ==========\n\n");

}
void mode2(){
                    printf("\n                                      Player 1 = X           Player 2 = O\n");
                    printf(" Please Enter Player 1 Name : ");
                    scanf("\n");
                    fgets(p1, 20,stdin);
                    printf("\n Please Enter Player 2 Name : ");
                    fgets(p2, 20,stdin);
}
void game2(){
            //int t=1,turn=2; //player 1 always go first
            newgame();

            printf("\nPlayer 1 is %s",p1);
            printf("\nPlayer 2 is %s",p2);
            gamescore=0;
            for(int j=0 ; j<9 ; j++){
            t = t* -1;
            layout2();
            turn=turn+t;
            printf("\n                                        Player %d Turn: ",turn);

            playerMarkMode2();

            slot();
            mark();

            gamecheck();
            }
            draw();
}
void layout2(){
                system("cls");

                printf("\n\n                                      ==========   Good Luck   ==========\n\n");
                printf("\n                          Player 1 With X-Mark is %s\n",p1);
                printf("\n                          Player 2 With O-Mark is %s\n",p2);

                board();
}
void playerMarkMode2(){
            char ichar;
            scanf(" %c",&ichar);
            while ( !isdigit(ichar)){

            layout2();
            printf("                                      ==========   Invalid Value   ==========\n");
            printf("                                        Player %d Turn: ",turn);

            scanf(" %c",&ichar);
            }
            i=(int)ichar-48;

}

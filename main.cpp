#include <iostream>
#include <cstdlib>

using namespace std;

const int ROWS = 20;
const int COLUMS = 50;
const int PLAYER = 7;
const int MOVEMENT = 3 ;
const char PLAYER_SYMBOL = 'P';
const char MOVEMENT_SYMBOL = 176 ;


typedef int GAMEWORLD[ROWS][COLUMS] ;

void game_environment(GAMEWORLD TABLE)
{

TABLE[7][10]=PLAYER;
TABLE[0][17] = 0 ;

}

void game_show_environmet(GAMEWORLD TABLE)
{
  for(int a = 0 ; a<ROWS ; a++)
  {
      for(int b = 0 ; b<COLUMS; b++)
      {

          if(TABLE[a][b]==PLAYER)
            cout<<PLAYER_SYMBOL<<"";
      else  if(TABLE[a][b]==MOVEMENT)
                cout<<MOVEMENT_SYMBOL;
             else
            cout<<"*";

      }
      cout<<endl ;
  }
}

void game_movement(GAMEWORLD TABLE)

{
  char movement = '\0' ;
  int our_gamerow =0 ;
  int our_gamecol = 0 ;
int gamerow=0;
int gamecol =0;
  cout<<"PLEASE MAKE A MOVE W(UP) S(DOWN) A(LEFT) D(RIGHT)"<<endl;
  cin>>movement ;

  //find your player in the game so that you can move him
  for(int a = 0 ; a<ROWS ; a++)
  {
      for(int b = 0 ; b<COLUMS; b++)
      {
         if(TABLE[a][b]==PLAYER)
         {
             our_gamerow=a ;
             our_gamecol=b ;
             gamerow=a ;
             gamecol =b ;



         }
      }
  }


  switch(movement)
  {

  case 'W':
    {
        our_gamerow-- ;  ///HOW OUR GAME MOVES
        TABLE[gamerow][gamecol]=3;
         break;
    }
    case 'w':
    {
        our_gamerow-- ;  ///HOW OUR GAME MOVES
      TABLE[gamerow][gamecol]=0;
         break;
    }
  case 'S':
    {
        our_gamerow++;
         TABLE[gamerow][gamecol]=3;
        break ;
    }
     case 's':
    {
        our_gamerow++;
        TABLE[gamerow][gamecol]=0;
        break ;
    }
    case 'A':
    {
        our_gamecol--;
         TABLE[gamerow][gamecol]=3;
              break ;
    }
    case 'a':
    {
        our_gamecol--;
       TABLE[gamerow][gamecol]=0;
              break ;
    }
    case 'D':
    {
        our_gamecol++;
         TABLE[gamerow][gamecol]=3;
              break ;
    }
       case 'd':
    {
        our_gamecol++;
        TABLE[gamerow][gamecol]=0;
              break ;
    }


  }
TABLE[our_gamerow][our_gamecol]= PLAYER ;

system("cls");
}




int main()
{

 typedef int GAMEWORLD[ROWS][COLUMS] ;
 GAMEWORLD TABLE ;
 int Game_moves=2000 ;

game_environment(TABLE) ;
game_show_environmet(TABLE) ;
do
{
    game_movement(TABLE) ;
    game_show_environmet(TABLE) ;
    Game_moves -- ;
}while(Game_moves>0) ;


}



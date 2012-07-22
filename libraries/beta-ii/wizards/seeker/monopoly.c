// Monopoly game -- seeker
#include <std.h>
inherit OBJECT;
/* Only use 6 and under,, if you go over the players peices will go
off the board, and bad things could happen */

#define game_peices ({ "shoe", "boat", "car", "dog", "cannon",\
                       "horse", "thimble" })
// Name, Cost, Mortgage value, House cost
#define game_places ([ "1" : ({"GO!", 0, 0}),\
                       "2" : ({"Mediterranean Avenue", 60, 30}),\
                       "3" : ({"Baltic Avenue",500}),\
                       "4" : ({"Income tax",500})\
                     ])
#define max_players sizeof(game_peices)
#define WHB "%^WHITE%^%^BOLD%^"
#define RES "%^RESET%^"
mapping players;

static void create()
{

 set_name("board");
 set_short("A Monopoly game board");
 set_long("The game board has many squares on it for which you can "
          "play Monopoly on. It has many game peices on it. There are "
          "two stacks of cards on the board. One labeled Community Chest, "
          "and the other Chance.");
 set_id( ({ "board", "monopoly", "monopoly board" }) );
 set_weight(10);
 players = ([]);
 
}
int get()
{
 if (wizardp(this_player())) return 1;
 write("You cannot pick that board up, youd ruin the game.");
 return 0;
}
int query_auto_load() { return 1; }

void init()
{
 ::init();
 add_action("enter_game", "join");
 add_action("show_board", "show");
 add_action("monopoly_line", "monopoly");
 add_action("roll_dice", "roll");
}
int roll_dice(string str)
{
 int a,b,c;
 if (member_array(this_player(), keys(players))==-1) return 0;
 if (!str || str == "")
   { 
    write("Roll what?");
    return 1;
   }
  a = random(6)+1;
  b = random(6)+1;
  c = a+b+players[this_player()]["place"]+c;
 
 write("%^BLUE%^%^BOLD%^You roll the dice and get a %^WHITE%^"+a+"%^BLUE%^ and a %^WHITE%^"+b+"%^BLUE%^.%^RESET%^");
 message("info", "%^CYAN%^<monopoly> %^RESET%^"+ this_player()->query_cap_name()+" rolls the dice and gets a "+a+" and a "+b+" and moves "+(a+b)+" spaces.", keys(players));
  if (c > 40)
    {
     c -= 40;
     write("You pass go and collect $200.");
  message("info", "%^CYAN%^<monopoly>%^RESET%^ "+this_player()->query_cap_name()+" passes go and collects $200.", keys(players));
    }
 players[this_player()]["place"] = c;
 return 1;
}
int monopoly_line(string str)
{
 if (member_array(this_player(), keys(players))==-1) return 0;
 if (!str || str=="") return 1;
 message("info",this_player()->query_cap_name()+" %^CYAN%^<monopoly>%^RESET%^ "+str,keys(players));
 return 1;
}
 string *query_place(int num)
{
 int i;
 string *ob;
 string *key;

 ob = ({});
 i = sizeof(players);
 key = keys(players);
 while(i--)
  {
   if (num == players[ key[i] ]["place"]) ob += ({capitalize(players[key[i]]["peice"]) });
  }
 return ob;
}
int show_board(string str)
{ 
 int i, a, b, v, c, j,z, y;
 string *board;
 string *ob, next;
 int s;
 if (!str || str =="" || str!="board") return notify_fail("Show what?\n");
board = ({
"_______________________________________________________________",
"|Free        |                                   | GO TO      |",
"| Parking    |                                   | JAIL       |",
"|            |___ _?_ ___ ___ ___ ___ ___ ___ ___|            |  %^BOLD%^%^GREEN%^Key%^RESET%^",
"|            |   |   |   |   |   |   |   |   |   |            |  %^MAGENTA%^---------%^RESET%^",
"|------------+-----------------------------------+------------|  %^CYAN%^%^BOLD%^T - %^BLUE%^Thimble",
"|         |  |   _________                       |  |         |  %^CYAN%^%^BOLD%^B - %^BLUE%^Boat%^RESET%^",
"|         |  |  [Community]                      |  |         |  %^CYAN%^%^BOLD%^S - %^BLUE%^Shoe%^RESET%^",
"|         |C |  [  Chest  ]                      | C|         |  %^CYAN%^%^BOLD%^D - %^BLUE%^Dog%^RESET%^",
"|         |  |  [_________]                      |  |         |  %^CYAN%^%^BOLD%^C - %^BLUE%^Cannon%^RESET%^",
"|         |  |                  __________       |  |         |  %^CYAN%^%^BOLD%^H - %^BLUE%^Horse%^RESET%^",
"|         |  |                 [  Chance  ]      | ?|         |",
"|         |  |                 [          ]      |  |         |",
"|         |  |                 [__________]      |  |         |",
"|         |  |                                   |  |         |",
"|------------+-----------------------------------+------------|",
"|Jail        |___|___|_?_|___|___|___|___|_C_|___|     GO     |",
"|            |                                   |  <-------  |",
"|Visiting    |                                   |            |",
"|-------------------------------------------------------------|" });
 write("You look over the game board:");
 i = sizeof(board);
 z=20;
 y=32;
 for (a=0; a<i; a++)
    {
/* All the rooms on the top between Free parking and goto jail */
 if (a==2) {
for (c=22, j=14; c<=30; c++, j+=4)
   {
    ob = query_place(c);
    s=sizeof(ob);
    b=j;
    v=0;
    while(s--)
     {
      if (b > j+2) b = j;
      if (v < 3)
        { v++; board[a-1][b] = ob[s][0]; }
       else
        board[a][b] = ob[s][0];
      b++;
     }
   }
}
    /* FREE PARKING! */
      if (a==4) {
        ob = query_place(21);
        s = sizeof(ob);
        b = 2;
        while(s--)
         {
          board[a][b] = ob[s][0];
          b++;
         }
     }

/* heres all the rooms from 12 - 20 and 32 - 40
   basically the sides of the board */
      
     if (a < 15 && a > 5)
       {
        ob = query_place(z);
        s = sizeof(ob);
        b = 2;
        while(s--)
         {
          board[a][b] = ob[s][0];
          b++;
         }
        
        ob = query_place(y);
        s = sizeof(ob);
        b= 54;
       while(s--)
        {
         board[a][b] = ob[s][0];
         b++;
        }
        z--; y++;
       }
     if (a == 18)
       { 
/* Jail, or visiting */
        ob = query_place(11);
        s = sizeof(ob);
        b = 2;
        while(s--)
         {
          board[a-1][b] = ob[s][0];
          b++;
         }

/* All between Jail and Go */
for (c=2, j=46; c<=10; c++, j-=4)
   {
    ob = query_place(c);
    s=sizeof(ob);
    b=j;
    v=0;
    while(s--)
     {
      if (b > j+2) b = j;
      if (v < 3)
        { v++; board[a-1][b] = ob[s][0]; }
       else
        board[a][b] = ob[s][0];
      b++;
     }
   }
/*  GO  */       
        ob = query_place(1);       
        s = sizeof(ob);
        b = 53;
        while(s--)
         {
          board[a][b] = ob[s][0];
          b++;
         }
       }
  
    }
 for (a=0; a<i; a++)
  {
//   board[a] = replace_string(board[a], "T", WHB+"T"+RES);
  }
 for (a=0; a<i; a++)
    write(board[a]);
 return 1;
}
void say_monopoly(string str)
{
 int i;
 
 message("info", "%^CYAN%^<monopoly>%^RESET%^ "+str, keys(players));
}
void move_place(object ob, int x)
{
 players[ ob ]["place"] = x;
}
object query_peice(string peice)
{
 int i;
 string *key;

 i = sizeof(players);
 key = keys(players);
 while(i--)
  {
   if (players[ key[i] ]["peice"] == peice) return (object)key[i];
  }
}

int enter_game(string str)
{
 string peice;

 if (sizeof(players) > max_players)
   return notify_fail("Theres already a max of "+sizeof(players)+" in the game.\n");
 if (!str || str == "")
   return notify_fail("Join as what game peice?\n");
 if (sscanf(str, "as %s", peice)!=1)
   return notify_fail("Join as what game peice?\n");
 if (member_array(peice, game_peices)==-1)
   return notify_fail("That is not a valid game peice.\n");
 if (query_peice(peice))
   return notify_fail("Somebody is already a "+capitalize(peice)+"\n"); 
 if (players[this_player()])
   return notify_fail("You are already playing a game of monopoly.\n");
 players[this_player()] = ([ "peice" : peice, "place" : 1 ]);
 write("You join the game of monopoly as the "+capitalize(peice)+".");
 say_monopoly(this_player()->query_cap_name()+" joins the game as the "+capitalize(peice)+".");
 return 1;
}

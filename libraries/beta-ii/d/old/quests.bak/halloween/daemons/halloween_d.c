/*********************************
    Halloween Quest 10/31/2000 

      By: Seeker

1st. Witch from the north will be in the northern part of the cemetary
2nd. Witch from the south will be somewhere in merkkirri.
3rd. Witch from the west will be somewhere in roston..
4th. Witch from the east will be somewhere in arlon

They will have a staff. Different names.
The quest will start at sundown PST.

"A full moon appears as the clouds around it fade away."
"You hear piercing howls from all around you."
"The sound of a witches shreaking laughter comes from every direction."
"Off in the sky you see four witches swooping through the air."

***********************************************************/

#undef __REAL_DEAL__
#include <halloween.h>

object *user;
int dead_zombies=0;
void do_intro(int i);

int query_real() { 
//#ifdef __REAL_DEAL__
 return 0;
//#elseif
 return 0;
//#endif
 }
void start_event()
{

#ifdef __REAL_DEAL__
// Setup all the cool stuff .. sigma the trick or treater
   if (find_living("sigma")) find_living("sigma")->remove();
   new(MOBS "sigmatt")->move("/d/standard/square");
// Carve the pumpkin in square
 if (present("pumpkin", get_object("/d/standard/square")))
   present("pumpkin", get_object("/d/standard/square"))->remove();
   new(OBJS "pumpkin")->move("/d/standard/square");
#endif 

 call_out("do_intro", 1, 0); 
}

void bah()
{
 while(find_living("zombie"))
  find_living("zombie")->remove();
}
void do_intro(int i)
{

 switch(i) {
   case 0: message("halloween", "%^BLUE%^%^BOLD%^A full moon rises up over the mountains.%^RESET%^", users()); 
       break;
   case 1: message("halloween", "%^WHITE%^%^BOLD%^You hear piercing howls from all around.%^RESET%^", users());
       break;
   case 2: message("halloween", "%^CYAN%^An %^BOLD%^ice cold%^RESET%^%^CYAN%^ wind chills your soul to its depths..%^RESET%^", users());
       break;
   case 3: message("halloween", "%^BLACK%^%^BOLD%^A frightening evil shadow spreads across the lands.%^RESET%^", users());
       break;
   case 4: message("halloween", "%^YELLOW%^Off in the distance, you see four witches swooping through the air.", users()); 
       break;
   case 5: message("shout", "A witch shouts: Halloween is OURS, and theres nothing you can do about it!", users()); 
       new(MOBS "wotw")->move("/d/arlon/room/house1");
       new(OBJS "rslippers")->move("/d/arlon/room/square");
       new(MOBS "wotn")->move("/d/standard/cemetary/gravyar8");       
       new(MOBS "wote")->move("/d/standard/rain_forest/puddle");
       break;
  }
 i++;
if (i!=6) call_out("do_intro", 10, i++);
}
void event1()
{
}

void end_event()
{
 while(find_living("sigma"))
   find_living("sigma")->remove();
}
int put_zombies()
{
 int i;
 string *rooms = ({ 

"/d/standard/cemetary/gravyar9.c",
"/d/standard/cemetary/gravyar8.c",
"/d/standard/cemetary/gravyar7.c",
"/d/standard/cemetary/gravyar6.c",
"/d/standard/cemetary/gravyar5.c",
"/d/standard/cemetary/gravyar4.c",
"/d/standard/cemetary/gravyar3.c",
"/d/standard/cemetary/gravyar2.c",
"/d/standard/cemetary/grave_yard.c" });
for (i=0; i < 100; i++)
{
 new(MOBS "zombie")->move(rooms[random(sizeof(rooms))]);
}
}


int continue_quest(int i)
{
 switch(i)
 {
   case 0: message("info", "%^BLUE%^%^BOLD%^A huge lightning bolt shoots up into the sky, and down at the Sindarii cemetary.", users()); 
           call_out("continue_quest", 5, 1);
           break;
   case 1: message("shout", "The knight shouts: AAAH!! ZOMBIES EVERYWHERE! RUN!", users());
           put_zombies();
 }
}


void report_zombiedeath(object ob)
{
 object *objec;
 int i, a;

 message("info", "zombie died "+dead_zombies+".", find_player("seeker"));
 dead_zombies++;
 if (dead_zombies > 99) { 
 /*
 objec = objects();
 i = sizeof(objec);
 while(i--) {
  if (objec[i]->query_exits()) 
    {
     for(a = 0; a < random(5); a++)
       new(OBJS "candy")->move(objec[i]);
    }
}
*/
}
 if (dead_zombies > 99)
   {
    message("shout", "A knight shouts: Yay! Sindarii is saved thanks to "+ob->query_cap_name()+"!", users());
    message("shout", "Candy falls from the sky covering the land in candy.", users());
    message("info", "You would have gotten 1mil exp and a quest but since this is a re-run no. Sorry", ob);
//    ob->add_exp(1000000);
//    ob->set_manual_quest("Witches reign", 10);
   }

}

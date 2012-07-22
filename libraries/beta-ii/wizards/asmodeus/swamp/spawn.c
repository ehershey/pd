// ghast spawning pool...

#include <std.h>
#include <swamp.h>

string *rooms = ({ MOB+"swamp1.c",
                   MOB+"swamp2.c" });


#define MAX_ROOMS (sizeof(rooms))
#define MAX_GHASTS 10 // i suggest you keep this 35 and below

inherit ROOM;

void create()
{
 ::create();
 set_short("spawning pool");
 set_long("this is where ghasts are spawned.. you shouldnt be here "
          "if your a mortal");
}

int is_ghast(object gh)
{
 if (gh->query_name()=="ghast") return 1; else return 0;
}
void reset()
{
 int b, c, i;
 object ob;
 object *ghasts;

 return; 
 ::reset();
 ghasts = filter_array(livings(), "is_ghast", this_object());
 b = sizeof(ghasts);
 c = MAX_GHASTS;
 c -= b;
 tell_object(find_player("seeker"),
 "C = "+c);
 while(c--)
 {
   i = random(MAX_ROOMS);
   ob = new(MOB "ghast")->move(rooms[i]);
 }
  

}


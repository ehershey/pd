#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();
set_name("Crack to Roston");
set_items((["snow"   : "A very deep white snow",
            "dirt"  : "A light brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("Crack in roston");
set_long("This is a great opening in the ground it seems to "
         "to lead all around under the earth, it looks like "
         "giant mountains are peeking up from the surface, from "
         "all directions you can see light begin to peek out of the "
         "the roof. ");

set_exits( ([ "up" : ROOMS "r_crack5",
              "down" : ROOMS "r_crack7" ]));
}                                                               
void reset() {
  ::reset();
     if(!present("bear"))
       {
       new(MOB "m_bear")->move(this_object());
       new(MOB "m_bear")->move(this_object());
       new(MOB "m_bear")->move(this_object());
   }
}          

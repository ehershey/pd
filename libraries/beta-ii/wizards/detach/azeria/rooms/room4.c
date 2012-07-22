#include <std.h>
#include <azeria.h>

inherit ROOM;

void create() {
  ::create();    

   set_name("Azeria");
   set_items((["ground"   : "The ground seems to glow with a yellow aura",
               "aura"  : "A bright light"]));         
   set_properties(([ "light":2, "night light":3 ]));
   set_short("A holy place");
   set_long("%^BOLD%^%^BLUE%^The ground rumbles with power, the endless forest surrounds azeria. The aura is all around.");
  set_night_long("%^BOLD%^%^WHITE%^The ground rumbles with power, the endless forest surrounds azeria. The aura is all around.");   
  set_exits( (["north" : ROOMS"room3", "south" : ROOMS"room5"]));
}
void reset() {

     if(!present("paladin"))
       {
        new(MOB"1.c")->move(this_object());
       }

}

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
   set_long("%^BOLD%^%^BLUE%^Chatter can be heard to the north, the ground apperas to glow golden. Azeria seems to be surrouned by a strange aura.");
  set_night_long("%^BOLD%^%^WHITE%^Chatter can be heard to the north, the ground apperas to glow golden. Azeria seems to be surrouned by a strange aura.");   
  set_exits( (["north" : ROOMS"room2", "south" : ROOMS"room4"]));
}
void reset() {

     if(!present("paladin"))
       {
        new(MOB"1.c")->move(this_object());
       }

}

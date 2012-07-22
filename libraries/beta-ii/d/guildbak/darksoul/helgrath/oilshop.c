#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Magic shop");
    set_properties(([
	"light":2, "night light":2, "no attack":1, "no magic":1, 
	"no bump":1, "no steal":1, "indoors":1, "no teleport":1,
      ]));

    set_long("%^BOLD%^%^BLACK%^Many strange and exotic items are hanging from the rafters. "
      "%^BOLD%^%^BLACK%^Peices of flesh still dripping with %^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^o%^RESET%^%^RED%^o%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ hang from hooks "
      "%^BOLD%^%^BLACK%^near a kiln. Flecks of %^WHITE%^ash%^BLACK%^ drift around the room like snow "
      "%^BOLD%^%^BLACK%^while the occaisonal scream can be heard close by. A strange "
      "%^BOLD%^%^BLACK%^looking man sits behind a counter that dosent look like its "
      "%^BOLD%^%^BLACK%^really there....faces can be seen moving in its dark surface.");
    set_exits(([
       "south" : DARKSOUL"helgrath/hall",
      ]));
    set_smell("default", "The stench of burning and rotting flesh lurks in the
air");
  set_listen("default", "The screams of tortured souls echo from below.");
}
void reset() {
   ::reset();
   if(!present("tutenkhamen"))
   new(ROOMS"darksoul/tutenkhamen")->move(this_object());
}

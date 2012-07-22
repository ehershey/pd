#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 3, "indoors" : 1]) );
set_property("building",1);
    set_short("inside a large tower");
    set_long(
      "The painted walls give you a comfortable feeling.  The opening in the "
      "floor is the base of a staircase that takes you downstairs.  A large, "
      "colorful painting makes itself at home on the southern wall.  Candles "
      "float in mid air, causing shadows to dance on the walls. "
    );
    set_items(([
	"walls" : "The walls are painted in a Victorian fashion and are home to "
	          "dancing shadows caused by the candles.",
	"staircase" : "It leads down into the darkness.",
	"painting" : "An old man glares peacefully at you with big,%^BOLD%^%^BLUE%^blue%^RESET%^ eyes that show a bit of suffering."
		      "His long, %^BOLD%^%^BLACK%^gray%^RESET%^ beard covers most of his face.  His skin is a pale %^GREEN%^green%^RESET%^ and "
		      "the hat he wears covers most of his %^BOLD%^%^BLACK%^gray%^RESET%^ hair.  His long robes "
		      "cover him comfortably.  He is smoking a %^ORANGE%^wooden%^RESET%^ pipe.",
	"candles" : "These candles hover in the air and leave shadows on the walls.",
    ]));
   set_exits( ([ 
        "down" : ROOMS"tower4.c",
        "east" : ROOMS"tower6.c",
    ]) );
}

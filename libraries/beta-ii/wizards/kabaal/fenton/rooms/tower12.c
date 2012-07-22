#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("building",1);
    set_short("servants quarters");
    set_long(
      "The room is a mess.  Empty vials have been tossed about and books "
      "scattered throughout the room.  An old, wooden chair sits in the "
      "middle of the room before a large table. The large door you entered"
      " lies open behind you."
    );
    set_items(([
	"vials" : "Empty vials have been tossed about. ",
	"books" : "Old books have been scattered throughout the room.",
	"door" : "A huge door that leads south is open.",
	"chair" : "Uncomfortable looking.",
	"table" : "Vials and books lie on the table.",
    ]));
   set_listen("default", "An empty sound fills the room.");
   set_exits( ([ 
        "out" : ROOMS"tower11.c",
    ]) );
}
void reset() {
::reset();
    if(!present("protelus.c"))
      new(MOB"protelus.c")->move(this_object());
}

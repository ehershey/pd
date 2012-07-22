#include <std.h>
inherit ROOM;

static int i;

void create() {
 ::create();
   set_short("At the bottom of a fresh water pond");
   set_long("%^CYAN%^"
	"The bottom of the fresh water pond is still and muddy. "
	"A few small fish swim about in and out of the seaweed, "
	"which covers most of the ground.");
   set_exits(([
	"up"   : "/d/freepk/keys/sorn/pool2"
   ]));
   i = 1;
}

void locket() {
   write("You find a silver locket in the seaweed!");
   say(this_player()->query_cap_name()+" finds something in the "
	"seaweed.", this_player());
   new("/d/freepk/keys/sorn/locket")->move(this_player());
   remove_search("seaweed");
}

void reset() {
 ::reset();
   // moved this into the seaweed itself
   //set_search("seaweed", (: locket :));
   if (!present("seaweed"))
     new("/d/freepk/keys/sorn/seaweed")->move(this_object());
   if (!present("zebrafish")) {
     new("/d/freepk/keys/sorn/zebrafish")->move(this_object());
     new("/d/freepk/keys/sorn/zebrafish")->move(this_object());
   }
}

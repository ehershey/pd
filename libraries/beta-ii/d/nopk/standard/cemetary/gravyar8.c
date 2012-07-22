#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
   ::create();
   set_property("light", 1);
   set("short", "Shadowwolf's grave");
   set("long",
      "You are in the northern reaches of the Praxis cemetary. Old, "
      "long-abandoned graves spread out around you.  An eerie silence "
      "has settled over the area, as if it's awaiting something horrible. "
      "You see a grave here, with an antique headstone.");
   set_items(
      (["cemetary" : "All about you stretch the silent graves.  "
	  "You feel like you are being watched.",
	"grave" : "The grave is old, and grass-covered.",
	"writing" : "The engraving says: Here lies the mysterious "
	  "Shadowwolf.  He was decisively executed by mudders when "
	  "it was discovered he hung out with Knights who say NI.",
	"headstone" : "The headstone is of grey marble. You might "
     "be able to read the writing on it. It is tilted and may be easily "
     "pushed over.",]) );
   set_exits( 
             (["southeast" : ROOMS+"cemetary/gravyar6",
               "south" : ROOMS+"cemetary/gravyar2"]) );
}
void reset() {
  ::reset();
   remove_exit("down");
    if (!present("ghost"))
     new(ROOMS+"cemetary/mon/ghost8")->move(this_object());
}

void init() {
  ::init();
    add_action("read","read");
     add_action("push","push");
}
int push(string str) {
   if(str != "headstone")
   { notify_fail("You want to what?!\n"); return 0; }
   write("As you push the headstone you discover a set of stair leading down into the earth.\n");
add_exit("/d/nopk/tirun/mage/necromancer/necromancer_join.c","down");
   return 1;
}


int read(string str) {
  if(str == "writing" || str == "headstone") {
    write (::query_long("writing"));
    return 1;
  }
  notify_fail("Read what?\n");
  return 0;
}


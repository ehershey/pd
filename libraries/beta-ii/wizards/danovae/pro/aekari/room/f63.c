
#include <std.h>
#include <aekari.h>
inherit ROOM;

void create() {
   ::create();
   set_properties( ([
     "cave" : 1,
     "no castle" : 1,
     "indoors" : 1,
     "light" : 1,
   ]) );
   set_short("Smoothed Cavern");
   set_long(
     "There is a ledge here that leads to another part of the cave, otherwise this is just a dead-end. There might be a way to jump down there. "
   );
   set_items( ([
     "ledge" : "It doesn't look too far down, you might be able to jump.",
     ({"crystals","fragments"}) : "there are none!",
     "stone" : "very smooth well-kept rock.",
   ]) );
   set_exits( ([
     "east" : ROOMS"f62",
   ]) );
}
void init() {
   ::init();
   add_action("jump","jump");
}

int jump(string str) {
   if(str != "down")
   { notify_fail("Jump where?\n"); return 0; }
   write("You jump down to the area below.\n");
   say(this_player()->query_cap_name()+" jumps down.\n");
   this_player()->move("/wizards/danovae/pro/aekari/room/f10");
   tell_object(this_player(), "You hit the ground pretty hard.\n");
   this_player()->add_hp(-10);
   return 1;
}

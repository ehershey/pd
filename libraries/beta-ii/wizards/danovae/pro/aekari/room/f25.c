
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
     "There is a ledge here that leads to an intersection in the cavern, you may be able to get down there somehow. Looks pretty far down. "
   );
   set_items( ([
     "ledge" : "It is a rocky edge over-looking an intersection of the cave. You may be able to get down there somehow.",
     ({"crystals","fragments"}) : "there are none!",
     "stone" : "very smooth well-kept rock.",
   ]) );
   set_exits( ([
     "north" : ROOMS"f24",
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
   this_player()->move("/wizards/danovae/pro/aekari/room/f26");
   tell_object(this_player(), "You hit the ground pretty hard.\n");
   this_player()->add_hp(-10);
   return 1;
}

void reset() {
   ::reset();
   if(!present("blue guard"))
   new(NPC"ae_magi3.c")->move(this_object());
}

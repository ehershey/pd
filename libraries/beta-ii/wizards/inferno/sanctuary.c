#include <std.h>
inherit ROOM;

static int access = 1;

void create() {
 ::create();
   set_property("no teleport", 1);
   set_short("Inferno's Sanctuary");
   set_long("This room is a large, white-walled room. The ground "
     "is made of white tile, and the ceiling is far too high up to see. "
     "A huge black chair sits in the center of the empty room.");
   set_items(([
     "chair" : "A huge, black wheeled chair."
   ]));
   set_exits(([ "south" : "/wizards/inferno/lounge" ]));
}

void reset() {
 ::reset();
   if (!present("box"))
      new("/wizards/inferno/bbox")->move(this_object());
}

int toggle(string str) {
   int i;
   object *ob;
   if (str) return 0;
   if (this_player()->query_name() != "inferno")
     return notify_fail("Access denied.\n");
   if (!access) {
     write("Open sanctuary access.");
     access = 1;
     return 1;
   }
   write("Closed sanctuary access - only Inferno allowed.");
   access = 0;
   ob = all_inventory(this_object());
   i = sizeof(ob);
   while (i--) {
     if (ob[i]->is_player() && ob[i]->query_name() != "inferno") {
       message("go_away", "Access denied to Sanctuary.", ob[i]);
       ob[i]->move("/wizards/inferno/lounge");
     }
   }
   return 1;
}

mixed init() {
 ::init();
   if(this_player()->query_name() != "inferno" && !access) {
     write("Access denied.");
     this_player()->move("/wizards/inferno/lounge");
     return 1;
   }
   add_action("toggle", "toggle");
}

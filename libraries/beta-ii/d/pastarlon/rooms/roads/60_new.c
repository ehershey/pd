#include <std.h>
#include <pastarlon.h>
inherit ROOM;
void create() {
    object ob;
 ::create();
    set_short("End of the road.");
    set_long(
      "The road ends here, no more houses can be seen.  There is nothing here but a swirling portal with a sign in front of it."
);
    set_exits( 
              (["east" : ROOMS"roads/0.c",
]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["sign" : "The sign reads: This portal takes you back to your own time."
         ]) );
    ob = new(OBJECT);
    ob->set_name("portal");
    ob->set_id(({"portal"}));
    ob->set_short("a portal");
    ob->set_long("This portal will take you back to your own time.");
    ob->set_prevent_get("The portal is not real!");
    ob->move(this_object());
}
void init() {
  ::init();
    add_action("enter","enter");
}

int enter(string str) {
   if(!str) {
     notify_fail("Enter what?\n");
     return 0;
   }
   if(str != "portal") {
     notify_fail("You cannot enter that.\n");
     return 0;
   }
   write("You are sucked through the portal to the land of the present.");
   say(""+this_player()->query_cap_name()+" is sucked into the portal.");
   this_player()->move_player("/d/nopk/newarlon/rooms/roads/60");
   return 1;
}

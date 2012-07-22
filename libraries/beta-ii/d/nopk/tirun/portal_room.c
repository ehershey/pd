#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() {
   object o;
   ::create();
   set_name("Portal Room");
   set_short("Tirun Portal Room");
   set_long("A portal of pulsing light dominates the center of the room. To the south end of the room a board hangs on the wall.");
   set_exits((["down":ROOMS"adv_hall",
//               "west": "/d/nopk/tirun/gcroom",
                "south": "/d/nopk/tirun/gbroom"]));
   set_properties((["light":2, "light":2, "indoors":1]));
   o=new(OBJECT);
   o->set_name("portal");
   o->set_long("This is a portal that will take players high above the sky.");
   o->set_short("a portal");
   o->set_prevent_get("Your hands move pass through the portal.");
   o->move(this_object());
}

void init() {
   ::init();
   add_action("enter", "enter");
}

int enter(string s) {
   if(!s || s != "portal") return notify_fail("Enter what?\n");
   if(this_player()->query_name() == "nightshade")
   {
      write("You are magically teleported to your room.");
      this_player()->move("/wizards/nightshade/workroom.c");
      return 1;
   }
   if(this_player()->query_level() < 20) return notify_fail("You are too young of an adventurer to enter.\n");
   write("You enter the portal.");
   this_player()->move_player("/d/warwick/main", "into the portal");
   return 1;
}


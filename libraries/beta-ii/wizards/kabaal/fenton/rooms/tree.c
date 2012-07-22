#include <std.h>;
#include <fenton.h>;
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 0, "indoors" : 1]) );
    set_short("inside a tree");
    set_long(
      "Inside the tree, mostly darkness is seen.  The air in here is stale "
      "and tastes of death.  The walls are brown, just as you would imagine the
"
      "inside of a tree would appear.  The floor here is very rough.  Cobwebs "
      "line the corners.  Against the northern wall you notice a skeleton."  
    );
    set_items(([
        "floor" : "Most of the floor is rough, but you notice a worn spot near
the center.",
        ({"worn", "area", "worn area"}):
         "After little searching around, you discover a hole.",
        "cobwebs" : "Someone needs to do some serious cleaning.",
        "skeleton" : "This is the skeleton of a giant.  There appears to be "
"something clenched in his hand.",

   "hand" : "Grasped in his hand appears to be a piece of paper.",
        "paper" : "It reads:"
"I tried.  I made it down four levels, but met my match.  It is... impossible."
"Father, I tried my hardest.  The monsters!  The monsters!  They're...
unreal.",
    ]));
   set_exits( ([ 
        "out" : ROOMS"room8.c",
    ]) );
}
void init() {
  ::init();
  add_action("enter_it","enter");
}

int enter_it(string str) {
  if(!str) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "hole") {

    notify_fail("You can't enter that!\n");
    return 0;
  }
  else {
    this_player()->move_player(ROOMS "hole3", "leaves into the darkness.");
    return 1;
}
}

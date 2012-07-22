#include <lodos.h>
#include <std.h>
inherit ROOM;
static int water=1;
void create() {
 ::create();
   set_short("Along a twisted staircase");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("The tower twists into many turns, and the staircase "
      "makes those turns even sharper, leading to the top of the "
      "tower. Someone has recently spilt water all over the ground.");
   set_exits(([ "south" : ROOMS"etower2",
                "east" : ROOMS"etower4"]));
   set_items(([
      "tower" : "It twists and turns, making you dizzy.",
      "staircase" : "It leads up to the top of the tower.",
      "turns" : "Many sharp turns make up the staircase and tower.",
      "water" : "A large pool of water is waiting to be mopped up.",
      "ground" : "The ground is wet."
   ]));
}

int mop(string str) {
   if (!present("mop", this_player())) return notify_fail("You have no mop.\n");
   if (!str || str != "water") return notify_fail("Mop what?\n");
   if (!water) return notify_fail("That is not here to be mopped up.");
   write("You mop up the mess.");
   remove_item("water");
   water = 0;
   set_long("The tower twists into many turns, and the staircase "
      "makes those turns even sharper, leading to the top of the "
      "tower. The ground looks unusually clean here.");
   add_item("ground", "It has been cleaned and mopped.");
   if (this_player()->set_mini_quest("mop", 7000, "You saved the maids a lot of time by mopping.")) {
      write("You feel more experienced.");
      tell_room(environment(this_player()), this_player()->query_cap_name()+
         " looks more experienced.", ({ this_player() }));
   }
   return 1;
}

void init() {
 ::init();
   add_action("mop", "mop");
}

void reset() {
 ::reset();
   if (!present("soldier"))
     make(MOB"soldier");
   if (!present("knight"))
     make(MOB"knight");
}

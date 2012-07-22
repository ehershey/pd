#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Marsh");
    set_day_long(
      "The surrounding area is just one giant mud hole.  There are occasional "
      "trees here and there.  Mud clings to everything, drying into a hardened "
      "shell.  Mudbugs forage the area for food and other materials."
    );
    set_night_long(
      "Guided only by moonlight, what used to be a boring marsh land, "
      "now it got interesting.  Dark shapes with beady red eyes are "
      "off in the night.  A bat flies overhead and vanishes into the "
      "darkness.  A rolling mist slowly sets in vanishing everything in sight."
    );
    set_items(([
        "marsh" : "There are bones sticking out of the mud and dead trees.",
        "mud" : "Mixture of dirt and water, mostly water.",
        "eyes" : "Red eyes glowing everywhere.",
        "shapes" : "As one shooshes by..you noticed a tail.",
        "trees" : "Looking north you see a palm tree mixed in with swamp "
                  "trees.",
        "palm tree" : "Yup, it's a palm tree, and around it, there is sand",
        "sand" : "Golden in color.",
    ]));
    set_smell("default", "Dry heat stings your nostrils.");
    set_listen("default", "Sounds of creatures splashing in a distance");
    set_exits( ([
"southwest" : ROOMS "marsh22",
"east" : ROOMS "marsh28",
"south" : ROOMS "marsh23",
"southeast" : ROOMS "marsh24",
"north" : SAB "sab",
    ]) );
    set_heart_beat(1);
    add_invis_exit("north");
}
void reset() {
       int i;
 ::reset();
// The following two lines are for night mobs
   if (query_night() && !present("mosquito", this_object())) {
    for(i=0; i< 2; i++) {
     new(MOB"fmosquito")->move(this_object());
   }
  }
// the following two lines are for day mobs
    if (!query_night() && !present("snake", this_object())) {
    for(i=0; i< 2; i++) {
     new(MOB"msnake")->move(this_object());
   }
  }
}
void init() {
 ::init();
   set_heart_beat(1);
}
void move(object ob) {
   message("info", ob->query_cap_name()+" leaves.", this_object());
   ob->move(ROOMS"removeroom.c");
}
void heart_beat() {
   int i, check;
   object *ob = ({ }), you;
   if (!query_night()) {
     if ((you = present("mosquito", this_object())))
       move(you);
   }
   if (query_night()) {
     if ((you = present("snake", this_object())))
       move(you);
   }
   ob = all_inventory(this_object());
   i = sizeof(ob);
   check = 0;
   while (i--) {
     if (ob[i]->is_player())
       check = 1;
   }
   if (!check) {
     set_heart_beat(0);
     return;
   }
}

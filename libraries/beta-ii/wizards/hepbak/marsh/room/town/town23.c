#include <std.h>
#include <marsh.h>
inherit VAULT;
void init() {
    ::init();
    add_action("read_sign", "read");
}
create() {
  ::create();
   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Uwagi Town");
    set_day_long(
      "The door almost blends in perfectly with the wall of trees.  "
      "Looking inside, wild vines puts up a winning fight amongst the "
      "the town's civilians.  Outside the door is the swampy marshlands."
          );
    set_night_long(
      "Mounds of wild vines can be seen under the light of fire-flies. "
    );
    set_items(([
        "door" : "It blends in with the wall of trees.  "
                 "There is a sign next to it.",
        "wall" : "Trees marks the territory, seperating "
                 "the marsh and the jungle where a town "
                 "is hidden inside.",
        "trees" : "Magical in nature.  They grew really tall."
                  "and wide to the point it touches another "
                  "tree to form a wall.",
        "vines" : "The vines, when cut, will regrow overnight",
        "civilians" : "Working hard to clear enough of the vines."
                      "to have a walkable path throught the town.",
        "marshlands" : "It looks cold and uninviting out there.",
        "flies" : "Unique, the body is an actual flame.",
    ]));
    set_exits( ([
"southwest" : TOWN "town20",
"out" : ROOMS "marsh10",
    ]) );
    add_invis_exit("north");
    set_door("door", ROOMS"marsh10", "out", 0);
}
int read_sign(string str) {
    if(!str) {
        notify_fail("Read what?\n");
        return 0;
    }
    if(str != "sign" && str != "Sign") {
        notify_fail("That is not here.\n");
        return 0;
    }
    write("The sign says, beware to all those that leave "
                 "town, the Town of Uwagi is not held "
                 "responisible when you die.");
     return 1;
}

#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Dark Woods Lake");
    set_long("An eerie %^GREEN%^green %^WHITE%^glow eminates from the murky "
      "waters of the lake. The steep, muddy embankments leading down to the water's "
      "edge are covered in icy, jagged rock outcroppings, between which emerge "
      "massive oak roots, reaching desperately for the water below. A tower "
      "sits in the middle of the lake." );
    set_exits( ([ "south" : ROOMS "forest_w02.c",
     ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A faint croaking noise can be heard.");
    set_items(([
        ({"water", "lake"}) : "%^GREEN%^A green glow comes from the lake, probably from magic.",
        "outcroppings" : "The outcroppings lead out over the water.",
        "roots" : "The roots snake across the lake, and look like they could be climbed.",
        "tower" : "A tall tower emerges from the middle of the lake."
    ]));

}
void reset(){
    ::reset();
    if(present("wolf")) return;
    new(MOB"wolf2.c")->move(this_object());
}

void init() {
  ::init();
  add_action("climb", "climb");
}

int climb(string str) {
  if(!str)
    return notify_fail("Climb what?\n");
  if(str != "roots")
    return notify_fail("You cannot climb that!\n");

  write("You grab a hold of the roots and pull yourself across the lake to the tower.");
  this_player()->move_player(ROOMS "mtower00", "along the roots");
  return 1;
}

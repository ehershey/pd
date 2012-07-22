#include <std.h>
#include <rain.h>

inherit ROOM;

void init() {
    ::init();
    add_action("go_north", "north");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no steal", 1);
    set_short("The armoury");
    set_long("This is a small weaponry shop with many weapons along "
             "the walls almost every type of weapon is visible");
  set_items(
	(["shop" : "You can buy and sell things here."]));
    set_exits((["west" : ROOMS"mpath4"]));
}

void reset() {
  ::reset();
    if(!present("excist")) 
      new(MOB"excist")->move(this_object());
}

int go_north() {
    if(!wizardp(this_player())) {
	message("my_action", "Excist stops you.", this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " is stopped in their tracks by Excist.", this_object(),
	  ({ this_player() }));
	return 1;
    }
    message("other_action", (string)this_player()->query_cap_name()+
      " pushes Excist out of the way, and goes north.", this_object(),
      ({ this_player() }));
    this_player()->move_player(ROOMS"storage", "north");
    return 1;
}


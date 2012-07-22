#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^A rather large, %^YELLOW%^golden gate %^BLACK%^blocks entry to the garden to the north.  There are big, scary looking houses north and south.");
   
    set_night_long("%^BOLD%^%^BLACK%^A rather large, %^YELLOW%^golden gate %^BLACK%^blocks entry to the garden to the north.  There are big, scary looking houses north and south.");
    
    set_items(([
        "houses" : "The houses to the east and west look pretty big... and scary.",
        "gate" : "The gate is crafted of beautiful gold but has rusted over the years.  What little can be seen behind it is a beautiful garden, full of life.",
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "dtownl2.c",
        "east" : ROOMS "dtownr2.c",
	"south" : ROOMS "dtowne5n.c",
	     
	 ]));
    
}

void init() {
 ::init();
  add_action("plant", "plant");
}

int plant(string str){
  if (!str || str!="flower") return notify_fail("Plant what?\n");
  if (!present("flower", this_player())) return notify_fail("You do not have that to plant.\n");
  present("flower", this_player())->remove();
  message("quest", this_player()->query_name()+" plants the flower into the gate pot and stuff happens", environment(this_player()), this_player());
  message("quest", "you plant the flower into the gate pot and stuff happens", this_player());
  call_out("do_flower_thing", 2);
  return 1;
}

void do_flower_thing(){
  message("quest", "stuff happens and the gate opens woo", environment(this_player()));
  add_exit("/d/standard/square", "square");
}

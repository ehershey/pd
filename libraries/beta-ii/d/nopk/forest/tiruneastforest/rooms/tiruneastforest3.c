/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_pre_exit_functions(({"north"}), ({"check_north"}));
    set_exits((["northwest" : ROOMS "tiruneastforest2.c", "east" : ROOMS "tiruneastforest4.c", "southwest" : ROOMS "tiruneastforest15.c", "northeast" : ROOMS "tiruneastforest21.c", "north" : "/d/guilds/lastsaints/rooms/tirunhall", "enter" : "/d/nopk/tirun/wand/gypsy/gypsy_join"]));
     set_invis_exits(({"north"}));
}
void reset() {
    ::reset();
    if(!present("wagon"))
new("/d/nopk/tirun/obj/misc/wagon")->move(this_object());
}
int check_north() {
   if(this_player()->query_original_guild() != "lastsaints" &&
!wizardp(this_player())) {
        write("You cannot pass.");
        return 0;
   }
   write("You pass through the bushes with ease.");
   return 1;
}


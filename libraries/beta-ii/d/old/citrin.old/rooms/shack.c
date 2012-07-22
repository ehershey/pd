// Coding by Whit
// Coded for Primal Darkness

#include <std.h>
#include <citrin.h>
inherit ROOM;

int climb(string str);
void init() {
::init();
add_action("climb","climb");
}
void create() {
::create();
    set_short("Old Shack");
    set_day_long("The shack is a mess.  Cloths and other miscellanious "
                 "things have been scattered about the room.  There is a "
                 "rocking chair in the middle of the room.  There is a "
                 "small butcher knife laying on the ground broken.  The "
                 "small windows let light in however they are very dirty. "
                 "It looks to be that no one has lived here for years.  "
                 "There is a ladder leaning against the wall.");
    set_night_long("The shack is a mess.  Cloths and other miscellanious "
                 "things have been scattered about the room.  There is a "
                 "rocking chair in the middle of the room.  There is a "
                 "small butcher knife laying on the ground broken.  The "
                 "small windows let light in however they are very dirty. "
                 "it looks to be that no one has lived here for years. "
                 "There is a ladder leaning against the wall.");
    set_items(([
        (({"window", "windows"})) : "The windows are dirty and cannot be seen
through.",
        "knife" : "The knife looks very old.  It is broken and cannot be used.",

        "ladder" : "It is old and maynot hold your weight."
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
        "out" : ROOMS+"treetop4.c",
    ]));
}

void reset() {
    ::reset();
    if (!present("hermit"))
          new(MON+"ranger.c")->move(this_object());
}
int climb(string str) {
if(str != "ladder") {
notify_fail("Climb what?");
return 1;

}
write("You climb up the ladder to the top of the shack.");
say(this_player()->query_cap_name()+" climbs up the ladder.");
this_player()->move_player(ROOMS"topshack", "up");
return 1;
}

#include <std.h>
#include <guild.h>
inherit ROOM;

void init()
{
::init();
add_action("storage", "storage");
}

void create()
{
::create();
set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1
]));
set_short("The Illuminati Equipment Store.");
set_long("%^RESET%^%^ORANGE%^The Illuminati Equipment Store.\nAll sorts of items adorn the many "
"cabinets within the room.\nIlluminati members may buy and sell equipment "
"here.");
set_exits(([
"northwest" : ROOMS"illuminati/new/floor2.c"
]));
}
void reset() {
::reset();
if(!present("monster"))
new(ROOMS"illuminati/new/eqsmith.c")->move(this_object());
}

int storage()
{
if(!wizardp(this_player()))
        {
message("my_action", "That would surely be against the law.", this_player());
message("other_action", (string)this_player()->query_cap_name()+" moves to the storage room, but then thinks better of it.", this_object(), ({ this_player()
}));
return 1;
}
this_player()->move_player(ROOMS"illuminati/new/eqstorage.c", "storage");
return 1;
}

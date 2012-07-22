#include <std.h>
#include <guild.h>
inherit ROOM;

void init() {
::init();
add_action("storage", "storage");
}

void create() {
::create();
set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1
]));
set_short("The Illuminati Armoury.");
set_long("%^RESET%^%^ORANGE%^The Illuminati Armoury.\nExamples of the armourer's work hang all "
"around the walls.\nIlluminati members may buy and sell armour here.");
set_exits(([
"west" : ROOMS"illuminati/new/floor2.c"
]));
}

void reset() {

::reset();
if(!present("matthew")) 
new(ROOMS"illuminati/new/armsmith.c")->move(this_object());
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
this_player()->move_player(ROOMS"illuminati/new/armstorage.c", "storage");
return 1;
}

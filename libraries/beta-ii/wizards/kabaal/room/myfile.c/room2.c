#include <std.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("Fenton Slums");
    set_long(
      "Here you see an old destroyed building to the east.  Above "
      "your head is a sign, swinging in the wind.  Looking at the"
      "old, beat up road, you decide you can only go three directions."
      "An old, dying tree rises up infront of you, stopping you from ."
      "traveling straight north."
    );
    set_items(([
        "building" : "The building used to be big, but is collapsed now.",
        "sign" : "Welcome to Fenton.",
        "road" : "It leads south, north west, and north east.",
        "tree" : "The tree almost seems to be glaring back at you.",
    ]));
    set_listen("default", "The sound of a rusted sign blowing in the wind.");
    set_exits( ([ 
        "south" :  "wizards/kabaal/room/myfile/room2.c",
        "northwest" :  "wizards/kabaal/room/myfile/room3.c",
        "northeast" :  "wizards/kabaal/room/myfile/room4.c",
    ]) );
}

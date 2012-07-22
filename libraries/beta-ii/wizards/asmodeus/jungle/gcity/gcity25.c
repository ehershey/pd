#include <std.h>
#include <gcity.h>
#include <mjungle.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_north", "north");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set_property("no bump", 1);
    set_property("no attack", 1);
    set_property("no magic", 1);
set("short", "%^YELLOW%^Dingo's General Store%^RESET%^");

set("long","%^YELLOW%^Welcome to Dingo's General Store.\n"
"%^YELLOW%^Dingo buys and sells goods created for and found "
"%^YELLOW%^by adventurers when he is in.  The store opens "
"%^YELLOW%^south to the Western road.  There is a passage to the "
     "north guarded by a magic field.");
  
  set_items(
     (["shop" : "You can buy and sell things here.",
"passage" : "Dingo keeps the things he has for sale back there.",
]));
    set_exits( 
(["south": GCITY "gcity11.c"]));
}

void reset() {
  ::reset();
if(!present("dingo")) 
new(GMOB"dingo")->move(this_object());
}

int go_north() {
    if(!wizardp(this_player())) {
message("my_action", "The magic of Dingo stops you.", this_player());
     message("other_action", (string)this_player()->query_cap_name()+
" is stopped by the magic of Dingo.", this_object(),
       ({ this_player() }));
     return 1;
    }
    message("other_action", (string)this_player()->query_cap_name()+
" cannot be stopped by Dingo's magic.", this_object(),
      ({ this_player() }));
this_player()->move_player(GCITY"storage.c", "north");
    return 1;
}

#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
    set_no_clean(1);
    set_short("Storage Tent");
    set_long("This tent is currently being used to store various supplies.  Large crates and barrels fill the tent.");
    set_properties((["light" : 2, "indoors" : 2,]));
    set_exits(([ "out" : MJUNGLE "mjungle16.c", ]));
    set_items(([
    "crates" : "Most of the crates are nailed shut.",
    "barrels" : "The barrels probably store water.  They are tightly closed.",
    "tent" : "The tent is well made and was woven by the Merkkirri.",
    ]));
}

void hidden_cloak() {
    message("my_action", "You discover a strange cloak inside one of the open crates.", this_player());
    message("other_action", this_player()->query_cap_name()+" finds a strange cloak within one of the open crates.", this_object(), ({ this_player() }));
    new(MOB "cloakofwyrmm")->move(this_object());
    remove_search("crate");
}

void reset() {
::reset();
    set_search("crate", (: hidden_cloak :));
    set_smell("default", "The aroma of incense lofts heavily in the tent.");
}

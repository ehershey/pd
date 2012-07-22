#include <std.h>
#include <arlon2.h>

inherit OBJECT;
string *names;
void create() {
    ::create();
   set_id(({"map stand", "mapstand"}));
    set_name("a map stand");
    set_short("a map stand");
    set_long("There is a small stand here with maps of Arlon.  You can <take map> if you would like one.");
    set_weight(20000);
    set_prevent_get("You may want to leave some maps for the other newbies.");
}

void init() {
    ::init();
    add_action("take", "take");
}

int take(string s) {
    if(s != "map") return notify_fail("Take what.\n");
        write("You take a map from the map stand.");
        say(this_player()->query_cap_name()+" gets a map from the map stand.\n");
        new(OBJ "map.c")->move(this_player());
   return 1;
}

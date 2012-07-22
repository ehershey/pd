#include <std.h>
#include <sindarii.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}
  
void create() {
  ::create();
    set_property("forest", 1);
    set_property("light", 2);
    set("short", "The path to the outlands");
    set("long","To the west lies Tirun the central seat of power in these lands. To the east a path runs through a dark and forboding forest. The forest is protected by Tirun law for a ways out and should be safe for inexperienced travellers. Though brigands and rogues do roam the forest from time to time."); 
    set_items(
	(["trail" : "A well set-out trail that ends abruptly northwest.",
	  "path" : "A well set-out trail that ends abruptly northwest.",
	  "jungle" : "It surrounds this trail.",
	  "road" : "A well-traveled road from which this trail is hidden.",
	  "sign" : "It is weathered heavily."]) );
    set_exits( 
              (["west" : "/d/nopk/tirun/egate",
"southeast" : "/d/nopk/forest/tiruneastforest/rooms/tiruneastforest0.c"]) );
}

int read(string str) {
    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(str != "sign" && str != "weathered sign") {
	notify_fail("That is not here.\n");
	return 0;
    }
    write("Stay away from this jungle and return to the road.");
    write("Your life may depend upon it, because it won't depend on the law!");
    return 1;
}


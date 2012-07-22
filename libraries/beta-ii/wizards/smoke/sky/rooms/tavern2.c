#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 1, "indoors" : 1, "night light" : 1,
                "no teleport" : 1, "town" : 1]) );
   set_short("Steel Hammer Tavern");
   set_long(
            "The tavern is dimly lit. It is filled with small tables "
            "for the customers. Peanut shells litter the floor. A "
	    "small bar is off to the east. Several customers are "
	    "here, enjoying drinks and gossip alike.");
   set_items(([
            "bar" : "A small bar stretches across the tavern. It is "
                        "just east of here.",
	    "tables" : "A few small tables fill the tavern. They're all "
		 "round and are the perfect size for Dwarves.",
	    "shells" : "Some peanut shells are scattered about on "
		 "the floor.",
	    "customers" : "A few customers sit in here all day, enjoying "
		 "the atmosphere. And of course the special brew."
   ]));
   set_smell("default", "It smells of old, spilt brew.");
   set_listen("default", "Murmurs of the customers carrying on their own "
		 "conversations echo about the room.");
   set_exits( ([ 
        "east" :  ROOMS "tavern1"]));
}
void reset() {
::reset();
    if(!present("dwarf")) new(MOB"drunk.c")->move(this_object());
    if(!present("dwarf 2")) new(MOB"drunk.c")->move(this_object());
}

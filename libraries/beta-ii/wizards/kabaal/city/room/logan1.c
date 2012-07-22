#include <std.h>
#include <kabaal.h>
inherit ROOM;

void create()
{
 ::create();
set_short("lost in the forest");
   set_long("The dense jungle is starting to clear up. A large, stone fountain "
           "sits here. It looks old, but no signs of not being used. Faint "
           "visions of a civilization are starting to appear before your eyes "
	   "off to the north.");
set_items( 
          ([ "path" : "It leads west to southwest and north.",
	     "ground": "It sinks as you walk, yet you can't see it completely.",
	     "base": "There is a plaque embeded in the base of the fountain.",
	     "plaque": "Logan the Griffon King.",
             "forest" : "Tall trees surround you." ]) );
set_property("light", 2);
set_property("night light", 1);
set_smell("default", "The humid air stifils your senses.");
set_listen("default", "Squaking, squeaking, and chattering of various animals fills the air.");
set_exits( (["southwest" :ROOMS "e2",
              "north" : ROOMS "logan2"]) );
}
void reset() {
 ::reset();
   if (!present("fountain", this_object()))
     new( ITEMS "fountain.c" )->move(this_object());
}

#include <std.h>
#include <kabaal.h>
inherit ROOM;

void create(){
 ::create();
set_short("Logan");
   set_long("Several people walk about the city. The gates seperate the city from "
           "the forest south and east of here. The street leads north and west. "
           "A small building can be seen northwest of here, but no obvious enterance "
	   "into it. Another medium sized building can be seen northeast of here "
	   "but no exit can be seen to that one either. ");
set_items( 
          ([ "street" : "The street appears to be old and cracked. It leads north and west "
			"of here.",
	     "ground": "The ground is starting to solidify that it is out of the forest.",
	     "city": "You stand in the city.",
	     "building": "A small building can be seen west, another medium sized building "
			 "lies northeast.",
	     "gates": "The large gates surround the ancient city.",
             "forest" : "The forest lies south and east of here." ]) );
set_property("light", 3);
set_property("night light", 2);
set_listen("default", "Faint murmuring and noises from the forest intertwine with eachother.");
set_exits( (["north" :ROOMS "logan7",
             "west" : ROOMS "logan5"]) );
}

void reset() {
::reset();
if(!present("citizen"))
new(MOB "lc2.c")->move(this_object());
}

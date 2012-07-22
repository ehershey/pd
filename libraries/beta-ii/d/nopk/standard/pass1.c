#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 0);
   set_property("mountain",1);
   set("short", "Eastern end of the Daroq Mountains Pass");
   set("long",
	"Down below this pass to the east is the Great Western Highway "
	"that crosses the lands of the east. Curving west through "
	"the Daroq Mountain Range, the pass encounters the territory of "
	"goblins, balrogs, and tak'daroqs. The highest point on the "
	"path is not too far west. The eastern end of the pass is covered "
        "in shadow from the mountains above.");
   set_items(
	(["pass" : "A gloomy pass through the Daroq Mountains.",
	  "highway" : "The Great Western highway.  It leads into Tirun.",
	  "lands" : "The fertile lands of the east.",
	  "range" : "The Daroq Mountains, home of many vile creatures.",
	  "mountains" : "The Daroq Mountains, home of many vile creatures.",
	  "territory" : "It belongs to the evil creatures of the underground."
   ]));
   set_exits( 
	      (["northwest" : ROOMS "pass2",
                 "up" : "/d/tirunmts/rooms/tirunmts_175.c",
		"east" : ROOMS "highway3"]) );
}

void reset() {
 ::reset();
   if (!present("sign", this_object()))
     new( OBJ "nsign.c" )->move(this_object());
}

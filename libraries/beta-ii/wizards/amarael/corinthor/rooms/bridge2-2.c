//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "night light": 1, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("%^ORANGE%^This wooden bridge extends over a rather large drop to the forest floor below. Large trees spring up all around, and further to the north can be seen what seems to be some kind of tree-top city. The bridge continues further north, and south into the hollow of a tree.%^RESET%^");
     set_night_long("%^ORANGE%^This wooden bridge extends over a rather large drop to the forest floor below. Further to the north can be seen many lights amongst the branches of huge trees, illuminatiing what appears to be a tree-top city. The bridge continues further north, and south into the hollow of a tree.%^RESET%^");
     set_exits(([
		"north" : ELFROOM"bridge2-1.c",
		"south" : ELFROOM"entry.c",
                ]));
}

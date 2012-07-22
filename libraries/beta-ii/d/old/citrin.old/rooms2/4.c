// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("Around a large lake");
set_long("The path winds its way along the side of the "
"vast lake.   The trees grow thick here from the large "
"water supply from the lake.  One of the trees has a "
"strange marking on it.");
set_items(([

"marking" : "The marking is strange.  Is was formed out of "
"some ancient language.  It says:  Stgy Aeay ",
(({ "tree", "trees" })) : "It has a strange marking on it.",
"lake" : "The lake is very large.  The only thing that can be "
"seen on it is a small island.",

]));
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1 ]));
set_exits(([ "northeast" : ROOM2"3.c", "south" : ROOM2"5.c" ]));

}

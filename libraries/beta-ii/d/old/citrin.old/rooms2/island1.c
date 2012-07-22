// Coded by Whit

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
set_name("A small island");
set_long("The small island beach is made from white grains of sand.  "
"The sand glistens in the sun.  Several sea shells lay here opened "
"where the island inhabitants have eaten.  Several trees line the "
"beach that coconuts grow from.");
set_items(([
(({ "seashell", "seashells" })) : "The seashells have washed up "
"from the lake",
"sprouts" : "They will become big when the time comes",

]));
set_properties(([ "light" : 1, "night light" : 1, "island" : 1, ]));
set_exits(([
"bridge" : ROOM2"bridge.c",
"north" : ROOM2"island2.c",
]));
set_listen("default", "A steady breeze blows through here");

}

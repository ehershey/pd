// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("By a large lake");
set_long("The path curves along the side of the large lake.  "
"There are small footprints on the ground leading to the water "
"front where animals come to drink.  The trees are very thick "
"here because of it being near water.");
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1 ]));

set_items(([

"path" : "It curves near the water.  It is scattered with small "
         "animal footprints",
(({"footprints", "footprint"})) : "They belong to many animals. Whatever they were "
	       "they left deep ruts.",
"lake" : "%^BOLD%^%^BLUE%^"
"~      ~       ~         ~      ~  ~    ~    ~  \n"
"   ~ ~   ~  ~     ~   ~     ~ ~   ~ ~ ~ ~  ~    \n"
"  ~  ~ ~ ~ ~     ~ ~   ~   ~ ~    ~  ~ ~   ~    \n"
"  ~    ~    ~ ~ ~~     ~    ~  ~  ~     ~   ~ ~ \n"
"~      ~       ~         ~      ~  ~    ~    ~  \n"
"   ~ ~   ~  ~     ~   ~     ~ ~   ~ ~ ~ ~  ~    \n"
"  ~  ~ ~ ~ ~     ~ ~   ~   ~ ~    ~  ~ ~   ~    \n"
"  ~    ~    ~ ~ ~~     ~    ~  ~  ~     ~   ~ ~ \n" 
"~      ~       ~         ~      ~  ~    ~    ~  \n"
"   ~ ~   ~  ~     ~   ~     ~ ~   ~ ~ ~ ~  ~    \n"
"  ~  ~ ~ ~ ~     ~ ~   ~   ~ ~    ~  ~ ~   ~    \n"
"  ~    ~    ~ ~ ~~     ~    ~  ~  ~     ~   ~ ~ \n"
"~      ~       ~         ~      ~  ~    ~    ~  \n"
"   ~ ~   ~  ~     ~   ~     ~ ~   ~ ~ ~ ~  ~    \n"
"  ~  ~ ~ ~ ~     ~ ~   ~   ~ ~    ~  ~ ~   ~    \n"
"  ~    ~    ~ ~ ~~     ~    ~  ~  ~     ~   ~ ~ \n",

]));
set_exits(([
"north" : ROOM2"4.c",
"southeast" : ROOM2"6.c",
]));
}

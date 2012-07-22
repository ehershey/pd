#include <rain.h>
#include <std.h>
inherit ROOM;

  void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "forest" :1 ]) );
    set_long("Trees are all around. The forest has many birds "
             "in the trees. There are also a few squirrels around. "
       "The ground is covered mostly by leaves and strange "
       "rotting stuff. The trail leads to the southwest");
    set_short("A forest");
    set_items((["trees": "All the trees are green and none of them"
                         "appear to be brown. There are old trees, and"
                         "little sapplings, all the trees have vines on"
                         "them",
                "leaves": "Most of the leaves are rotting"]));
   set_exits((["southwest" : "/d/standard/rain_forest/zexor/path1"]));
   new("/d/standard/rain_forest/zexor/obj/sign.c")->move(this_object());
}           


void reset() {
  ::reset();
   if (!present("rabbit"))
      new(MOB"rabbit")->move(this_object());
}

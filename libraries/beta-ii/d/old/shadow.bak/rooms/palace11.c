inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the southern wing of the castle.  The wedding "
    "decorations are a bit more sparse here, but it is still well kept.  "
    "The hall heads north and a large stairway leads up.  This hall is "
    "adorned with pictures of royalty.  The stairwell is made of finely carved "
    "cedar, and looks like it took years to finish.");
  set_smell("default","The air has an antique odor about it.");
  set_listen("default","It is fairly quiet here.");
  set_items(([({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls.",
    "wall":"The wall is lined with various pictures and armour displays.",
    "pictures":"The pictures are all grand, and likely bigger than life.",
    "stairs":"They are carved with intricate figures in the handrail.",
    "figures":"There are cute little forest animals engraved on the handrail."]));
  set_exits((["north":ROOMS "palace10.c","up":ROOMS "palace22.c"]));
}

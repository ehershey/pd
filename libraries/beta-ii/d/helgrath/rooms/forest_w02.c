#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Dark Woods");
    set_long("Massive trunks of gray, twisted oak line the sides of the long forest path. A small, "
      "dark hole in a nearby tree provides shelter for an old, wilting owl. Several varying types of "
      "animal tracks can be made out in the dark soil underfoot. ");
    set_exits( ([ "west" : ROOMS "forest_w01.c",
      "east" : ROOMS "forest_w03.c",
      "north" : ROOMS "forest_lake_w01.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A faint croaking noise can be heard.");

}
void reset(){
    ::reset();
    if(present("owl")) return;
    new(MOB"owl.c")->move(this_object());
}

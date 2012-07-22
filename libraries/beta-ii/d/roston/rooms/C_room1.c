#include <roston.h>
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_short("a huge cave");
    set_long("This is the entrance of the cave of Carnage, many "
      "adventurers have lost their life here. The walls seem "
      "to be covered with cobwebs and dust, the floor is made "
      "of rock hard granite.");
    set_items(([
	"walls" : "The walls are covered with cobwebs and dust.",
	"ground" : "The ground is a hard granite floor that "
	"seems to be coverd with dust." ]));
    set_property("light", 1);

    set_exits(([
	"south" : ROOMS"C_room2.c",
	"north" : ROOMS"C_room3.c",    
	"west" : ROOMS"C_room4.c",
	"up" : "/d/nopk/standard/pass13"]));
}

void reset() {
    /*  Buggin...  I cant find the monster -- Whit
	if(!present("spider"))
	    new("/d/roston/obj/mob/spider")->move(this_object());
    */
}

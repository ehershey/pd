#include <roston.h>
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_short("");
    set_long("A large worked mine. The walls and floor are smooth marbled granite with vains of other rock formations running throughout. The walls and ceiling are braced at regular intervals to keep tons of rock from caving in. Passages lead off to the north, south, and east. The exit to the outside world is to the west.");
    set_items(([
	"walls" : "The walls are covered with cobwebs and dust.",
	"ground" : "The ground is a hard granite floor that "
	"seems to be coverd with dust." ]));
    set_property("light", 1);

    set_exits(([
	"south" : ROOMS"C_room2.c",
	"north" : ROOMS"C_room3.c",    
	"west"  : ROOMS"C_room4.c",
             ]));
}

void reset() {
    /*  Buggin...  I cant find the monster -- Whit
	if(!present("spider"))
	    new("/d/roston/obj/mob/spider")->move(this_object());
    */
}

#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Inside some sort of sacrificial room");
    set_properties((["light" : 2 ]));
    set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
    set_long("The room is bare, with the exception "
      "of a small door leading west, several windows against the wall, "
      "and a long, flat sacrificial altar. The altar is spattered with "
      "dried blood and smashed bones.");
    set_exits(([ "west" : ROOMS"wtower5" ]));
    set_items(([
	"room" : "It is almost completely bare.",
	"blood" : "It is everywhere and it is old.",
	"bones" : "They are smashed up.",
	"altar" : "Sacrifices take place here."
      ]));
    set_pre_exit_functions( ({"west"}), ({"watch_message"}) );

}

int watch_message()
{

    object o;

    if (random(10)!=5)
    {
        //o=new(OBJ"watchobj.c");
        //o->move(this_player());
        //o->start_fmv();
	return 1;
    }
    return 1;
}

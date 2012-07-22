#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
      "indoors" : 1
    ]));
    set_short("Weapons Shop - The Adrenaline of War");
    set_long("The walls of this shop are lined with numerous display cases holding a wide "
      "variety exquisitely crafted weaponry, the likes of which must cost a fortune. " );
    set_exits( ([ "south" : ROOMS "marketrd_e03.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "It is strangely quiet here.");
}
void reset(){
    ::reset();
    if(present("yorik")) return;
    new(MOB"vendor_weapons.c")->move(this_object());
}

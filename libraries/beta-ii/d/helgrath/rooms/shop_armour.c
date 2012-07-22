#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
      "indoors" : 1
    ]));
    set_short("Armour Shop - The Wary Wanderer");
    set_long("The shop is cluttered with various stands and display cases holding numerous "
      "exquisitely crafted suits of plate mail, gauntlets, helms and other such "
      "armours and accessories." );
    set_exits( ([ "south" : ROOMS "marketrd_e01.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");
}
void reset(){
    ::reset();
    if(present("olaf")) return;
    new(MOB"vendor_armour.c")->move(this_object());
}

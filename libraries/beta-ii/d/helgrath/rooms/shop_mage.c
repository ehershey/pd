#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
      "indoors" : 1
    ]));
    set_short("Mage Shop - Magus De Arcanum");
    set_long("Ancient tomes clutter the oddly crafted tables and shelves in this huge building. "
      "The sheer size of the room is awe-inspiring. Somehow it doesn't seem like a room "
      "of this magnitude would even fit in a building as small as this. It is strangely warm in "
      "the room, quite a drastic difference from the bone-chilling cold just beyond the north door." );
    set_exits( ([ "north" : ROOMS "marketrd_e01.c" ]));
    set_smell("default", "Strange sulferous oders waft about the room.");
    set_listen("default", "%^GREEN%^F%^YELLOW%^a%^RED%^i%^BLUE%^n%^YELLOW%^t  %^GREEN%^c%^YELLOW%^h%^RED%^a%^BLUE%^n%^GREEN%^t%^YELLOW%^i%^RED%^n%^BLUE%^g %^GREEN%^can be heard.");
}
void reset(){
    ::reset();
    if(present("yaenel")) return;
    new(MOB"vendor_mage.c")->move(this_object());
}

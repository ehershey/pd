#include <std.h>
#include <helgrath.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([
      "indoors" : 1
    ]));
    set_short("Storage Room");
    set_long("A storage room for the mage shop." );
}
void reset(){
    ::reset();
   if(!present("rod", this_object()))
    new(ITM"rod.c")->move(this_object());
   if(!present("wax", this_object()))
   {
    if(random(100) < 35)
    new("/d/nopk/tirun/obj/misc/seal_blank_new")->move(this_object());
    if(random(100) < 35)
    new("/d/nopk/tirun/obj/misc/seal_blank_new")->move(this_object());
    if(random(100) < 35)
    new("/d/nopk/tirun/obj/misc/seal_blank_new")->move(this_object());
   }
}

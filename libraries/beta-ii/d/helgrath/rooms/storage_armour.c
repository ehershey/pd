#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
      "indoors" : 1
    ]));
    set_short("Armour Storage");
    set_long("A storage room for the armourers." );
    set_smell("default", "The smell of newly worked metal wafts through the air.");
    set_listen("default", "The metallic dint of steel on steel rings in the air.");

}
void reset(){
    ::reset();
    new(ARM"platemail.c")->move(this_object());
    new(ARM"parmour.c")->move(this_object());
    new(ARM"pboots.c")->move(this_object());
    new(ARM"pleggings.c")->move(this_object());
    if(random(100) > 74) {
    if (!present("belt of candles")) 
        new("/d/nopk/tirun/obj/misc/beltofcandles.c")->move(this_object()); }
}

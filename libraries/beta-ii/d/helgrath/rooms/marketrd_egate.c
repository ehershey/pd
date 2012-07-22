#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Gate of the Moon");
    set_long("The East Gate, also known as the Gate of the Moon, towers over even the "
      " massive buildings of the inner city. Militaristic fortifications atop the battlements "
      "ensure the utter annihilation of any would-be invaders. Archers and Guards in "
      "full battle plate patrol the walls like deadly clockwork. " );
    set_exits( ([ "west" : ROOMS "marketrd_e05.c",
      "gate" : ROOMS "forest_w01.c" ]));
    set_smell("default", "It is too cold to smell anything.");
   set_listen("default", "The scraping of the guards' scabbards colliding with their armor can barely be heard.");

}
void reset(){
    ::reset();
    if(present("guardian")) return;
    new(MOB"guardian.c")->move(this_object());
    if(present("guardian 2")) return;
    new(MOB"guardian.c")->move(this_object());
}

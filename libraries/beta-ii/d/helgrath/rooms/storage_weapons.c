#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
      "indoors" : 1
    ]));
    set_short("Weapons Storage");
    set_long("A storage room for the weaponsmiths." );
    set_smell("default", "The smell of newly worked metal wafts through the air.");
    set_listen("default", "The metallic dint of steel on steel rings in the air.");

}
void reset(){
    ::reset();
    new(WEP"shortsword.c")->move(this_object());
   new("/wizards/detach/azeria/obj/1.c")->move(this_object());
   new("/wizards/detach/azeria/obj/2.c")->move(this_object());
   new("/wizards/detach/azeria/obj/5.c")->move(this_object());
   new("/wizards/detach/azeria/obj/6.c")->move(this_object());
   new("/wizards/detach/azeria/obj/7.c")->move(this_object());
}

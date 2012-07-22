#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Yull Temple Courtyard");
    set_long("The vast courtyard spans hundreds of yards. Tall, black marble pillars support "
      "the high, vaulted roof of the temple to the north. A large stone fountain rests "
      "just below the wide, tiered steps of the temple and a large donation pit occupies "
      "the center of the courtyard. "  );
    set_exits( ([ "south" : ROOMS "yullblvd_n05.c",
                  "enter" : ROOMS "temple01",
    ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A faint chanting can be heard.");

}
void reset(){
    ::reset();
    if(present("pit")) return;
    new(ITM"pit.c")->move(this_object());
    if(present("fountain")) return;
    new(ITM"fountain.c")->move(this_object());
}

#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
      "indoors" : 1
    ]));
    set_short("White Horse Tavern");
    set_long("Welcome to the White Horse Tavern!\n"
      "The White Horse Tavern was established thirty-eight years ago. "
      "These days it seems to be showing its age, and is a bit outdated, "
      "but it still appears quite sturdy and well-maintained. A menu of the "
      "items served is at the bar. Type <look menu> to see what is served. " );
    set_exits( ([ "north" : ROOMS "marketrd_e04.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "Conversation and drunken laughter reverberates throughout the establishment.");

}
void reset(){
    ::reset();
    if(present("Milex")) return;
    new(MOB"vendor_barkeep.c")->move(this_object());
}

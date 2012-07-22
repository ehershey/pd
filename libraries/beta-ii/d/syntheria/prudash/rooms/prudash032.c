#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("This is the throne room of for the Lord of Prudash. From this room he plans all of his strategies and policies. A small wooden throne sits next to the south wall, it looks like a normal chair with some red paint on it. A large red banner is hung on the wall behind the throne, it is the only thing in the room that doesn't look to be worn down. The floor is covered by a giant fur from some strange animal.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        "indoors"     : 1,
        ]) );
        set_items(([
        "banner"       :   "A large red banner with the symbol of an axe sewn into it.",
    	"throne"       :   "A small wooden chair that has been painted red.",
    	"fur"          :   "The fur of a large bear like creature, it must have been a mighty beast.",
        ]));
	    set_listen("default", "It is rather quiet.");
	    set_smell("default", "The sounds of burning torches echos through the halls.");
	    set_exits(([
            "north"     : ROOMS "prudash028.c", 
        ]));
}

void reset() {
   ::reset();
if (!present("leader", this_object()))
    new(MOB"troll_leader.c")->move(this_object());
if (!present("guard", this_object()))
    new(MOB"troll_guard.c")->move(this_object());
if (!present("guard 2", this_object()))
    new(MOB"troll_guard.c")->move(this_object());
    if (!present("spy", this_object()))
    new(MOB"troll_spy.c")->move(this_object());

}

//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Home");
     set_long("This would appear to be the living area of an elven home, there are several wicker lounges arranged around the middle of the room. Along the eastern wall runs a bench, probably for preparing food before sitting down to eat. There is a window that opens out to the west, providing a magnificent view of the forest.");
     set_exits(([
                "south"              : ELFROOM"earthhome1.c"
                ]));
     set_items(([
		({ "lounge", "lounges" })	: "The lounges are made in a similar fashion to wicker baskets, and have cushions to make them comfortable.",
		"bench"				: "The bench would appear to be the elven equivalent of a kitchen, as the elves eat little meat.",
                ({ "view", "window" })          : "The view through the window is marvelous, and is there simply as a reminder of nature when indoors."
                ]));
}

void reset() {
   ::reset();
     if(!present("lord"))
       new(ELFMOB"erthlord.c")->move(this_object());
     if(!present("guest"))
       new(ELFMOB"erthguest.c")->move(this_object());
     if(!present("guest 2"))
       new(ELFMOB"erthguest.c")->move(this_object());
     if(!present("guest 3"))
       new(ELFMOB"erthguest.c")->move(this_object());
}

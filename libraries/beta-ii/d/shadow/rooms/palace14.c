inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",1);
    set("short","Palace");
    set("long","The ceiling of this room is stories high and makes anyone "
      "who enters this room feel small.  Two large silver plated doors to "
      "the east are open, beckoning you to join the festivities in the throne "
      "room.  Servants here are running in and out of this room, fetching "
      "things for the lords attending the wedding.");
    set_smell("default","The smell of a great feast wafts towards you.");
    set_listen("default","The sound of people talking and making merry can be "
      "heard to the east.");
    set_items(([({"streamer","streamers"}):"The streamers hang from the "
	"chandeleir in beautiful %^BOLD%^%^RED%^sw%^BLUE%^ir%^GREEN%^ls%^RESET%^.",
	({"decorations","wedding decorations"}):"Flowers and fine silk decorations "
	"line the walls and steps.",
	"doors":"These huge silver plated doors must take 2 men to open each one."])
    );
    set_exits((["east":ROOMS "palace18.c","west":ROOMS "palace08.c","north":ROOMS 
	"palace13.c","south":ROOMS "palace15.c"]));
}

void reset() {
    ::reset();
    if(!present("knight")) {
	new(MOB "pknight")->move(this_object());
	new(MOB "pknight")->move(this_object());
    }
    if(!present("servant")) {
	new(MOB "mservant")->move(this_object());
	new(MOB "fservant")->move(this_object());
	new(MOB "fservant")->move(this_object());
    }
}


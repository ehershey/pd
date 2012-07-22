#include <std.h>
#include <rain.h>

inherit VAULT;

int open_bookshelf();
object rm;
int searched;

create() {
    ::create();
    set_properties( ([ "light" : 2, "night light" : 2, "indoors" :1 ]) );
    set_short("A house");
    set_long("A small family room. There is "
      "a table sitting in the center of the room. "
      "A bookshelf sits over at the edge of the room.");
    set_exits((["out" : ROOMS"home1",
	"south" : ROOMS"house12",
	"bookshelf" : ROOMS"bookshelf" ]));
    set_items((["table" : "This is a large wooden table with a vase "
	"sitting on it.",
	"vase" : "This vase has something shiny in it ",
	"bookshelf" : "On the shelf, there are various books.",
	"books" : "The books have a key hole in them!"]));

    set_door("bookshelf", ROOMS"bookshelf", "bookshelf", "book key");
    set_func("bookshelf", "open", "open_bookshelf" );
    set_func("bookshelf", "close", "close_bookshelf");
    add_invis_exit("bookshelf");
    set_locked("bookshelf", 1);
    rm = this_object();
    restore_object("/d/standard/rain_forest/house1");
}

int close_bookshelf() {
    write("You secret bookshelf door closes slowly.");
    add_invis_exit("bookshelf");
    return 1;
}

int open_bookshelf() {
    remove_invis_exit("bookshelf");
    write("The secret bookshelf door creaks open.");
    return 1;
}

int vase_search(string str) {
    if(str != "vase")
	return 0;
    if(searched)
	return 0;
    write("You find a key in the vase!");
    new(OBJ"key")->move(this_player());
    searched = 1;
    return 1;
}

void reset() {
    ::reset();
    set_search("vase", (: this_object(), "vase_search" :));
    if(!present("child"))
	new(MOB"child.c")->move(this_object());
    if (!present("mother"))
	new(MOB"mother.c")->move(this_object());
    if (!present("father"))
	new(MOB"father.c")->move(this_object());
    searched = 0;
}
int bookshelf()
{
    if (invis_exit("bookshelf"))
    {
	write("What?");
	return 1;
    }
    return 0;
}

void init()
{
    ::init();
    add_action("vase_search", "search");
}

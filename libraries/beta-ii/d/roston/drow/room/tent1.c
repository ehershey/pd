#include <std.h>
#include <roston.h>
inherit ROOM;

void init() {
    ::init();
    add_action("enter_book" , "enter");
}
void create() {
    ::create();
    set_name("Drow Camp");
    set_items((["snow"   : "A deep white snow",
	"book" : "There seems to be a huge hole in the middle of the book, maybe you could enter it",
	"dirt"  : "A dark brown mixture"]));
    set_properties((["light":2, "night light":3]));
    set_short("camp");
    set_long("This is a deep black room, in the middle of a deep "
      "black tent.  There seems to be a golden book in the "
      "center of the room.  It looks as if there is a deep bright "
      "light coming from somewhere.");

    set_exits( ([ "up" : DROWROOM"room73"]));
}                                                             
int enter_book(string what) {
    if (what != "book") return 0;
    this_player()->move_player(DROWROOM"tent2.c", "into
the glowing book and vanishes without a trace.");
    return 1;
}


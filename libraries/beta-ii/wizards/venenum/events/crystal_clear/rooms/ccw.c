#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("A dead end");
    set_long("This section of the cave has apparently suffered a cave-in and further access is impossible. The floor, walls and ceiling of this section of cave are heavily damaged, although they do not look to be in imminent danger of falling in again.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is a little musty.");
    set_items(([
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"cc26.c",
      ]));
}

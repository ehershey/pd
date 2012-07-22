#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Dead end");
    set_long("The path stops abruptly here as the path falls into shrubbery. The trees are more dense around here, blocking off the path, although it would appear that the path itself terminates naturally. There is a large pool of blood here, containing a severely wounded halfling.");
    set_listen("default", "Soft moaning comes from the halfling.");
    set_smell("default", "The lavender scent of halfling blood is strong here.");

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"northeast" : ROOMS"cc2.c",
      ]));
}

void reset()

{

    if (!present("halfling")) {
	new(MOB"wounded_halfling.c")->move(this_object());
    }
}

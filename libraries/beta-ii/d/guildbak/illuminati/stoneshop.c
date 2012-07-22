#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Magic shop");
    set_properties((["light" :2, "indoors":1]));
    set_short("Illuminati Magic Shop");
    set_long("This strange room has all sorts of odd figurines placed all around on shelves. "
      "Each of them radiates with magical energy and has a specific purpose, it would "
      "be best not to touch them. At the back of the room is a bench with a man "
      "standing behind it, waiting to serve you. A sign hangs on the wall.");
    set_exits(([
	"northeast" : ROOMS"illuminati/hall",
      ]));
}
void reset() {
    ::reset();
    if(!present("rand"))
	new(ROOMS"illuminati/mobs/rand")->move(this_object());
}

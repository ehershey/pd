#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Main Bedroom");
    set_long("This room clearly functions as the bedroom for a married couple, with a large double bed and a large glass window overlooking the front of the house. Several beautiful, elaborate paintings hang from the walls of this room, but by far the most prominent feature here is the bloated, dead corpse which occupies a portion of the floor between the wall closest to the door and the bed.");
    set_smell("default", "The scent of death is strong.");
    set_listen("default", "The house is quiet and peaceful.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_items(([
	({"bed", "double bed"}) : "This large double bed has been recently made.",
	({"window"}) : "The window overlooks the front of the house, affording an excelent view of Galthus Road.",
	({"paintings"}) : "These paintings are high quality art which depicts landscapes. One picture is a head-and-shoulders of a white horse. The quality is exceptional.",
	({"painting", "picture", "white horse", "horse"}) : "The horse's white hair flows down the side of it's neck in this extremely artistic rendering of it's head.",
      ]));
    set_exits(([
	"west" : ROOMS"devereux4.c",
      ]));
    new(ITEM"house_body.c")->move(this_object());
}


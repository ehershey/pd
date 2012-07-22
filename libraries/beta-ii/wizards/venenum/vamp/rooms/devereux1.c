#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("A stately garden");
    set_long("This stately house sits to the north of Ganthus road. The gardenhere is extensively decorated and well manicured. Many large roses bushes and shrubs have been planted here, although their form is somewhat disturbing - the silhouette of animals on the hunt. The house itself is large and expensive looking, with brass handrails on the second floor and a pair of large, heavy double doors which appear to be solid bronze.");
    set_smell("default", "The faint smell of flowers is present here.");
    set_listen("default", "This neighbourhood is quiet and peaceful.");
    set_items(([
	({"animals", "animal", "shrub", "shrubs", "rose", "roses"}) : "These shrubs are immaculately well cared for, shaped into the shapes of animals on the hunt. All of the animals, without exception, are predators- large cats, wolves, dogs and crocodiles.",
	({"house"}) : "This house looks extremely expensive and solidly constructed.",
	({"handrail", "handrails"}) : "These handrails are solid bronze and probably cost many gold coins to have crafted.",
	({"doors", "door", "double doors", "heavy doors"}) : "These huge doors look to be extremely strong and crafted of solid bronze.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"south" : "/d/nopk/tirun/nwganthus2.c",
	"enter" : ROOMS"devereux2.c",
      ]));
}


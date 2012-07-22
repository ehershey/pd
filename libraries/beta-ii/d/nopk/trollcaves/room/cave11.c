#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The tunnel seems to level out here and broaden to the east, while narrowing and rising to the west. A flow of water trickles out a hole in the wall, makes it's way through a shallow groove across the path of the tunnel before dropping down another hole to locations unknown. To the east, some light appears to shine from some source.");
    set_smell("default", "The rancid stench of rotting meat is incredible.");
    set_listen("default", "The cavern is as silent as a tomb.");
    set_items(([
	({"stone"}) : "The stone underfoot makes a sudden switch to a red-yellow coloured stone with occasional cracks of blue streaking through it.",
	({"light"}) : "The light is only faint, but it is more then enough to see by in these darkened conditions.",
	({"scratch marks", "marks", "scratch", "scratches"}) : "There are none here."
      ]));
    set_properties(([
	"light" : -1,
	"night light" : -2,
      ]));
    set_exits(([
	"west" : ROOMS"cave10.c",
	"east" : ROOMS"cave12.c",
      ]));
}

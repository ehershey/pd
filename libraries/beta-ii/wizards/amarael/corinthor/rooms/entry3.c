//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor");
     set_long("Around and around and around the stairs go, every one the same as the last. The walls blur by, never changing, never changing. That giant hole in the middle of the hollow continues on seemingly forever up and down, round and round.");
     set_exits(([
		"up"    : ELFROOM"entry4.c",
		"down"  : ELFROOM"entry2.c",
                ]));
     set_items(([
		"hole" : "It's a fair way down, but the roof is just as far now.",
		({ "stairs", "steps" }) : "They are wooden planks set into the side of the hollow."
		]));
    set_listen("default", "Footsteps echo a thousand times a thousand fold.");
}

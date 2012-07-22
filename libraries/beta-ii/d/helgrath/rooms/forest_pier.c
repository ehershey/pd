#include <std.h>
#include <helgrath.h>
#include <daemons.h>
inherit ("/std/docks");
void create()
{
    ::create();
    set_short("Helgrath Docks");
    set_long("Many boats rise and fall on the swell of the ocean waves. The supports "
      "of the pier covered with slimy seaweed. Green and yellow lichens cover "
      "the nearby rock outcroppings. A small shack sits off from the pier to the left.  You can get on your boat here if you have one. If your boat is not docked at this "
      "pier type <recall boat>. Once its docked here type <board (name)>");
    set_listen("default", "A slight breeze blows in from the open water.");
    set_smell("default", "The strong smell of sea water fills the air.");
    set_exits( ([ "west" : ROOMS "forest_w03.c", "shack" : ROOMS"upgradestore.c", ]) );
    set_letter("B");
}

#include <std.h>
inherit ROOM;

void create() {
  ::create();
   set_name("Roston Square.c");
   set_properties((["light":2, "night light":3]));
   set_short("Roston Square");
   set_long("Roston Square is the meeting place of the dwarven hunters. "
         "You seem to be surrounded by snow covered mountains, to "
         "the west you can hear sounds of banging metal, the scent "
         "of burning leather comes from the south, there seems to "
         "be a large building to the north");
set_exits( ([ "north" : "/wizards/detach/roston/roston2",
              "south" : "/wizards/detach/roston/roston3" ]));
}
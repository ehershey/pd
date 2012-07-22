#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Tunnel");
    set_day_long(
      "This tunnel is crudely dug out.  Claw marks along the walls, with "
      "spatters of blood everywhere.  Bones line the tunnel floor making "
      "walking difficult."
    );
    set_night_long(
      "This tunnel is crudely dug out.  Claw marks along the walls, with "
      "spatters of blood everywhere.  Bones line the tunnel floor making "
      "walking difficult."
    );
    set_items(([
        "bones" : "They line the floor, making walking difficult.",
        "blood" : "The blood is splatter everywhere.",
        "marks" : "They mark up the walls, as if a battle was done here.",
        "tunnel" : "Rather dark in smelly in here.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of howling echoing off the walls");
    set_exits( ([
"out" : ELE "ele6",
"south" : ELE "ele5",
    ]) );
}

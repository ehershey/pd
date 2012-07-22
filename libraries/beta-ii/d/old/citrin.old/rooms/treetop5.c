// Coded by Whit

#include <std.h>
#include <citrin.h>
inherit ROOM;

int repair(string str);
void init() {
::init();
add_action("repair","repair");
}

void create() {
    ::create();
    set_short("Amoung the tree tops");
    set_properties( (["light" : 3, "night light" : 2]) );
    set_long("The walkway abruptly ends to the north where it was collapsed.  The only way out is back the way you came.");
    set_exits( (["southwest" : ROOMS+"treetop3.c"
              ]) );
set_items(([
"walkway" : "You may be able to repair it.",
]));
}

int repair(string str) {
if (str != "walkway") {
object slave, env1;
if (present("planks", this_player())) {
if (present("planks", this_player())->remove());
write("The walkway has been restored.");
slave = new("/wizards/whit/slave");
slave->move(ROOMS"treetop6.c");
env1 = environment(slave);
slave->remove();
tell_room(env1, "Someone repairs the walkway from the other side.", ({ }));
add_exit("/d/citrin/rooms/treetop6", "northeast");
say(this_player()->query_cap_name()+" has repaired the broken walkway.");
return 1;
}
}
write("You cannot repair it without some planks.");
return 1;
}

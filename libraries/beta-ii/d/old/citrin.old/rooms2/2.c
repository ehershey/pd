// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;


/*
void init() {
::init();
add_action("climb_vine", "climb");
}
*/


void create() {
::create();
set_name("Citrin Forest");
set_long("A smooth breeze flows through this area making "
"the leaves ruffle and fall from the trees. Acorns and "
"twigs lay scattered amoung the indy path from the overhead "
"trees. On one of the trees there is a vine");
set_items(([
(({ "twigs", "twig", "path", "acorns", "acorn" })) : "The path "
"is covered in acorns and twigs.",
"vine" : "You may be able to climb it",

]));

set_properties(([ "light" : 1, "night light" : 1, "forest" : 1 ]));
set_exits(([ "west" : ROOM2"1.c", "south" : ROOM2"3.c" ]));

}

/*
int climb_vine(string str) {
   if(!str) {
        notify_fail("Climb what?\n");
        return 0;

    }
    if(str != "vine") {
        notify_fail("You cant climb that!\n");
        return 0;
    }


write("You grab ahold of the vine tightly and climb up it.");
this_player()->move_player("/d/citrin/rooms/treetop1");
say(this_player()->query_cap_name()+" climbs up the tree.");
return 1;
}
*/

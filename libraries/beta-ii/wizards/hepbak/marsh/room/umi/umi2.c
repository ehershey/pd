#include <std.h>
#include <marsh.h>
inherit OCEAN;
void create() {
ocean::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Umi Town");
    set_long(
      "%^BLUE%^Here stands the entrance to the town of Umi, the town "
      "%^BLUE%^seems to be in some sort of air bubble, with the entrance "
      "%^BLUE%^sealed off by a forcefield."
    );
    set_items(([
        "town" : "Unlike the one up on land, this is very modern looking.",
        "door" : "The is no door to speak of, but looking through, something is
holding the water back.",
        "entrance" : "The entrance looks very inviting.",
        "forcefield" : "Some kind of electrical energy, that dosn't shock when
y
ou touch it.",
    ]));
    set_exits( ([
"enter" : UMI "umi5",
"up" : WATER "lvl4",
    ]) );
}
void init()
{
 ::init();
 add_action("Fenter", "enter");
}
int Fenter()
{
 write("You squeeze and implode, ouch!.");
 return 0;
}

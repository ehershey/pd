#include <std.h>
#include <purgatory.h>
inherit ROOM;
void create() {
    ::create();
 set_properties( ([ 
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 1,
                    "no steal"    : 1, ]) );
    set_property("town",1);
    set_listen("default", "The wails of tortured souls echo around this place.");
    set_smell("default", "A strange sent wafts in from the north.");
    set_short("Tirun Park");
    set_long("%^BOLD%^%^WHITE%^Purgatory Crossroads.\n"
"%^BOLD%^%^BLACK%^An eerie sense of foreboding permeates this place like rancid "
"%^BOLD%^%^BLACK%^meat. The broken people of Purgatory wander aimlessly through "
"%^BOLD%^%^BLACK%^the crossroads. The statue of Death looms over the crossroads "
"%^BOLD%^%^BLACK%^as if reminding whomever enters this area of who dwells here. "
"%^BOLD%^%^BLACK%^Trampled bodies line the gutters of the streets from the last mad dash "
"%^BOLD%^%^BLACK%^for safety. ");
    set_exits((["north" : ROOMS "purgatory1",
        "south" : ROOMS "purgatory3",
        "west" :  ROOMS "purgatory2",
        "east" : ROOMS "purgatory4"]));
    set_items( ([
        "Death"  : "%^BOLD%^%^BLACK%^You can feel a chill enter your bones as you gaze "
                   "%^BOLD%^%^BLACK%^into the folds of Death's shrouded form.",
        "plaque" : "%^BOLD%^%^BLACK%^Death himself ordered this visage of himself to"
                   "%^BOLD%^%^BLACK%^ remind the people of Purgatory of who brought them all here.",
      ]) );

 
}

void reset() {
 ::reset();
  if (!present("guard", this_object()))
    new(MOBS"skeleton.c" )->move(this_object());
}

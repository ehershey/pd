#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Purgatory26");
     set_short("Purgatory26");
     set_long("%^BOLD%^%^BLACK%^An old beaten path\n"
"%^BOLD%^%^WHITE%^This path follows the aged and beaten walls to the castle, "
"%^BOLD%^%^WHITE%^rats and other predators sometime prowl around here. ");
     set_night_long("%^BOLD%^%^BLACK%^An old beaten path\n"
"%^BOLD%^%^WHITE%^This path follows the aged and beaten walls to the castle, "
"%^BOLD%^%^WHITE%^rats and other predators sometime prowl around here. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["east" : ROOMS"purgatory25", 
              "west" : ROOMS"purgatory27"]) );



}

void reset() {
 ::reset();
  if (!present("rat", this_object()))
    new(MOBS"rat" )->move(this_object());

 if (!present("rat 2", this_object()))
    new(MOBS"rat" )->move(this_object());

 if (!present("rat 3", this_object()))
    new(MOBS"rat" )->move(this_object());

 if (!present("rat 4", this_object()))
    new(MOBS"rat" )->move(this_object());
}

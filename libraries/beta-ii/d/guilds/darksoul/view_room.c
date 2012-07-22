#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
     set_name("Viewing Room");
     set_short("Viewing Room");
     set_long("%^BOLD%^%^BLACK%^The Pool.\n"
"%^BOLD%^%^BLACK%^Hidden deep within the Hall lies a room with mystical "
"%^BOLD%^%^BLACK%^properities that have been pried from the minds of tortured "
"%^BOLD%^%^BLACK%^demons. %^RED%^Bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ trickles down the walls and from the ceiling to "
"%^BOLD%^%^BLACK%^gather in a pool carved into the ground. ");
   set_properties(([
     "light":2, "night light":2, "no attack":1, "no magic":1, 
     "no bump":1, "no steal":1, "indoors":1, "no teleport":1,
     ]));

 set_exits( (["up" : ROOMS"darksoul/dungeon"]) );
    set_items( ([
        "wall"  : "%^BOLD%^%^WHITE%^Empty eyed skulls streaked with %^BOLD%^%^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^WHITE%^ stare back at you and fleshless hands wave to you from their places in the walls.",
        "ceiling" : "%^BOLD%^%^WHITE%^Streaked with %^BOLD%^%^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^WHITE%^ the bones of the dead seem to cave inward twards you.",
        "blood" : "%^BOLD%^%^BLACK%^Running rivers of %^BOLD%^%^RED%^b%^RESET%^%^RED%^lo%^BOLD%^%^RED%^od%^BOLD%^%^BLACK%^ flow from the walls and ceiling to form a huge pool in the middle of the room."
      ]) );
}
void reset() {
 ::reset();
  if (!present("pool", this_object()))
    new("/d/guilds/common/obj/scry_pool.c")->move(this_object());
}
#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
::create();
    set_properties(([
        "light":1,
        "night light":1,
        "no teleport":1,
        "no kill":1,
        "no bump":1,
        "no steal":1,
        "indoors":1,
      ]));
    set_short("Bow of the Black Trident");
 set_long(
"%^BLACK%^BOLD%^A small cramped space the bow is. Inside lives the ship's wizard. His many trinkets and potions lie about in a cluttered mess. Bubbling nearby is a large cauldron, filled to the brim with the wizard's famous '%^RESET%^%^ORANGE%^Healing Grog%^BOLD%^%^BLACK%^'. A pile of empty bottles litter the floor, ready to be filled....for a fee of course. Opposite the cauldron is a large pile of %^ORANGE%^gold dubloons%^BLACK%^. One side features a bastet's skull and the other crossed scimitars. The pile of dubloons radiates with magical energy.%^RESET%^"
    );
set_night_long(
"%^BLACK%^BOLD%^A small cramped space the bow is. Inside lives the ship's wizard. His many trinkets and potions lie about in a cluttered mess. Bubbling nearby is a large cauldron, filled to the brim with the wizard's famous '%^RESET%^%^ORANGE%^Healing Grog%^BOLD%^%^BLACK%^'. A pile of empty bottles litter the floor, ready to be filled....for a fee of course. Opposite the cauldron is a large pile of %^ORANGE%^gold dubloons%^BLACK%^. One side features a bastet's skull and the other crossed scimitars. The pile of dubloons radiates with magical energy.%^RESET%^"
);
    set_items(([
        "cauldron" : "Even the smell of this stuff gets you a little buzzed.",
         ]));
set_exits( ([
              "east"  :  "/d/guilds/blacksails/treasury.c",
                             ]) );
  set_smell("default", "The strong smell of the Ale fills your lungs.");
    set_listen("default", "The wizard mutters to himself as he flips through his spellbook.");
}
 void reset() {
 ::reset();
 if (!present("robillard", this_object()))
 new("/d/guilds/blacksails/robillard")->move(this_object());
}

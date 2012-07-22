#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^West road of Quixxiol%^RESET%^");
set_day_long("%^YELLOW%^You are on the Western road of Quixxiol heading towards the %^YELLOW%^palace.  You can continue east towards the city square or %^YELLOW%^west towards a large golden gatekeep.  You see large torches %^YELLOW%^mounted upon stakes along the pathway.%^RESET%^");
set_night_long("%^YELLOW%^You are on the Western road of Quixxiol heading towards the %^YELLOW%^palace.  You can continue east towards the city square or %^YELLOW%^west towards a large golden gatekeep.  You notice large %^YELLOW%^torches mounted on stakes leading up to the gatekeep.%^RESET%^");
set_items(([
"houses" : "The houses are made of solid %^BOLD%^YELLOW%^gold%^RESET%^.",
"palace" : "The palace is quite large and like the rest of the city, made completely of gold.  You see four large guard towers shoot into the sky and an even taller tower near the far west end.",
"torches" : "The torches are mounted on wooden stakes standing nearly as tall as a human.  The pathway to the golden gatekeep looks quite uninviting.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"east": GCITY "gcity12.c",
"west": GCITY "gcity16.c",
]));
}

void reset() {
 ::reset();
}

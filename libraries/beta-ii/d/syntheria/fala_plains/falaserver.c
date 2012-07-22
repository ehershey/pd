#include <std.h>
#include <fala_plains.h>

inherit VIRTUALSERVER;

void create() {
   ::create();
     set_how_long(7);

     set_day_sentances(({
       "%^GREEN%^BOLD%^Small patches of green grass dot the landscape.%^RESET%^",
       "%^GREEN%^%^BOLD%^A small, thin pine tree stand here.%^RESET%^",
       "%^GREEN%^%^BOLD%^A small shrub sits here, it looks to have many thorns growing on its stems.%^RESET%^",
       "%^GREEN%^%^BOLD%^A small patch of dirt is here, the grasses of the plain seem to avoid it.%^RESET%^",
       "%^GREEN%^%^BOLD%^Some strange rocks are scattered about, it looks like there may once have been a structure here.%^RESET%^",
       "%^GREEN%^%^BOLD%^A large patch of weeds grows up from the ground, choking off life from the grass near it.%^RESET%^",
       "%^GREEN%^%^BOLD%^The grass of the plains sways in the breeze.%^RESET%^",
       "%^GREEN%^%^BOLD%^Some of the grass seems to have been grazed on recently.%^RESET%^",
       "%^GREEN%^%^BOLD%^Small hills can be seen far off to the east.%^RESET%^",
       "%^GREEN%^%^BOLD%^A tiny bit of water has pooled here, it looks murky.%^RESET%^",
       "%^GREEN%^%^BOLD%^A patch of yellow flowers blooms here, they sway with the grass.%^RESET%^",
       "%^GREEN%^%^BOLD%^A tall Prairie Sumac stands here, it reaches high into the sky.%^RESET%^",
       "%^GREEN%^%^BOLD%^A strange haze covers the plains, it moves with the breeze.%^RESET%^",
       "%^GREEN%^%^BOLD%^Some grey dirt swells up here creating a small mound.%^RESET%^",
                }));

     set_night_sentances(({
        "%^GREEN%^The plain stretches off into all directions.%^RESET^",
        "%^GREEN%^Small patches of green grass dot as far as the eye can see.%^RESET%^",
        "%^GREEN%^The grass of the plains sways in the breeze.%^RESET%^",
        "%^GREEN%^A tall Prairie Sumac stands here, it reaches high into the sky.%^RESET%^",
        "%^GREEN%^A tiny bit of water has pooled here, it looks murky.%^RESET%^",
        "%^GREEN%^A small patch of dirt is here, the grasses of the plain seem to avoid it.%^RESET%^",
        "%^GREEN%^Some of the grass seems to have been grazed on recently.%^RESET%^",
        "%^GREEN%^A large patch of weeds grows up from the ground, choking off life from the grass near it.%^RESET%^",
                }));

     set_item_list(([
        "sumac"     : "A tall, thin tree with strange reddish berries growing on it.",
        "grass"     : "Short green patches of grass that grow across the plains.",
        "pine tree" : "A small pine tree with many pointy needles.",
        "shrub"     : "A thorny short shrub common to the Fala Plains.",
        "dirt"      : "Some dirt that nothing is growing in, perhaps something is wrong with it.",
        "rocks"     : "Some rocks that looked like they once belonged to a structure, perhaps a small house.",
        "weeds"     : "Some tall and ungly weeds, they starve the grass and kill it.",
        "hills"     : "The hills look very short, but very far away.",
        "water"     : "Some water from a recent rain shower, it is very murky.",
        "flowers"   : "Tiny plants with yellow flowering blooms, they can be seen in all directions",
        "haze"      : "A light haze that coveres the plains.",
                ]));

     set_smell("The air is fresh and clean.");
     set_listen("Grass rustles in the breeze.");

  set_reset_list( ({

  }) );

     set_properties(([ "light"          : 1,
                       "plain"          : 1,
                       "night light"    : 0
                   ]));
  set_short("Fala Plains");
}

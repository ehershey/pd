#include <std.h>
#include <vplain.h>

inherit VIRTUALSERVER;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1 ]) );
  set_short("a wide plain");
  set_day_sentances( ({
    "The plain stretches out in all directions.",
    "Small shrubs are growing here and there.",
    "The ground here is a little bit rocky.",
    "Thick, yellow grass grows nearly everywhere.",
    "A shallow depression has saved a little bit of water from the last rain.",
    "Some birds are flying in a formation far overhead.",
    "A patch of bare earth peeks out from the grass.",
    "A few tall trees can be seen off in the distance.",
    "The horizon is clearly visible just above the gently rolling plains.",
    "Many flowers are blooming all around.",
    "Some dry cattails stick up out of the grass.",
    "A tiny animal disturbs the grasses as it darts away."
  }) );
  set_item_list( ([
    ({"plain","plains"}) : "A wide plain with not much to see besides grass.",
    "shrubs" : "Short, scrubby plants that offer a little green to the landscape.",
    ({"ground","earth"}) : "Brown and hard, it seems to be enough for the grass.",
    ({"grass","grasses"}) : "Long ago it might once have been a vibrant green, now it looks dry and yellow.",
    "depression" : "Nothing more than a dent in the earth where a bit of water sits.",
    "water" : "Stagnant, but clear. Probably left over from the last rain.",
    ({"birds","formation"}) : "The birds make a giant V in the sky.",
    "trees" : "They're hard to see from here but it might be a forest.",
    "horizon" : "The seperation between earth and sky.",
    "flowers" : "Small white wildflowers.",
    "cattails" : "Dry and prickly plants that are eager to stick into fabric or fur.",
    "animal" : "It is already gone."
  ]) );
  set_listen("The grass blows gently in the wind.");
  set_reset_list( ({
    MOBS "hare", MOBS "hare", MOBS "hare",
    MOBS "fox", MOBS "fox", MOBS "fox",
    MOBS "weimic", MOBS "weimic",
    MOBS "goblin", MOBS "goblin",
    MOBS "nymph"
  }) );
  set_how_long(5);
}

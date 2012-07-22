#include <std.h>
#include <vplain.h>

inherit VIRTUALSERVER;

void create() {
  ::create();
  set_properties( ([ "light" : 1, "night light" : 0, "forest" : 1 ]) );
  set_short("a dense forest");
  set_day_sentances( ({
    "Trees tower over you in all directions.",
    "A squirrel scurries up a tree trunk nearby.",
    "There are many short shrubs growing between the trees.",
    "A fallen tree is lying here rotting.",
    "Stray leaves rustle and then drift down from overhead.",
    "A single beam of sunlight manages to get through the foliage here.",
    "The ground is littered with leaves, mosses and an occaisonal stone.",
    "Many tiny insects flit through the air.",
    "The land all around is very flat.",
    "A large flat rock pokes out of the ground.",
    "A bird can be seen gliding in the sky directly above you."
  }) );
  set_night_sentances( ({
    "Trees tower over you in all directions.",
    "Something scurries up a tree trunk nearby.",
    "There are many short shrubs growing between the trees.",
    "A fallen tree is lying here rotting.",
    "Stray leaves rustle and then drift down from overhead.",
    "Moonlight barely manages to get through the foliage here.",
    "The ground is littered with leaves, mosses and an occaisonal stone.",
    "Many tiny insects flit through the air.",
    "The land all around is very flat.",
    "A large flat rock pokes out of the ground.",
    "An owl flies between the trees directly above you."
  }) );
  set_item_list( ([
    ({"tree","trees"}) : "Very tall and with thick leaves, more trees "
      "are visible as far as the eye can see.",
    ({"squirrel","something"}) : "It's already gone.",
    "trunk" : "The trunk extends about 50 feet upward from the ground "
      "with branches starting halfway up.",
    "shrubs" : "Small scrubby plants similar to the ones on the plains, "
      "but these are green and look healthier.",
    ({"leaves","foliage"}) : "Thick, green, and roughly diamond-shaped leaves.",
    ({"sunlight","moonlight","light"}) : "Not much light gets down here.",
    ({"land","ground"}) : "A lot of leaves and moss cover the rich black "
      "earth of the forest.",
    ({"mosses","moss"}) : "Green webs that grow across the ground and trees.",
    "stone" : "Mostly pebble-sized, a few stones are scattered here "
      "and there on the ground.",
    "insects" : "Mosquitos, gnats, and other bothersome things buzz quietly "
      "around the air.",
    "rock" : "Long, flat, and low to the ground. A good resting place.",
    "bird" : "It's way up there and very hard to see clearly.",
    "owl" : "The owl is gone before you can get a clear look."
  ]) );
  set_listen("Only an occaisonal rustling of leaves breaks the silence.");
  set_smell("The scent of rich soil and many trees is everywhere.");
  set_reset_list( ({
    MOBS "hog",
    MOBS "fhare",
    MOBS "fox",
    MOBS "fweimic",
    MOBS "goblin",
    MOBS "nymph"
  }) );
  set_how_long(5);
}

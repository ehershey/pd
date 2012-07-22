#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "forest" : 1, "light" : 2, "night light" : 1]) );
  set_smell("default", "The smells of vanilla and sap merge together here and please your olfactory senses.");
  set_short("%^GREEN%^Forest%^RESET%^");
  set_long("The path slides east from here. A few of the trees have been chopped down, leaving only stumps in their place. The remaining trees are still fairly tall. The forest seems to thin out even more as the numbers of stumps increase to the east.");
  set_night_long("The fairly large trees cast a shadow over the ground, causing the path to disappear at certain points. There are a few stumps of trees laying around as the forest starts to thin out. It looks as if someone has recently made this place their own. To the east the trees thin out even more.");
  set_items(([
    "tree" : "This tree is fairly tall.",
    "stump" : "This stump used to be a tree, now it just sits there, dead.",
    "trees" : "They are starting to thin out.",
    "stumps" : "They increase in number to the east.",
    "path" : "It gently leads east.",
   ]));
  set_exits(([
      "west" : "/d/shadow/rooms/thirtythree", // shadow.h for tene uses ROOMS too, blah
    "east" : ROOMS"farm1"
   ]));
}

#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

static int bell = 1;

string query_day_long() {
   if (bell)
    return "The bright daylight and splendor of the stained glass "
     "windows are nothing compared to the beautiful light greenish light "
     "further up this central spire of the temple. This spire is a single "
     "tower in the center of the temple that reaches higher than even the "
     "turrets and lower than the temple floor. A dim green light fills "
     "the room. In the center of the room, the ground is wooden instead "
     "of stone. The wood is a large circle, probably a holy symbol of this "
     "temple.";
   else
    return "The bright daylight and splendor of the stained glass "
     "windows are nothing compared to the beautiful light greenish light "
     "further up this central spire of the temple. This spire is a single "
     "tower in the center of the temple that reaches higher than even the "
     "turrets and lower than the temple floor. A dim green light fills "
     "the room. A gaping hole is in the center of the room. It looks like "
     "something huge ripped a hole in the ground.";

}

void set_bell(int x) { bell = x; }

int query_bell() { return bell; }

string query_night_long() {
   if (bell)
    return "Even during the dark night, this room is filled with a "
      "dim greenish light. The light seems to be comming down from higher "
      "up this central spire. The spire is a tower in the center of the "
      "temple that reaches higher than the turrets and lower than the "
      "temple ground. Dim green light fills this place. In the center of "
      "room is an area that is wooden instead of stone. The wood part of "
      "the ground is a large circle, a symbol of some sort.";
   else
    return "Even during the dark night, this room is filled with a "
      "dim greenish light. The light seems to be comming down from higher "
      "up this central spire. The spire is a tower in the center of the "
      "temple that reaches higher than the turrets and lower than the "
      "temple ground. Dim green light fills this place.";

}

string query_long(string str) { if (str) return ::query_long(str);
                      if (query_night()) return query_night_long();
                      else return query_day_long(); }

void create() {
 ::create();
   set_short("Ground floor of the center spire of the temple");
   set_items(([
     "light" : "Dim green light gives the same lighting to this room day "
               "and night.",
     "wood"  : "It is a wooden circle in the center of the floor. Not at "
               "all as strong as the stone around it.",
     "floor" : "It is stone except for the wood in the center... How odd.",
     "spire" : "Both higher and lower than any other part of the temple."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "indoors" : 1 ]));
   set_exits(([
     "north" : ROOMS"l1m2",
     "up"    : ROOMS"l2m5"
   ]));
}

void reset() {
 ::reset();
   set_search("wood", "A blow of great strength would smash right through "
                      "the wood. How odd that it is here.");
}

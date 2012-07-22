/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

int gloves_routine();
void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));

  set_listen("default","You hear a faint hum coming from nearby.");
  set_listen("hum", "The humming is coming from a hatch hidden in the floor of the wardrobe.");

  set_smell("default","The smell of mold is strong here. An odd chemical smell accompanies it.");
  set_smell( ({ "chemical","chemicals" }),"The smells of iodine and chlorine are coming from a panel in the back of the wardrobe.");

  set_long(
   "This appears to be the captain's clothes closet."
   " Most of the clothes seem to be intact thanks to a magical barrier upon the wardrobe."
   " Several suits of armor line the wardrobe bearing the seal of Trydryill."
   " A couple of magical robes are here as well."
   " Several pairs of gloves line the bottom of the closet."
   "\n\nSomething doesn't seem right here..."
  );

  add_invis_exit("hatch");
  add_invis_exit("panel");
  set_exits(([
    "panel":ROOMS2"secret-6c.c",
    "hatch":ROOMS2"secret-6d.c",
    "out":ROOMS2"secret-6a.c"
   ]));
  set_items(([
    "gloves": (: gloves_routine :),
    "clothes":"Most of the clothes are fairly simple in design. Apparently either the captain had simple tastes or wasn't paid very well.",
    "armor":"These are the official armor of Trydryill's armed forces, naval division.",
    "seal":"The seal bears the mark of a half-dragon, half-lich wearing a Mage's Cloak. This must be what a dracolich looks like.",
    "robes":"The official robes of the dracolich's necromancers."
   ]));
  new(PEARLS"star_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}

int gloves_routine() {
  object dart=new(TRIVIA"probe.c");
  object TP=this_player();
  object TR=environment(TP);
  object prize;
  string cap_tp=TP->query_cap_name();
  string sex_tp=TP->query_possessive();
  string pname=TP->query_name();
  int index=150;
  int score;
  //
  // index set @ 2 for testing
  //

  load_object(ROOMS2"secret-5.c");
  dart->move(ROOMS2"secret-5.c");
  score=(environment(dart)->score_check(pname));
  dart->remove();

  if( score < index ) {
    message("info",
     "Several moldy, decaying gloves line the bottom of the closet."
     ,TP);
    return 1;
  }
  else {
    message("info",
     "You find a pair of gloves that still look useable."
     ,TP);
    message("info",
     cap_tp+" finds a pair of useable gloves."
     ,TR,TP);
    prize = new(PRIZES"valor_gloves.c");
    if (prize->move(TP)) prize->move(TR);
    TP->set_property("gloves-of-valor",1);
    return 1;
  }
}

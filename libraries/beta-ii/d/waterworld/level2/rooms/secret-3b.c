/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

int helmet_routine();

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_listen("default","You hear Pelican Pete mixing drinks from some place about this room.");
  set_listen("hum","The hum is coming out of a trapdoor that has been built into the bedrock in the corner of the cave!");
  set_short("Pelican Pete's Living Room");
  set_smell("default","It smells like wet feathers here.");
  set_long("This cave in the bedrock seems to be directly under Pelican Pete's place."
   " There are several perches located throughout the room."
   " On one side of the cave is a looking glass."
   " There is a coffee table here with a copy of 'Pelican Digest' on it, open to a page about daiquiris."
   " It is quite ovious that this is Pelican Pete's pad."
  );
  add_invis_exit("trapdoor");
  set_exits(([
    "trapdoor":ROOMS2"secret-3c.c",
    "up":ROOMS1"room-1d4.c"
   ]));
  set_items(([
    "coffee table": (: helmet_routine :),
    "looking glass":"It's a magical mirror that allows Pete to see whomever he wishs.",
    "pelican digest":"The recipe for daiquiris is quite thorough.",
    "perches":"Several sticks with cross beams for birds to land on.",
    "bedrock":"There is a strange hum originating from some place in the corner of this room."
   ]));
  new(PEARLS"star_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
int helmet_routine() {
  object dart=new(TRIVIA"probe.c");
  object TP=this_player();
  object TR=environment(TP);
  object prize;
  string cap_tp=TP->query_cap_name();
  string pname=TP->query_name();
  int score;
  int index=125;
  //
  //  index set to 2 for testing purposes
  //    index = 125 when installed into live site.
  //

	 load_object(ROOMS2"secret-5.c");
  dart->move(ROOMS2"secret-5.c");
  score=(environment(dart)->score_check(pname));
  dart->remove();

  if(score<index) {
    message("info","Several pieces of literature litter the coffee table.",TP);
    return 1;
  }
  else if(score >= index) {
    message("info","\n\nThe Helm of Honor sits regally in the center of the coffee table."
     "\nIt glows at your approach, then flies into your hands!"
     ,TP);
    message("info","\n\n"+cap_tp+" has found the %^ORANGE%^Helm of Honor%^RESET%^ on the coffee table!"
     ,TR,TP);
    prize = new(PRIZES"helm-of-honor.c");
    if (prize->move(TP)) prize->move(TR);
    TP->set_property("helm-of-honor",1);
    TP->force_me("save");
    return 1;
  }
}

/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

int bracer_routine();
void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_smell("default", "A faint smell of rot lingers in the air.");
  set_long(
   "This seems to be the waste disposal system for the ship."
   " Skeletons are piled upon one another about four feet high."
   " There doesn't seem to be much here other than rags and bones, the remains of the lich's unfortunate victims."
  );

  set_exits(([
    "out":ROOMS2"secret-6b.c"
   ]));
  set_items(([
    "skeletons": (: bracer_routine :)
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}

int bracer_routine() {
  object dart=new(TRIVIA"probe.c");
  object TP=this_player();
  object prize;
  string pname=TP->query_name();
  int index=100;
  int score;

  load_object(ROOMS2"secret-5.c");
  dart->move(ROOMS2"secret-5.c");

  score=(environment(dart)->score_check(pname));
  dart->remove();
  if(score>=2) {
    message("info","You find a set of glowing bracers amongst the skeletons!", TP);
    message("info",TP->query_cap_name()+" finds something.", environment(TP), TP);
    prize = new(PRIZES"spirit_bracer.c");
    if (prize->move(TP)) prize->move(environment(TP));
    TP->set_property("spirit_bracer",1);
    TP->force_me("save");
    return 1;
  }
  else {
    message("info","Just a pile of rotting bones.", TP);
    return 1;
  }

}

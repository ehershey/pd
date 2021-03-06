// item file for waterworld - level 2- tirun reef
//      by ironman

#include <std.h>
#include <rooms.h>
#include <waterworld.h>

inherit OBJECT;

object tp,ob,monster;
void fish_loader();


void create() {
  ::create();
  set_name("angler lure");
  set_id(({"angler lure","ironman angler lure","lure","light","appendage"}));
  set_short("a %^YELLOW%^glowing light%^MAGENTA%^ dangles near the coral");
  set_long( (: fish_loader :) );
  set_weight(1);
  set_curr_value("copper",1);
  set_prevent_get("It moves too fast to grab it.");
  if (clonep())
    set_heart_beat(1);
}

void fish_loader() {
  tp=this_player();
  ob=this_object();

  message("info","A very HUNGRY angler fish charges at you!",tp);
  message("info","A very HUNGRY angler fish charges at "+(tp->query_cap_name())+"!",environment(tp),tp);

  monster=new(MOB2"angler_fish.c");
  monster->move(environment(tp));
  monster->force_me("kill "+(tp->query_name()));
  monster->kill_ob(tp);
  this_object()->move(ROOM_CACHE);
  set_heart_beat(0);
  call_out("remove", 0);

}

void heart_beat() {

  int odds;

  odds=random(100);

  if(odds<=2) {
    message("info","%^MAGENTA%^The %^YELLOW%^light%^MAGENTA%^ wiggles slightly in the darkness.",environment(this_object()) );
  }
}

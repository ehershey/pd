#include <std.h>
#include <tirun.h>
inherit "/std/police.c";
 
int test_heart;
 
void create()
{
 ::create();
  set_name("patrol guard");
  set_id( ({"patrol guard", "guard", "town guard" }) );
  set_short("A patrol guard");
  set_long("A member of the town guard that patrols the area.");
  set_race("human");
  set_gender("male");
  set_body_type("human");
  set_level(30);
  set_max_hp(2000);
  set_hp(2000);
  set_heart_beat(1);
  set_property("no attack", 1);
  set_patrol(3, ({ "north", "north", "northeast", "east", "east", "east", "east",
                   "east", "south", "south", "south", "south", "south",
                   "southwest", "west", "west", "west", "west", "west",
                   "north", "north", "north" }) );
  new(WEP"bclub")->move(this_object());
  command("wield club");
}
 
int test_heart() { 
    if(!heart_beat_on) set_heart_beat(heart_beat_on = 1);
 return 1; 
}

#include <std.h>
#include <shadow.h>
inherit ROOM;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","Alley");
  set("long","This is a small alley in the south west part of town.  "
    "There is a half way collapsed house here to the north.  "
    "The road here abruptly ends in a wall to the east.");
  set_smell("default","The air here is dry and musty.");
  set_listen("default","The silence here is oppressive.");
  set_items((["sky":"The sky is dark as ever.","road":"The cobblestone road heads west.",
    "house":"The house here has collapsed half way.  The rubble here is piled up.",
    "rubble":"The rubble slopes up towards the roof.  Perhaps you could climb it.",
    "wall":"The wall here blocks the path east.",
    "stone":"The cobblestones are black and grey.  Like the sky."]));
  set_exits((["west":ROOMS "tene05.c"]));
}

void init() {
  ::init();
  add_action("climb_it","climb");
}

int climb_it(string str) {
  if(!str) {
    notify_fail("Climb what?\n");
    return 0;
  }
  if(str != "rubble") {
    notify_fail("You can't climb that!\n");
    return 0;
  }
  else {
    if(this_player()->query_stats("dexterity") < 30){
       say(this_player()->query_cap_name()+" tries to climb up, but falls on his butt.",this_player());
       notify_fail("You try to climb the wall but slip down due to lack of dexterity.\n");
       this_player()->add_hp(-5);
       return 0;}
    else {
    this_player()->move_player(ROOMS "roof01.c", "climbs the rubble.");
    return 1;}
  }

}

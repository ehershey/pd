#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "water" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^You are under the surface of the water, near the ground. You can see the path below you running west and east, but the path has been beaten up by the water. There are some seaweed plants scattered along the ground.");
  set_night_long("%^BLUE%^The light from the moon shines gently down into the river. It is very calming under the water at night. A few seaweed plants are scattered around here and there on the ground. It is possible to go up out of the water here. Moonlight casts gentle, wavering shadows upon the path below you.");
  set_items(([
    "path" : "There appears to be a small hole in the middle of the path.",
    "hole" : "The water just rushes right past it, not much water is actually going through it. You may be able to swim down into it.",
    "seaweed" : "They are scattered all around on the ground.",
    "water" : "It is all around.",
    "river" : "You are swimming in it."
   ]));
  set_smell("default", "The water plugs up your nose.");
  set_exits(([
    "up" : ROOMS"farm22"
   ]));
  add_pre_exit_function("up", "go_up");
}
int go_up() {
  object waterobject = present("uwtrb", this_player());
  if(this_player()->query_subclass() == "blue") {
    write("You fly out of the water.");
    tell_room(environment(this_player()), this_player()->query_name()+", glides out of the water.", ({ this_player() }));
    if(waterobject) waterobject->remove();
    return 1;
  }
  else {
    write("Why don't you <surface> instead?");
    return 0;
  }
}

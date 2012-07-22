#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 0);
   set_short("Below Melissa Praxis' coffin");
   set_long("The cold and damp air seems as though it is "
            "trying to suffocate you in this horrible place. "
            "The soil is so thick down here that noone could "
            "possibly hear you shout. It is too dark to make "
            "out where you are.");
   set_items(
	(["hole" : "It is barely big enough for you to fit into.",
	  "soil" : "The cold, black soil is so thick, it could muffle "
                   "any scream.",
          "air" : "Cold and damp, it adds an eerie feel to the area.",
          "dirt" : "A horrible fealing comes over you.",
          "under" : "You are six feet under.",
	  "grave" : "The grave is horribly empty and sad."]));
    set_exits(([
                "up" : ROOMS"cemetary/coffin1",
                "east" : ROOMS"cemetary/coffin2",
                "north" : ROOMS"cemetary/coffin2",
                "northwest" : ROOMS"cemetary/coffin2",
                "southwest" : ROOMS"cemetary/coffin2",
                "southeast" : ROOMS"cemetary/coffin2",
                "northeast" : ROOMS"cemetary/coffin2",
                "west" : ROOMS"cemetary/coffin3" ]));
   set_invis_exits(({ "east", "north", "northwest", "southwest",
            "southeast", "northeast", "west" }));
}

int blocked() {
   write("You are far too disoriented to do that.");
   return 1;
}

int muffle() {
   write("Your screams are muffled by the thick soil!");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
      "'s screams are muffled by the thick soil!", ({ this_player() }));
   return 1;
}

void init() {
 ::init();
   add_action("blocked", "peer");
   add_action("blocked", "survey");
   add_action("muffle", "shout");
   add_action("muffle", "scream");
}

void reset() {
 ::reset();
   if (!present("zombie"))
      new(ROOMS"cemetary/mon/zombie1")->move(this_object());
}

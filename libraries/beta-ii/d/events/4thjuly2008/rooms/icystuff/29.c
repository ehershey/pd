#include <std.h>
#include <id4.h>
#include <dragonevent.h>

inherit ROOM;

mixed search_bones(string);
string look_bones(string);

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a fresh and frozen smell to it.");
set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
set_short("venturing through icy tunnels");
set_long("The icy tunnels slip through many directions, sliding to nowhere. The air is composed of a fresh mixture of %^BOLD%^cold%^RESET%^ and clean. Flakes of %^BOLD%^snow%^RESET%^ float through the air, sticking to any dry surfaces. There is a large torch hanging on the wall, burning through the %^BOLD%^%^CYAN%^ice%^RESET%^ and showing gravel. An %^BOLD%^%^CYAN%^icy%^RESET%^ pile of bones shivers lazily between two frozen rocks.");
set_items(([
"bones" : (: look_bones :),
"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
"snow" : "The ground is covered in a thin layer of snow..",
"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
]));
set_exits(([ "north" : ROOMS "/icystuff/27.c"]));
}

string look_bones(string str) {
  if (functionp(query_search("bones"))) return "Something shines out from the pile of bones.";
  else return "Just an old skeleton.";
}

mixed search_bones(string str) {
  object tp = this_player();
  object env = this_object();
  object gem;
  remove_search("bones");
  gem = load_object(DRAG_ITEMS+"bluegem");
  if (gem->move(tp)) gem->move(env);
  message("search", "You find a blue gem!", tp);
  message("search", tp->query_cap_name()+" finds a blue gem!", env, tp);
  if (DRAG_D->query_data("canfindbluegem") == 1) {
    DRAG_D->set_data("canfindbluegem", 0);
    DRAG_D->set_data("winnerfoundbluegem", tp->query_name());
    tp->set_stats("wisdom", tp->query_base_stats("wisdom")+1);
    tp->set_stats("dexterity", tp->query_base_stats("dexterity")+1);
    tp->add_exp(100000);
    message("magic", "%^BOLD%^%^BLUE%^The gem pulses softly.", env);
    message("magic", "%^BOLD%^%^BLUE%^The gem's magic strengthens your will.", tp);
  }
}

void reset() {
  ::reset();
  if (!sizeof(children(DRAG_ITEMS+"bluegem"))) set_search("bones", (: search_bones :) );
}

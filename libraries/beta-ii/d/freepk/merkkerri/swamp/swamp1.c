#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
    ::create();
    set_short("Entrance to the Merkkirri Swamp");
    set_day_long("The sweltering jungle has now given way to the dark and murky swamps of Merkkirri.  Dangerous creatures inhabit this region making sure that those who enter must be careful if they expect to leave.  The plantlife here is extremely lush and strange noises fill the area.  Even during the daylight hours, the swamp remains dark from the thick tree leaves above.");
    set_night_long("The sweltering jungle has now given way to the dark and murky swamps of Merkkirri.  Dangerous creatures inhabit this region making sure that those who enter must be careful if they expect to leave.  The plantlife here is extrememly lush and strange noises fill the area.  During the twilight hours the jungle is most haunting as very little light enters the region.");
    set_property("swamp",1);
    set_items(([
	"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"bugs" : "Insects float around you waiting for a moment to take a bite.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"northwest": MJUNGLE "mjungle39.c",
"east": SWAMP "swamp3.c",
"south":SWAMP "swamp2.c",
])); 
    add_pre_exit_function("northwest", "go_northwest");
}
void reset() {
::reset(); 
ghast = random(100);
if ((ghast) > 93) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 97) { new(MOB "ghast")->move(this_object()); }
 }
}
}
int go_northwest() {
  if(!this_player()->is_player()) return 0;
  return 1;
}

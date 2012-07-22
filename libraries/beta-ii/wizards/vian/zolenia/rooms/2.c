#include <std.h>
#include <zolenia.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 4, "night light" : 4, "indoors" : 1]) );
set_smell("default", "A strong, earthy smell fills the air");
set_listen("default", "Small rocks can be heard falling toward the ground.");
set_short("climbing down the rocky slope");
set_long("Although the fall from above was quite far, the cliffs still go farther than you can see.  The standing point above can't quite be seen, and there doesn't appear to be a way to get back up.  Perhaps a few more jumps down will resolve in solid ground.");
set_items(([
({"rock", "rocks"}) : "Although many rocks are sharp and jagged, there are plenty of flat ones to aide climbing down..",
]));
set_exits(([ "down" : ROOMS "3.c"]));
}
void reset() {
    ::reset();
    if(!present("burningrat"))
        new(MOB"burningrat")->move(this_object());
        new(MOB"burningrat")->move(this_object());
    if(!present("laughingrat"))
        new(MOB"laughingrat")->move(this_object());
        new(MOB"laughingrat")->move(this_object());
}
void init() {
  ::init();
   if (this_player()->is_player()) {
   write("You fall to the ground quite painfully.. the jump was higher than it looked.");
   say("It looks like "+this_player()->query_cap_name()+" didn't know how far down the jump was.");
   this_player()->add_hp(-random(200));
}
}

#include <std.h>
#include <zolenia.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 4, "night light" : 4, "indoors" : 1]) );
set_smell("default", "A strong, earthy smell fills the air");
set_listen("default", "Small rocks can be heard falling toward the ground.");
set_short("climbing down the rocky slope");
set_long("It appears as if the ground is finally stable, although definitely not flat.  Rocky cliffs surround your ledge, falling a shorter distance than before to what appears to be some stable ground.  This ledge, strangely, is made of some sort of crystal, a change from the constant onyx.");
set_items(([
({"rock", "rocks"}) : "Although many rocks are sharp and jagged, there are plenty of flat ones to aide climbing down..",
]));
set_exits(([ "down" : ROOMS "4.c"]));
}
void reset() {
    ::reset();
    if(!present("unicorn"))
        new(MOB"unicorn")->move(this_object());
}
void init() {
  ::init();
   if (this_player()->is_player()) {
   write("You fall to the ground quite painfully.. the jump was higher than it looked.");
   say(""+this_player()->query_cap_name()+" falls from above, landing with a loud thud.");
   this_player()->add_hp(-random(150));
 }
}

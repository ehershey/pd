//Valleyman
#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "forest" : 1, ]));
set_short("Farm");
set_day_long("The paddock is large and full of green grass, and a lone bull can be seen to the wandering around, occasionally stopping to drink from a water hole to the south. A forest can be seen surrounding the property and many different birds can be seen. The paddock continues on to the south and west and a small gate leading out is to the north.");
set_night_long("The paddock is illuminated by the faint moonlight. This paddock appears to be empty bar for a lone bull wandering around occasionally stopping to drink from a water hole to the south. A dark forest can be seen surrounding the property and faint lights can be seen to the northeast.");
     
   set_items(([
                ({"gate" , "gates"}) : "The gate is old and made out of the same wood as the forest. It is latched closed to stop the animals from getting out.",
                ({"bird" , "birds"}) : "There are many different species of birds flying in and out of the surrounding forest.",     
           "forest"   : "The forest is full of swaying trees, and a few stumps can be seen around the edge",
                ]));
    set_listen("default", "The sound of trees leaves rustling in the wind can be heard.");
        set_exits(([
"gate" : ROOMS"pathw.c",
"west" : ROOMS"paddockw2.c",
"south" : ROOMS"paddockw3.c",
"southwest" : ROOMS"paddockw4.c",
                ]));
add_pre_exit_function("gate", "go_gate");
}

int go_gate() {
  if(!this_player()->is_player()) return 0;
  return 1;
}


#include <std.h>
#include <lidelas.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("feng avenue");
        set_short("Feng avenue");
        set_long("Feng avenue bisects Lidelas, splitting the town into the north and south ends. Feng avenue ends here, and only goes to the east, it leads right into a house. The avenue is made of very fine cobble stone, each stone looks almost new. Many large buildings line the street, the common theme between them all is that every one of them has ornate sculptures of gargoyles at points all over the buildings. All of the gargoyles seem to have been made to face the street, so that they may look onto anyone who passes by. Every building has many arched windows, above every window is a sharp point that eventually leads to a sharp tower.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
        "gargoyles"    :  "They are not very large, and seem to be carved into the building."
            ]));
            set_listen("default", "The sound of carts moving on the stone steets can be heard in all directions.");


            set_smell("default", "The odor of horse manure fills the air.");
            set_exits(([
                        "east"          : ROOMS "lidelas030.c",
                        "south"         : ROOMS "lidelas034.c",
                        "enter"     : ROOMS "lidelasHouse3.c",
        ]));
        add_pre_exit_function("enter", "go_enter");
}

int go_enter() {
  if(!this_player()->is_player()) return 0;
  return 1;
}

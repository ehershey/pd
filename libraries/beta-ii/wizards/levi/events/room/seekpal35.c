#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The Inner Temple");
    set_long("A narrow and long staircase rests to the north, leading up to a room that brilliant light spills "
        "out from.  Each step is made of a petrified wood that dim light shines through.  A great fire burns to "
        "the south.");
    
    set_items(([
          "staircase" : "The staircase is quite long but narrow.",
          "steps" : "The steps are made of petrified wood and a dim light shines through them.",
          "fire" : "Raging with life but not out of control, this great fire burns brilliantly to the side of the room.",
                  
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
        "no teleport" : 1,
    ]));
    set_exits(([
        "up" : ROOMS "seekpal36.c",
        "south" : ROOMS "seekpal34.c",
    ]));
set_pre_exit_functions( ({ "up" }), ({ "go_up" }) );
}

int go_up() {
if(present("anavastein")) {
present("anavastein")->force_me("emote is in your way!");
return 0;
}
return 1;
}

void init(){
 ::init();

if(!present("anavastein"))new("/wizards/levi/events/mob/anavastein")->move(this_object());
}

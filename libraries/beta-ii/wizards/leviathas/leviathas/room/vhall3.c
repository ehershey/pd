#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("The room is incredibly bright but the light is artificial.  Ivory pillars hold the ceiling up, reaching extremely high. "
           "There are no visible signs of age in this room other than on the ground, dirty from the passing of many feet. A fountain "
           "trickles out blood to the south and a staircase leads down into the ball room. ");
   
    set_night_long("The room is incredibly bright but the light is artificial.  Ivory pillars hold the ceiling up, reaching extremely high. "
           "There are no visible signs of age in this room other than on the ground, dirty from the passing of many feet. A fountain "
           "trickles out blood to the south and a staircase leads down into the ball room. ");
    
    set_items(([
        "staircase" : "The staircase is quite nice.",
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
        "no teleport" : 1,
        "no attack" : 1,
        "no bump" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "vhall2.c",
        "downstairs" : ROOMS "cainball1.c",
                     
         ]));
set_pre_exit_functions( ({ "downstairs" }), ({ "go_downstairs" }) );
}

int go_downstairs() {
  if (present("guard"))
    if (!present("ballpass", this_player())) {
       present("guard")->force_me("say You have no invitation and are not on the guest list.");
       return 0;
      } else {
       write("You show your invitation card to the guard.");
       present("guard")->force_me("say Alright, you may enter");
    }
  return 1;
}

void reset(){
 ::reset();
 if(!present("guard"))new(MOB "guardofball")->move(this_object());
}

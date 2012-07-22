#include <wiz.h>
inherit ROOM;
object board;

void create() {
 ::create();
   set_properties(([ "light" : 1,  "night light" : 1,  "no steal" : 1,
                     "no bump" : 1, "no magic" : 1, "no castle" : 1,
                     "no attack": 1, "town" : 1, "indoor" : 1
                 ]));
  set_short  ("Arlon Kwik-E Mart");
  set_long   ("This is the Arlon Kwik-E Mart. We are just moving in to our "
              "new location, so many of our delicious snack foods are not here "
              "ye. Please enjoy our %^BOLD%^squishies%^RESET%^ in the meantime.");
  set_exits((["down"  : WIZHOUSE ]));
  set_items((["wall"  : "pretty wall" ]));
}
void reset(){
 ::reset();
    if (!present("apu")){
       new(HOUSEMOB"apu.c")->move(this_object());
     }
    if (!present("squishie machine")){
       new(HOUSEITEM"machine.c")->move(this_object());
     }
}
void init() {::init(); add_action("read_sign", "list"); }

void read_sign(string str){
    message("info", "h0h0! Welcome to the Kwik-E Mart!", this_player());
    message("info", "-----------------------------------------------",
this_player());
    message("info", "1. A Package of Nachos\t\t 71 gold", this_player());
    message("info", "2. A Super Squishie\t\t 37 gold", this_player());
    message("info", "3. A h0h0 Squishie\t\t 50 gold", this_player());
    message("info", "-----------------------------------------------",
this_player());
    message("info", "<buy number> to buy something.", this_player());
}

#include <guild.h>
#include "ether.h"
inherit ETHERSTD;

void create() {
  ::create();
    set_short( "Ethereal Herbal Shop" );
    set_long( "%^BOLD%^%^ORANGE%^Homer's Herbal Shop%^RESET%^\n"
              "%^RESET%^%^ORANGE%^Immense granite shelves reach all the way to the ceiling."
              " A large assortment of herbs and peculiar oddities line the right and left walls."
              " Upon the back wall, however, are many diverse vials of liquid potions."
              " A pudgy man stands behind a counter munching on cakes, waiting to be of service.\n"
               );
    set_items(([ "shelves" : "Large granite shelves which hold objects of a wide variety.",
                 "herbs" : "%^RESET%^%^GREEN%^Potted herbs which StrongBad uses to create some of his many potions and remedies.%^RESET%^",
                 "oddities" : "Obscure objects rest along the walls of this shop.",
                 "vials" : "Vials of liquid.",
                 "sign"  : "\n"
"The sign reads: \n"
"-------------------------------------------------------------- \n"
"[ An arctic orb ] \n"
"    A tiny orb which was enchanted to contain the powers \n"
"    of the  frosty  arctic.  It can be used to replenish \n"
"    mana. ( 20 gold pieces ) \n"
"[ An inferno orb ] \n"
"    A tiny orb which was enchanted to contain the powers \n"
"    of the  fiery  inferno.  It can be used to replenish \n"
"    health. ( 20 gold pieces ) \n\n"
" You can <purchase # [inferno/arctic]> to buy a  specific \n"
" number of orbs. \n"
"-------------------------------------------------------------- \n"
 
         ]));
   set_smell( "default" , "Strange odors seem to rival eachother in the stale air of this room.");
   set_listen( "default" , "Faint gaelic chanting is accompanied with the clashing of glass.");

    set_exits( ([

        "north" :  ROOMS "2-1.c",
    ]) );

}
void reset() {
	if (!present("homer")) {
        	new(MOB"homer")->move(this_object());
	}
}

#include <guild.h>
#include "ether.h"
inherit ETHERSTD;

void create() {
  ::create();
    set_short( "Ethereal Pet Shop" );
    set_long( "%^BOLD%^%^ORANGE%^Trogdor's Pet Shop%^RESET%^%^ORANGE%^\n"
              "It seems as if this room has been enchanted to resemble a tiny forest."
              " Patches of bamboo surround bales of hay all around the room."
              " Giant pandas eat together with a herd of calfs."
              " Cats and rabbits frolic merrily about the scene."
              " A tall dragon stands affront of it all, waiting to be of service.\n"
              " %^BLACK%^.%^RESET%^" );
    set_items(([ "bamboo" : "%^RESET%^%^GREEN%^Patches of bamboo surrounding bales of golden hay.%^RESET%^", 
             "hay" : "%^RESET%^%^ORANGE%^Bales of golden hay.%^RESET%^",
             "pandas" : "%^BOLD%^%^BLACK%^Elite pandas eating their bamboo, waiting to be sold.%^RESET%^",
             "panda" : "%^BOLD%^%^BLACK%^An Elite panda eating its bamboo, waiting to be sold.%^RESET%^",
             "calfs" : "%^BOLD%^%^WHITE%^Cute Baby Cows munching on hay, waiting to be sold.%^RESET%^",
             "calf" : "%^BOLD%^%^WHITE%^A cute Baby Cow munching on some hay, waiting to be sold.%^RESET%^",
             "cats" : "%^BOLD%^%^BLACK%^Cute Council Cats waiting to be sold.%^RESET%^",
             "cat" : "%^BOLD%^%^BLACK%^A cute Council Cat waiting to be sold.%^RESET%^",
             "rabbits" : "%^BOLD%^%^WHITE%^Cute Bunny Rabbits waiting to be sold.%^RESET%^",
             "rabbit" : "%^BOLD%^%^WHITE%^A cute Bunny Rabbit waiting to be sold.%^RESET%^", 
	     "sign"  :  "The sign reads:\n"
		"%^GREEN%^---------------------------------------- \n"
		"           %^GREEN%^%^BOLD%^Trogdor's Pet Shop%^RESET%^ \n"
		"%^GREEN%^---------------------------------------- \n"
		"    %^GREEN%^Shoplifters will be %^BOLD%^BuRNiNaTeD%^RESET%^%^GREEN%^! \n"
		"%^GREEN%^---------------------------------------- \n\n"
		"%^BOLD%^%^GREEN%^Currently in Stock: \n"
		"%^BOLD%^%^GREEN%^Elite Pandas %^RESET%^%^GREEN%^------------------- %^BOLD%^%^GREEN%^1000gps \n"
		"%^BOLD%^%^GREEN%^Council Cats %^RESET%^%^GREEN%^-------------------- %^BOLD%^%^GREEN%^900gps \n"
		"%^BOLD%^%^GREEN%^Bunny Rabbits %^RESET%^%^GREEN%^------------------- %^BOLD%^%^GREEN%^800gps \n"
		"%^BOLD%^%^GREEN%^Baby Cows %^RESET%^%^GREEN%^----------------------- %^BOLD%^%^GREEN%^700gps%^RESET%^ \n\n"
		"%^GREEN%^---------------------------------------- \n"
		"%^GREEN%^     Use %^BOLD%^%^GREEN%^<buy animal>%^RESET%^%^GREEN%^, to purchase. \n"
		"---------------------------------------- \n"
         ]));
   set_smell( "default" , "The stale smell of hay intertwines with the musky odor of the forest.");
   set_listen( "default" , "Cows moo, and cats mew. Who knew?");

    set_exits( ([
        "south" :  ROOMS "2-1.c",
    ]) );

}
void reset() {
	if(!present("trogdor")) {
		new(MOB"trogdor")->move(this_object());
	}
}
 

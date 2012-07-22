#include <std.h>
#include <waterworld.h>
inherit MONSTER;

int profit;
object pearls;
void create()   {
        ::create();
             set_name("heldalogala");
             set_id(({"heldalogala","crab"}));
            set_short("Heldalogala, the not-so-friendly hermit crab");
             set_long("This is Heldalogala, the not-so-friendly hermit crab. He spends his days searching the beaches far and wide collecting Pearls of all descriptions. The rarer the pearl the more he's willing to trade for it.");
             set_level(100);
             set_body_type("fish");
             set_gender("male");
             set_race("crab");
             set_class("fighter");
             set_subclass("warrior");
            set_emotes(3,({
              "Heldalogala digs through the sand with his claws.",
              "Heldalogala snaps his claws at your foot, making you withdraw it instinctively so he can search under the sand in that spot.",
              "Heldalogala looks over a radiant STAR pearl, grins and puts it in his pouch.",
               "Heldalogala mumbles something about a legendary pearl as he frantically searches the beach."
                      }),0);
}
////// Pearl routines
void catch_tell(string recieved) {
            PEARLS"PEARL_SHOP.c"->pearl_reciever(recieved,profit, this_object());
           if(pearls=present("pearl")) {pearls->remove();}
}

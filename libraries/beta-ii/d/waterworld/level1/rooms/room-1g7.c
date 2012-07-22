/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

int profit;
void create()   {
      ::create();
      set_properties(([
                     "water":1,
                      "light":3,"night light":3,
                      "no attack":1,"no magic":1,
                      "no bump":1,"no steal":1
                      ]));
       set_listen("heldalogala about pearls","Heldalogala stops digging for a second and explains, 'There are 7 levels of pearls in all.\nThey are as follows;\n\n white pearl \n black pearl \n blue pearl \n PURPLE pearl \n ROSE Pearl \n STAR pearl\n ??? pearl \n\n The farther down the list you come the rarer the find and the more money im willing to pay you for it!!"
       "\nThe ??? pearl is a total mystery to me. It has only been located twice in all of recorded history!! If you locate this insanely rare pearl, I will be VERY interested in it."
         );
       set_listen("heldalogala about rumors","Heldalogala sits down next to you and says,'So you wish to learn of the Legend do ya?? Well good!! Unfortunately I dont know much about history but if you locate Quessalaz, The Tourtoise of the Reef, he can give you more information. He lives in a cavern someplace in the upper section of the reef.\n\n Good Luck!!'");
       set_listen("heldalogala about legend","Heldalogala sighs heavily as he climbs to the top of his pile of pearls and says, 'Now listen folks.. I told ya I don't know much about the legend but I'll tell you what I do know.\n\n Someplace hidden in this reef is an old outpost that belonged to the race of beings that saved our world from the clutches of the Dracolich, Tridryill.\n\n If you can locate it, there is a partial history on the scroll there that I can't read. We hermit crabs are kinda short ya know!!'");
       set_listen("heldalogala","There are several different versions of pearls. I'll tell you about them if you wish to take the time to listen to me.");
       set_listen("heldalogala about quessalaz","Heldalogala says, 'He is the official Atlantian historian. If you want to learn about our reef he is the one to talk with.'");
      set_smell("","");
         set_long(
                 "A large section of the sand has been roped off."
                 " A large hermit crab seems to be digging through the sand looking for something."
                  " A collection of pearls sits next to the crab on the sand.");

         set_exits(([
                  "north":ROOMS1"room-1g6.c",
                   "northwest":ROOMS1"room-1f6.c",
                   "west":ROOMS1"room-1f7.c"
                     ]));
         set_items(([
             "pearls":"There are pearls of several sizes and shapes."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
         if(!present("monster"))
         {
           PEARLS"heldalogala.c"->move(this_object());
                   }
                      }

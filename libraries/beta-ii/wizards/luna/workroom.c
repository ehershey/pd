#include <locations.h>
 
//      from the Nightmare mudlib
//      an example workroom for new immortals
 
#include <std.h>
 
inherit ROOM;
 
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The workroom of a new immortal");
    set("night long", "Fire crackles and pops in a small cooking fire set in the center of the room. The smoke from a spit curls up through a hole in the celing.  Around the fire lie several fur rugs, pillows of different shapes and sizes, and the bones of those who trespassed.  The chamber is well lit from the fire and torches which line the walls.  At first glance the chamber looks warm and inviting....  until the shadow plunges the chamber into an eery light. \n");
    set("day long", "Outside the sun shines brightly. Neither light nor dark can penetrate the gloom of this chamber.  An unnatural shade fills it the fartherest corners are barely visible to the natural eye. Burning torches line the walls giving some source of light. Tapestries decorate the walls and although they may have once been brillant in hue, they now hang in graying tatters. The tapestries still show of once grand images of magical beasts and symbols of spellcasting.   \n");
   set_items(([
               "fire" : "A small cozy cooking fire.",
               "spit" : "The charred body of a fairie slowly turns over the fire.",
               "shadow" : "Eminating from the shadow is a sense of ancient power.",
               "rugs" : "Various furs of different animals.",
   	       "bones" : "Remains from ancient to recent.",
	       "tapestries" : "One tapestry stands out as though someone stands behind it.",
              "tapestry" : "The outlines of an armless statue of a female spellcaster show through."
   ]));
    
   set_exits( ([ 
"leadermeet"  :  "/d/guilds/leadermeet.c",
         "square" :  SQUARE_LOC,
         "pub" :  "/d/nopk/tirun/pubstart",
         "range"  :  "/wizards/stormbringer/room/newhouse.c",
         "hall"  :  "/d/nopk/standard/adv_inner",
         "guildmeet"  :  "/d/guilds/meeting",
    ]) ); 
    set_smell("default", "It smells like a new immortal in here.");
    set_listen("default", "You hear the sounds of code creation.");
}
void reset() {
 ::reset();
  if (!present("portal"))
      new("/wizards/stormbringer/portal")->move(this_object());
  }

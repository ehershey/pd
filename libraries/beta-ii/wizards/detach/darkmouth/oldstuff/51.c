#include <std.h>

inherit ROOM;

void create() {
::create();
   set_name("The Caverns");
   set_items((["wall"   : "%^BOLD%^%^BLACK%^You wonder why your looking at a wall if your lost"]));
   set_properties((["light":2, "night light":2]));
   set_short("The Caverns");                      
   set_long("%^BOLD%^%^BLACK%^S%^WHITE%^o%^BLACK%^m%^WHITE%^e "
           "%^BLACK%^W%^WHITE%^h%^BLACK%^e%^WHITE%^r%^BLACK%^e "
           "%^WHITE%^I%^BLACK%^n %^WHITE%^T%^BLACK%^h%^WHITE%^e "
"%^BLACK%^C%^WHITE%^a%^BLACK%^v%^WHITE%^e%^BLACK%^r%^WHITE%^n%^BLACK%^s.

The Caverns lead to the: %^BOLD%^BLACK%^north, east, south, west");
set_exits( ([ "north" : "/wizards/detach/darkmouth/51",
              "south" : "/wizards/detach/darkmouth/3",
              "west"  : "/wizards/detach/darkmouth/50",           
              "east" : "/wizards/detach/darkmouth/4"]));

set_invis_exits(({"north","south","west","east"}));


skip_obvious();
}
 void reset() {

     if(!present("dragon"))
       {
       new("/wizards/detach/darkmouth/mob/sss")->move(this_object());
      new("/wizards/detach/darkmouth/mob/troll")->move(this_object()); 
      }

}                                                                              


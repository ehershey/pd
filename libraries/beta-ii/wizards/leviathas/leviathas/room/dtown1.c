#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^The whole town is almost completely dark.  Rarely, a %^ORANGE%^light %^BLACK%^can be seen at some buildings but very dimly.  South of here is a low roof leading up to a chimney, east and west two ghastly looking streets and to the north there is a rather large mansion with a tower extending from it, into the darkness.  ");
   
    set_night_long("%^BOLD%^%^BLACK%^The whole town is almost completely dark.  Rarely, a %^ORANGE%^light %^BLACK%^can be seen at some buildings but very dimly.  South of here is a low roof leading up to a chimney, east and west two ghastly looking streets and to the north there is a rather large mansion with a tower extending from it, into the darkness.  ");
   
    
    set_items(([
        "town" : "Shadows are cast everywhere from the dim lights and it seems that just 10 feet away from you in all directions there is darkness.",
        "roof" : "You can barely make it out, but it's there.",
        "chimney" : "The chimney can be seen quite well, illuminated by a fire within.  It is crumbling and old with many cobwebs attached to it..",
        "buildings" : "They range in size, some large and some small.  Typical of any town.",
        "streets" : "Cold wind rushes through the streets and whistles a tune.",
        "mansion" : "The mansion could be considered a castle, if not for that eerie transylvanian look to it.",                  
        "tower" : "A jet black tower, darker than the night itself, extends up into the sky.  For some reason there are no stars out.",
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "dtownmp1.c",
        "east" : ROOMS "dtowne1.c",
        "west" : ROOMS "dtown2.c",
        
    ]));

}
void reset() {
  ::reset();
    if(!find_living("Ethereal Thug") || !environment(find_living("Ethereal Thug")))
      new(MOB "ethug")->move(this_object());


}


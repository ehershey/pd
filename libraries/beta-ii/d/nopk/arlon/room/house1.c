#include <std.h>
#include <arlon.h>

inherit ROOM;

static void create()
{
 ::create();
 set_short("a house");
 set_long("You are in front of a gigantic mansion. The overhang "
          "towers above you. The door has square glass inserts. " 
          "There is a door mat right below the door. The lawn "
          "stretches out around the mansion. There is a fountain "
          "in the middle of the lawn.");

 set_items( ([ ({"door mat","mat"}) : "Instead of reading \"Welcome\", it says, \"Go away.\"", 
               "lawn" : "It is really %^GREEN%^green%^RESET%^.",
               "door" : "It's made out of oak wood.",
               "fountain" : "The water runs down the sides of the fountain."]) );
 
 set_exits ( ([ "east" : ROOMS "hgates"  ]) );
 
}

void reset()
{
 ::reset();
}

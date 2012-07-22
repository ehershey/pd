#include <std.h>
#include <arlon.h>
inherit ROOM;

static void create()
{
 ::create();
 set_short("a house");
 set_long("You are in front of a small run down shack. The windows have "
          "been broken out and the door is wide open. The grass, wait "
          "there is no grass. This is a totally different look than "
          "the neighboring house.");

 set_items( ([ 
               "lawn" : "It is really not there." ]) );
 
   set_exits ( ([ "east" : ROOMS "hgates2",
                  "west" : "/dev/null"  ]) );
 
}
void reset()
{
 ::reset();
}

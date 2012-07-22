#include <std.h>
#include <arlon.h>

inherit ROOM;

static void create()
{
 ::create();
 set_short("Path south of Arlon square");
 set_long("This cobblestone path continues to the north and the south. "
          "The streets are occupied by shopping townsmen and townswomen. "
          "The gigantic trees overhang the street. The beatiful array of "
          "plants and flowers outline the cobblestone path. There is a small "
          "shack to the west of here.");
 
 set_exits ( ([ "north" : ROOMS "s_square",
                "west"  : ROOMS "stoneshop",
                "south" : ROOMS "hgates" 
                ]) );
 
}

void reset()
{
 ::reset();
}

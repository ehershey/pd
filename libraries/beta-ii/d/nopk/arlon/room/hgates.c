#include <std.h>
#include <arlon.h>

inherit ROOM;

static void create()
{
 ::create();
 set_short("Travelling on Guinness Drive");
 set_long("You are on Guinness Drive.\nMany houses can be seen "
          "scattered south from here. They are all seperated by "
          "streets running everywhere. This seems like the nice "
          "part of town.");
 
 set_exits ( ([ "north" : ROOMS "s_square2",
                "south" : ROOMS "hgates2",
                "west"  : ROOMS "house1" 
                ]) );
 
}

void reset()
{
 ::reset();
}

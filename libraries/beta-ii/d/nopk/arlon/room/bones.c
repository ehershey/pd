#include <std.h>
#include <arlon.h>

inherit ROOM;

static void create()
{
 ::create();
 set_short("");
 set_long("");
 
 set_exits ( ([ ]) );
}

void reset()
{
 ::reset();
}

#include <std.h>
#include <marsh.h>
inherit ROOM;
void create()
{
    ::create();
    set_short("The Oil Shop");
    set_properties( ([ "no attack":1,
        "no bump":1,
        "light":1,
        "no magic":1 ]) );
    set_long(
      "Kale's Magical Stones\n"
      "Read the sign for instructions.");
    set_exits( ([ "northwest" : HIVE "hiv27" ]) );
}
void reset()
{
    ::reset();
    if (!present("kale")) 
        new(MOB "kale")->move(this_object());
}

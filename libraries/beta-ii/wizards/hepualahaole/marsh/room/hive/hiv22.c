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
      "Milton's Herb Shop\n"
      "Read the sign for instructions.");
    set_exits( ([ "southwest" : HIVE "hiv17" ]) );
}
void reset()
{
    ::reset();
    if (!present("milton")) 
        new(MOB "milton")->move(this_object());
}

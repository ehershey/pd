#include <std.h>
#include <gcity.h>
#include <mjungle.h>

inherit ROOM;

static void create()
{
 ::create();
set_short("%^YELLOW%^Magic Shop%^");
set_long("%^YELLOW%^This shop is where the Merkkirri come to buy magic goods and in particular, magic stones.%^RESET%^");
 
 set_exits ( ([ "south" : GCITY "gcity5.c" ]) );
 set_properties( ([ "no attack":1,
                    "no magic": 1,
                    "no bump": 1,
                    "light":2,
                    "night light":2 ]) );
}

void reset()
{
 ::reset();
if(!present("gracken")) {
new(GMOB "gracken.c")->move(this_object());
}
}

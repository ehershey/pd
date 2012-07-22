#include <std.h>
#include <gcity.h>
#include <mjungle.h>

inherit ROOM;

void create()
{
 ::create();
set_short("%^YELLOW%^The Quixxiol House of Healing%^RESET%^");
 set_properties( ([ "no attack":1,
                    "no bump":1,
                    "light":2,
                    "night light":2,
                    "no magic":1 ]) );
set_long("%^YELLOW%^The House of healing is where Merkkirri come to buy healing oils and other curing aids.  The store sees quite a few customers from the harsh jungle animals.%^RESET%^");
set_long("%^YELLOW%^The House of healing is where Merkkirri come to buy healing oils and other curing aids.  The store sees quite a few customers from the harsh jungle animals.  A sign on the wall shows what can be purchased here.%^RESET%^");
set_exits( ([ "north" : GCITY "gcity5.c" ]) );
}

void reset()
{
 ::reset();
if (!present("minorra"))
new(GMOB "minorra")->move(this_object());
}

#include <mjungle.h>
#include <gcity.h>
#include <std.h>
#include <sindarii.h>

inherit ROOM;


void create()
{

 ::create();
set_short("%^YELLOW%^Quixxiol stables%^RESET%^");
set_long("%^YELLOW%^Here the Merkkirri breed a strange steed known as an Equill.  A cross between a horse and lizard, these odd beasts carry the gnolls through the jungle and swamp terrain effortlessly.%^RESET%^");
 set_smell("default", "The smell of manure fills your senses.");
set_exits ( ([ "south" : GCITY "gcity12.c" ]) );

}

void reset()
{
 ::reset();
if (!present("equill"))
   {
new(GMOB "equillsilver")->move(this_object());
new(GMOB "equillblue")->move(this_object());
new(GMOB "equillgreen")->move(this_object());
   }
}

#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
object oi;
::create();
set_properties((["light":3, "indoors":1]));
set_name("Illuminati Book Of Grudges");
set_short("Illuminati Book Of Grudges");
set_long("%^RESET%^%^ORANGE%^A large, round, room. All around the walls tapestries hang, 
depicting various scenes of vengeance. In the very centre of 
the floor lies the holy symbol of Lathander, patron deity of 
the Illuminati. Atop it lies the legendary Book of Grudges.");
set_exits(([
"northeast"     : ROOMS"illuminati/new/floor4.c"
]));
set_items(([
"tapestries"    : "Each one depicts a scene of vengeance being carried out. An "
"Archangel piercing a Demon's chest with his sword, Praetor Amakiira destroying "
"Verushin: Last of the Lich Kings. As well as a few other examples.",
"symbol"        : "A pure dawn mirrored on placid lake."
]));
oi = new("/std/bboard");
oi->set_name("The Book Of Grudges");
oi->set_id( ({ "board", "illuminati board" }) );
oi->set_board_id("Illuminati_Book_Of_Grudges");
oi->set_max_posts(99);
oi->set_edit_ok(({"aziraphale", "halo", "gabriel"}));
oi->set_location(ROOMS"illuminati/new/grudges.c");
oi->set("short", "%^BOLD%^%^BLACK%^...The Book Of Grudges...%^RESET%^");
oi->set("long", "The ancient book of grudges. To mark someone for a
grudge:\n\n%^RESET%^%^CYAN%^<post [Offender's Name]>\n<The reason you have a grudge against them>\n");
}

#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
    object oi;
    ::create();
    set_properties((["light":3, "indoors":1, "no scry":1]));
    set_name("Illuminati Book Of Grudges");
    set_short("Illuminati Book Of Grudges");
    set_long("%^ORANGE%^A large, round, room. All around the walls tapestries hang, depicting various scenes of vengeance. In the very centre of the floor lies the holy symbol of Lyramallor, patron deity of the Illuminati. Atop it lies the legendary Book of Grudges.%^RESET%^");
    set_exits(([
	"northeast"     : ILROOM"floor4.c"
      ]));
    set_items(([
	"tapestries"    : "Each one depicts a scene of vengeance being carried out. An Archangel piercing a Demon's chest with his sword, Praetor Amakiira destroying Verushin: Last of the Lich Kings. As well as a few other examples.",
	"symbol"        : "A pure dawn mirrored on placid lake."
      ]));
    oi = new("/std/bboard");
    oi->set_name("The Book Of Grudges");
    oi->set_id( ({ "board", "book" }) );
    oi->set_board_id("Illuminati_Grudge_Book");
    oi->set_max_posts(99);
    oi->set_edit_ok(({"furiae"}));
    oi->set_location(ILROOM"grudges.c");
    oi->set_short("%^BOLD%^BLACK%^...The Book Of Grudges...%^RESET%^\n\n");
    oi->set_long("The ancient book of grudges. To mark someone for a grudge correctly:\n\n%^CYAN%^<post [Offender's Name]>\n\n%^CYAN%^<The reason you have a grudge against them>\n\n\n%^RESET%^");
}



void init() {
    ::init();
    if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
	ILOBJ"ejection"->eject(this_player());
}

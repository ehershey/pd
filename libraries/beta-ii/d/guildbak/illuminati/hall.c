#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    object oi;
    ::create();
    restore_object("/d/guilds/save/illuminati");
    set_properties((["light":3, "indoors":1]));
    set_name("Illuminati Hall");
    set_short("Illuminati Hall");
    set_long("The Hall of Light, meeting place of the Illuminati. Along "
      "the length of the hall huge round white marble pillars support the weight of "
      "the tower. Oddly, black streaks swirl slowly around the pillars. The large "
      "stained glass windows on the surrounding walls unceasingly project their "
      "heavenly images perfectly upon the floor between the pillars despite the "
      "position of the sun. The floor is all polished white marble, and there is "
      "enough room to fit a hundred people comfortably. At the far end of the hall there "
      "are three thrones floating absolutely still in the air. The entrance to the "
      "guild's treasury is through a steel door in the southern wall. To the east lies "
      "the prayer room, and the guild's equipment store lies on the other side of a "
      "door to the southeast.");
    set_exits( ([
	"hall"      : ROOMS"meeting",
	"south"     : ROOMS"illuminati/treasury",
	"down"      : ROOMS"illuminati/entrance",
	"east"      : ROOMS"illuminati/prayer",
	"southeast" : ROOMS"illuminati/itemshop",
	"southwest" : ROOMS"illuminati/stoneshop",
      ]));
    set_items(([
	"throne"   : "The front throne is made of pure black marble "
	"and seems to absorb light from the air around it. Set out from the high back "
	"like a crown is a skull with a golden starburst impressed on it's forehead. The "
	"words %^BOLD%^M'Hael Artanis%^RESET%^ have been etched upon it The other two "
	"thrones sit to either side of the first, and slightly below. They are identical "
	"in almost every way, being made out of solid platinum inlaid with gold they have "
	"a small back and each has a golden halo floating above it. One has the words "
	"%^BOLD%^Asha'man Aziraphale%^RESET%^ inscribed upon it, the other says "
	"%^BOLD%^Asha'man Gabriel%^RESET%^.",
	"thrones"   : "The front throne is made of pure black marble "
	"and seems to absorb light from the air around it. Set out from the high back "
	"like a crown is a skull with a golden starburst impressed on it's forehead. The "
	"words %^BOLD%^M'Hael Artanis%^RESET%^ have been etched upon it The other two "
	"thrones sit to either side of the first, and slightly below. They are identical "
	"in almost every way, being made out of solid platinum inlaid with gold they have "
	"a small back and each has a golden halo floating above it. One has the words "
	"%^BOLD%^Asha'man Aziraphale%^RESET%^ inscribed upon it, the other says "
	"%^BOLD%^Asha'man Gabriel%^RESET%^.",
	"pillars"     : "Strong support pillars.",
      ]));
    oi = new("/std/bboard");
    oi->set_name("Illuminati Board");
    oi->set_id( ({ "board", "illuminati board" }) );
    oi->set_board_id("Illuminati_Board");
    oi->set_max_posts(99);
    oi->set_edit_ok(({"artanis", "Aziraphale", "wisp", "gabriel", "loki", "scourge"}));
    oi->set_location(ROOMS"illuminati/hall");
    oi->set("short", "Illuminati Board");
    oi->set("long", "This board is for the members of the Illuminati. \n");
}

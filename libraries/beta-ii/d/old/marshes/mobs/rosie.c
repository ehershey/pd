#include <std.h>
#include <amun.h>
inherit BARKEEP;
void create() {
    ::create();
    set_name("Rosie");
    set("id", ({ "rosie", "monster" }) );
    set_level( 1000 );
    set("short", "Rosie" );
    set("long", "Rosie is cleaning the shop making it look presentable for travelers." );
    set("race", "raknid" ); 
    set_gender( "female" );
    set_body_type("raknid");
    set_skill("melee", 1000);
    set_class("fighter");
    set_currency("gold");
    set_menu( ({"frozen mist", "murky water", "marsh mallow"}), ({"drink", "drink", "drink"}), ({ 25, 25, 25}) );
    set_menu_short(
      ({
	"%^BOLD%^%^CYAN%^Frozen Mist",
	"%^RESET%^%^ORANGE%^Murky %^RESET%^Water",
	"%^BOLD%^%^BLACK%^Marsh Mallow",
      })
    );
    set_my_mess(
      ({
	"The frozen mist gives you a head rush as it slides down your throat.\n",
	"You down the murkey water and notice it has a strong bite!\n",
	"Letting the marsh mallow expand slightly in your mouth, you begin to choke then swallow.\n",
      })
    );
}	
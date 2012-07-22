#include <illuminati.h>
#include <guild.h>

inherit ILOBJ"homeroom.c";

void create() {
    object ob;
    ::create();
    set_properties(([ "no scry" : 1, "indoors" : 1, "light" : 3 ]));
    set_short("Scourge's Room");
    set_long("%^RED%^Upon entering this mighty room, you are at first nearly "
      "knocked off your feet by the stench of%^RESET%^ %^BOLD%^BLACK%^rotting "
      "%^RESET%^%^BOLD%^RED%^heads%^RESET%^ %^RED%^strung upon the walls. Dry "
      "blood and other fluids seep down leaving trails of%^RESET%^ %^BOLD%^BLACK%^"
      "black%^RESET%^ %^RED%^and%^RESET%^ %^ORANGE%^yellow%^RESET%^ %^RED%^stains "
      "below where Scourge displays the%^RESET%^ %^BOLD%^BLACK%^fallen enemies"
      "%^RESET%^ %^RED%^of%^RESET%^ %^BOLD%^Illuminati%^RESET%^. %^RED%^In the "
      "center of the room is a large%^RESET%^ %^BOLD%^BLACK%^obsidian "
      "altar%^RESET%^ %^RED%^bearing a statue of the%^RESET%^ %^MAGENTA%^demon "
      "lord%^RESET%^ %^BOLD%^MAGENTA%^Asmodeus%^RESET%^ %^RED%^and around it a "
      "pentagram carved into%^RESET%^ %^WHITE%^stone%^RESET%^ %^RED%^floor with "
      "runic inscriptions in the%^RESET%^ %^MAGENTA%^demon language%^RESET%^. "
      "%^RED%^This room is disgusting, certainly not a sight for the faint "
      "hearted.%^RESET%^"); 








    set_exits(([
	"down"  : ILLUMINATI"hall"
      ]));
}

void init() {
    ::init();
    add_action("cmd_start", "start");
}

int cmd_start(string str)
{
    if (!str || str=="") 
    {
	notify_fail("Start where?\n");
	return 0;
    }

    if (str!="here")
    {
	notify_fail("You cannot start there.\n");
	return 0;
    }

    this_player()->set_primary_start("/d/guilds/illuminati/rooms/scourge");
    write("You are now set to start here.");
    return 1;
}


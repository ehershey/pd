#include <illuminati.h>
#include <guild.h>

inherit ILOBJ"homeroom.c";

void create() {
    ::create();
    set_properties(([ "no scry" : 1, "indoors" : 1, "light" : 3 ]));
    set_short("Illuminati Tower");
    set_long("%^CYAN%^Aziraphale's home is a most luxurious space with many couches and cushions, all of which have a fur cow pattern on them. A huge soft bed in the corner emits an aura of comfort, and along one wall is a writing desk with ink, quill and parchment.%^RESET%^");
    set_exits(([
	"down"  : ILLUMINATI"hall",
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

    this_player()->set_primary_start("/d/guilds/illuminati/rooms/aziraphale");
    write("You are now set to start here.");
    return 1;
}


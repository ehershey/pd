#include <illuminati.h>
#include <guild.h>

inherit ILOBJ"homeroom.c";

void create() {
    object ob;
    ::create();
    set_properties(([ "no scry" : 1, "indoors" : 1, "light" : 3 ]));
    set_short("Scourge's Room");
    set_long("%^MAGENTA%^This room is painted a dark black, lit by a series of  torches in open-skull holders, the flames of which seem to cower away from the centre of the room, although there is no breeze or wind to speak of in this area.  A large double bed rests in the middle of this place, a thick black blanket resting over it, decorated with silver thread wound in a spider-web pattern.  A small chest rests to one side, bearing the label 'Toys'.%^RESET%^");
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

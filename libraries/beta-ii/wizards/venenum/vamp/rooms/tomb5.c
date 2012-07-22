#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Underneath the graveyard");
    set_long("This tiny passage leads out towards the east and south. A small circular passage is visible to the south, with the rest of the tunnel disappearing off into the gloom of the east. A scattering of rose petals is found here, along with a disturbing sight; a set of bloodied footprints leading off to the east, accompanied by a few drops of blood. They stop abrumptly, however.");
    set_smell("default", "The sweet smell of crushed roses and blood is present here.");
    set_listen("default", "As quiet as a grave.");

    set_items(([
	({"petal", "petals", "rose", "roses"}) : "There are handfuls of these rose petals littering the tomb.",
	({"footprints", "footprint", "prints", "bloody footprints", "blood", "drops of blood", "blood drops"}) : "These look reasonably fresh, only a day or two old. They stop abrumptly, as though whatever made them suddenly took flight.",
	({"floor"}) : "The floor underneath you seems somewhat intangible, as though you could sink through down into it if you tried hard enough.",
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"east" : ROOMS"maze1.c",
	"south" : ROOMS"tomb4.c",
	"down" : ROOMS"tomb6.c",
      ]));
    add_invis_exit("down");
    set_pre_exit_functions( ({"down"}), ({"illusion_message"}) );
}

int illusion_message()
{
    string str;
    if(present("quest_item_devereux", this_player()))
    {
	write("%^BOLD%^%^GREEN%^You strain your mental faculties, attempting to disbelieve what you see and feel.%^RESET%^");
	str = present("quest_item_devereux")->query_quest_message();
	write(str);
	write("%^BOLD%^%^MAGENTA%^Your body sinks through the stone.%^RESET%^");
	return 1;
    }
    else
    {
	write("%^BOLD%^%^GREEN%^You strain your mental faculties, attempting to disbelieve what you see and feel.%^RESET%^");
	write("%^BOLD%^%^BLUE%^Your mind hurts.%^RESET%^");
	return 0;
    }
}


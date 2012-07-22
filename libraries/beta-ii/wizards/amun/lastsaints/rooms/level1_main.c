#include <std.h>
#include <amun.h>
inherit TREASURY;
void create() {
    ::create();
    set_guild("Last Saints");
    set_name("Last Saints");
    set_long("The treasury for the Last Saints, this is where the guilds "
      "gold is stored. The room is bare white everywhere except for a "
      "small inscription on the opposite wall. A large steel door leads "
      "north into the hall.  For a list of commands please "
      "<read sign>");
    set_properties((["light":1, "night light":1, "indoors":1, "no scry" :
	1]));
    set_items(([ "inscription" : "It's a sign you can read."]));
    set_short("Last Saints");
    set_exits((["south" : GUILDROOM"level1_1",
	"up"    : GUILDROOM"last_saints_board.c",
      ]));
}

// Coded by Whit
#include <std.h>
#include <guild.h>

inherit ROOM;
mapping leader, council;
string *leaders, *councils;
int i;
object ob;
void init() {
    ::init();
#ifndef NO_START
    add_action("fstart", "start");
#endif
}
void create() {
    ::create();
    restore_object("/d/guilds/save/blackforce");
    set_short("Black Force Hall");
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );
    set_long("This is the heart of the Scorpio guild.  The dark glow that "
      "illuminates the darkness comes from a small sphere floating  "
      "above the middle of the room. There seems to be a very hidden "
      "and secret force that runs through here. There is a small table "
      "that runs along the wall that has many strange vials on top "
      "of it. The distortion from the sphere makes the room seem as though it is "
      "spinning. There is a large board in the middle of the room that members of the "
      "guild can post about evil plots or anything that may come to mind.");
    set_exits(([
	"hall" : ROOMS"meeting",
	"up" : ROOMS"scorpio/entrance.c",
	"south" : ROOMS"scorpio/treasury.c",
	"east" : ROOMS"scorpio/meeting.c",
	"down" : ROOMS"scorpio/oilshop",
      ]) );
    set_items(([
	"sphere" : "It gives off a dark and mystical force.",
	"table" : "Many vials of poisons lay upon the table.",
      ]));

    ob = new(BBOARD);
    ob->set_location(ROOMS"scorpio/hall.c");
    ob->set_id(({ "board", "force board", "black force board" }));
    ob->set_board_id("scorpio");
    ob->set_edit_ok(leader, council);
    ob->set_max_posts(99);
    ob->set_short("the Scorpio Board of evil plots");
    ob->set_long("The Scorpio Board of evil plots.");
}

int fstart(string str) {
    if (!str || str=="") {
	notify_fail("Start where?\n");
	return 0;
    }
    if (str!="here") {
	notify_fail("You cannot start there.\n");
	return 0;
    }
    if(this_player()->query_original_guild() == "illuminati")
	this_player()->set_primary_start("/d/guilds/illuminati/new/board");
    else
    if(this_player()->query_original_guild() == "aod")
	this_player()->set_primary_start("/d/guilds/AoD/hall");
    else
	this_player()->set_primary_start("/d/guilds/"+this_player()->query_original_guild()+"/hall");
    write("You are now set to start in the "+capitalize(this_player()->query_guild())+
      " hall.\n");
    return 1;
}


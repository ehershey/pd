//Board Room
//boardroom.c
#include <std.h>
#include <guild.h>
#include <daemons.h>
inherit ROOM;
object ob;
void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 2);
    set_property("no magic", 1);
    set_property("no attack", 1);
    set_property("no castle", 1);
    set_property("no steal", 1);
    set_property("no teleport", 1);
    set_property("no scry", 1);
    set_short("The Vorticon crypt");
    set_long("%^BOLD%^WHITE%^This is the centre point of "
      "the Vorticon crypt, the %^BOLD%^RED%^b%^RESET%^RED%^"
      "loo%^BOLD%^dl%^RESET%^RED%^us%^BOLD%^t%^WHITE%^ and "
      "power of the Vorticons lures many to this forsaken "
      "place. The room is lit with %^BLACK%^m%^RESET%^"
      "%^BLUE%^y%^BOLD%^s%^WHITE%^t%^RESET%^BLUE%^I"
      "%^BOLD%^BLACK%^c %^BLUE%^t%^RESET%^BLUE%^o%^BOLD%^"
      "%^BLACK%^r%^RESET%^BLUE%^c%^BOLD%^h%^BLACK%^e"
      "%^RESET%^BLUE%^s%^BOLD%^WHITE%^ that %^RESET%^i"
      "%^BOLD%^YELLOW%^llu%^RESET%^min%^BOLD%^YELLOW%^at"
      "%^RESET%^e%^BOLD%^ the demonic creatures in the "
      "%^BOLD%^BLACK%^sh%^WHITE%^ad%^BLACK%^ows%^WHITE%^. "
      " Corpses cover the ground hiding the featureless "
      "stone floor. An altar has been elevated in the "
      "north of the room where their resides a fountain "
      "churning out %^RESET%^RED%^blood%^BOLD%^WHITE%^ "
      "and adjacent to it a %^RESET%^WHITE%^bone pedestal"
      "%^BOLD%^ where an ancient book lies open.%^RESET%^");
    set_smell("default","%^RED%^The sweet smell of blood "
      "lingers in the air.");
    set_exits(([
	"hall": "/d/guilds/meeting",
	"north": VORTICON "shop.c",
	"out": VORTICON "entrance.c",
	"west": VORTICON "treasury.c"]));
    set_items(([
	"crypt": "This is the resting place of the Vorticon "
	"family vampires.",
	({"torches", "mystic torches"}): "The torches to not emit "
	"any form of light but draw the darkness inside of "
	"them so there is enough light to see.",
	"corpses": "There seems to have been some sort of "
	"slaughter, corpses line the floor many of them have "
	"bite marks on their neck.",
	"floor": "The crypt floor is made entirely from "
	"basic stone but the ground is covered in corpses.",
	"altar": "The only notable features on the altar: "
	"are the fountain and the bone pedestal.",
	"fountain": "Blood flows from the bronze fountain "
	"into the basin, below.",
	"blood": "Blood..",
	({"pedestal", "bone pedestal"}): "A magical "
	"pedestal made from bone. The book of vampires lies "
	"open on it for you to read."
      ]));
    //    new(STUFF "bloodbook.c")->move(this_object());

    ob = new("std/bboard");
    ob->set_name("vorticon board");
    ob->set_board_id("vorticon_board");
    ob->set_id( ({ "book", "board", "book of vampires", 
	"blood book" }) );
    ob->set_short("%^BOLD%^WHITE%^Book of Vampires%^RESET%^");
    ob->set_edit_ok(GUILD_D->post_able("vorticon"));
    ob->set_long( "The unholy members of the guild record down "
      "details here to plot their ascension over the mortals, "
      "each post is written in blood.\n");
    ob->set_max_posts(100);
    ob->set_location(VORTICON"hall");
}

void init() {
    ::init();
    add_action("fstart", "start");
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
	this_player()->set_primary_start("/d/guilds/illuminati/new/hall");
    else
    if(this_player()->query_original_guild() == "aod")
	this_player()->set_primary_start("/d/guilds/AoD/hall");
    else

	this_player()->set_primary_start("/d/guilds/"+this_player()->query_original_guild()+"/hall");
    write("You are now set to start in the "+capitalize(this_player()->query_guild())+
      " hall.\n");
    return 1;
}


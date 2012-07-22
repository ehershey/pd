#include <std.h>
#include <guild.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Forsaken Helgrath Portal Room");
    set_short("Forsaken Helgrath Portal Room");
    set_long("This is the portal room of the Forsaken's Rhondale Subhall. "
      "This room has a large flaming portal glowing in the center of the room. "
      "Swirls of energy swarm the room. The source of light comes from several "
      "large pillars.  The engulfed pillars seem to be burning, yet do no harm at "
      "all to the grand structure.");
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );

    set_exits( (["north" : ROOMS"forsaken/rhonhall", ]) );
}

void reset() {
    ::reset();
    if (!present("portal", this_object()))
	new("/d/guilds/forsaken/portal" )->move(this_object());
}

void init() {
    ::init();
    add_action("enter_portal","enter");
}

int enter_portal(string str) {
    if(!str) {
	notify_fail("Enter what?\n");
	return 0;
    }
    if(str != "portal") {
	notify_fail("You can't go there!\n");
	return 0;
    }
    else {
	if(this_player()->query_guild() != "forsaken"){
	    say(this_player()->query_cap_name()+" is an idiot",this_player());
	    notify_fail("Only the Forsaken may dare this portal!\n");
	    this_player()->add_hp(-50);
	    return 0;}
	else {
	    this_player()->move_player(ROOMS"forsaken/mainportal", " screams as their "
	      "body is moved to the main hall.");
	    return 1;}
    }
}
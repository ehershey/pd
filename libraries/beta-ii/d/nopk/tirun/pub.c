#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light"       : 2,
	"indoors" : 1,
	"no attack" : 1,
	"no magic" : 1]) );
    set_short("The Drowning Fish Tavern.");
    set_long("%^MAGENTA%^The Drowning Fish Tavern%^RESET%^\n"
      "The tavern was established many years ago. It has "
      "served the people of Tirun well, keeping them "
      "informed on the latest news that goes on around "
      "the city.  A menu of drinks is on the wall.  The "
      "Tirun Board is to the south.  Up the stairs "
      "is a gambling hall and to the west is the exit "
      "to the Tirun Market. ");
    set_items(
      (["tavern" : "The most happenin' place in Tirun.",
	"bar" : "A large counter that has been polished smooth with years of use.",
    ]) );
    set_exits( (["north" : ROOMS "ehonin1",
	"south" : ROOMS "pubstart",
	"up"  : ROOMS "ghall",
	"down"  : ROOMS "wand/bard/bard_join",
        "west"  : ROOMS "square4"]) );
    set_listen( "default", "The sounds of gambling come from up the stairs."
    );
}

void reset() {
    ::reset();
    /*
	    new("/std/obj/player_list")->move(this_object()); 
    */
    if(!present("lars")) 
	new(MOB"lars")->move(this_object());
}


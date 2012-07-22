#include <locations.h>
#include <locations.h>
// Remodeled 12/28/00
#include <std.h>
#include <tirun.h>
inherit ROOM;

int sigma;
int cmd_start(string str);

void init()
{
    ::init();
    add_action("cmd_start", "start");
    add_action("cmd_drop", "drop");
}

void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"no wander"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set_listen("default", "A peaceful silence permeates this place.");
    set_short("Tirun Park");
    set_long(
      "%^CYAN%^Tirun Central Park%^RESET%^\n"
      "The park of Tirun is situated in the center of market square.  "
      "It is a place of peace and rest dedicated to the Gods of the "
      "realm.  The bustling activity of the town does not encroach "
      "upon this place.  Not even time invades this sanctuary of "
      "the Gods. "
    );
    set_exits((["north" : ROOMS "square1",
	"south" : ROOMS "square5",
	"east" :  ROOMS "square3",
	"west" :  ROOMS "square7"]));
    set_items( ([
	"dragon" : "The dragon's head is pulled back, ready to attack. "
	"It's eyes seem to gaze deep into the depths of your soul.",
	"plaque" : "A gold plaque, you should read it.",
	"water" : "Pure untainted water spilling from the dragon into the pool."
      ]) );
}



void reset() {
    ::reset();
    /*
    if (!sizeof(children("/wizards/nulvect/mexican_food_cart_vendor")))
      new("/wizards/nulvect/mexican_food_cart_vendor")->move(this_object());
    */
    /*
	if (!find_living("sigma") || !environment(find_living("sigma")))
	 {
	   new(MOB "sigma")->move(this_object());
	   sigma=1;
	}
	if (!present("well"))
	  new(OBJ "well")->move(this_object());
	if(!present("statue"))
	  new(OBJ "d_statue")->move(this_object());
    */
/*
	    if(!present("station"))
		new(OBJ "firework_station")->move(this_object());
*/
  /*
	  if(!present("tree"))
	    new("/d/events/xmas/obj/tree")->move(this_object());
  */
    if(!present("pit"))
	new(OBJ "pit")->move(this_object());
    if(!present("squareboard"))
	new(OBJ "squareboard")->move(this_object());
    if(!present("fountain"))
	new(OBJ "d_fount")->move(this_object());
    if (!present("guard"))
	new(MOB "townguard")->move(this_object());
/*
	    if (!present("pie"))
		new("/wizards/luna/pie.c")->move(this_object());
*/
/*
	if (!present("santa"))
	    new("/wizards/daos/mon/santa")->move(this_object());
*/
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

    this_player()->set_primary_start(SQUARE_LOC);
    write("You are now set to start here.");
    return 1;
}

int cmd_drop(string str)
{
    if (!str || !present(str, this_player())) return 0;
    this_player()->force_me("put "+str+" in pit");
    return 1;
}

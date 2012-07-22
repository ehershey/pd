#include <std.h>
#include <thrarandil.h>

inherit ROOM;

int preview();

void create()
{
    ::create();
        set_name("rogue hall");
        set_short("Rogue Hall");
        set_long("The entrance to the rogue hall is lined with expensive paintings and sculptures. Everything here is obviously stolen, it is an amazing collection. On the floor lies an expensive tapestry, being used as a rug. In the corner is a small fireplace, it looks like it hasn't been used in years.");  
        set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1,
        "indoors"     : 1,
        "town"        : 1, ]) );
        set_items(([
    	"paintings"    :  "Various paintings from around the world.",
    	"sculptures"   :  "Expensive sculptures stolen fron various places around the world."
	    ]));
	    set_listen("default", "Small whispers can be heard everywhere.");
	    set_smell("default", "The air is stale.");
	    set_exits(([
			"out"		: ROOMS "thrarandil013.c",
			"down"      : ROOMS "futureroom.c",
        ]));
        add_pre_exit_function("down", "go_down");
}



void init() {
    ::init();
    add_action("preview","preview");
}

int preview() {
    if((string)this_player()->query_class() != "child") {
        message("info", "You have already choosen your path.", this_player());
        return 1;
    }
    message("other_action", this_player()->query_cap_name()+" seeks to learn about rogues.", this_object(), ({this_player()}));
  
    write("Welcome, child!\n");
    write("Rogues are people who make their life and pleasure from the misery "
        "of others.  They keep their hideout here in the Outlands so as to "
        "keep a low profile in the eyes of the civilized world which is only "
        "interested in hunting them down and bringing them to justice. "
        "Rogues are made up of many different types of scum.  Some are murderers, "
        "while others are thieves and bandits.  But they all love it. "
        "Keep in mind that once you choose to become a rogue, you will be "
        "hated by people from all walks of life.  You will never be able to "
        "move about safely.  Unless you avoid targeting players, that is. "
        "Type <become rogue> to become a rogue.");

    return 1;
}

int go_down() {
    if(!this_player()->is_player()) return 0;
    if(this_player()->query_position() == "wizard"){
        write("Mighty immortals are always welcome into the hall.");
    }else if(this_player()->query_class() != "rogue") {
        write("You can not enter!");
        return 0;
    }
    return 1;
}




#include <std.h>
#include <lidelas.h>

inherit ROOM;

int preview();

void create()
{
    ::create();
        set_name("rogue hall");
        set_short("Rogue Hall");
        set_long("This is the basement of one of the grand buildings in Lidelas. It serves as the hideout for the rogues of the town, they come here to plan their targets. Several tables have been set up all over the room so friends can sit and enjoy a good chat. The room is very dark, and there are no windows, only a few torches hanging from the walls give off any light down here. The lack of light would help make identifying each other difficult if someone ever were to rat anyone out. There are various barrels and crates with a wide variety of goods in them, most likely they are stolen.");  
        set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1,
        "indoors"     : 1,
        "town"        : 1, ]) );
        set_items(([
    	"table"    :  "A heavy wooden table, used to plan nefarious activities.",
    	"torches"  :  "Some small torches that light the room."
	    ]));
	    set_listen("default", "Small whispers can be heard everywhere.");
	    set_smell("default", "The air is stale.");
	    set_exits(([
			"out"		: ROOMS "lidelas024.c",
			"down"		: ROOMS "lidelasRhall.c",
        ]));
        add_pre_exit_function("down", "go_down");
}

void reset() {
   ::reset();
if (!present("swidhelm", this_object()))
     new(MOB"swidhelm.c")->move(this_object());
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
    if(this_player()->query_position() == "wizard" || this_player()->query_position() == "Avatar"){
        write("Mighty immortals are always welcome into the hall.");
    }else if(this_player()->query_class() != "rogue") {
        write("You can not enter!");
        return 0;
    }
    return 1;
}



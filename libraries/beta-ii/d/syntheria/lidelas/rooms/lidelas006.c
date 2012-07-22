#include <std.h>
#include <lidelas.h>

inherit ROOM;

int preview();

void create()
{
    ::create();
        set_name("wanderer hall");
        set_short("Wanderer Hall");
        set_long("This is the inside of the Great Hall of Wanderers. People travel from all over the world to hear the tales of other wanderers, who have been to strange and exotic places. The main hall is enormous, windows line all of the walls. The floor is made of very polished marble, it reflects any light that reaches it. Large flags are draped on all of the walls between the windows, the flags stretch from the ceiling down to the floor. Each flag has a different crest on it, each looking to represent a distant part of the world. Torches create a path leading to the west, it looks as the path the torches create are the only part of the hall that is walked on. Children may <preview> what it is like to be a wanderer.");  
        set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1,
        "indoors"     : 1,
        "town"        : 1, ]) );
        set_items(([
    	"torches"    :  "Torches made of fine gold, they burn some black liquid.",
    	"windows"    :  "Large stain glass windows that display various people and places."
	    ]));
	    set_listen("default", "People chatting in the hall echos off the walls.");
	    set_smell("default", "The smell of smoke fills the air.");
	    set_exits(([
			"east"		: ROOMS "lidelas005.c",
			"west"		: ROOMS "lidelasWhall.c",
        ]));
        add_pre_exit_function("west", "go_west");
}

void reset() {
   ::reset();
if (!present("coenred", this_object()))
     new(MOB"coenred.c")->move(this_object());
}

void init() {
    ::init();
    add_action("preview","preview");
}


int preview() {
    if((string)this_player()->query_class() != "child") {
        write("You have already choosen your path.");
        return 1;
    }
    say(this_player()->query_cap_name()+" seeks to learn about wanderers.", this_player());
    write("Welcome, child!\n");
    write("Wanderers are those people who have chosen to spend the rest "
      "of their lives traveling and moving about. All wanderers have at least two "
      "things in common: their love of fun and pranks and their overwhelming "
      "wanderlust. Some wanderers choose to spend their time with others "
      "who wander about in groups, while others will travel alone from town "
      "to town telling jokes and entertaining peasants for a few coins. "
      "Wanderers are sometimes looked down upon because they have a "
      "tendancy towards theft.  To become a wanderer, type <become wanderer> "
      "and strike out now and find your path in life, go and find the hall "
      "of the Bard, the hall of the Gypsy, the hall of the Jester, "
      "or the hall of the Swashbuckler.");
    return 1;
}




int go_west() {
    if(!this_player()->is_player()) return 0;
    if(this_player()->query_position() == "wizard"){
        write("Mighty immortals are always welcome into the hall.");
    }else if(this_player()->query_class() != "wanderer") {
        write("You can not enter!");
        return 0;
    }
    return 1;
}





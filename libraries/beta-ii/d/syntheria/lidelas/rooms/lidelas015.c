#include <std.h>
#include <lidelas.h>

inherit ROOM;

int preview();

void create()
{
    ::create();
        set_name("mage hall");
        set_short("Mage Hall");
        set_long("The tower is almost hollow all the way up, except for the very top. A circular staircase can be seen that goes around the whole building leading up to the very top of the tower. Large banners hang from various parts of the stairs, each banner has a different crest woven into it. In the center of the room, a large pit with a enourmas fire burns. The flames easily reach several stories high, yet it seems to produce to smoke. A strange breeze blows through the tower. <preview> will tell you about becoming a mage.");  
        set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1,
        "indoors"     : 1,
        "town"        : 1, ]) );
        set_items(([
    	"banners"    :  "Each banner represents a different type of magic.",
    	"fire"       :  "A fire unlike any ever seen, it does not produce any heat or smoke,"
	    ]));
	    set_listen("default", "Only the roaring fire can be heard.");
	    set_smell("default", "The air is stale.");
	    set_exits(([
			"out"		: ROOMS "lidelas014.c",
			"up"		: ROOMS "lidelas0Mhall.c",
        ]));
        add_pre_exit_function("up", "go_up");
}

void reset() {
   ::reset();
if (!present("osfrid", this_object()))
     new(MOB"osfrid.c")->move(this_object());
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
    message("other_action", this_player()->query_cap_name()+" seeks to learn about mages.", this_object(), ({this_player()}));
    message("info", "Welcome, child!", this_player());
    message("info", "Mages have no overriding beliefs which unite them, but instead "
        "they are united in their love of the art of magic.  Some of them "
        "are devoted practitioners of white magic, while others are evil "
        "dark mages.  Their agical arts are centered around those "
        "which will most help them along in the material world, the arts "
        "of conjuring and magical combat.  To become a mage, type <become mage>"
        "and strike out now and find your path in life, go and find the hall "
        "of the Necromancer, the hall of the Pyromancer, the hall of the Sorceror, "
        "or the hall of the Wizard.", this_player());
    return 1;
}

int go_up() {
    if(!this_player()->is_player()) return 0;
    if(this_player()->query_position() == "wizard"){
        write("Mighty immortals are always welcome into the hall.");
    }else if(this_player()->query_class() != "mage") {
        write("You can not enter!");
        return 0;
    }
    return 1;
}




#include <std.h>
#include <lidelas.h>

inherit ROOM;

int preview();

void create()
{
    ::create();
        set_name("fighter hall");
        set_short("Fighter Hall");
        set_long("This is the Great Hall of the fighter class, people come here from all over the world to train in the ways of combat. Hundreds of weapons line the walls of the hall, each one looking more deadly then the last. There are three fireplaces, one on the back wall, the east wall, and the west wall. Each fireplace contains an enormous fire in it, and there is a pile of firewood next to each fireplace to ensure that they keep burning. There are seven banners hanging from the ceiling, each one represents a different type of weapon. There are groups of fighters all over the hall, talking loudly to one another. The floor looks like it used to be made of a very nice marble, but now there are many cracks and gouges in the floor, most likely from combat between fighters. At the far back of the hall, there is a staircase that leads down. Children may <preview> what it is like to be a fighter.");  
        set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1,
        "indoors"     : 1,
        "town"        : 1, ]) );
        set_items(([
        "fireplace"    :   "A gigantic fireplace that burns wildely.",
        "banners"      :   "Huge banners with the symbols of each type of weapon woven into them",
            ]));
            set_listen("default", "The fighters in the hall yell at eachother loudly.");
            set_smell("default", "The smell of food and drink permeate the air.");
            set_exits(([
                        "north"         : ROOMS "lidelas030.c",
                        "down"          : ROOMS "lidelasFhall.c",
        ]));
        add_pre_exit_function("down", "go_down");
}

void reset() {
   ::reset();
if (!present("redwald", this_object()))
     new(MOB"redwald.c")->move(this_object());
}

void init() {
    ::init();
    add_action("preview","preview");
}


int preview() {
    if((string)this_player()->query_class() != "child") {
        message("info", "You have already chosen your path.", this_player());
        return 1;
    }

    say(this_player()->query_cap_name()+ " seeks to learn about fighter.",
this_player());
    write("Welcome, child!");
    write("Fighters are people whose only uniting belief is in combat as a "
        "form of art.  Some are great knights who fight for good wherever "
        "they go.  Others might be considered quite fiendish in some circles. "
        "They therefore have no moral restrictions placed upon them. But "
        "they spend so much time learning the arts of combat, that they "
        "are almost entirely ignorant of the ways of magic.  To become a "
        "fighter, type <become fighter>."
	);

    return 1;
}




int go_down() {
    if(!this_player()->is_player()) return 0;
    if(this_player()->query_position() == "wizard"){
        write("Mighty immortals are always welcome into the hall.");
    }else if(this_player()->query_class() != "clergy") {
        write("You can not enter!");
        return 0;
    }
    return 1;

}


#include <std.h>
#include <gcity.h>
#include <mjungle.h>
#include <sindarii.h>

inherit ROOM;

void init() {
    ::init();
    add_action("become", "become");
add_action("go_northwest","northwest");
    add_action("preview","preview");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
set("short", "%^YELLOW%^The Quixxiol Hall of Fighters%^RESET%^");
    set("long",
"%^YELLOW%^The Quixxiol Hall of Fighters is as ancient as the city itself.  The fighter is held in high regard in Merkkirri culture.  Here combatants of all types come to tell tales of glory and young warriors stand outside hoping to learn the ways of the fighter.  Children may <preview> what it is like to be a fighter.  A %^RESET%^BLUE%^blue%^RESET%^YELLOW%^ force field covers the entrance northwest into the inner chamber.%^RESET%^");  
    set_items( 
	([({"tapestry", "tapestries", "wall"}) : "The walls are all "
	    "covered with some of the most ornate tapestries from "
	    "all over.  The one you are looking at depicts a heroic "
	    "battle between a dragon and a human combatant.",
({"force field", "light", "blue light"}) : "To the northwest, "
"there is a force field covering the entrance into the inner chamber. ",
	  "fighters" : "They are loud and obnoxious.", 
	  ({"warriors", "young warriors"}) : "They look clueless."]) );
    set_exits( 
(["east" : GCITY"gcity9.c",
"northwest" : "(: northwest :)"]) );
    set_listen("default", "Fighters are yelling and screaming and "
      "being generally obnoxiously loud.");
}

int preview() {
    if((string)this_player()->query_class() != "child") {
	write("This is not for you.\n");
	return 1;
    }
    say(this_player()->query_cap_name()+" seeks to learn about fighter.", 
	this_player());
    write("Welcome, child!");
    write("Fighters are people whose only uniting belief is in combat as a "
	"form of art.  Some are great knights who fight for good wherever "
	"they go.  Others might be considered quite fiendish in some circles. "
	"They therefore have no moral restrictions placed upon them. But "
	"they spend so much time learning the arts of combat, that they "
	"are almost entirely ignorant of the ways of magic.  To become "
	"a fighter, type <become fighter>.");
    return 1;
}

int become(string str) {
    if(!str) {
	notify_fail("Become what?\n");
	return 0;
    }
    if(str != "fighter") {
	notify_fail("You cannot become that here.\n");
	return 0;
    }
    if((string)this_player()->query_class() != "child") {
	write("You are much too old to start learning our ways now!");
	return 1;
    }
    write("The Great Warrior initiates you into the class of fighters.");
    say(this_player()->query_cap_name()+" becomes a fighter.", this_player());
    this_player()->set_class("fighter");
    this_player()->setenv("TITLE", "$N the page");
    this_player()->init_skills("fighter");
this_player()->setenv("start", GCITY"gcity29.c");
    return 1;
}

int go_northwest() {
    if((string)this_player()->query_class() != "fighter") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	    "fighter's sanctuary, but fails.", this_player());
	return 1;
    }
this_player()->move_player(GCITY"gcity29.c", "through the light in the passage");
    return 1;
}


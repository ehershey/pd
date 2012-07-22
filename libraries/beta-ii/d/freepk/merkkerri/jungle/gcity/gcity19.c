#include <std.h>
#include <mjungle.h>
#include <gcity.h>
#include <sindarii.h>

inherit ROOM;

void init() {
    ::init();
    add_action("become", "become");
add_action("go_southeast","southeast");
    add_action("preview","preview");
}

void create() {
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
set("short", "%^YELLOW%^Entry to the Hall of Monks");
set_long("%^YELLOW%^The Quixxiol monastery is a place where monks gather and initiate new believers.  A passage to the east if filled with a shimmering light. <preview> will tell you about becoming a monk.");
    set_items(
	(["candles" : "They are all over the monastery.",
	  "candle" : "It burns brightly and helps light the room.",
	  "passage" : "You sense that only monks may pass that way."]) );
    set_exits( 
(["west" : GCITY "gcity10.c",
"southeast" : "(: southeast :)"]) );
}

int preview() {
    if((string)this_player()->query_class() != "child") {
	message("info", "This is not for you.", this_player());
	return 1;
    }
    say(this_player()->query_cap_name()+" seeks to learn about the monks.", 
	this_player());
    message("info", "Welcome, child!", this_player());
    message("info", "Monks make up people of many different beliefs of "
      "great faith, but they are all united in their belief in a single "
      "deity of Goodness and will devote themselves to Holy War to fight "
      "evil wherever it might be.  They are nearly fanatical about their "
      "beliefs.  To become a monk, type <become monk>,", this_player());
    return 1;
}

int become(string str) {
    if(!str) {
	notify_fail("Become what?\n");
	return 0;
    }
    if(str != "monk") {
	notify_fail("You cannot become that here.\n");
	return 0;
    }
    if((string)this_player()->query_class() != "child") {
	message("my_action", "You are much too old to start learning our ways now!", this_player());
	return 1;
    }
    message("my_action", "The Grand Lord High Priestess initiates you into the class of monks.", this_player());
    message("other_action", this_player()->query_cap_name()+" becomes a monk.",
      this_object(), ({ this_player() }));
    this_player()->set_class("monk");
    this_player()->setenv("TITLE", "$N the novice monk");
    this_player()->init_skills("monk");
this_player()->setenv("start", GCITY "gcity32.c");
    return 1;
}

int go_southeast() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the humble monastary.");
	} else 
    if((string)this_player()->query_class() != "monk") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the monk's sanctuary, but fails.", this_player());
  	return 1;
    }
this_player()->move_player(GCITY "gcity32.c", "through the light in the passage");
    return 1;
}




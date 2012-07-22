// Note: May 29, 8:00 pm
#include <std.h>
#include <sindarii.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 1);
    set("short", "Inside a towering monument");
    set_long(
      "This is the inside of a towering monument, to honor those who have "
      "died.  The cold, marble floor, and walls provide the exterior of "
      "the structure.  A lantern hangs suspended by some strong magic in midair.");
    set_items(([
	({ "floor", "wall", "walls", "marble", "marble floor", "marble walls", "marble wall" }) :
	"Cold and lonely.",
	"magic" : "It keeps the lantern suspended in the air.",
	"lantern" : "Eternally lighting the way of hope.",
	"flowers" : "A grand assortment of flowers have been layed down here.",
	"air"  : "An evil mark shimmers in the light.",
	"mark" : "An evil mark, you may try reading it.",
      ]));
    set_exits(([
	"out" : ROOMS"cemetary/gravyar9",
      ]));
}
int pray() {
    int x;
    x = this_player()->query_max_hp() - this_player()->query_hp();
    this_player()->add_hp(x);
    x = this_player()->query_max_sp() - this_player()->query_sp();
    this_player()->add_sp(x);
    x = this_player()->query_max_mp() - this_player()->query_mp();
    this_player()->add_mp(x);
    this_player()->set_paralyzed(15);
    write("You are held in prayer.");
    return 1;
}
void init() {
    ::init();
    add_action("pray", "pray");
    add_action("GoBow", "bow");
    add_action("GoUp", "up");
    add_action("GoDown", "down");
    add_action("read_mark", "read");
}
int GoBow(string str) {
    if(!str || str != "head") {
	notify_fail("Bow what?\n");
	return 0;
    }
    if (this_player()->query_class() != "fighter" ||
      this_player()->query_subclass() != "none" ) {
	write("Nothing happens.");
	return 1;
    }
   this_player()->move_player("/d/nopk/tirun/fighter/antipaladin/antipaladin_join.c");
    say(this_player()->query_cap_name()+" vanishes.");
    return 1;
}
int GoUp() {
    if (this_player()->query_subclass() != "antipaladin" ) {
	write("You cannot go that way.");
	return 1;
    }
    this_player()->move_player("/d/nopk/tirun/fighter/antipaladin/antipaladin_join.c");
    say(this_player()->query_cap_name()+" vanishes.");
    return 1;
}
int GoDown() {
    if (this_player()->query_subclass() != "kataan") {
	write("You cannot go that way.");
	return 1;
    }
   this_player()->move_player("/d/nopk/tirun/clergy/kataan/kataan_hall.c");
    say(this_player()->query_cap_name()+" vanishes.");
    return 1;
}
int read_mark(string str) {
    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(str != "mark") {
	notify_fail("You can't read that!\n");
	return 0;
    }
    if((this_player()->query_class() != "fighter")&&(this_player()->query_subclass() != "none")) {
	message("info", "The markings look like jibberish.", this_player());
	return 1;
    }
    message("info", "The vileness of the realms has taken this monument of good,", this_player());
    message("info", "We strike from here to bathe the realms in blood.", this_player());
    message("info", "You have but to bow your head to ask to enter,", this_player());
    message("info", "Then too shall you reign evil from our center.", this_player());
    return 1;
}

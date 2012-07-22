#include <std.h>
#include <illuminati.h>

inherit HALL;

void init() {
    ::init();
    add_action("homeroom", "up");
    add_action("blockview", "peer");
    if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
	ILOBJ"ejection"->eject(this_player());
}

int homeroom() { 
    if(this_player()->query_name() == "helena")  
	this_player()->move_player(load_object(ILROOM+"tsuke.c"), "into "+this_player()->query_possessive()+" room");
    else if(this_player()->query_name() == "jacie")  
	this_player()->move_player(load_object(ILROOM+"aziraphale"), "into "+this_player()->query_possessive()+" room");  
    else if(this_player()->query_name() == "goldenberry")
	this_player()->move_player(load_object(ILROOM+"goldenberry"), "into "+this_player()->query_possessive()+" room");
    else if(load_object(ILROOM+this_player()->query_name()+".c")) 
	this_player()->move_player(ILROOM+this_player()->query_name(), "into "+this_player()->query_possessive()+" room");  
    else  
	message("info", "You do not have your own room.", this_player(), );  
    return 1;  
}

int blockview(string str) {
    if(str == "up" || str == "u") {
	message("info", "The personal rooms cannot be seen from down here.", this_player(), );
	return 1;
    }
    return 0;
}

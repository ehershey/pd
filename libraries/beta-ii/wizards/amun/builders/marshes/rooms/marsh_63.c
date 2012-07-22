#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The path seems to grow more narrow causing the rocks to be utilized for balance or to be climbed on. The clouds above clap with thunder threatening to pour rain. From this area, a large marsh can be seen to the north. Something can be seen floating in its marshy waters.%^RESET%^");
    set_items( ([ "water": "%^BOLD%^%^BLACK%^There are dead faces in the water, these are the faces of those who came, fought and died.", "marsh": "%^RESET%^%^ORANGE%^This looks like a sad place full of death." ]) );
    set_exits( ([ "south" : MARSHROOM+"marsh_62", "north" : MARSHROOM+"marsh_64" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
int sp_sap() {if (this_player()->query_stats("dexterity") <= 50)
    {  this_player()->add_sp(-30);
	return 1;}
    if (this_player()->query_stats("dexterity") > 50 &&
      this_player()->query_stats("dexterity") <= 75) { 
	this_player()->add_sp(-25); return 1; }
    if (this_player()->query_stats("dexterity") > 75 &&
      this_player()->query_stats("dexterity") <= 100) {
	this_player()->add_sp(-20); return 1; }
    if (this_player()->query_stats("dexterity") > 100 &&
      this_player()->query_stats("dexterity") <= 150) { 
	this_player()->add_sp(-15); return 1; }
    if (this_player()->query_stats("dexterity") >= 150) { 
	this_player()->add_sp(-10); return 1; }
}

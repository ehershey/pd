#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_121", "north" : MARSHROOM+"marsh_125", "south" : MARSHROOM+"marsh_105" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
int sp_sap() {if (this_player()->query_stats("dexterity") < 76)
    {  this_player()->add_sp(-30);
	return 1;}
    if (this_player()->query_stats("dexterity") > 75 &&
      this_player()->query_stats("dexterity") < 151) {
	this_player()->add_sp(-25); return 1; }
    if (this_player()->query_stats("dexterity") > 151 &&
      this_player()->query_stats("dexterity") < 226) {
	this_player()->add_sp(-20); return 1; }
    if (this_player()->query_stats("dexterity") > 226 &&
      this_player()->query_stats("dexterity") < 301) {
	this_player()->add_sp(-15); return 1; }
    if (this_player()->query_stats("dexterity") >= 300) {
	this_player()->add_sp(-10); return 1; }
}

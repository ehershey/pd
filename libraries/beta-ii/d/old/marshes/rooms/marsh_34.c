#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^BLACK%^Moving deeper into the marsh, you notice that your legs are now knee deep in the water.  Feeling bodies moving around your legs, you move slowly forward, trying not to look at the dead faces in the water.\n");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "water": "%^RESET%^%^BLUE%^The water is thick with mud and thick with bodies.  You see and feel dead things around you.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "north" : MARSHROOM+"marsh_33", "south" : MARSHROOM+"marsh_35" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
    new(MARSHMON+"inferi_gnoll.c")->move(this_object());
    new(MARSHMON+"inferi_illithid.c")->move(this_object());
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

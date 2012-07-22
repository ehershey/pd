#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Smoke has built up dramatically in this area from sporadic fires that it is hard to see. Through the smoke, v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e%^BLACK%^s can be seen swooping down picking at the dead bodies in the marsh waters. A hand can be seen grasping the earth trying to pull a dead body from the waters. A clap of thunder booms across the sky.%^RESET%^");
    set_items( ([ "hand": "%^BOLD%^%^BLACK%^The rotten hand is pulling a corpse out of the murky water.", "water": "%^RESET%^%^BLUE%^The water is thick with mud and thick with bodies.", "body": "These bodies are those of many races." ]) );
    set_exits( ([ "northeast" : MARSHROOM+"BM_4", "west" : MARSHROOM+"BM_8", "north" : MARSHROOM+"BM_12" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("northeast", "sp_sap");
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

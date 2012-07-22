#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^A loud growling can be heard across the marshes causing the shrubs to rattle in fear. A hand, that was hanging out of the water, vanishes from sight and creates a small splash. This place is not one of happiness, it is as if this place is cursed to live in doom for all eternity. Thunder rolls across the land.%^RESET%^");
    set_items( ([ "hand": "%^BOLD%^%^BLACK%^There is a hand hanging out of the water, and is then jerked back in." ]) );
    set_exits( ([ "east" : MARSHROOM+"BM_28", "southeast" : MARSHROOM+"BM_26", "northeast" : MARSHROOM+"BM_30", "west" : MARSHROOM+"BM_34" ]) );
    add_pre_exit_function("southeast", "sp_sap");
    add_pre_exit_function("west", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("centaur", this_object()))
	new(MARSHMON+"inferi_centaur")->move(this_object());
    if (!present("halfelf", this_object()))
	new(MARSHMON+"inferi_halfelf")->move(this_object());
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

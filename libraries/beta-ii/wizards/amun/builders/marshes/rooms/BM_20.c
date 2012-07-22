#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^In all directions, the marsh stretches as far as the naked eye can see. To the east, %^BOLD%^%^BLACK%^black smoke %^RESET%^%^ORANGE%^can be seen rising above a few small f%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s. More dragons can be seen flying south towards the ocean. They seem to be running away.%^RESET%^");
    set_items( ([ "smoke": "%^BOLD%^%^BLACK%^There are fires light all around." ]) );
    set_exits( ([ "south" : MARSHROOM+"BM_16", "north" : MARSHROOM+"BM_24" , "southwest" : MARSHROOM+"BM_14" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("gnome", this_object()))
	new(MARSHMON+"inferi_gnome")->move(this_object());
    if (!present("ogre", this_object()))
	new(MARSHMON+"inferi_ogre")->move(this_object());
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

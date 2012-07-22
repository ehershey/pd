#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^A small wand planted here and there shows where the path zigzags from tuft to tuft of %^GREEN%^green-scummed %^ORANGE%^pits and foul quagmires. Rank reeds and lush, %^GREEN%^slimy water-plants %^ORANGE%^send an odor of decay and a heavy miasmatic vapor into the air, while a false step of wanderers can plunge them thigh-deep into the %^BOLD%^%^BLACK%^dark quivering mire%^RESET%^%^ORANGE%^. Tenaciously, its grip plucks heels causing stray souls to sink as if some malignant hand was tugging them down into those obscene depths.%^RESET%^ ");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "water": "%^RESET%^%^BLUE%^The water is thick with mud and thick with bodies.  You see and feel dead things around you.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "southeast" : MARSHROOM+"BM_8", "north" : MARSHROOM+"BM_28", "northwest" : MARSHROOM+"BM_32", "southwest" : MARSHROOM+"BM_36" ]) );
    add_pre_exit_function("northwest", "sp_sap");
    add_pre_exit_function("southwest", "sp_sap");
    add_pre_exit_function("southeast", "sp_sap");
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

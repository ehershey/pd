#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^Recent %^BOLD%^%^BLUE%^rai%^CYAN%^nf%^BLUE%^all %^RESET%^%^ORANGE%^has caused the swamplands to swell, the water rising up to a few feet high. The reeds in this area have grown particularly thick, and together with the thick muddy water make travel difficult. A large rotting tree trunk lays just to the west, a swarm of flies filling the air over it. A badly decayed corpse rests inside the hollow log with its flesh half eaten by larva and birds.%^RESET%^ ");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "northeast" : MARSHROOM+"BM_26", "west" : MARSHROOM+"BM_38" ]) );
    add_pre_exit_function("northeast", "sp_sap");
    add_pre_exit_function("west", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("imp", this_object()))
	new(MARSHMON+"inferi_imp")->move(this_object());
    if (!present("faerie", this_object()))
	new(MARSHMON+"inferi_faerie")->move(this_object());
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

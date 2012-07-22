#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes strech as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "northwest" : "/wizards/amun/marshes/rooms/marsh_147", "northeast" : "/wizards/amun/marshes/rooms/marsh_149", "southeast" : "/wizards/amun/marshes/rooms/marsh_129", "south" :  "/wizards/amun/marshes/rooms/marsh_128", "southwest" : "/wizards/amun/marshes/rooms/marsh_127", "east" : "/wizards/amun/marshes/rooms/marsh_137", "west" : "/wizards/amun/marshes/rooms/marsh_140" ]) );
    new("/wizards/amun/marshes/mobs/inferi_centaur")->move(this_object());
    add_pre_exit_function("southeast", "sp_sap");
    add_pre_exit_function("southwest", "sp_sap");
    add_pre_exit_function("west", "sp_sap");
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

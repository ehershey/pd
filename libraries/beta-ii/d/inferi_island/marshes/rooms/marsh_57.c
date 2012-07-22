#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The smell of ash and brimstone fills the air. This area appears to have been the scene of a battle. A line of fire, possibly from a mighty red dragon cuts a black scar across the land. Charred, blackened rocks are half-melted to the ground. Small black clouds are tossed violently around by the strong winds.%^RESET%^"); 
    set_exits( ([ "north" : MARSHROOM+"marsh_56", "south" : MARSHROOM+"marsh_58" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}

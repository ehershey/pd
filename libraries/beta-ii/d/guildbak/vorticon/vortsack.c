#include <std.h>
inherit PACK;
void create() {
    ::create();
    set_id( ({"sack"}) );
    set_name("sack");
    set("short", "%^ORANGE%^hu%^BOLD%^m%^RESET%^%^RED%^an s%^ORANGE%^ki%^RED%^%^BOLD%^n s%^RESET%^%^ORANGE%^a%^BOLD%^c%^RESET%^%^BOLD%^%^RED%^k^");
    set_weight(19);
    set("long", "%^RED%^%^BOLD%^The sack of choice for members of the Ethereal Guild.  Keep it closed[close sack] to keep thieves away, but open it[open sack] if you want to place things inside.");
    set_curr_value("gold", 250);
    set_max_internal_encumbrance(900);
    set_possible_to_close(1);
}

int autoload() {
    if(this_player()->query_guild() == "vorticon")
	return 1;
}

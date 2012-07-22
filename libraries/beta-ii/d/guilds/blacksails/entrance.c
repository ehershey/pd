#include <std.h>
inherit ROOM;
void create() {
    object ob;
    room::create();
    set_properties( ([ "light" : 2, "outdoors" : 1]) );
    set_short("Deck of the Black Trident");
    set_long(
      "%^BLACK%^%^BOLD%^The deck of the Black trident, mother ship of the blacksails. The sun reflects off the puddles of water sloshing around the deck. Three oak masts Rise high into the air. Each mast has a black sail proudly flying from it. Atop the center and tallest mast sails the flag of the Blacksails: A black flag with twin scimitars crossed over a Bastet skull. Littered about the deck are many barrels of rum and other drink. This is where the pirates gather and discuss plans. A board hangs on the bow mast. A small wooden door leads down to the hold and a gang plank leads back to the docks%^RESET%^"
    );
    set_night_long(
      "%^BLACK%^%^BOLD%^The deck of the Black trident, mother ship of the blacksails. The moon reflects in the puddles of water sloshing around the deck. Three oak masts Rise high into the air. Each mast has a black sail proudly flying from it. Atop the center and tallest mast sails the flag of the Blacksails: A black flag with twin scimitars crossed over a Bastet skull. Littered about the deck are many barrels of rum and other drink. This is where the pirates gather and discuss future plans. A board hangs on the bow mast. A small wooden door leads down to the hold and a gang plank leads back to the docks. %^RESET%^"
    );
    set_items(([
	"barrels" : "Yo Ho Ho and a bottle of Rum!",
      ]));
    set_exits( (["work"  :  "/wizards/gob/workroom.c",
	"down" : "/wizards/gob/bsails2.c",
      ]) );
    set_smell("default", "The mixed smells of old rum and sea water fill the air.");
    set_listen("default", "Waves steadily slosh against the sides of the ship.");
    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({"board", "blacksails board"}) );
    ob->set_board_id("blacksails_board");
    ob->set_max_posts(50);
    ob->set_edit_ok( ({"gob", "trooper"}) );
    ob->set_location("/wizards/gob/room/bsails1");
    ob->set_short("The Board of Piracy");
    ob->set_long("Old and faded board, with many faded stains.");
}

void init() {
    add_action("step", "step");
}

int step(string str) {
    if (!str || str != "on plank") {
	return notify_fail("Step on what?\n");
    }
    write("You step on the plank");
    this_player()->move_player("/d/guilds/blacksails/hall");
    return 1;
}


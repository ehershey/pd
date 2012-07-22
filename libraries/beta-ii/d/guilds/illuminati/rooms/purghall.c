#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
    ::create();
    set_properties((["light":3, "indoors":1, "no scry":1]));
    set_name("Illuminati Purgatory Subhall");
    set_short("Illuminati Purgatory Subhall");
    set_long("%^ORANGE%^This is the Illuminati subhall of Purgatory, an outpost of the Tower of Light. Members often come here to escape the harsh heat and humidity of the jungle. Large chairs all make a perfect spot to %^BOLD%^WHITE%^<relax>%^RESET%^ORANGE%^.%^RESET%^"); 
    set_exits(([
	"south" : "/d/freepk/purgatory/room/purgatorysquare"
      ]));
    set_items(([
	"chairs"     : "The chairs are placed in a circle facing inwards to a magical flame that actually sucks the heat from the room. It would be great to %^CYAN%^<relax>%^RESET%^ in one."
      ]));
}

void reset() {
    object ob;
    ::reset();
    if(!present("joena")) {
	ob = new(ILMOB"rand.c");
	ob->set_name("Joena");
	ob->set_short("%^BOLD%^WHITE%^Joena%^RESET%^");
	ob->set_long("Joena lives here in the Merkkirri hall of the Illuminati, and in return sells restorative items to it's members.");
	ob->set_id(({ "joena" }));
	ob->set_gender("female");
	ob->move(this_object());
    }
}

void init() {
    ::init();
    add_action("sit", "relax");
    if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
	ILOBJ"ejection"->eject(this_player());
}

int sit(string str) {
    write("You sit down in the comfy chair and relax in the cool.");
    this_player()->set_paralyzed(3, "Ohhhhhh that feels good.");
    return 1;
}

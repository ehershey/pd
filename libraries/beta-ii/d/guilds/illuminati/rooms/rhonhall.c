#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_properties((["light":3, "indoors":1, "no scry":1]));
    set_name("Illuminati Rhondale Subhall");
    set_short("Illuminati Rhondale Subhall");
    set_long("%^ORANGE%^This is the Illuminati subhall of Rhondale, an outpost of the Tower of Light. Members often come here for no other reason than to simply %^BOLD%^WHITE%^<relax>%^RESET%^ORANGE%^ in one of the many large chairs.%^RESET%^"); 
    set_exits(([
	"north" : "/d/freepk/rhondale/rooms/zvillage/inouteast"
      ]));
    set_items(([
	"chairs"     : "The chairs are placed in a circle facing inwards. It would be great to %^CYAN%^<relax>%^RESET%^ in one."
      ]));
}

void reset() {
    object ob;
    ::reset();
    if(!present("hazel")) {
	ob = new("/d/guilds/illuminati/mobs/rand.c");
	ob->set_name("Hazel");
	ob->set_short("%^BOLD%^WHITE%^Hazel%^RESET%^");
	ob->set_long("Hazel lives here in the Rhondale hall of the Illuminati, and in return she sells restorative items to it's members.");
	ob->set_id(({ "hazel" }));
	ob->set_gender("female");
	ob->move(this_object());
    }
}

void init() {
    ::init();
    add_action("sit", "relax");
    if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
	"/d/guilds/illuminati/obj/ejection"->eject(this_player());

}

int sit(string str) {
    write("You sit down in the comfy chair and relax in the cool.");
    this_player()->set_paralyzed(3, "Ohhhhhh that feels good.");
    return 1;
}

#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
    ::create();
    set_properties((["light":3, "indoors":1, "no scry":1]));
    set_name("Illuminati Tenebrae Subhall");
    set_short("Illuminati Tenebrae Subhall");
    set_long("%^ORANGE%^This is the Illuminati subhall of Roston, and an outpost of the Tower of Light. Many members come here to escape the cold mountain air. Large chairs make a perfect spot to %^BOLD%^WHITE%^<relax>.%^RESET%^");
    set_exits(([
	"northwest" : "/d/roston/rooms/roston.c",
      ]));
    set_items(([
	"chairs"     : "The chairs are placed in a circle facing inwards around the center of the room. It would be great to sit and <relax> in one."
      ]));
}

void reset() {
    object ob;
    ::reset();
    if(!present("portal"))
	new(ILOBJ"portal.c")->move(this_object());
    if(!present("drizzl")) {
	ob = new(ILMOB"rand.c");
	ob->set_name("Drizz'l");
	ob->set_short("%^BOLD%^WHITE%^Drizz'l%^RESET%^");
	ob->set_long("Drizz'l lives and works within the Roston hall of the Illuminati. He makes and sells heartstones and angreals for guild members.");
	ob->set_id(({ "drizzl", "drizz'l" }));
	ob->set_race("drow");
	ob->set_body_type("elf");
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
    write("You sit down in the comfy chair and relax in the quiet.");
    this_player()->set_hp(this_player()->query_max_hp());
    this_player()->set_sp(this_player()->query_max_sp());
    this_player()->set_mp(this_player()->query_max_mp());
    this_player()->set_paralyzed(3, "Ohhhhhh that feels good.");
    return 1;
}

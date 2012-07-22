#include <std.h>
#include <aziraphale.h>
inherit ROOM;
int searchit;
void create() {
    ::create();
    set_properties((["light": 3, "night light" : 1, "forest" : 1]));
    set_short("Altar to the Sun");
    set_day_long("%^ORANGE%^A small clearing in the trees allows a single shaft of golden light to pierce the gloomy forest. Directly in the middle of the clearing is a large stone altar, with several stones scattered around it.%^RESET%^");
    set_night_long("%^CYAN%^A small clearing in the trees allows silvery beams of moonlight to shimmer through the air. Directly in the middle of the clearing is a large stone altar, with several stones scattered around it.%^RESET%^");
    set_exits(([
	"northwest"             : KEEPROOM"zforest/x11y9.c",
	"northeast"		: KEEPROOM"zforest/x11y11.c",
	"southeast"		: KEEPROOM"zforest/x13y11.c",
	"east"   		: KEEPROOM"zforest/x12y11.c",
	"south"	        	: KEEPROOM"zforest/x13y10.c"
      ]));
    set_items(([
	"stones": "The stones are scattered all about, it'd take a thorough search to turn up anything of note."
      ]));
    searchit = 1;
    new(KEEPARMOUR"zforest/sunaltar.c")->move(this_object());
}

void init() {
    ::init();
    add_action("readin", "read");
    add_action("placin", "place");
    add_action("searchin", "search");
}

int readin(string str) {
    if(str != "writing") return 0;
    message("read", "\n\n%^YELLOW%^ < .nuS eht sa ti ekam ot ratla eht no ti ecalP - .eno tcefrep eht rof senots eht hcraeS >%^RESET%^\n", this_player(), );
    message("read", this_player()->query_cap_name()+" reads the writing around the altar.", this_object(), this_player());
    return 1;
}

int placin(string str) {
    object tp;
    tp = this_player();
    if(str != "stone on altar") return 0;
    if(present("worthmark", this_player()) || present("sunstone", this_player()) || member_array("kratoan", this_player()->query_quests()) != -1 || this_player()->query_property("killersmark") == 1) return notify_fail("Why bother? You already found what you need.\n");
    if(query_night()) return notify_fail("The darkness of night nothing happens.\n");
    if(!present("spherestone", tp)) return 0;
    present("spherestone", tp)->remove();
    message("info", "You place the stone on the altar.", this_player(), );
    message("info", this_player()->query_cap_name()+" places a spherical stone on the altar.", this_object(), this_player());
    call_out("done", 3, tp);
    return 1;
}

int searchin(string str) {
    if(str != "stones") return 0;
    if(present("worthmark", this_player()) || present("spherestone", this_player()) || present("sunstone", this_player()) || member_array("kratoan", this_player()->query_quests()) != -1 || this_player()->query_property("killersmark") == 1) { write("Why bother? You already found what you need."); return 1; }
    if(searchit == 0) {
	message("info", "You search through the stones but find nothing of interest.", this_player(), );
	message("info", this_player()->query_cap_name()+"searches through the stones yet finds nothing of interest.", this_object(), this_player());
	return 1;
    }
    message("info", "You find a wondrously spherical stone amongst the jumble.", this_player(), );
    message("info", this_player()->query_cap_name()+" finds an interesting stone and pockets it.", this_object(), this_player());
    new(KEEPARMOUR"zforest/spherestone.c")->move(this_player());
    searchit = 0;
    return 1;
}

int done(object tp) {
    message("info", "%^YELLOW%^The stone suddenly beings to glow brightly and "+tp->query_cap_name()+" picks it up.", this_object(), tp);
    message("info", "%^YELLOW%^The stone suddenly begins to glow brightly.%^RESET%^", tp, );
    message("info", "You get a glowing yellow stone from the altar.", tp, );
    new(KEEPARMOUR"zforest/sunstone.c")->move(tp);
    return 1;
}

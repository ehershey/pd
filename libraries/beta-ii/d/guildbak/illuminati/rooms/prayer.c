#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
    ::create();
    set_properties((["light":3, "indoors":1, "no scry":1]));
    set_name("Illuminati Tower");
    set_short("Illuminati Tower");
    set_long("%^BOLD%^WHITE%^The Tranquil Garden.\n%^RESET%^GREEN%^The room is filled by beautiful plants and trees. A shallow pool of perfectly clear crystal water is fed by a natural fountain. This place is so peaceful that many come to %^RESET%^<pray> %^GREEN%^here.%^RESET%^");
    set_smell("default", "Pure life fills this place.");
    set_listen("default", "The peaceful sound of birds singing.");
    set_items(([
	"garden"      : "The garden is filled with all kinds of plants.",
	"pools"       : "The shallow pools are filled with perfectly clear water."
      ]));
    set_exits(([
	"west"        : ILROOM"floor3.c"
      ]));
}

void init() {
    ::init();
    add_action("pray", "pray");
    if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
	ILOBJ"ejection"->eject(this_player());
}

int pray() {
    //this_player()->new_body();
    this_player()->fix_vital_bonus();
    this_player()->set_hp(this_player()->query_max_hp());
    this_player()->set_mp(this_player()->query_max_mp());
    this_player()->set_sp(this_player()->query_max_sp());
    this_player()->set_paralyzed(3, "You pray to the gods of life.");
    write("You pray to the gods of life.");
    return 1;
}

#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
    object oi;
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set_name("Illuminati Tower");
    set_short("Illuminati Tower");
    set_long("%^ORANGE%^This is the discussion hall of the Illuminati. There is a board in the middle of the room where all members encouraged to post their thoughts and requests.%^RESET%^");
    set_exits(([
	"northwest"     : ILROOM"floor4.c"
      ]));
    oi = new("/std/bboard");
    oi->set_name("Illuminati Board");
    oi->set_id( ({ "board", "illuminati board", "__ilboard" }) );
    oi->set_board_id("Illuminati_Tower_Board");
    oi->set_max_posts(99);
    oi->set_edit_ok(({"furiae", "goldenberry"}));
    oi->set_location(ILROOM"board.c");
    oi->set("short", "%^YELLOW%^Holy %^WHITE%^board of the %^YELLOW%^Illuminati%^RESET%^");
    oi->set("long", "This board is for the members of the Illuminati. \n");
}

void init() {
    ::init();
    if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
	ILOBJ"ejection"->eject(this_player());
}

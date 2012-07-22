#include <std.h>
#include <guild.h>
inherit ROOM;

void init() {
    ::init();
#ifndef NO_START
    add_action("fstart", "start");
#endif
}

void create()
{
    object oi;
    ::create();
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );
    set_name("Illuminati Board Room");
    set_short("Illuminati Board Room");
    set_long("%^RESET%^%^ORANGE%^This is the discussion hall of the illuminati. There is a "
      "%^RESET%^%^ORANGE%^board in the middle of the room where all members can post "
      "%^RESET%^%^ORANGE%^their thoughts and requests.");
    set_exits(([
        "northwest"     : ROOMS"illuminati/new/floor4.c"
      ]));
    oi = new("/std/bboard");
    oi->set_name("Illuminati Board");
    oi->set_id( ({ "board", "illuminati board" }) );
    oi->set_board_id("Illuminati_Board");
    oi->set_max_posts(99);
    oi->set_edit_ok(({"aziraphale", "halo", "gabriel"}));
    oi->set_location(ROOMS"illuminati/new/board.c");
    oi->set("short", "%^BOLD%^%^YELLOW%^Holy %^WHITE%^board of the %^YELLOW%^Illuminati%^RESET%^");
    oi->set("long", "This board is for the members of the Illuminati. \n");
}

int fstart(string str) {
    if (!str || str=="") {
        notify_fail("Start where?\n");
        return 0;
    }
    if (str!="here") {
        notify_fail("You cannot start there.\n");
        return 0;
    }
    if(this_player()->query_original_guild() == "illuminati")
      this_player()->set_primary_start("/d/guilds/illuminati/new/board");
    else
    if(this_player()->query_original_guild() == "aod")
      this_player()->set_primary_start("/d/guilds/AoD/hall");
    else
      this_player()->set_primary_start("/d/guilds/"+this_player()->query_original_guild()+"/hall");
    write("You are now set to start in the "+capitalize(this_player()->query_guild())+
      " hall.\n");
    return 1;
}


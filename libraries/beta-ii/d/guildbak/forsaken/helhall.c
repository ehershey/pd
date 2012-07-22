#include <daemons.h>
#include <std.h>
#include <guild.h>
inherit ROOM;

void create() {
    object board;
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

    set_name("Hall of the Forsaken");
    set_long("You have entered Forsaken's secret hall in Helgrath. The "
      "detailed designs and pictures of exotic looking demihumans and extra-planar "
      "beings are etched all along the walls. They seem to glow as you walk past "
      "them and they spurt forth the piercing blue coldfire from their eyes. The fire "
      "gathers in the middle of the room, swirling and dancing as it forms an enormous "
      "clawed hand, which reaches towards the ceiling.");
    set_items(([
	"sword" : "An inscription reads 'The Forsaken. He who does battle with "
	"monsters must see to it that he does not himself become a monster. When you "
	"gaze long into the abyss, the abyss also gazes into you.'",
      ]));
    set_exits(([
	"out" : "/d/helgrath/rooms/wilndursquare_wm.c",
	"south" : ROOMS"forsaken/helportal",
      ]));
    board = new("/std/bboard");
    board->set_name("Forsaken's Helgrath board");
    board->set("long", "This is the board for the Forsaken's guild.  Members "
      "post on anything from ideas to assassinate missions.");
    board->set_edit_ok(GUILD_D->post_able("forsaken"));
    board->set("short", "Forsaken's board");
    board->set_max_posts(99);
    board->set_board_id("forsaken");
    board->set_location("/d/guilds/forsaken/helhall");
    board->set_id(({"board", "forsakens board", "forsaken board", "guild board"}));
}

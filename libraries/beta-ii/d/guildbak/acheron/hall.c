#include <daemons.h>
#include <std.h>
inherit ROOM;
//Coded by a nutcase
void create() {
    object board;
    ::create();
    set_short("Main Hall of Acheron");
    set_long("%^BOLD%^%^BLUE%^The hall of %^BOLD%^%^CYAN%^A%^BOLD%^%^BLACK%^ch"
      "%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^ro%^BOLD%^%^CYAN%^n%^RESET%^%^%^BOLD%^"
      "%^BLUE%^ stands well lit with portraits of past "
      "%^BOLD%^%^BLUE%^warriors in battle. The main board, where guild issues "
      "are %^BOLD%^%^BLUE%^brought to attention, stands in the middle of the "
      "room. %^BOLD%^%^BLUE%^Behind the door is a plaque that looks meant to "
      "be read.");
    set_properties(([
	"light"       : 2, 
	"night light" : 2, 
	"no teleport" : 1, 
	"no attack"   : 1,  
	"no magic"    : 1,
	"no bump"     : 1,
	"no steal"    : 1,
	"indoors"     : 1,
      ]));

    set_items(([
	"plaque" : "%^RESET%^%^ORANGE%^The %^BOLD%^%^RED%^Rules%^RESET%^"
	"%^ORANGE%^ of Acheron:\n %^RESET%^    %^BOLD%^%^RED%^1. "
	"%^RESET%^%^ORANGE%^One does not kill another in same guild."
	"\n%^RESET%^     %^BOLD%^%^RED%^2. %^RESET%^%^ORANGE%^One does "
	"not steal from their own guild.\n%^RESET%^     %^BOLD%^%^RED%^3."
	"%^RESET%^%^ORANGE%^ One respects %^BOLD%^%^RED%^all%^RESET%^"
	"%^ORANGE%^ Leaders and Council.\n\n%^RESET%^%^RESET%^%^ORANGE%^"
	"If these rules are not abided, thou shall be %^BOLD%^%^RED%^"
	"punished%^RESET%^%^ORANGE%^.%^RESET%^ "]));
    set_exits(([
	"down" : "/d/guilds/acheron/treasury",
	"up":"/d/guilds/acheron/vote",
	"out" : "/d/guilds/acheron/entrance",
	"hall" : "/d/guilds/meeting",
	"east" : "/d/guilds/acheron/prayer_room",
	"north" : "/d/guilds/acheron/oil_shop",
	"south" : "/d/guilds/acheron/lockerar",
	"west" : "/d/guilds/acheron/shop",
      ]));
    board = new("/std/bboard");
    board->set_board_id("Acheron_Board");
    board->set_id(({"board", "acheron board"}));
    board->set_name("Acheron Board of Inspiration");
    board->set_short("Acheron Board of Inspiration");
    board->set_long("The Acheron board of inspiration is here so that the many "
      "members may post their ideas and insights for everyone to see.");
    board->set_location("/d/guilds/acheron/hall.c");
    board->set_edit_ok(GUILD_D->post_able("acheron"));
    board->set_max_posts(100);
    board->set_board_name("Acheron Board");
}


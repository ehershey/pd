#include <std.h>
inherit ROOM;
//Coded by a nutcase
void create() {
object board;
  ::create();
    set_short("Helgrath Sub-hall of Acheron");
    set_long(
"%^BOLD%^%^BLUE%^This hall is much smaller then the %^BOLD%^%^CYAN%^A%^BOLD%^%^BLACK%^ch%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^ro%^BOLD%^%^CYAN%^n%^RESET%^%^%^BOLD%^%^BLUE%^ main hall. Hidden underground it is "
"%^BOLD%^%^BLUE%^the perfect place to get away from others. From the small sky window you can "
"%^BOLD%^%^BLUE%^see the Helgrath Square. Stairs upwards lead there and west is the way back to " 
"%^BOLD%^%^BLUE%^Tirun.");
    set_properties(([
        "light" : 1,
        "night light" : 1,
        "no teleport" : 1,
        "no attack"   : 1,
    ]));
    set_items(([
        "plaque" : "%^RESET%^%^ORANGE%^The %^BOLD%^%^RED%^Rules%^RESET%^%^ORANGE%^ of Acheron:\n %^RESET%^    %^BOLD%^%^RED%^1. %^RESET%^%^ORANGE%^One does not kill another in same guild.\n%^RESET%^     %^BOLD%^%^RED%^2. %^RESET%^%^ORANGE%^One does not steal from their own guild.\n%^RESET%^     %^BOLD%^%^RED%^3.%^RESET%^%^ORANGE%^ One respects %^BOLD%^%^RED%^all%^RESET%^%^ORANGE%^ Leaders and Council.\n\n%^RESET%^%^RESET%^%^ORANGE%^If these rules are not abided, thou shall be %^BOLD%^%^RED%^punished%^RESET%^%^ORANGE%^.%^RESET%^ ",
        "window" : "People walk across the window, not noticing that eyes are peering up at them."]));
    set_exits(([
        "up" : "/d/guilds/acheron/helentrance",
        "west" : "/d/guilds/acheron/helportal",
    ]));
board = new("/std/bboard");
board->set_board_id("Acheron_Board");
board->set_id(({"board", "acheron board"}));
board->set_name("Acheron Board of Inspiration");
board->set_short("Acheron Board of Inspiration");
board->set_long("The Acheron board of inspiration is here so that the many members may post their ideas and insights for everyone to see.");
board->set_location("/d/guilds/acheron/helhall.c");
board->set_edit_ok(({"artanis", "eios"}));
board->set_max_posts(100);
board->set_board_name("Acheron Board");
}

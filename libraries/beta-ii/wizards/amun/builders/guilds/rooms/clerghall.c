#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit HALL;
object bb;
void create() {
    ::create();
    set_type("clergy");
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set_short("Board Room");
    set("long","%^BOLD%^%^WHITE%^This is a place for clergy, men and women, to come and train, improve and level to be the best at what they do. There are many shelves filled with books for those who wish to study. This is also a room for clergy members to share their wisdom with others like themselves. They place their ideas, concerns and general comments on the board.%^RESET%^");
    set_items( ([ "shelves" : "%^BOLD%^%^WHITE%^The shelves are piled high with books to read.%^RESET%^", "books" : "%^BOLD%^%^WHITE%^The books line the shelves for those who wish to read through them.%^RESET%^" ]) );
    set_exits( ([ "northeast" : GROOM "r_main4" ]) );
    bb = new("std/bboard");
    bb->set_name("Temple Clergy Board");
    bb->set_id( ({ "board", "guild", "clergy", "clergy board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nulvect", "daos", "whit", "daboura", "luna", "amun" }) );
    bb->set_location(GROOM "clerghall");
    bb->set_short("%^BOLD%^%^WHITE%^Clergy Board%^RESET%^");
    bb->set_long("%^BOLD%^%^WHITE%^This board is for all those who wish to share their adventures and concerns.%^RESET%^");
    bb->set_board_id("guild_clergy_board");
    bb->move(environment(this_object()));
}
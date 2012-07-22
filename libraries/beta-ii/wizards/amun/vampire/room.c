#include <std.h>
#include <vampq.h>
inherit ROOM;
object ob;
void create() {
    ::create();
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set("short", "Vampire Workroom");
    set_long("%^BOLD%^%^BLACK%^Let's work on the Vampire Quest! YAY!%^RESET%^");
    set_smell("default", "%^BOLD%^%^BLACK%^It smells like death and decay...%^BOLD%^%^RED%^not to mention blood.%^RESET%^");
    set_exits( ([ "tirun" : "/d/nopk/tirun/square" ]) ); 
    ob = new("/std/bboard");
    ob->set_max_posts(500);
    ob->set_board_id("vampire board");
    ob->set_location("/wizards/amun/vampire/room");
    ob->set_id(({ "board", "vampire board" }));
    ob->set_short("%^BOLD%^%^BLACK%^Vampire Project Board%^RESET%^");
    ob->set_long("%^BOLD%^MAGENTA%^This is the board the Amun and Daos use to write there ideas down. Please feel free to leave them a msg.%^RESET%^\n");
    ob->set_name("Vampire Project Board");
    ob->set_edit_ok( ({"amun", "daos"}) );
    ob->move(environment(this_object()));
}

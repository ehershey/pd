#include <std.h>
#include <diran.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" : 1, "light" : 2, "night light" : 2]) );
set_smell("default", "The smell of smoke is strong in the square.");
set_listen("default", "The commotion of the busy city is concentrated here.");
set_short("Diran city square");
set_long("%^BOLD%^%^WHITE%^The city square of Diran is a large, open space surrounding a giant bonfire.  Smoke billows from the fire and fills up the entire space.  A messaging board hangs from a post near the fire.  There are blankets and logs surrounding the fire for sleeping and resting on.");
set_exits(([ "north" : ROOMS "mountaindwarf/79.c",
 "east" : ROOMS "mountaindwarf/77.c",
"south" : ROOMS "mountaindwarf/85.c"]));
    set_items( ([
({"blankets"}):"Blankets of all colors and sizes look quite comfortable and welcoming.",
"logs":"Large logs surround the bonfire, ready to be sat on.",
]) );
    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "diran board" }) );
    board->set_max_posts(99);
board->set_edit_ok(({"WS_MAYOR"}));
    board->move(this_object());
    board->set("short", "%^BOLD%^%^BLACK%^Diran Board%^RESET%^");
    board->set("long", "A small board in the middle of the Dwarven City.  A note is scratched onto the board, saying messages are magically synced with the board of Whitestorm.\n");
    board->set_board_id("adv_board");
}
void reset() {
    ::reset();
        if(!present("bonfire"))
          new(OBJ "bonfire")->move(this_object());
    if(!present("mdguard")){
        new(MOB"mdguard")->move(this_object());
        new(MOB"mdguard")->move(this_object());
}
}
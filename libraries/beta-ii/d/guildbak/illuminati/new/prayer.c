//Prayer room
#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":3, "indoors":1, "no attack":1]));
set_name("Illuminati Prayer Room");
set_short("Illuminati Prayer Room");
set_long("%^RESET%^%^ORANGE%^The Tranquil Garden. You are surrounded by beautiful plants and "
"trees. The shallow pools of clear water are fed by a small waterfall.");
set_smell("default", "Pure life fills this place.");
set_listen("default", "The sound of birds chirping fills your ears.");
set_items(([
"garden"      : "The garden is filled with all kinds of plants.",
"pools"       : "The shallow pools are filled with perfectly clear water."
]));
set_exits(([
"west"        : ROOMS"illuminati/new/floor3.c"
]));
}
void init() {
    ::init();
    add_action("pray", "pray");
}
int pray() {
    int x;
    x = this_player()->query_max_hp() - this_player()->query_hp();
    this_player()->add_hp(x);
    x = this_player()->query_max_sp() - this_player()->query_sp();
    this_player()->add_sp(x);
    x = this_player()->query_max_mp() - this_player()->query_mp();
    this_player()->add_mp(x);
    this_player()->set_paralyzed(3);
    write("You pray to the gods");
    return 1;
}

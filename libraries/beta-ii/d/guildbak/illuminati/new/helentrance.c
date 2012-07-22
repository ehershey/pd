#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":3, "indoors":1]));
set_name("Illuminati Helgrath Subhall Entrance");
set_short("Illuminati Helgrath Subhall Entrance."); 
set_long("%^RESET%^%^ORANGE%^This is the entrance to the Helgrathian subhall of the Illuminati. "
"Stairs lead down to the inner sanctum, and a door in the south wall leads back "
"out to the harsh cold."); 
set_exits(([
        "down"          : ROOMS"illuminati/new/helhall.c",
        "south"         : "/d/helgrath/rooms/marketrd_w01"
]));
set_listen("default", "The wind whistles outside.");
}

void init() {
   ::init();
     add_action("enter", "down");
}

int enter() {
    object tp;
    tp = this_player();
    if (tp->query_guild() != "illuminati" && !wizardp(tp)) {
       message("info", "%^RESET%^%^CYAN%^A shadow says:%^RESET%^ You are not welcome here!", environment(tp), );
       message("info", "%^BOLD%^%^WHITE%^A blinding light %^YELLOW%^consumes%^WHITE%^ "+tp->query_cap_name()+"!%^RESET%^", environment(tp), tp);
       write("%^BOLD%^%^WHITE%^A blinding light %^YELLOW%^consumes%^WHITE%^ you!%^RESET%^");
       tp->add_hp(-5);
       tp->add_sp(-5);
       tp->add_mp(-5);
       write("hp: "+tp->query_hp()+"   sp: "+tp->query_sp()+"   mp: "+tp->query_mp()+"");
       return 1;
       }
    write("You walk down the stairs to the inner sanctum.");
    message("info", ""+tp->query_cap_name()+" walks down the stairs to the inner sanctum.", environment(tp), tp);
    tp->move_player(ROOMS"illuminati/new/helhall.c");
    return 1;
}

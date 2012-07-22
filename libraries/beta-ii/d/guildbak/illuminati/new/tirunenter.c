#include <daemons.h>
#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":3, "indoors":1]));
set_name("Illuminati Tirun Subhall Entrance");
set_short("Illuminati Tirun Subhall Entrance.");
set_long("%^RESET%^%^ORANGE%^Here is the entrance to the Illuminati hall of Tirun. The room is "
"bare except for stairs on the back wall leading to the second floor.%^RESET%^"); 
set_exits(([
        "north"         : "/d/nopk/tirun/seganthus2.c",
        "up"            : ROOMS"illuminati/new/tirunhall.c"
]));
set_listen("default", "The sounds of the city can be heard outside.");
}

void init() {
   ::init();
     add_action("enter", "up");
}

int enter() {
    object tp;
    tp = this_player();
   if (GUILD_D->query_guild(tp->query_name()) != "illuminati" && !wizardp(tp))
{
       message("info", "%^RESET%^%^CYAN%^A shadow says:%^RESET%^ You are not welcome here!", environment(tp), );
       message("info", "%^BOLD%^%^WHITE%^A blinding light%^YELLOW%^ consumes%^WHITE%^ "+tp->query_cap_name()+"!%^RESET%^", environment(tp), tp);
       write("%^BOLD%^%^WHITE%^A binding light %^YELLOW%^consumes you!%^RESET%^");
       tp->add_hp(-5);
       tp->add_sp(-5);
       tp->add_mp(-5);
       write("hp: "+tp->query_hp()+"   sp: "+tp->query_sp()+"   mp: "+tp->query_mp()+"");
       return 1;
       }
    write("You walk up the stairs to the inner sanctum.");
    message("info", ""+tp->query_cap_name()+" walks up the stairs to the inner sanctum.", environment(tp), tp);
    tp->move_player(ROOMS"illuminati/new/tirunhall.c");
    return 1;
}

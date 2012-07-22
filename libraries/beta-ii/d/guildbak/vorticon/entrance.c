//Entrance room
//entrance.c
// only guild members should be able to enter the crypt
// the southeast should lead back to the room (n,n,n,e,e,n) (the monastary)
// that room should have an INVISIBLE exit which leads to this room :)

#include <daemons.h>
#include <std.h>
#include <guild.h>

inherit "/std/room";

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 2);
    set_property("no magic", 1);
    set_property("no attack", 1);
    set_property("no castle", 1);
    set_property("no steal", 1);
    set_property("no teleport", 1);
    set_property("no scry", 1);
    set_short("Hidden on a path");
    set_long("Hidden besides the monastery this corridor leads "
      "to a crypt deep in the ground towards the north. "
      "%^BOLD%^BLACK%^Dar%^WHITE%^k%^RESET%^WHITE%^n%^BOLD%^e"
      "%^BLACK%^ss%^RESET%^ seems to linger around the crypt "
      "preventing any natural light from reaching the crypt. "
      "Torches line each side of the corridor glowing %^BOLD"
      "%^RED%^blood red%^RESET%^.");
    set_listen("default", "Chanting can be heard all around.");
    set_exits(([
        "southeast": "/d/nopk/tirun/monastery",
	"crypt": VORTICON "hall.c"
      ]));
    set_items(([
	"monastery": "The Tirun monastery is to the southeast of this "
	"passage.",
	"crypt": "The crypt cannot be seen through the darkness.",
	"darkness": "It is no natural darkness, it permanently conceals "
	"the appearance to the crypt from outsiders.",
	"torches": "They provide unnatural light."
      ]));
    set_pre_exit_functions( ({"crypt"}), ({"go_crypt"}) );
}

int go_crypt() {
    object ob=this_player();
    if(GUILD_D->query_locked() && !wizardp(this_player())) return
      notify_fail(GUILD_D->query_lock_reason());


    if(ob->query_original_guild() != "vorticon" && !wizardp(ob)) {
	write("You are thrown back and prevented access to the crypt.\n");
	message("environment", ob->query_cap_name()+" is thrown back "
	  "from the crypts entrance.", environment(this_player()), ({ob}) );
     return 0;
    }
    return 1;
}


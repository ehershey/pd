#include <std.h>
#include <guild.h>
#include <daemons.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Entrance to the Guild of the Unholy");
    set_long("This is the inside of the Tirun wall.  Part of it is hollow, "
      "with an awkward crack for an opening. "  
      "A ladder leads down into a dark hole.");
    set_items(([
        "crack" : "The crack leads back into the town.",
        "ladder" : "The ladder decending into the dark has copper rungs, which have decayed to an old green colour."    
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 2,
        "night light" : 2,
        "no teleport" : 1,
        "no kill" : 1,
        "no bump" : 1,
    ]));
    set_exits(([
        "crack" : "/d/nopk/tirun/wgate",
        "down" : ROOMS "unholy/hall.c",        
    ]));
}
void init() {
::init();
add_action("down", "down");
}
int down_closed() {
write("All guilds are currently suspended.  Please see Whit for more information.");
return 1;
}
int down() {
if(this_player()->query_guild()!="unholy" && !wizardp(this_player())) {
write("Only guild members may enter!");
return 1;
}
    if(GUILD_D->query_locked() && !wizardp(this_player())) return
      notify_fail(GUILD_D->query_lock_reason());

this_player()->move_player(ROOMS"unholy/hall");
say(this_player()->query_cap_name()+" leaves down into the heart of the guild.");
return 1;
}

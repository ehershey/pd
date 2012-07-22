// Coded by Whit

#include <daemons.h>
#include <guild.h>
#include <std.h>
inherit ROOM;

int down(string str);

void reset() {
    ::reset();
    if(!present("guild guard"))
        new("/d/guilds/scorpio/guard.c")->move(this_object());
}


void init() {
    ::init();
    add_action("down", "down");
}
void create() {
    ::create();
    set_short("Black Force Guild Entrance");
    set_properties( (["light" : 3, "night light" : 2]) );
    set_smell("default", "The smell of Death lingers through here.");
    set_long("This is the begining of the hidden depths of the "
      "Scorpio guild.  The only source of light comes from a "
      "small, black sphere floating overhead.   A stairwell leads down "
      "into the heart of the guild.");
    set_exits( (["down" : "/d/guilds/scorpio/hall"
        ,"out" : "/d/nopk/tirun/wganthus2"
      ]) );
}


int down(string str) {
    if(this_player()->query_guild() != "scorpio" && 
      !wizardp(this_player())) {
        write("You are not part of the Guild.");
        return 1;
    }
    if(GUILD_D->query_locked() && !wizardp(this_player())) return
      notify_fail(GUILD_D->query_lock_reason());

    this_player()->move_player("/d/guilds/scorpio/hall");
    return 1;
}

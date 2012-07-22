#include <std.h>
#include <tirun.h>

inherit ROOM;

void init() {
    ::init();
    add_action("fiat", "fiat");
    add_action("touch", "touch");

}

void create()
{

    ::create();
    set_short("North Stables");
    set_long("The stable looks like its a clean place for "
      "horses to stay in. There is a bail of hay on the "
      "ground, along with a huge water trench. Horses "
      "roam around here freely.");
    set_listen("default", "The sounds of horses neiighing fills your ears.");
    set_smell("default", "The smell of manure fills your senses.");
    set_exits ( ([ "out" : ROOMS "nveros7" ]) );

}

void reset()
{
    ::reset();
    if (!present("horse"))
    {
	new(MOB"horse")->move(this_object());
	new(MOB"horse")->move(this_object());
    }
    //    if(present("ethereal_guild_orb", this_object()))
    //present("ethereal_guild_orb", this_object())->remove();
}
// fiat justitia, ruat caelum
int fiat(string s) {
    if(s != "justitia, ruat caelum") return 0;
    if (this_player()->query_guild() != "ethereal") return notify_fail("You are not a member of this guild!\n");
    write("%^BOLD%^Welcome to the Hall of Ethereal.  We are currently allies "
      "with: Unholy. To exit this guild at any time, you should chant our "
      "motto, \"fiat justitia, ruat caelum\".  To belong to this guild is a "
      "privilege, not a right. We do have rules here. You can view the rules at "
      "any time while in the hall by simply typing <rules>. Happy Mudding%^RESET%^.");
    this_player()->move_player("/d/guilds/newethereal/ethereal/room/1-1.c");
    return 1;
}


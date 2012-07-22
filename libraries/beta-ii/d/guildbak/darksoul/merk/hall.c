#include <std.h>
#include <guild.h>
#include <mjungle.h>

inherit ROOM;
string query_edit();
void create() {
    object board = new(BBOARD);
    ::create();

    set_properties(([ "light":1, "night light":1, "no steal":1,
        "no bump":1, "no scry":1, "no gate":1, "no castle":1, "no attack":1,
        "no teleport":1 ]));
    set_name("Darksouls Hall");
    set_short("darksouls on merk");
    set_long("%^BOLD%^%^BLACK%^This is the meeting spot of the "
      "D%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^r%^BOLD%^%^WHITE%^k%^BOLD%^%^BLACK%^ "
      "S%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^u%^BOLD%^%^WHITE%^l%^BOLD%^%^BLACK%^s. "
      "%^BOLD%^%^BLACK%^This is where %^BOLD%^%^BLACK%^they come to go over the kills of the day, "
      "%^BOLD%^%^BLACK%^or problems that %^BOLD%^%^BLACK%^have arisen in the guild. Tons of "
      "%^BOLD%^%^BLACK%^corpses are strewn %^BOLD%^%^BLACK%^haphazardly on the floor. Pools of "
      "%^RESET%^%^RED%^blood%^BOLD%^%^BLACK%^ are all over the %^BOLD%^%^BLACK%^ground. The message "
      "%^BOLD%^%^BLACK%^for all people who are not part of this %^BOLD%^%^BLACK%^group that happen "
      "%^BOLD%^%^BLACK%^to set foot in here is %^BOLD%^%^WHITE%^You Do Not Have To "
      "%^BOLD%^%^WHITE%^Fear Us Unless You Are Alive.");
    set_exits(([
        "north" : ROOMS"darksoul/merk/shop",
        "south" : ROOMS"darksoul/merk/store",
        "east" : ROOMS"darksoul/merk/pray",
        "west" : MJUNGLE"mjungle12", ]));
    board->set_name("Dark Souls Board");
    board->set_id( ({ "board", "dark board", "souls board" }) );
    board->set_board_id("Dark_Souls_Board");
    board->set_max_posts(100);
    board->set_edit_ok(({"wraith"}));
    board->set_location(ROOMS"darksoul/merk/hall");
    board->set("short", "%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k "
      "%^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s "
      "%^WHITE%^B%^BLACK%^o%^WHITE%^a%^BLACK%^r%^WHITE%^d");
    board->set("long", "This board is for the members of Dark souls");
}

void init() {
    ::init();
    add_action("reclaim", "reclaim");
}

int reclaim() {
    if (this_player()->query_guild() != "darksoul")
        return notify_fail("um no\n");

    if (!present("guild ring", this_player())) {
        write("A ring appears in your hand.\n");
        say("A ring appears in "
          +this_player()->query_cap_name()+"'s hand.");
        new("/d/guilds/darksoul/ring")->move(this_player());
        return 1;
    }
    write("You already have your ring.\n");
    return 1;
}

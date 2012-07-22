#include <std.h>
#include <ace.h>
#include <daemons.h>

inherit ROOM;

string *guilds = ({ "AoD" });
void init() {
    ::init();
    add_action("move_machine", "move");
}

void create() {
    ::create();
    set_properties( ([ "indoor" : 1, "light" : 2, "night light" : 2]) );
    set_property("no castle", 1);
    set_property("no attack", 1);
    set_short("The hall.");
    set_long(
      "The Drowning Fish Casino\n"
      "Welcome to the Casino!  Gambling can be heaps of "
      "fun.  Many have struck it rich, while others have lost it "
      "all.  Several games of chance are waiting for the next "
      "winner.");
    set_items( ([
        (({"roulette"})) : "A roulette table set up in another area of "
        "the casino.",
        (({"bones"})) : "A dice game set up in another area of the casino."
      ]) );
    set_exits( (["down" : "/d/nopk/tirun/pub",
        "roulette" : ROOMS "casino",
        "bones" : ROOMS "bone"]) );
}

int move_machine(string str) {
    if(!str) {
        notify_fail("move what?\n");
        return 0;

    }
    if(str != "machine") {
        notify_fail("You can't move that!\n");
        return 0;
    }

    message("info", (string)this_player()->query_cap_name()+" moves the machine "
      "aside. ", this_object(), ({ this_player() }));
    message("info", "The machine moves aside.", this_player());
    add_exit("/d/guilds/AoD/hall", "enter");
    add_pre_exit_function("enter", "do_enter");
    call_out("go_hole", 10);
    return 1;
}

int do_enter() {
    if(!wizardp(this_player()) &&
member_array(this_player()->query_guild(),guilds)==-1) {
        write("A magical force holds you back.");
        return 0;
    }
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
      notify_fail(GUILD_D->query_lock_reason());

    return 1;
}

void go_hole() {
    message("info", "The machine slides back in place.",
      all_inventory(this_object()));
    remove_exit("enter");
}
void reset() {
    ::reset();
    if(!present("slot", this_object()))
        new(OTHER "slot.c")->move(this_object());
}


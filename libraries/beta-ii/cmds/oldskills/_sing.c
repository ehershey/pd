#include <std.h>
#define SDIR "/cmds/song/"
#define MASTER "/cmds/song/master"
#define FAIL "You do not know that song.\n"
inherit DAEMON;

int abil();

static object song;

int cmd_sing(string str) {
    object ob, tp, env;
    string what, target;
    tp = this_player();
    env = environment(tp);

    if (!abil()) {
	write("What?\n");
	return 1;
    }

    if (!str) return notify_fail("Sing what?\n");
    if (sscanf(str, "%s to %s", what, target) != 2) {
	what = str;
	target = tp->query_name();
    }
    if (!(ob = present(target, environment(tp))))
	return notify_fail("You do not see that here.\n");
    if (!ob->is_living())
	return notify_fail("You sing it a lullaby, but don't seem to get any thanks..\n");
    if (env->query_property("no attack") || env->query_property("no magic"))
	return notify_fail("You cannot sing here.\n");
    if (present("a_bard_song", tp))
	return notify_fail("You are already singing a song!\n");
    if(this_player()->query_ghost())
        return notify_fail("Your voice is hollow and ineffective.\n");
    // Find the song in MASTER
    if (MASTER->find_song(what))
	song = new(MASTER->find_song(what)); // song found -> use it
    else {
	if (song) song->remove();
	return notify_fail(FAIL); // song not found -> fail
    }
    // See if you can sing it
    if (!song->check_sing(tp)) {
	if (song) song->remove();
	return notify_fail(FAIL);
    }
    // Stops players from testing bad songs on themselves
    if (song->query_type() == "bad" && ob == tp)
	return notify_fail("You would not like to sing this song to yourself.\n");
    // Prevents players from attacking themselves
    if (song->query_auto())
	if(!this_player()->kill_ob(ob)) {
	    write(ob->query_cap_name()+" can't be attacked by you yet.");
	    return 1;
	}
	// Set caster/target
    song->set_caster(tp);
    song->set_target(ob);
    // Move the song to this player and start singing!
    song->move(tp);
    song->start_singing();
    return 1;
}

int abil() {
    object o;
    o = this_player();
    if (o->query_subclass()!="bard"&&
      o->query_subclass()!="jester"&&
      o->query_subclass()!="gypsy") return 0;
    return 1;
}
void help() {
    write(@TEXT
Syntax: <sing [song name]>
Bards and Gypsies are able to sing wonderous songs to
TEXT);
}

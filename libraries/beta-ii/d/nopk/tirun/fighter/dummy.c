#include <std.h>
inherit OBJECT;

static int head=1;

int create() {
    ::create();
    set_name("dummy");
    set_short("a man-sized dummy");
    set_long("This dummy has been mutilated and torn apart "
      "from years of usage. It has been attached to an "
      "old, metal pole. You could probably attack without "
      "anyone minding.");
    set_id(({ "dummy", "man sized dummy", "man-sized dummy" }));
    set_prevent_get("You can't take that out of the ground!");
    set_weight(80);
}

int get() { return 0; }

void tell_all(string verb, string this, object me) {
    message("info", "You "+verb+" "+this, me);
    tell_room(environment(me), me->query_cap_name()+" "+verb+"s "+this,
      ({ me }));
}

int attack(string what) {
    int i;
    if (what != "dummy") {
	write("Attack what?");
    }
    i = random(this_player()->query_skill("melee"));
    if (i >= 150) {
	if (head) {
	    tell_all("mutilate", "the dummy, severing it's head!", this_player());
	    tell_room(environment(this_object()), "A head falls to the ground.", ({
	      }));
	    set_short("a horribly mutilated dummy");
	    set_long("This dummy has been mutilated and torn apart "
	      "from years of usage. It has been attached to an "
	      "old, metal pole. You could probably attack without "
	      "anyone minding. It's head has recently been ripped "
	      "off, probably during practice.");
	    new("/d/nopk/tirun/fighter/head")->move(environment(this_player()));
	    head = 0;
	} else tell_all("tackle", "the dummy, throwing it around!",
	      this_player());
    } else if (i >= 135) {
	tell_all("slam", "the dummy with an powerful punch to it's torso!",
	  this_player());
    } else if (i >= 120) {
	tell_all("charge", "towards the dummy, slamming it mercilessly!",
	  this_player());
    } else if (i >= 110) {
	tell_all("send", "a flying spinning kick at the dummy!", this_player());
    } else if (i >= 100) {
	tell_all("tackle", "the pole, missing the dummy!", this_player());
	tell_room(environment(this_player()), this_player()->query_cap_name()+
	  " winces in pain.", ({ this_player() }));
	if (this_player()->query_hp() > 10) this_player()->add_hp(-(random(10)));
    } else if (i >= 80) {
	tell_all("gouge", "at the dummy's eyes!", this_player());
    } else if (i >= 75) {
	tell_all("slam", "the defenseless dummy with a right hook.",
	  this_player());
    } else if (i >= 62) {
	tell_all("send", "a powerful left hook to the dummy's gut!",
	  this_player());
    } else if (i >= 50) {
	tell_all("smack", "the dummy around!", this_player());
    } else if (i >= 40) {
	if (head)
	    tell_all("punch", "the dummy in the head!", this_player());
	else
	    tell_all("swing", "where the dummy's head _was_ and miss!",
	      this_player());
    } else if (i >= 30) {
	tell_all("kick", "the dummy's leg.", this_player());
    } else if (i >= 15) {
	tell_all("bite", "the dummy's arm! Owch!", this_player());
    } else tell_all("miss", "the dummy!", this_player());
    return 1;
}

void init() {
    ::init();
    add_action("attack", "attack");
}

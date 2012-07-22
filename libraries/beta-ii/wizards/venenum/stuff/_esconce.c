// Venenum

#include <std.h>
#include <rest.h>
#include <daemons.h>
inherit DAEMON;

int abil();

int cmd_esconce() {
    object env;
    if (!abil())
	return notify_fail("Don't you just wish?\n");
    env = environment(this_player());
    if(this_player()->query_ghost())
	return notify_fail("While you could most certainly hide, what good would it do you?\n");
    if (this_player()->query_disable())
	return notify_fail("Your concentration is disturbed.\n");
    if (environment(this_player())->query_property("no attack"))
	return notify_fail("There's no reason for you to hide in this area of peace.\n");
    if(this_player()->query_current_attacker()) {
	write("You cannot hide in combat!");
	return 1;
    }
    if(this_player()->query_level() > 30) {
	write("You have become far too large to hide.");
	return 1;
    }
    if(env->query_property("indoors") == 1 && this_player()->query_level() > 15) {
	write("You have become far too large to hide indoors.");
	return 1;
    }

    // There should be a check for nighttime here, 
    // but I don't know what it is and there was nobody on to ask.

    this_player()->set_disable();
    this_player()->set_invis();
    new("/wizards/venenum/stuff/esconceobj.c")->move(this_player());
}
}

void help() {

    write(@ENDTEXT
Syntax: <esconce>
Baby black dragons are able to hide themselves in their natural surroundings, even indoors, at night. However, as they get larger they may find that they loose this ability due to their size.
ENDTEXT);
}

int abil() {
    object r;
    r = this_player();
    if (r->query_subclass() != "black") return 0;
}

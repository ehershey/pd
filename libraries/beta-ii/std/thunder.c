// /std/thunder.c courtesy of Stormbringer
// Molded for Carnage by Inferno
#include <std.h>
#define TIME    100
string *MESSAGE = ({ "Thunder cracks off in the distance.",
"You see the flicker of lightning out of the corner of your eye.",
"A mighty boom of thunder rattles your bones.",
"The rumble of thunder rolls across the land.",
"The sizzle-CRASH of lightning sounds nearby.",
"The thunder rolled, and the lightning crashed...",
"A jag of lightning tears the sky asunder.",
"A distant lightning bolt is followed by a rippling wave of thunder." });

inherit DAEMON;

static int going;

void do_thunder();
void stop_thunder();
void start_thunder();

void create() {
 ::create();
   set_no_clean(1);
   if (!going) {
      going = 1;
      call_out("start_thunder",TIME);
    }
}

void do_thunder() {
    int i, x = random(sizeof(MESSAGE)-1);
    for(i = 0;i < sizeof(users());i++) {
        if((environment(users()[i])->query_property("thunder")==1) &&
(interactive(users()[i]))) {
            message("info","%^YELLOW%^"+MESSAGE[ x ],users()[i]);
        }
    }
}

void thunder_timer() {
    if(going == 0) {
        do_thunder();

        call_out("thunder_timer", TIME);
    }
}

void stop_thunder() {
    going = 1;
}

void start_thunder() {
    if(going) {
        going = 0;
        call_out("thunder_timer",TIME);
    }
}
/*
void remove() {
    ::remove();
}
*/

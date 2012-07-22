// Coded by Whit

#include <std.h>
#include <citrin.h>
inherit ROOM;

mapping visitors;

void init() {
  ::init();
  if(!wizardp(this_player()))
    add_action("filter_act", "", 1);
  call_out("begin_story", 4, this_player());
}

void create() {
  ::create();
  set_property("light", 1);
  set_property("night light", 1);
    set_property("no teleport", 1);
  set("short", "A small dimly lit cave");
    set("long", "The small room is dimly lit.  It looks to be a house for
someone.  There is "
"a bed against the side of one of the wall.  A small candle is attached to the
wall providing "
"light in this room.");
    skip_obvious();
  visitors = ([]);
}

int filter_act(string str) {
    if(query_verb() == "say" || query_verb() == "tell" || query_verb() ==
"shout") {
        write("You are too intuned with the old man.\n");
    }
    else {
        write("You are too intuned with the old man.\n");
    }
    return 1;
}

void begin_story(object tp) {
 write("The man sits down on top of what looks to be a bed.\n");
  call_out("continue_story_1", 3, tp);
}

void continue_story_1(object tp) {
write("%^CYAN%^the man says: %^RESET%^Its been so long since i've had visitors I "
"almost forgot my manners.\n");
call_out("continue_story_2", 3, tp);
}

void continue_story_2(object tp) {
write("%^CYAN%^the man says: %^RESET%^I am Victor.\n");
call_out("continue_story_3", 4, tp);
}

void continue_story_3(object tp) {
write("%^CYAN%^Victor says: %^RESET%^For many years people came.  They came to talk to me about
anything.  "
"Now since that dirty thief Bordus stole the water crystal everyone is afraid
to come near me now.\n");
call_out("continue_story_4", 3, tp);
}

void continue_story_4(object tp) {
write("%^CYAN%^Victor says: %^RESET%^That crystal protects the lake above us.  Without it no
animal "
"here is safe.\n");
call_out("continue_story_5", 2, tp);
}

void continue_story_5(object tp) {
write("%^CYAN%^Victor says:  %^RESET%^But i have no doubt that you will retrieve the crystal.
Right?\n");
call_out("continue_story_6", 3, tp);
}

void continue_story_6(object tp) {
write("%^CYAN%^Victor says: %^RESET%^Oh my goodness.  Ive kept you too long.  I should let you
go now.\n");
call_out("continue_story_7", 3, tp);
}
void continue_story_7(object tp) {
write("%^CYAN%^Victor says: %^RESET%^If you are willing to go on this "
"quest for me.  Here take this.");
write("The man hands you an object.");
new(OBJ2"staff1.c")->move(this_player());
call_out("continue_story_8", 4, tp);
}

void continue_story_8(object tp) {
write("A loud rumble is heard in the distance.\n");
call_out("continue_story_9", 4, tp);
}

void continue_story_9(object tp) {
object slave, env1, victor;

write("Victor shrieks in terror.");
write("%^CYAN%^Victor says: %^RESET%^Run its collapsing!");
write("You run out of the room.");

slave = new("/wizards/whit/slave");
slave->move(ROOM2"ecave");
env1 = environment(slave);
slave->remove();
victor = new(MON2"victor.c");
victor->move(ROOM2"ecave");
tell_room(env1, "The cave suddenly collapses.");
// this_player()->set("savior",1);
this_player()->move_player(env1);
}

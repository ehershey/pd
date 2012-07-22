#include <std.h>
inherit "/std/ride.c";

void create() {
    ::create();
    set_name("griffon");
    set_id(({ "griffon"}));
    set_level(100);
    set_short("Golden Griffon");
    set_long(
      "The large massive griffon appears to be waiting for something. "
      "The beaste seems to be quite intelligent. Giant in size, the griffon "
      "looks capable of carrying heavy loads."
    );
    set_race("griffon");
    set_gender("male");
    set_alignment(0);
    set_body_type("equine");

    add_money("gold",random(100));
}

void init() {
    add_action("fly", "fly");
}

int fly(string str) {
    if(str == "castle") {
        return 1;
    }

    write("The eagle nods and squelches");
    call_out("next", 2);
    return 1;
}
void next(){
    write("You are swooping high over Sindarii. Far down below you notice many people running around.");
    call_out("next1", 3);

    return;
}
void next1() {

    write("blah blah");
    call_out("next2", 5);
    return;
}

void next2(){
    write("lalala");
    this_player()->move_player("/wizards/stormbringer/workroom.c");
    return;
}

#include <std.h>
#include <tirun.h>
#include <daemons.h>
inherit ROOM;
void init() {
    ::init();
    add_action("become", "become");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Sorceror's Wisdom");
    set("long",
          "A sphere of glowing, yellow light shines in the middle of the room, "
          "representing the power of the mind.  The inside of this room is tiled, "
          "even it's walls and ceiling.  Although dark, the light of the sphere "
          "illuminates the room. "
          "<Preview> will tell you about becoming a sorceror.");
    set_items(
        (["sphere" : "The glowing sphere represents the mind to the sorcerors.",
          "tiles" : "There are stone tiles all over the room."]) );
    set_exits( 
         (["out" : ROOMS"ewayward3",
           "west" : ROOMS"mage/sorceror/sorceror_hall"]) );
    add_pre_exit_function("west", "go_east");
}
int preview() {
    if((string)this_player()->query_class() != "mage" ||
            this_player()->query_subclass() == "pyromancer" ||
            this_player()->query_subclass() == "necromancer" ||
            this_player()->query_subclass() == "wizard") {
        message("info", "You have not the mind to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == "sorceror"){
        message("info", "You are already a manipulator of the mind.",
this_player());
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about sorcerors.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Sorcerors are manipulators of the mind.  Quite intelligent and "
                   "potentially adept as mages, the sorceror can inflict heavy damage "
                   "to a person's mind rather than their body.  Type <become sorceror> "
                   "to become a sorceror.", this_player());
    return 1;
}
int become(string str) {
    if(!str) {
        notify_fail("Become what?\n");
        return 0;
    }
    if(str != "sorceror") {
        notify_fail("You cannot become that here.\n");
        return 0;
    }
    if((string)this_player()->query_class() != "mage") {
        write("You must choose the path of the mages first.");
        return 1;
    }
    if(this_player()->query_subclass() == "necromancer" ||
       this_player()->query_subclass() == "pyromancer" ||
       this_player()->query_subclass() == "sorceror" ||
       this_player()->query_subclass() == "wizard") {
        write("You have already chosen your path in life!");
        return 1;
    }
    write("The wise sorceror initiates you into the path of the sorcerors.");
    say(this_player()->query_cap_name()+" becomes a sorceror.", this_player());
    this_player()->set_subclass("sorceror");
    this_player()->set_alignment(2000);
    this_player()->setenv("TITLE", "$N the novice sorceror");
    this_player()->init_skills("mage");
    this_player()->setenv("start", "/d/tirun/mage_hall");
   this_player()->register_channels();
    return 1;
}
int go_east() {
    if(wizardp(this_player())) return 1;
    if((string)this_player()->query_subclass() != "sorceror") {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "mage's domain, but fails.", this_player());
        return 0;
    }
    return 1;
}
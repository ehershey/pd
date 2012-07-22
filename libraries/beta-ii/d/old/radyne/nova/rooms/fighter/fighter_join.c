#include <std.h>
#include <radyne.h>
inherit ROOM;
void init() {
    ::init();
    add_action("become", "become");
     add_action("go_up","up");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "The Hall of Fighters");
    set("long",
      "The Hall of Fighters is decorated with ornate tapestries of "
      "men and women engaged in combat of all traditions.  Adventuring "
      "fighters are gathered around discussing glory at the base of a "
      "spiraling staircase which leads up through a magically lit hole "
      "in the ceiling.  Young warriors stand about hoping to learn the "
      "ways of the fighter.  Children may <preview> what it is like to "
      "be a fighter.");
    set_items( 
        ([({"tapestry", "tapestries", "wall"}) : "The walls are all "
            "covered with some of the most ornate tapestries from "
            "all over.  The one you are looking at depicts a heroic "
            "battle between a dragon and a human combatant.",
          ({"hole", "light", "opening", "ceiling"}) : "Up in the ceiling, "
            "the staircase leads through a mystical light up "
            "to the second floor.",
          "staircase" : "It leads through the opening in the ceiling "
            "to the second floor.",
          "fighters" : "They are loud and obnoxious.", 
          ({"warriors", "young warriors"}) : "They look clueless."]) );
    set_exits( 
        ([
          "south" : ROOMS"sparroom",
          "up" : "(: up :)"]) );
    set_listen("default", "Fighters are yelling and screaming and "
      "being generally obnoxiously loud.");
}
int preview() {
    if((string)this_player()->query_class() != "child") {
        write("This is not for you.\n");
        return 1;
    }
    say(this_player()->query_cap_name()+" seeks to learn about fighter.", 
        this_player());
    write("Welcome, child!");
    write("Fighters are people whose only uniting belief is in combat as a "
        "form of art.  Some are great knights who fight for good wherever "
        "they go.  Others might be considered quite fiendish in some circles. "
        "They therefore have no moral restrictions placed upon them. But "
        "they spend so much time learning the arts of combat, that they "
        "are almost entirely ignorant of the ways of magic.  To become a "
        "fighter, type <become fighter> and strike out now and find your "
        "path in life, go and find the hall of the Antipaladin, the hall "
        "of the Berserker, the hall of the Paladin, the hall of the Ranger, "
        "or the hall of the Warrior.");
    return 1;
}
int become(string str) {
    if(!str) {
        notify_fail("Become what?\n");
        return 0;
    }
    if(str != "fighter") {
        notify_fail("You cannot become that here.\n");
        return 0;
    }
    if((string)this_player()->query_class() != "child") {
        write("You are much too old to start learning our ways now!");
        return 1;
    }
    write("The Great Warrior initiates you into the class of fighters.");
    say(this_player()->query_cap_name()+" becomes a fighter.", this_player());
    this_player()->set_class("fighter");
    this_player()->setenv("TITLE", "$N the page");
    this_player()->init_skills("fighter");
   this_player()->register_channels();
    return 1;
}
int go_up() {
    if(wizardp(this_player())){
      write("Mighty immortals are always welcome into the hall.");
    } else
    if((string)this_player()->query_class() != "fighter") {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "fighter's sanctuary, but fails.", this_player());
        return 1;
    }
this_player()->move_player(ROOMS"fighter/fighter_hall", "through the light in the passage");
    return 1;
}
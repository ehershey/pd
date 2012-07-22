#include <std.h>
#include <tirun.h>
#include <daemons.h>
#define CLASS     "clergy"
#define SUBCLASS  "kataan"
#define ALIGNMENT -1500
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
    set("short", "Entrance to the Kataan Hall");
    set("long",
        "You are in a dark underground cavern beneath a hidden crypt.  "
        "There are very sophisticated religious murals carved into the "
        "walls of the cavern.  Down deeper into the cavern is a very "
        "unusual passage, only allowing one-way travel.  The grave "
        "is back through the tunnel. <preview> will tell you about being a kataan.");
    set_items(
        (["mural" : "It is very old and depicts gruesome cult practices.",
          "murals" : "They are quite ancient and are made up of "
            "pictures depicting bizarre rituals.",
          "light" : "You are certain that it is a field which allows "
            "only kataans to pass.",
          "passage" : "It has been designed much like a spider hole.",
          "cavern" : "The cavern almost pulses with hidden evil."]) );
    set_exits( 
         (["west" : "/d/nopk/standard/cemetary/tunnel2",
            "enter" : ROOMS+""+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall"]) );
    add_pre_exit_function("enter", "go_enter");
}
int preview() {
 if (this_player()->query_class() != "clergy" ||
     this_player()->query_subclass() != "none")  {
        message("info", "You have not the training to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == SUBCLASS){
        message("info", "You are already one of the chosen.", this_player());
        return 1;
    }
  say(this_player()->query_cap_name()+" seeks to learn about "
      "kataans.", this_player());
  write("Welcome, child! ");
  write("Kataans are an ancient coven of evil, magical warriors skilled "
        "in the use of projectiles and stealth.  They are careful to do "
        "no acts which might be considered good.  Instead, they use the "
        "powers given to them by their demon masters to terrorize good "
        "beings wherever they may be.\n"
        "To become a kataan, type <become kataan>\n");
    return 1;
}
int become(string str) {
    if(!str) {
        notify_fail("Become what?\n");
        return 0;
    }
     if((string)this_player()->query_race() == "archangel") {
          write("You are an archangel!");
          return 1;
      }
    if(str != SUBCLASS) {
        notify_fail("You cannot become that here.\n");
        return 0;
    }
    if((string)this_player()->query_class() != "clergy") {
        write("You must choose the path of Clergy first.");
        return 1;
    }
   if (this_player()->query_subclass()!="none")
        return notify_fail("You have already chosen your path in life!");
    write("The Master ArchDemon initiates you into the class of kataans.");
    say(this_player()->query_cap_name()+" becomes a kataan.", this_player());
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start", "/d/tirun/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
   this_player()->register_channels();
    return 1;
}
int go_enter() {
    if(wizardp(this_player())) return 1;
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the kataan's sanctuary, but fails.", this_player());
        return 0;
    }   
    return 1;
}

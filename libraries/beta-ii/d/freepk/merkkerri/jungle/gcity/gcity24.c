#include <gcity.h>
#include <mjungle.h>
#include <std.h>

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
set("short", "%^YELLOW%^Quixxiol Cleric Hall%^RESET%^");
    set("long",
"%^YELLOW%^You are inside the Quixxiol Cleric Hall."
"%^YELLOW%^The Merkkirri clerics allow people of all faiths to enter."
"%^YELLOW%^The clerics of the church also initiate young "
"%^YELLOW%^adventurers into the class of clerics. <preview> will tell you "
"%^YELLOW%^about becoming a cleric.  There is set of stairs leading up.%^RESET%^");
set_items(([
       "light" : "A %^BLUE%^blue%^RESET%^ light protects this place.",
"stairs" : "They lead up into the cleric's inner sanctum."]) );
    set_exits( 
(["north" : GCITY "gcity11.c",

"up" : "(: up :)"]) );
}

int preview() {
    if((string)this_player()->query_class() != "child") {
message("info", "Only fresh minds are capable of becoming"
                " instruments of the gods.", this_player());
     return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn
about clerics.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Clerics are deeply religious people of greatly varied "
      "beliefs, yet united in their belief in the sanctity of the natural
world.  Their "
     "ability to get in touch with the unity of nature through prayer "
     "gives them great healing powers as well as powers of protection.  "
     "Destruction is the most horrible of evils to them, and they will "
     "lose the powers they have through prayer if they become too "
     "destructive.  Type <become cleric> to become a cleric.", this_player());
    return 1;
}

int become(string str) {
    if(!str) {
     notify_fail("Become what?\n");
     return 0;
    }
    if(str != "cleric") {
     notify_fail("You cannot become that here.\n");
     return 0;
    }
    if((string)this_player()->query_class() != "child") {
     write("You are much too old to start learning our ways now!");
     return 1;
    }
    write("The High Priestess of Clerics initiates you into the class of
clerics.");
    say(this_player()->query_cap_name()+" becomes a cleric.", this_player());
    this_player()->set_class("cleric");
    this_player()->set_alignment(2000);
    this_player()->setenv("TITLE", "$N the novice cleric");
    this_player()->init_skills("cleric");
this_player()->setenv("start", GCITY "gcity28.c");
    return 1;
}

int go_up() {
    if((string)this_player()->query_class() != "cleric") {
     write("You cannot penetrate the force field that blocks the passage.");
     say(this_player()->query_cap_name()+" tries to get into the "
         "church's inner sanctum, but fails.", this_player());
     return 1;
    }
this_player()->move_player( GCITY "gcity28.c", "through the light in
the passage");
    return 1;
}

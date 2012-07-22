#include <std.h>
#include <mjungle.h>
#include <gcity.h>
inherit ROOM;

void init() {
    ::init();
    add_action("become", "become");
add_action("go_east","east");
    add_action("preview","preview");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
set_short("%^YELLOW%^Within the Hall of Magi%^RESET%^");
    set("long",
"%^YELLOW%^The Quixxiol Hall of Magi welcomes magi of all types as well as those who wish to learn the ways of the mage.  A doorway leads east into the main chamber of the hall and is protected by a magical "
"%^RESET%^BLUE%^blue%^RESET%^ "
"%^YELLOW%^light.  The High Mage Warlock waits here to initiate aspiring "
"%^YELLOW%^magic users into the mysterious class of the mages.  "
"%^YELLOW%^<preview> will tell you about becoming a mage.%^RESET%^");
    set_items(
(["hall" : "The Quixxiol Hall of Magi is made of solid %^BOLD%^YELLOW%^gold%^RESET%^.",
       "light" : "You are certain that it is a field which allows "
         "only mages to pass.",
       "warlock" : "He awaits to initiate new mages.",
       "mage" : "He awaits to initiate new mages and explain "
         "the difference between transitive and intransitive verbs.",
       "torches" : "They create an eerie glow to the room."]) );
    set_exits( 
(["west" : GCITY "gcity9.c"]));
}

int preview() {
    if((string)this_player()->query_class() != "child") {
     message("info", "This is not for you.", this_player());
     return 1;
    }
    message("other_action", this_player()->query_cap_name()+" seeks to learn
about mages.", this_object(), ({this_player()}));
    message("info", "Welcome, child!", this_player());
    message("info", "Mages have no overriding beliefs which unite them, but
instead "
     "they are united in their love of the art of magic.  Some of them "
     "are devoted practitioners of white magic, while others are evil "
     "dark mages.  Their magical arts are centered around those "
     "which will most help them along in the material world, the arts "
     "of conjuring and magical combat.  You can type <become mage> to "
     "be initiated into the class of mages.", this_player());
    return 1;
}

int become(string str) {
    if(!str) {
     notify_fail("Become what?\n");
     return 0;
    }
    if(str != "mage") {
     notify_fail("You cannot become that here.\n");
     return 0;
    }
    if((string)this_player()->query_class() != "child") {
     message("my_action", "You are much too old to start learning our ways now!",
this_player());
     return 1;
    }
    message("my_action", "The High Mage Warlock initiates you into the class of
mages.", this_player());
    message("other_action", this_player()->query_cap_name()+" becomes a mage.",
this_object(), ({this_player()}));
    this_player()->set_class("mage");
    this_player()->setenv("TITLE", "$N the novice mage");
    this_player()->init_skills("mage");
this_player()->setenv("start", GCITY +"gcity30.c");
    return 1;
}

int go_east() {
    if((string)this_player()->query_class() != "mage") {
     message("my_action", "You cannot penetrate the force field that blocks the
passage.", this_player());
     message("other_action", this_player()->query_cap_name()+" tries to get into
the mage's sanctuary, but fails.", this_object(), ({this_player() }));
     return 1;
    }
this_player()->move_player(GCITY "gcity30.c", "through the light and into the hall of Magi"
);
    return 1;
}

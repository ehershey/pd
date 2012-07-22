#include <std.h>
#include <mjungle.h>
#include <gcity.h>
#include <sindarii.h>
inherit ROOM;

void init() {
    ::init();
add_action("go_south","south");
    add_action("preview","preview");
}

void create() {
    ::create();
    set_property("no castle", 1);
    set_property("light", 2);
    set_property("indoors", 1);
set("short", "%^YELLOW%^The dark church of the Kataan");
    set("long",
"%^YELLOW%^You are standing in the entrance of the Kataans dark church.  "
"%^YELLOW%^There are very sophisticated religious murals carved into the "
"%^YELLOW%^walls of the church.  To the south is a very "
"%^YELLOW%^unusual passage, protected by a shimmering %^RESET%^BLUE%^blue%^RESET%^YELLOW%^ light.  "
"%^YELLOW%^<preview> will tell you about being a kataan.");
    set_items(
     (["mural" : "It is very old and depicts gruesome cult practices.",
       "murals" : "They are quite ancient and are made up of "
         "pictures depicting bizarre rituals.",
       "light" : "You are certain that it is a field which allows "
         "only kataans to pass.",
          "passage" : "It has been designed much like a spider hole.",
]));
    set_exits( 
(["east" : GCITY "gcity10.c",
"south" : "(: south :)"]) );
}

int preview() {
  say(this_player()->query_cap_name()+" seeks to learn about "
      "kataans.", this_player());
  write("Welcome, child! ");
  write("Kataans are an ancient coven of evil, magical warriors skilled "
        "in the use of projectiles and stealth.  They are careful to do "
        "no acts which might be considered good.  Instead, the use the "
        "powers given to them by their demon masters to terrorize good "
        "beings wherever they may be.\n"
);
    return 1;
}


int go_south() {
    if((string)this_player()->query_class() != "kataan") {
     write("You cannot penetrate the force field that blocks the passage.");
     say(this_player()->query_cap_name()+" tries to get into the kataan's
sanctuary, but fails.", this_player());
     return 1;
    }
this_player()->move_player(GCITY "gcity31.c", "through the light in the
passage");
    return 1;
}

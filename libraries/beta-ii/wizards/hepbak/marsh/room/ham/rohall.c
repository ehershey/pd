#include <std.h>
#include <marsh.h>
#include <config.h>
#include <daemons.h>
inherit ROOM;
string get_new_title(object tp);
string get_male(int lev);
string get_female(int lev);
string previous_title(object tp);
int get_cost(string which, int lev);
void create() {
    ::create();
    set_property("no attack",1);
    set_property("no bump", 1);
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "The heart of the rogue hideout");
    set("long",
         "Welcome into the rogue hideout! "
         "Rogues come here to sharpen their fiendish skills. "
        "The available commands are <cost>, <advance>, <list (number)>, "
        "<train skill amount>, <improve stat> and <roll stats>.  Up "
        "through a stairway guarded by a shimmering %^BLUE%^blue%^RESET%^ "
        "light is the entrance to the fortress. <help skills> will list "
        "all of the full names of skills. You can choose your subclass "
        "here.");
    set_exits(
              (["up" : HAM "hut3"]) );
  
}

#include <std.h>
#include <marsh.h>
#include <daemons.h>
inherit ROOM;
#define MAGEH ROOMS+ "mage/"
string get_new_title(object tp);
string get_male(int lev);
string get_female(int lev);
string previous_title(object tp);
int get_cost(string which, int lev);
int inf(string where);
void create() {
    object ob;
    ::create();
    set_property("no attack",1);
    set_property("no magic", 1);
    set_property("no teleport", 1);
    set_property("no bump", 1);
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "A magical pool of water.");
    set("long",
        "Welcome to the hidden Mage hall! "
        "Mages come here to advance their knowledge of the magical arts.  "
        "The available commands are <cost>, <advance>,  "
        "<improve stat>, and <train skill amount> .  "
        "<help skills> will list all skills with their full, proper names.");
    set_exits(
              (["out" : WATER "ll5"]) );
  
}

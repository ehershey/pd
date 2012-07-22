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
    set_property("no castle", 1);
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The hidden chamber of the kataans");
    set("long",
      "Welcome to the hidden chamber of the kataans! "
      "Kataans come here to advance in the art of combat and magic. "
      "The available commands are <cost>, <advance>,<improve stat> , "
      "and <train skill amount>. ");
    set_exits( ([
      "out" : GAR "gar",
      "stairway" : BA "hhole17",
]) );
}

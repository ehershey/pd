#include <std.h>
#include <marsh.h>
#include <daemons.h>
inherit ROOM;
string get_new_title(object tp);
string get_male(int lev);
string get_female(int lev);
void create() {
    set_property("no attack",1);
    set("short", "The inner sanctum of the clerics");
      "<improve stat>, <train skill amount>, and <roll stats>.  "
      "Through the passage guarded by a shimmering %^BLUE%^blue%^RESET%^ "
      (["out" : UMI "hosp"]) );

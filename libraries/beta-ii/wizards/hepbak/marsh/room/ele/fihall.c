#include <std.h>
#include <marsh.h>
#include <daemons.h>
inherit ROOM;
string get_new_title(object tp);
string get_male(int lev);
string get_female(int lev);
string previous_title(object tp);
int get_cost(string which, int lev);
int moveWarrior();
int movePaladin();
int moveRanger();
int moveAntipaladin();
int inf(string where);
int moveKnight();
int moveSoldier();
void create() {
  object ob;
  ::create();
  set_property("no attack", 1);
  set_property("no castle", 1);
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no magic", 1);
  set_property("no attack", 1);
  set_property("no teleport", 1);
  set_property("no bump", 1);
  set("short", "The inner sanctum of the Hall of Fighters");
  set("long",
      "Welcome to the Fighter's Hideout!\n"
      "Fighters gather here to advance in the art of combat and in life.  "
      "In this hall, a fighter may <advance>, "
      "<improve stat>, <train skill amount>, and <roll stats>. "
      );
   set_exits( ([
      "out" : ELE "cliff2",
       ]) );
}

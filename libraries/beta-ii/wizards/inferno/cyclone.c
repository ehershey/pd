#include <std.h>
#include <rest.h>
inherit OBMOUNT;

static int silent = 1;
static string owner;
int ride(string str);
string query_owner();
void set_owner(string str);

void create() {
 ::create();
   set_name("chariot");
   set_id( ({ "chariot", "cyclone chariot", "cyclone" }) );
   set_short("%^BOLD%^%^YELLOW%^C%^CYAN%^y%^BLUE%^"
     "cl%^RESET%^%^BLUE%^one Cha%^BOLD%^ri%^CYAN%^o%^YELLOW%^t%^RESET%^");
   set_long("The Cyclone Chariot is the chariot that many great warriors "
	"and kings rode when they led their armies to victory, power "
	"radiates from within it, a barely audible hum seems to confirm "
	"it's awesome power.");
   set_prevent_get("You cannot take that!");
   silent = 1;
}

string query_owner() { return owner; }

void set_owner(string str) { owner = str; }

int ride(string str) {
   if (!str) return 0;
   if (present(str, environment(this_player())) != this_object())
	 return 0;
   if (this_player()->query_name() != owner) { write(
	"Try as you might, you cannot mount this chariot."); return 1; }
   return 0;
}

int poof(string str) {
   if (!str) return 0;
   if (present(str, environment(this_player())) != this_object())
     return 0;
   if (this_player()->query_name() != owner) return notify_fail(
	"You cannot do that.\n");
   write("You drain the chariot's force.");
   say(this_player()->query_cap_name()+" drains the chariot of its "
	"force.",
	this_player());
   this_player()->add_mp(300 + random(100));
   return 1;
}

void init() {
 ::init();
   add_action("ride", "ride");
   add_action("poof", "dispell");
}

int move(object where) {
   object *all = ({ }), tp, env, tmp, blank;
   string *exits, ex;
   int i, lev1, lev2, r;
   if (silent == 1) { silent = 0; return ::move(where); }
   r = ::move(where);
   env = environment(this_object());
   message("info", "%^BOLD%^%^CYAN%^M%^BLUE%^ig%^RESET%^%^BLUE%^hty "
	"winds and tempest whip into the room with mighty fo"
	"%^BOLD%^%^BLUE%^rc%^CYAN%^e.", env);
   tp = this_object()->query_rider();
   if (tp == blank) return r;
   if (env->query_property("no attack") || env->query_property("no magic")
	|| env->query_property("no bump")) return r;
   lev1 = tp->query_level() / 3;
   lev2 = tp->query_level() / 2;
   all = all_inventory(env);
   i = sizeof(all);
   while(i--) {
     if (!all[i]->is_living()) continue;
     if (all[i]->query_level() <= lev1 && !all[i]->is_monster()) {
       message("info", "%^BLUE%^"+all[i]->query_cap_name()+" is blown "
	"out of the room!", env, all[i]);
       message("info", "%^BLUE%^You're blown out of the room!", all[i]);
       exits = env->query_exits();
       ex = exits[ random(sizeof(exits)) ];
       if (env->query_door(ex))
         if (env->query_closed(env->query_door(ex))) {
           message("info", all->query_cap_name()+" is slammed against "
           	"the "+env->query_door(ex)+"!", env, all[i]);
           message("info", "You are slammed into the "
		+env->query_door(ex)+"!", all[i]);
           continue;
           }
       tmp = env->query_exit(ex);
       all[i]->move(tmp);
     }
     if (all[i]->query_level() <= lev2 && environment(all[i]) == env) {
       message("info", "%^CYAN%^"+all[i]->query_cap_name()+" is thrown "
	"to the ground!", env, all[i]);
       message("info", "%^CYAN%^You're thrown to the ground!", all[i]);
       all[i]->set_rest_type( SIT );
     } else message("info", "%^BOLD%^%^CYAN%^Powerful winds whip "
	"across your body.", all[i]);
   }
   return r;
}

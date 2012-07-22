#include <std.h>
inherit ROOM;

static object GUARD, user;
static string user_name;

int close_me();
void init();
void create();
void set_user(object ob);
void stock_vault();
void set_guard(object ob);
int go_out();
object query_guard();

object query_guard() { return GUARD; }

void create() {
 ::create();
   set_short("A safely guarded vault");
   set_long("This vault room is painted completely white. Within it "
	"are stored many various goods.");
   set_exits(([
	"out" : "/wizards/inferno/safe/enter"
   ]));
   set_properties(([ "no attack" : 1, "no magic" : 1, "no teleport" : 1,
	"no bump" : 1 ]));
}

void set_guard(object ob) {
   GUARD = ob;
}

void set_user(object ob) {
   user = ob;
   user_name = user->query_name();
}

void stock_vault() {
   string *all;
   int i;
   all = GUARD->query_list(user_name);
   i = sizeof(all);
   while(i--) {
     new(all[i])->move(this_object());
   }
}

int go_out() {
   this_player()->move_player("/wizards/inferno/safe/enter", "out");
   close_me();
   return 1;
}

int prev() {
   write("You cannot do that here.");
   return 1;
}

void init() {
 ::init();
   add_action("go_out", "out");
   add_action("prev", "put");
   add_action("prev", "drop");
}

int close_me() {
   object *all;
   int i;
   all = all_inventory(this_object());
   i = sizeof(all);
   while (i--) {
     if (all[i]->is_living())
	all[i]->move_player("/wizards/inferno/safe/enter", "out");
   }
   all = all_inventory(this_object());
   GUARD->save_me(user_name, all);
   i = sizeof(all);
   if (i && i != 0)
     all->remove();
   this_object()->remove();
   return 1;
}

#include <std.h>
inherit WEAPON;

static object room, who;
static int loaded;

void create() {
 ::create();
   set_name("launcher");
   set_short("a grenade launcher");
   set_long("A large gun made for launching grenades.");
   set_weight(14);
   set_value(0);
   set_id(({"launcher", "grenade launcher", "illegal arms"}));
   set_type("blunt");
}

int fire(string str) {
   object ob, env, to;
   string where;
   if (!str || !sscanf(str, "grenade %s", where))
     return notify_fail("Syntax: <launch grenade [target]>\n");
   if (present(where, env)) ob = present(where, env);
   else if (find_player(where)) ob = find_player(where);
   else if (env->query_exit(where) != "/d/standard/void")
	ob = (object)env->query_exit(where);
   else return notify_fail("Illegal target!\n");
   write("You load a grenade into the grenade launcher.");
   say(this_player()->query_cap_name()+" loads a grenade into a "
	"grenade launcher.", this_player());
   write("%^YELLOW%^You cackle with glee as you launch a grenade at "
     "your target!");
   say(this_player()->query_cap_name()+" cackles with glee and "
	"launches a grenade!", this_player());
   if (ob->is_player()) tell_object(ob,
	"%^YELLOW%^"+this_player()->query_cap_name()+" launches a "
	"grenade at you!");
   to = new("/wizards/inferno/arms/grenade");
   to->set_pin(0);
   to->move(ob);
   return 1;
}

void init() {
 ::init();
   add_action("fire", "launch");
}

#include <std.h>
inherit OBJECT;

static object room;

void create() {
 ::create();
   set_name("eye");
   set_short("the blind eye of truth");
   set_long("The magical sphere is known as the blind eye of truth, "
     "for through it the viewer can see all, but the eye never sees. "
     "The eye is a small, hazy glass sphere with a smaller, green "
     "sphere in the center, rotating slowly. The eye is strangely "
     "heavy for its size. Its history is wrapped in secrets and riddles. "
     "The eye's true nature is unknown to most and a secret to be kept.");
   set_weight(70);
   set_value(0);
}

int query_auto_load() { return 1; }

int desc(object ob) {
   string tmp;
   object tp;
   tp = this_player();
   if (!ob) return 0;
   if (!present(tp->query_cap_name(), environment(this_object())) &&
       tp != environment(this_object())) return 0;
   if ((tmp = ob->query_long()))
    message("info", tmp, tp);
   if ((tmp = ob->query_smell("default")))
    message("info", "%^RESET%^%^ORANGE%^"+tmp, tp);
   if ((tmp = ob->query_listen("default")))
    message("info", "%^RESET%^%^CYAN%^"+tmp, tp);
   tmp = "%^RESET%^%^GREEN%^"+ob->query_long_exits()+"%^RESET%^";
    message("info", tmp, tp);
   if ((tmp = ob->describe_living_contents(({this_player()}))) != "")
    message("info", tmp, tp);
   if ((tmp = ob->describe_item_contents(({}))) != "")
    message("info", tmp, tp);
   return 1;
}

int find(string str) {
   object ob, env;
   if (!str) return notify_fail("Find whom?\n");
   if (!(ob = find_player(str))) return
     notify_fail("You cannot find "+capitalize(str)+" in the eye.\n");
   env = environment(ob);
   room = env;
   desc(env);
   write("%^YELLOW%^You find "+ob->query_cap_name()+" in the eye.");
   say(this_player()->query_cap_name()+" stares into the blind eye of truth and sees.", this_player());
   return 1;
}

int view(string str) {
   object ob;
   if (!room) return notify_fail("The eye is hazy and unfocused.\n");
   if (!str) {
     write("%^YELLOW%^You look into the eye and see.");
     say(this_player()->query_cap_name()+" looks into the blind eye "
         "of truth and sees.", this_player());
     desc(room);
     return 1;
   }
   if (present(str, room)) {
     ob = present(str, room);
     message("info", "%^YELLOW%^Through the eye you see:", this_player());
     if (ob->is_living()) {
       message("info", ob->query_long(), this_player());
       return 1;
     }
     message("info", ob->query_long(), this_player());
     return 1;
   }
   if (room->query_item_description(str) && room->query_item_description(str) !=
       "") {
     message("info", "%^YELLOW%^Through the eye you see:", this_player());
     message("info", room->query_item_description(str), this_player());
     return 1;
   }
}

int unfocus(string str) {
   object none;
   if (!str || str != "eye") return notify_fail("Unfocus what?\n");
   write("%^YELLOW%^The eye's glow dims out to a haze.");
   room = none;
   return 1;
}

int focus(string str) {
   object new, mine;
   if (!str) return notify_fail("Focus what?\n");
   if (str == "eye") {
     say("%^YELLOW%^"+this_player()->query_cap_name()+" focuses the blind eye "
         "of truth.", this_player());
     write("%^YELLOW%^You find yourself in the eye.");
     room = environment(this_player());
     desc(room);
     return 1;
   }
   if (!room) return notify_fail("Focus what?\n");
   if (!new = (object)room->query_exit(str)) return notify_fail("Focus what?\n");
   if (room->query_exit(str) == "/d/standard/void") return notify_fail("In the "
       "eye you see only mist.\n");
   mine = new("/d/lodos/quest/mon/cat");
   mine->move(new);
   new = environment(mine);
   mine->remove();
   if (!desc(new))
     return notify_fail("In the eye you see only mist.\n");
   room = new;
   return 1;
}

void init() {
 ::init();
   add_action("find", "find");
   add_action("unfocus", "unfocus");
   add_action("view", "view");
   add_action("focus", "focus");
}

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

void desc(object ob) {
   string tmp;
   object tp;
   tp = this_player();
   if (!present(tp->query_cap_name(), environment(this_object())) &&
       tp != environment(this_object())) return;
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
   if (!str) {
     if (!room) return notify_fail("The eye is hazy and unfocused.\n");
     write("%^YELLOW%^You look into the eye and see.");
     say(this_player()->query_cap_name()+" looks into the blind eye "
         "of truth and sees.", this_player());
     desc(room);
     return 1;
   }
   if (present(str, room)) {
     ob = present(str, room);
     message("%^YELLOW%^Through the eye you see:");
     if (ob->is_living()) {
        return 1;
     }
     message("info", ob->query_long(), this_player());
     return 1;
   }
   if (room->query_item(str)) {
     write("%^YELLOW%^
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
   if (!str || str != "eye") return notify_fail("Focus what?\n");
   write("%^YELLOW%^You find yourself in the eye.");
   room = environment(this_player());
   desc(room);
   return 1;
}

void init() {
 ::init();
   add_action("find", "find");
   add_action("unfocus", "unfocus");
   add_action("view", "view");
   add_action("focus", "focus");
}

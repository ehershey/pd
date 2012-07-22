#include <std.h>
inherit OBJECT;
void create() {
 ::create();
   set_name("seal");
   set_short("Seal of Tirun");
   set_long("A hardened wax seal depicting the coat of arms of the founding family of Tirun.");
   set_weight(1);
   set_curr_value("gold", 100);
   set_id(({ "seal", "tirun seal", "seal of tirun" }));
   set_property("magic item", ({"break"}) );
}
void init() {
 ::init();
   add_action("crack", "break");
}
int crack(string str) {
    object tp;
    tp = this_player();
   if (str != "seal") return 0;
   if (environment(tp)->query_property("no teleport")) return notify_fail("You cannot do that here.\n");
   if (tp->query_current_attacker()) return notify_fail("You cannot do that in battle!\n");
   if (tp->query_arena()) return notify_fail("You cannot do that in the arena!");
   write("%^BOLD%^%^GREEN%^Mystical energies engulf you!\n%^RESET%^");
   tell_room(environment(tp), "%^BOLD%^%^GREEN%^Mystical energies engulf "+this_player()->query_cap_name()+"!\n%^RESET%^", ({ this_player() }));
   remove_action("crack", "break");
   call_out("goingalready", 6, tp);
   return 1;
}
int goingalready(object tp) {
    int sps;
    write("\n%^BOLD%^GREEN%^You appear in a new location!\n%^RESET%^");
    message("info", "%^BOLD%^%^GREEN%^"+tp->query_cap_name()+" vanishes from sight!%^RESET%^", environment(tp), tp);
    if((sps = this_player()->query_sp()) < 0)
      this_player()->set_sp(20);
this_player()->move_player("/d/nopk/tirun/square", "in a flash of light!");
    this_player()->set_sp(sps);
    this_object()->remove();
    return 1;
}
int query_auto_load() {return 1;}

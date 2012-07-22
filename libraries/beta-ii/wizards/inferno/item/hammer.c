#include <std.h>
inherit WEAPON;
int this();
static object *list=({ });
void create() {
 ::create();
   set_short("%^ORANGE%^The mighty hammer of the %^RED%^crimson%^ORANGE%^ forge%^RESET%^");
   set_name("infhammer");
   set_long("%^ORANGE%^Here is Lord Inferno's own hammer. Be wary, "
            "thine mortals. Stray through nary a shadow and always keep "
            "one eye open. The hammer has a strange shadow about it, "
            "preventing you from seeing the spell of life engraved upon "
            "it.%^RESET%^");
   set_weight(100);
   set_value(10000);
   set_wc(900);
   set_ac(10);
   set_hands(2);
   set_type("blunt");
   set_id(({ "hammer" }));
   set_wield(this());
   set_property("no steal", 1);
}

int this() {
   if (this_player()->query_name() != "inferno") {
      write("You are not strong enough to lift this hammer.");
      return 1;
   }
}

int hamma_time(string str) {
   int i;
   object *ob=({ }), env;
   if (str != "hammer" && str != "death") {
      write("Pound what?");
      return 1;
   }
   if (this_player()->query_name() != "inferno") return 0;
   tell_room(environment(this_player()), "%^YELLOW%^Inferno raises his hammer above his head and slams it deep into the earth!", ({ }));
   message("shout", "%^RESET%^%^RED%^A "
      "%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^g%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^y%^BOLD%^%^BLACK%^ "
      "c%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^g "
      "%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^ "
      "b%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ "
      "h%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^d "
      "%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^s "
      "%^RESET%^%^RED%^I%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^f%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^'%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^ "
      "h%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^m%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^ "
      "h%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^ "
      "t%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e "
      "%^RESET%^%^RED%^g%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^! ",  users());
  if (str == "death") {
   message("shout", "%^ORANGE%^Flames engulf the land, scorching your body!%^RESET%^", users());
   users()->die(); 
  }
   ob = all_inventory(environment(this_player()));
   i = sizeof(ob);
   env = environment(this_player());
   message("info", "%^CYAN%^All matter disipates before the wrath of Inferno.%^RESET%^", environment(this_player()));
   env->remove_listen("default");
   env->remove_smell("default");
   env->set_long("You are standing in the center of a huge crater.");
   while (i--) {
     if (!interactive(ob[i])) {
       tell_room(environment(ob[i]), ob[i]->query_short()+" dissolves!");
       ob[i]->remove();
     }
   }
   return 1;
}

int swing(string str) {
   string target, limb;
   object ob;
   if (!archp(this_player())) {
      write("You are not strong enough!");
      return 1;
   }
   if (sscanf(str, "hammer at %s", target)) {
      ob = present(target, environment(this_player()));
      if (!ob) {
         write("You do not see that here.");
         return 1;
      }
   } else ob = (object)this_player()->query_current_attacker(); 
   if (!ob) {
     write("You do not see that here.");
     return 1;
   }
      limb = "head";
      ob->do_damage("head", 900000);
      tell_room(environment(this_player()), this_player()->query_cap_name()+
      " swings "+this_player()->query_title_gender()+" hammer and "
      "slams it into "+ob->query_cap_name()+"'s "+limb+"!", ({ this_player() }));
      write("You swing your hammer and slam it into "+ob->query_cap_name()+
      "'s "+limb+"!");
      ob->check_on_limb(limb);
      ob->die();
      return 1;
}

void init() {
 ::init();
   add_action("hamma_time", "pound");
   add_action("swing", "swing");
}

int query_auto_load() { return 1; }

#include <std.h>

inherit WEAPON;

void create() {
   ::create();
   set_id( ({ "whip","flail","velvet flail" }) );
   set_name("velvet flail");
   set_short("%^BOLD%^MAGENTA%^velvet flail%^RESET%^");
   set_long("THE Velvet flail. Edited by Amarael specifically for Azire.");
   set_mass(10);
   set_wc(1);
   set_type("flail");
   set_prevent_get("This isn't yours.");
   set("skill level", 1);
}

void init() {
   ::init();
     add_action("flog", "flog");
}

int flog(string str) {
   object ob;
   if(!str || str=="")
     return notify_fail("Who do you wish to flog?\n");
   ob = present(str, environment(this_player()));
   if(!ob)
     return notify_fail("Sorry Azzy, Couldn't find "+str+".");
   write("You whip "+capitalize(ob->query_name())+"'s tender bottom.");
   say(this_player()->query_cap_name()+" whips "+capitalize(ob->query_name())+"'s tender bottom.");
   ob->force_me("moan");
   ob->force_me("say Please mistress, more!");
   return 1;
}

int query_auto_load() {
    if(this_player()->query_name() == "azire") return 1;
}

void move(mixed ob) {
     object az;
     if(objectp(ob)) {
       if(ob->is_player() && ob->query_name() == "azire")
         return ::move(ob);
       }
     if(az = find_player("azire"))
       return ::move(az);
     return ::move("/d/nopk/standard/void.c");
}

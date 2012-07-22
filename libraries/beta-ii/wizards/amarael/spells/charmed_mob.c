#include <std.h>

inherit MONSTER;

static object ob, pl;

void create(object my_copy, string my_owner) {
   ::create();
     ob = this_object();
     pl = present(my_owner, environment(ob));
     set_exp_share(pl, to_float(3/4));

     set_name( my_copy->query_name() );
     set_id( my_copy->query_id() );
     set_gender( my_copy->query_gender() );
     set_short( my_copy->query_short() );
     set("aggressive", my_copy->query("agressive") );
     set_heart_beat(1);
     set_level( my_copy->query_level() );
     set_exp( my_copy->query_exp() );
     set_long( my_copy->query_long() );
     set_body_type( my_copy->query_body_type() );
     set_alignment( my_copy->query_alignment() );
     set_race( my_copy->query_race() );
     if(my_copy()->query_class())
       set_class( my_copy->query_class() );
     if(my_copy()->query_subclass())
       set_subclass( my_copy->query_subclass() );

     if(my_copy->query_spell_chance()) {
       set_spell_chance( my_copy->query_spell_chance() );
       set_spells( my_copy->query_spells() );
       }
}

void init() {
   ::init();
     add_action("command_me", "command");
}

int command_me(string str) {
    string order, tm;
    object oi;
    int x;

    if(random(query_level()) >= pl->query_skill("psionics")/12) {
      write(query_cap_name()+" ignores your command!");
      return 1;
      }
    else if(random(query_level()) >= pl->query_skill("psionics")/6) {
      write(query_cap_name()+" breaks out of your control!");
      kill_ob(pl, 0);
      pl = (object)"";
      return 1;
      }

    if(!str || sscanf(str, "%s to %s", tm, order)!=2)
      return notify_fail("Syntax: <command [monster] to [command]>\n");

    oi = present(tm, environment(pl));
    if(oi != this_object())
      return notify_fail("Command who?\n");

    if(order == "reveal powers") {
      message("info", "You delve into the "+query_race()+"'s mind, and "+query_subjective()+" reveals much.", pl);
      if(query_spell_chance())
        message("info", "During combat query_subjective() will "+implode(query_spells(), ", ")+".", pl);
      message("info", capitalize(query_subjective())+" has the ability to heal people request.", pl);
      message("info", capitalize(query_subjective())+" is level "+query_level()+".", pl);
      return 1;
      }
    if(order == "die" || order == "suicide") {
      write(query_cap_name()+" breaks out of your control!");
      kill_ob(pl, 0);
      pl = (object)"";
      return 1;
      }
    if(sscanf(str, "%s* to heal %s", order) == 2)
      command("heal "+order);
    return 1;
}

void heart_beat() {
     object *killz;
     int i;
   ::heart_beat();
     if(!pl) return;
     if(environment() != environment(pl)) {
       if(file_name(environment(pl))[0..8] == "/d/arena/") {
         message("info", ob->query_cap_name()+" seems to come out of a daze, and wanders off.", environment(ob));
         ob->remove();
         return;
         }
      message("info", "%^BOLD%^GREEN%^"+query_cap_name()+" follows "+pl->query_cap_name()+"%^RESET%^\n", environment());
      ob->move(environment(pl));
      message("info", "%^BOLD%^GREEN%^"+query_cap_name()+" enters.%^RESET%^\n", environment());
      }
    if(pl->query_attackers())
      set_attackers(pl->query_attackers());
}

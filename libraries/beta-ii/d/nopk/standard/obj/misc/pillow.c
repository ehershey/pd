#include <std.h>
inherit OBJECT;
static void create()
{
 set_name("sleep_pillow");
 set_id( ({ "pillow" }) );
 set_short("A fluffy pillow");
 set_long("A fluffy pillow made out of goose feathers");
 set_property("no steal", 1);
 set_mass(0);
 set_value(0);
 }
void init()
{
 ::init();
 
 call_out("do_heal", 1, this_player());
  if (present("pillow", environment(this_player() ) ))
   {
   this_object()->remove();
   return 0;
   }
 this_player()->set_rest_type(1);
    add_action("check_act", "", 1);
 if (!this_player()->is_monster()) call_out("do_heal", 1, this_player());
 
}
 
int check_act(string str)
{
 if (present("pillow", environment(this_player() ) ))
   {
   this_object()->remove();
   return 0;
   }
 if (query_verb()=="wake")
   {
    message("info", "You open your eyes, yawn and awaken.", this_player());
    message("info", (string)this_player()->query_cap_name()+ " awakens.", environment(this_player()), this_player());
    this_player()->set_rest_type(0);
    this_object()->remove();
    return 1;
   }
 if (query_verb()=="hp" || query_verb()=="status") return 0;
 message("info", "You are sleeping.", this_player());
 return 1;
}
 
void do_heal(object ob)
{
 if(!ob) {
   this_object()->remove();
   return;
 }
 if (ob->query_hp() < 1) this_object()->remove();
// if (!ob->is_monster()) return;
 ob->add_hp(2+random(3));
 ob->add_sp(2+random(3));
 ob->add_mp(2+random(4));
 call_out("do_heal", 2, ob);
}

void notify_die(object killer, object victim) { this_object()->remove(); }

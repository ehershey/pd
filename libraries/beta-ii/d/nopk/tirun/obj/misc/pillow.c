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
 
 call_out("do_heal", 5, this_player());
  if (present("pillow", environment(this_player() ) ))
   {
   this_object()->remove();
   return 0;
   }
 this_player()->set_rest_type(1);
 message("info", "You fall fast asleep, tired from exhaustion.", this_player());
 message("info", (string)this_player()->query_cap_name()+" falls fast asleep", environment(this_player()), this_player());

    add_action("check_act", "", 1);
 if (!this_player()->is_monster()) call_out("do_heal", 5, this_player());
 
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
 message("info", "You are too comfortable to do that.", this_player());
 return 1;
}

void do_heal(object ob)
{
 if (ob->query_hp() < 1) this_object()->remove();
 if (!ob->is_monster()) return;
 ob->heal(random(10));
 call_out("do_heal", 5, this_player());
}

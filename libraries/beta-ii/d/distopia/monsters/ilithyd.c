#include <std.h>
#include <hermes.h>
inherit MONSTER;
object *all;
int i;
int wielded_sword = 0;
void create() 
{
  ::create();
  set_name("ilithyd");
  set("short", "Ilithyd: The Demon Hunter");
  set("long", "The eyes of the Demon Hunter move across you.  He "
   "raises his blades and growls a challenge.");
  set("id", 
   ({"monster","demon hunter","archangel","angel","ilithyd"})
  );
  set("race", "archangel");
  set_body_type("archangel");
  set_gender("male");
  set_class("wanderer");
  set_subclass("swashbuckler");
  set_spell_chance(40);
  set_spells( ({"bladedance", "lunge", "disarm", "feint lunge", "feint slash", "swiftness", "riposte"}) );
  new(WEAP"warblade")->move(this_object());
  new(WEAP"warblade")->move(this_object());
  new(ITEMS"bloodwings")->move(this_object());
  add_money("gold", 500);     
  add_money("platinum", 200);

  set_languages( ({"annarian", "kanashi"}) );
  set_speech(5, "annarian", 
   ({"Have you seen him?",
    "Are there demons nearby?",
    "At last, I shall have...revenge."}),
   0);
  this_object()->force_me("wield warblade");
  this_object()->force_me("wield warblade 2");
  this_object()->force_me("wear all");
  set_level(75);
  //        set_exp(310000);
  if(random(200) > 190) {
    new("/wizards/daboura/arm/dull_brass_helmet.c")->move(this_object());
    command("wear helmet");
  }
}                                            

void init()   
{

  ::init();
  all = all_inventory(environment(this_object()));
  i = sizeof(all);
  while (i--)
  {
    if (all[i]->is_player() && all[i]->query_race()=="demon")
    {
      this_object()->demonkill(all[i]);
    }
  }       
}
void demonkill(object ob)
{
  this_object()->force_me("kill "+ob->query_name());
}

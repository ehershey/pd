#include <std.h>
inherit WEAPON;

void create() {
  ::create();
  set_name("fireball");
  set_short("%^RESET%^%^RED%^A flaming fireball%^RESET%^");
  set_long("A small fireball. Strangley, the fire does not burn you.");
   set_weight(1);
  set_id( ({ "fireball" }) );
   set("no store", 1);
  set_curr_value("gold", 0);
  set_type("blunt");
  set_wc(1);
  set_hands(1);
  set_wield("Flames start traveling up your arm and a fireball appears in your hand");
}


int throw(string str) {
  string you;
  object ob;
  if (!str)
    return notify_fail("Syntax: <throw fireball at [person]>");
  if (!sscanf(str, "fireball at %s", you))
    return notify_fail("Syntax: <throw fireball at [person]>");
  ob = find_player(you);
  if (!ob)
    return notify_fail("Who did you want to burn?");

  if (ob->query_invis())
    write("The fireball flys through space and catches a shadow on fire.");

  call_out("hit", 4, ob, this_player());
  tell_room(environment(this_player()), this_player()->query_cap_name()
           +" throws a fireball at "+ob->query_cap_name()+"!", ({ this_player() }));
  write("You throw a fireball at "+ob->query_cap_name()
       +" while a blue flame trails behind it like a tail!");

   this_object()->move("//d/nopk/standard/void.c");
  return 1;
}


void hit(object ob, object tp) {
  if(!ob) {
    message("info", "They left before the fireball could burn them!", tp);

    return;
  }
  tell_object(ob, "A small fireball wizzes into the room and catches your hair on fire for a few moments!");
  (ob->add_hp(-10));
  if(ob->query_hp()<1) ob->add_hp(10);
  if (wizardp(ob))
    tell_object(ob, ""+tp->query_cap_name()+" nailed you!");
  tell_room(environment(ob), "A ball of fire wizzes in and catches "
           +ob->query_cap_name()+"'s hair on fire for a few seconds.", ({ ob }));

  this_object()->move(ob);
}


void init() {
  ::init();
  add_action("throw", "throw");
  add_action("eat", "eat");
}


int eat(string str) {
  string trash;
  if (!str) return notify_fail("What?\n");
  if (!sscanf(str, "fireball%s", trash)) return notify_fail("What?\n");

  tell_room(environment(this_player()), this_player()->query_cap_name()
           +" grabs a fireball and stuffs it into their mouth!", ({this_player()}));
  write("Thats a spicy meatball!");

  this_object()->remove();
  this_player()->add_stuffed(350);
  return 1;
}

int query_auto_load() { return wizardp(this_player()); }

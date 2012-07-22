//  Bow inherit by Nightshade for
//  shooting into other rooms
#include <std.h>

inherit WEAPON;

int Arrows;

void init() {
  ::init();
  add_action("shoot", "shoot");
}

int shoot(string str) {
  string thingy, dir, limb, from;
  object env, target, *stuff;
  int i, flag, dmg;

  if(!str)
    return notify_fail("Shoot what?\n");
  if(this_player()->query_skill("ranged") < 40)
    return notify_fail("You fumble about with the bow unsuccessfully.\n");
  if(this_player()->query_sp() < 10)
    return notify_fail("You are too tired to shoot anything.\n");
  if(this_object()->query_wielded() != this_player())
    return notify_fail("You dont have the "+this_object()->query_name()+" wielded!\n");
  if(sscanf(str, "%s %s", thingy, dir) != 2)
    return notify_fail("Syntax: <shoot [living] [direction]>\n");
  if(this_player()->query_disable())
    return notify_fail("You are too busy to notch an arrow and shoot it!\n");
  if(!environment(this_player())->query_exit(dir))
    return notify_fail("That is not a direction you can shoot your bow!\n");
  env = get_object(environment(this_player())->query_exit(dir));
  if(!(target = present(thingy, env)))
    return notify_fail("There is no "+thingy+" "+dir+".\n");
  if(!target->is_living())
    return notify_fail("This isnt time for target practice.\n");
  if(env->query_property("no attack"))
    return notify_fail("You cannot shoot into that room!\n");
  stuff = all_inventory(this_player());
  i = sizeof(stuff);
  flag = 0;
  while(i-- && flag == 0) {
    if(stuff[i]->is_quiver() && stuff[i]->query_arrows()) {
      stuff[i]->use_arrow();
      flag = 1;
    }
  }
  if(flag == 0)
    return notify_fail("You do not have any arrows to shoot!\n");
  if(!this_player()->kill_ob(target))
    return notify_fail("You are unable to kill that.\n");

  dmg = this_player()->query_skill("ranged") +
        this_player()->query_skill("perception")/2 +
        this_player()->query_stats("dexterity")*2/3 -
        target->query_stats("dexterity") -
        target->query_skill("perception")/2 -
        target->query_skill("defense")/2;

  this_player()->set_disable();

  switch(env->query_direction(base_name(environment(this_player())))) {
    case "down": from = "below"; break;
    case "up": from = "above"; break;
    case "enter": from = " the entrance"; break;
    default: from = "the "+env->query_direction(base_name(environment(this_player())));
  }

  if(dmg <= 0) {
    message("info", "An arrow wizzes in from "+
                    from+
                    " and sticks into the ground.", env);
    say(this_player()->query_cap_name()+" shoots an arrow "+dir+" at "+thingy+
          ", but "+possessive(this_player())+" arrow lands pitifully short.");
    write("You shoot an arrow at "+thingy+", but your arrow lands pitifully"
          " short of it's mark.");
    return 1;
  }
  limb = target->query_limbs()[random(sizeof(target->query_limbs()))];
  message("info", "An arrow wizzes in from "+
                  from+
                  " and strikes "+thingy+" in the "+
                  limb+"!", env, target);
  message("info", "An arrow wizzes in from "+
                  from+
                  " and strikes you in the "+
                  limb+"!", target);
  say(this_player()->query_cap_name()+" shoots an arrow "+dir+" at "+thingy+
        " and hits them!");
  write("You shoot an arrow at "+thingy+", striking them badly in the "+limb+"!");
  dmg = dmg/2 + random(dmg/2);
  this_player()->add_sp(-dmg/10 - random(10) - random(5));
  this_player()->add_skill_points("ranged", dmg/6);
  target->do_damage(limb, dmg);
  return 1;
}

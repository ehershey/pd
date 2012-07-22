//    Zerker rage object.
//    By Nightshade.
 
#include <std.h>
inherit OBJECT;

object owner;

void special();
void fright();
 
void create() {
  ::create();

  set_name("crazie");
  set_heart_beat(1);
  set_short("");
  set_long("blah");
  set_weight(0);
  set_value(0);
  set_id(({"zerker_object"}));
}

void set_die() {
    if(!owner) owner = environment(this_object());
     owner->add_skill_bonus("attack",-owner->query_skill("rage"));
    owner->add_skill_bonus("defense",owner->query_skill("rage")/8);
    this_object()->remove();
   if(this_object()) destruct(this_object());
}

void init() {
  ::init();
  add_action("blah","", 1);
}

int blah(string str) {
  string verb;

  if(wizardp(this_player()))
    return 0;

  verb = query_verb();

  if(verb == "quit")
    return 0;

  switch(verb) {
      case "age":
      case "look":
      case "cost":
      case "skills":
      case "score":
      case "body":
      case "time":
      case "hp":
      case "party":
      case "tell":
      case "reply":
      case "stand":
      case "status": return 0;
      default:
  }

  if((verb == "slash"))
    return 0;
  if(verb == "jab")
    return 0;
  if(verb == "whirl")
    return 0;
  if(verb == "rush")
    return 0;
  if(verb == "headbutt")
    return 0;

  write("You are too furious to bother with such trivialities!");

  return 1;
}

void heart_beat() {
  object *stuff;
  int i;

   if(!environment(this_object())) return 0;
  if((!owner) && environment(this_object()) && (environment(this_object())->is_living())) {
    owner = environment(this_object());
    message("info", "You fly into a %^RED%^fit of rage!%^RESET%^",owner);
    message("info", owner->query_cap_name()+" flies into a fit of %^RED%^rage%^RESET%^!", environment(owner), owner);
    owner->add_skill_bonus("attack",owner->query_skill("rage"));
    owner->add_skill_bonus("defense",-owner->query_skill("rage")/8);
  }
  if(environment(this_object()) && !environment(this_object())->is_living())
    this_object()->remove();

  stuff = all_inventory(environment(owner));

  i = sizeof(stuff);
  while (i--)
    if((stuff[i]->query_attackers() != owner) && (!userp(stuff[i])) && (living(stuff[i]))
       && stuff[i] != owner->query_riding() && stuff[i] != owner)
      owner->kill_ob(stuff[i]);

    owner->clean_up_attackers();

  if(!sizeof(owner->query_attackers()) || !owner->query_current_attacker()) {
    if(file_name(environment(owner)) == "/d/standard/freezer")
      return;
    this_object()->finish();
    return;
  }

  if(owner->query_rest_type())
    owner->force_me("stand");

  while(i < owner->query_skill("ferocity")/8)
  i = random(100);

  if(i > 95)
    special();
  else if(i > 85)
    fright();
  else if(i > 10) {
    if(!sizeof(owner->query_wielded()))
      owner->force_me("rush");
    else
      owner->force_me("slash");
  }
  else {
    if(!sizeof(owner->query_wielded()))
      owner->force_me("headbutt");
    else
      owner->force_me("slash");
  }

  if(owner->query_sp() < 200)
    owner->set_sp(200);

  if(!userp(environment(this_object())))
    this_object()->remove();
}

void special() {
    object ob;

    if(owner->query_paralyzed()) {
        message("info", "%^RESET%^%^BOLD%^In a feat of strength, you break free of your paralyzed state!%^RESET%^", owner);
        message("info", "%^RESET%^%^BOLD%^In a feat of strength, "+owner->query_cap_name()+" breaks free of "+possessive(owner)+" paralyzed state!", environment(owner), owner);
        owner->set_paralyzed(0);
        return;
    }

    message("info", "You roar %^CYAN%^mightily%^RESET%^ and %^MAGENTA%^cleave%^RESET%^ your opponent!%^RESET%^",owner);
    message("info", owner->query_cap_name()+" roars %^CYAN%^mightily%^RESET%^ and %^MAGENTA%^cleaves%^RESET%^ "+possessive(owner)+" opponent!%^RESET%^", environment(owner), owner);

    ob = owner->query_current_attacker();

    message("info", owner->query_cap_name()+" slams into you with their weapon!", ob);

    ob->add_hp(-1 * (owner->query_skill("attack")/2 + owner->query_stats("strength")));
}

void fright() {
    object ob;

    if(owner->query_paralyzed()) return;

    ob = owner->query_current_attacker();

    message("info", "Your eyes %^BOLD%^light up%^RESET%^, instilling %^ORANGE%^fear%^RESET%^ in your opponent.%^RESET%^",owner);
    message("info", owner->query_cap_name()+"'s eyes %^BOLD%^light up%^RESET%^, instilling %^ORANGE%^fear%^RESET%^ in their opponent.%^RESET%^", environment(owner), owner);

    message("info", owner->query_cap_name()+" scares you with their savageness!", ob);

    ob->set_paralyzed(2 + random(4), owner->query_cap_name()+" has scared you senseless!");
}

void finish() {

    if(!owner) owner = environment(this_object());
    message("info", "You finally calm down, breathless.%^RESET%^",owner);
    message("info", (string)owner->query_cap_name()+" finally calms down, breathing hard.%^RESET%^", environment(owner), owner);
    owner->add_skill_bonus("attack",-owner->query_skill("rage"));
    owner->add_skill_bonus("defense",owner->query_skill("rage")/8);
    owner->set_sp(100);
    owner->add_skill_points("rage", random(10) + random(10));
    this_object()->remove();
   if(this_object()) destruct(this_object());

}
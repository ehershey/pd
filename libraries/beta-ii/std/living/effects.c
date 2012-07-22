/*
 * code to handle any sort of effect that can happen to living things
 * these will mostly be buff and debuff spells and abilities
 * -Nulvect 2008-Oct-10
 *  added code for recast and delay timers 2008-Oct-20
 *  made paralyze a standard effect 2010-Oct-02
 */

#include <effect_cl.h>
#include <function.h>
#include <damage.h>
#include <damage_types.h>

static class Effect *Effects = ({});
static mapping RecastTimers = ([]);
static mapping DelayTimers = ([]);

class Effect *query_all_effects();
string *query_all_effect_names();
string *query_all_effect_descs();
class Effect *query_effects(string name);
class Effect query_effect(mixed eff);
void add_effect(class Effect eff);
void remove_effect(mixed eff);
void remove_effects(string name);
void set_recast(string, int);
int query_recast(string);
int query_recast_time(string);
void set_delay(string, int);
int query_delay(string);
int query_delay_time(string);

int query_paralyzed();
varargs void set_paralyzed(int, string, string);
void remove_paralyzed();
varargs string query_paralyze_message(int);
int query_blind();
void set_blind(int i);
void remove_blind();
int query_stupor();
void set_stupor(int i);
void remove_stupor();
varargs mixed query_crippled(string);
void set_crippled(string, int);
void remove_crippled(string);
int query_bleeding();
void set_bleeding(int i);
void add_bleeding(int i);
void remove_bleeding();
void do_bleeding(class Effect);
int query_poisoned();
void set_poisoned(int i);
void add_poisoned(int i);
void remove_poisoned();
void do_poisoned(class Effect);
int query_poisoning();
void add_poisoning(int x);


void create() {
  Effects = ({});
  RecastTimers = ([]);
  DelayTimers = ([]);
}

void heart_beat() {
  // this could potentially be called a LOT, and I have been assured by driver
  // developers that this is the most efficient way to populate an array
  // using done += ({ blah }) is quite slow!!
  string *done = allocate(sizeof(Effects));
  int i = 0;
  foreach (class Effect eff in Effects) {
    if ((eff->endtime && time() > eff->endtime) ||
        (eff->maxhits && ++eff->numhits >= eff->maxhits)) {
          remove_effect(eff);
    }
    else if (eff->interval && time() > eff->lasthit + eff->interval) {
      string *msgs = eff->messages;
      eff->lasthit = time();
      // if multiple entries with same name, only show messages from first one
      // this avoids "Your wounds bleed." 5 times per round, for example
      if (sizeof(msgs) && member_array(eff->name, done) == -1) {
        done[i++] = eff->name;
        // purposely not using break here so it falls through:
        switch (sizeof(msgs)) {
          case 2:
            message("info", msgs[1], environment(eff->target), eff->target);
          case 1:
            message("info", msgs[0], eff->target);
        }
      }
      if (functionp(eff->func) && !(functionp(eff->func) & FP_OWNER_DESTED))
        evaluate(eff->func, eff);
    }
  }
}

class Effect *query_all_effects() { return Effects; }
string *query_all_effect_names() { return map(Effects, (: $1->name :) ); }
string *query_all_effect_descs() { return map(Effects, (: $1->desc :) ); }

class Effect *query_effects(string name) {
  return filter(Effects, (: $1->name == $2 :), name);
}

class Effect query_effect(mixed eff) {
  if (stringp(eff)) {
    class Effect *current = query_effects(eff);
    if (sizeof(current))
      return current[0];
  }
  else if (classp(eff)) {
    foreach (class Effect this in Effects)
      if (this == eff)
        return this;
  }
  return 0;
}

// |= adds it only if it's not already in the array
void add_effect(class Effect eff) {
  function f;
  Effects |= ({ eff });
  // try to attach the functions to our living object,
  // in case the defining object gets removed
  if (eff->func && !( functionp(eff->func) & FP_LOCAL || functionp(eff->func) & FP_NOT_BINDABLE) ) {
    f = bind(eff->func, this_object());
    if (functionp(f))
      eff->func = f;
  }
  f = 0;
  if (eff->endfunc && !( functionp(eff->endfunc) & FP_LOCAL || functionp(eff->endfunc) & FP_NOT_BINDABLE) ) {
    f = bind(eff->endfunc, this_object());
    if (functionp(f))
      eff->endfunc = f;
  }
}

void remove_effect(mixed eff) {
  string *msgs;
  class Effect this;

  this = query_effect(eff);

  if (this) {
    // only show end messages if it's the last one with this name
    if (sizeof(query_effects(this->name)) == 1) {
      msgs = this->endmessages;
      switch (sizeof(msgs)) {
        case 2:
          message("info", msgs[1], environment(this->target), this->target);
        case 1:
          message("info", msgs[0], this->target);
      }
    }
    if (functionp(this->endfunc) && !(functionp(this->endfunc) & FP_OWNER_DESTED))
      evaluate(this->endfunc, this);

    Effects -= ({ this });
  }
}

void remove_effects(string name) {
  class Effect *all = query_effects(name);
  foreach (class Effect eff in all) {
    all -= ({ eff });
    if (sizeof(all)) {
      eff->messages = 0;
      eff->endmessages = 0;
    }
    remove_effect(eff);
  }
}

void set_recast(string name, int time) { RecastTimers[name] = time; }
int query_recast(string name) { return query_recast_time(name) > time(); }
int query_recast_time(string name) { return RecastTimers[name]; }
void set_delay(string name, int time) { DelayTimers[name] = time; }
int query_delay(string name) { return query_delay_time(name) > time(); }
int query_delay_time(string name) { return DelayTimers[name]; }

// ---------
// shortcuts for common bad things
// ---------

// *** paralyzed ***

int query_paralyzed() { return query_effect("paralyzed") ? 1 : 0; }
varargs void set_paralyzed(int i, string msg, string endmsg) {
  class Effect para = query_effect("paralyzed");

  if (nullp(i)) return;
  if (nullp(msg))
    msg = "You are stiff as stone.";
  if (nullp(endmsg))
    endmsg = "You can move again.";

  // set_paralyzed(0) silently removes paralyze
  if (i <= 0) {
    if (para)
      para->endmessages = 0;
    remove_effect("paralyzed");
    return;
  }

  if (para) return;

  para = new(class Effect);
  para->name = "paralyzed";
  para->desc = msg;
  para->caster = this_player() || previous_object();
  para->castername = para->caster->query_name() || para->caster->query_short();
  para->target = this_object();
  para->endmessages = ({ endmsg });
  para->endtime = time()+i-2;
  
  add_effect(para);
}
// remove_paralyzed() shows you the end message, default "You can move again."
void remove_paralyzed() { remove_effect("paralyzed"); }
varargs string query_paralyze_message(int i) {
  class Effect para = query_effect("paralyzed");

  if (!para)
    return "";

  if (i)
    return para->endmessages[0];

  else
    return para->desc;
}

// *** blindness ***

int query_blind() { return query_effect("blind") ? 1 : 0; }
void set_blind(int i) {
  class Effect bl = query_effect("blind");

  if (i == 0) {
    remove_effect("blind");
    return;
  }

  // can't be blinded if you're already blind
  if (bl) return;
  
  bl = new(class Effect);
  bl->name = "blind";
  bl->desc = "You are blind.";
  bl->caster = this_player() || previous_object();
  bl->castername = bl->caster->query_name() || bl->caster->query_short();
  bl->target = this_object();
  bl->endmessages = ({ "You can see again." });
  // set_blind(-1) lasts until something removes it
  if (i != -1)
    bl->endtime = time()+i;

  add_effect(bl);
}
void remove_blind() { set_blind(0); }

// *** stupor ***

int query_stupor() { return query_effect("stupor") ? 1 : 0; }
void set_stupor(int i) {
  class Effect st = query_effect("stupor");

  if (i == 0) {
    remove_effect("stupor");
    return;
  }

  // being stupored while already stupored does nothing
  if (st) return;
  
  st = new(class Effect);
  st->name = "stupor";
  st->desc = "You can't think straight.";
  st->caster = this_player() || previous_object();
  st->castername = st->caster->query_name() || st->caster->query_short();
  st->target = this_object();
  st->endmessages = ({ "You can think clearly again." });
  // set_stupor(-1) lasts until removed
  if (i != -1)
    st->endtime = time()+i;

  add_effect(st);
}
void remove_stupor() { set_stupor(0); }

// *** crippled ***

// query_crippled("head") returns 1 or 0
// query_crippled() returns ({ "head", "left hand" }) or 0
varargs mixed query_crippled(string limb) {
  class Effect *crippled = query_effects("crippled");

  if (stringp(limb)) {
    crippled = filter(crippled, (: $1->misc == $2 :), limb);
    return sizeof(crippled) ? 1 : 0;
  }

  if (nullp(limb))
    return map(crippled, (: $1->misc :) );

  return 0;
}
void set_crippled(string limb, int i) {
  class Effect *crippled = query_effects("crippled");
  class Effect cr;

  if (!limb) return;

  if (limb != "all")
    crippled = filter(crippled, (: $1->misc == $2 :), limb);

  if (i == 0) {
    foreach (cr in crippled)
      remove_effect(cr);
    return;
  }

  // can't cripple the same limb multiple times
  if (sizeof(crippled))
    return;

  cr = new(class Effect);
  cr->name = "crippled";
  cr->desc = "Your "+limb+" is crippled.";
  cr->caster = this_player() || previous_object();
  cr->target = this_object();
  cr->endmessages = ({ "You can move your "+limb+" again." });
  cr->misc = limb;
  if (i != -1)
    cr->endtime = time()+i;
  add_effect(cr);
}
void remove_crippled(string limb) { set_crippled(limb, 0); }

// *** bleeding ***

// returns total of all bleeding effects
int query_bleeding() {
  class Effect *bl = query_effects("bleeding");
  int total = 0;
  foreach (class Effect this in bl)
    total += this->misc;
  return total;
}
void set_bleeding(int i) {
  class Effect bl = query_effect("bleeding");
  
  //set_bleeding(0) removes ALL bleeding effects
  if (i <= 0) {
    remove_effects("bleeding");
    return;
  }

  // set the first bleeding instance if we're already bleeding
  if (bl)
    bl->misc = i;
  else
    add_bleeding(i);

}
void remove_bleeding() { set_bleeding(0); }
void add_bleeding(int x) {
  // if adding, create a new bleeding effect
  if (x > 0) {
    class Effect bl;
    bl = new(class Effect);
    bl->name = "bleeding";
    bl->desc = "You are bleeding.";
    bl->caster = this_player() || previous_object();
    if (userp(bl->caster) && environment(bl->caster)) {
      bl->startroom = file_name(environment(bl->caster));
      bl->startzone = environment(bl->caster)->query_zone();
    }
    bl->castername = bl->caster->query_name() || bl->caster->query_short();
    bl->target = this_object();
    bl->func = (: do_bleeding :);
    bl->interval = 2;
    bl->messages = ({ "Your wounds bleed." });
    bl->misc = x;
    add_effect(bl);
  }
  // if reducing bleeding...
  else if (x < 0) {
    class Effect *bleeds;
    x = -x;
    bleeds = query_effects("bleeding");
    bleeds = sort_array(bleeds, (: $1->misc > $2->misc ? 1 : -1 :) );
    // remove the smallest bleeds first - smaller wounds heal faster
    foreach (class Effect bleed in bleeds) {
      if (x >= bleed->misc) {
        x -= bleed->misc;
        bleed->misc = 0;
        remove_effect(bleed);
        if (x <= 0)
          break;
      }
      else {
        bleed->misc -= x;
        break;
      }
    }
  }
}
void do_bleeding(class Effect eff) {
  object to = eff->target;
  int bleed = eff->misc;
  if (!bleed) return;

  if (bleed > 10)
    bleed = bleed/4 + random(bleed*3/4);
  if (bleed < 1)
    bleed = 1;
  to->do_damage(0, bleed, DAMAGE_PHYSICAL,
    DAMAGE_HP_ONLY | DAMAGE_BYPASS_ARMOUR | DAMAGE_BYPASS_STRENGTHS,
    eff->caster || eff->castername, eff->startzone);
  //to->add_hp(-bleed);
  /*
  if (eff->caster && userp(eff->caster)) {
    to->remove_property("last damage");
    to->set_property("last damage", ({ eff->caster, time(), eff->startroom }) );
  }
  */
  eff->interval = 2*(1+random(2));
  eff->misc -= bleed;
  if (eff->misc <= 0){
    eff->endmessages = ({ "The bleeding stops." });
    eff->misc = 0;
    eff->endtime = 1;
  }
}

// *** poison ***

// returns total of all poison effects
int query_poisoned() {
  class Effect *po = query_effects("poison");
  int total = 0;
  foreach (class Effect this in po)
    total += this->misc;
  return total;
}
void set_poisoned(int i) {
  class Effect po = query_effect("poison");
  
  //set_poisoned(0) removes ALL poison effects
  if (i <= 0) {
    remove_effects("poison");
    return;
  }

  // set the first poison instance if we're already poisoned
  if (po)
    po->misc = i;
  else
    add_poisoned(i);

}
// this is varargs because autoremove passes the class var in
// but I want to be able to do player->remove_poisoned();
void remove_poisoned() { set_poisoned(0); }
void add_poisoned(int x) {
  // if adding, create a new poison effect
  if (x > 0) {
    class Effect po;
    po = new(class Effect);
    po->name = "poison";
    po->desc = "You are poisoned.";
    po->caster = this_player() || previous_object();
    if (userp(po->caster) && environment(po->caster)) {
      po->startroom = file_name(environment(po->caster));
      po->startzone = environment(po->caster)->query_zone();
    }
    po->castername = po->caster->query_name() || po->caster->query_short();
    po->target = this_object();
    po->func = (: do_poisoned :);
    po->interval = 2+random(4);
    po->messages = ({ "You start to feel weak." });
    po->misc = x;
    add_effect(po);
  }
  // if reducing poison...
  else if (x < 0) {
    class Effect *poisons;
    x = -x;
    poisons = query_effects("poison");
    poisons = sort_array(poisons, (: $1->misc > $2->misc ? 1 : -1 :) );
    // remove the lesser poisons first - easier to heal
    foreach (class Effect poison in poisons) {
      if (x >= poison->misc) {
        x -= poison->misc;
        poison->misc = 0;
        remove_effect(poison);
        if (x <= 0)
          break;
      }
      else {
        poison->misc -= x;
        break;
      }
    }
  }
}
void do_poisoned(class Effect eff) {
  object to = eff->target;
  int poison = eff->misc;
  string cap = to->query_cap_name();
  mixed *poison_messages = ({
    ({
      "You cough up some blood.",
      cap+" coughs up some blood.",
    }),
    ({
      "You shake and shiver violently.",
      cap+" shakes and shivers.",
    }),
    ({
      "Your body feels numb.",
      cap+" slumps numbly.",
    }),
    ({
      "A sharp pain surges through your veins.",
      cap+" winces in pain.",
    }),
  });
  int amt;

  if (!poison) return;

  amt = -(poison/2 + random(poison*3/2));
  to->do_damage(0, -amt, DAMAGE_POISON, DAMAGE_HP_ONLY | DAMAGE_BYPASS_ARMOUR,
    eff->caster || eff->castername, eff->startzone);
  //to->add_hp(amt);
  to->add_sp(amt*2/3);
  to->add_mp(amt*5/4);

  /*
  if (eff->caster && userp(eff->caster)) {
    to->remove_property("last damage");
    to->set_property("last damage", ({ eff->caster, time(), eff->startroom }) );
  }
  */

  if (random(1000) < 400)
    eff->messages = poison_messages[random(random(sizeof(poison_messages)+1))];
  else
    eff->messages = 0;

  eff->interval = 2+random(8);
  eff->misc -= 1+random(3);
  if (eff->misc <= 0) {
    eff->endmessages = ({ "You feel better." });
    eff->misc = 0;
    eff->endtime = 1;
  }
}
int query_poisoning() { return query_poisoned(); }
void add_poisoning(int x) { add_poisoned(x); }



#include <std.h>
#include <rest.h>

inherit MONSTER;

void gotosleep();
int do_special_check(string);

string *allcolors = ({ "red", "blue", "white", "black" });
mapping sizeinfo = ([
  "small" : 35,
  "medium" : 45,
  "large" : 60,
]);
string *allsizes = keys(sizeinfo);

void create() {
  string col, size, long;
  int level;
  string *spells = ({
    "bite", "claw", "tailspear", "swoop", "usespecial",
    "dragonfury", "wrap 10", "roar", "shield me",
  });
  ::create();
  set_gender( ({ "male", "female" })[random(2)] );
  col = allcolors[random(sizeof(allcolors))];
  size = allsizes[random(sizeof(allsizes))];
  
  set_name(col+" dragon");
  set_id( ({ "dragon", col+" dragon", }) );
  long = "This dragon has %^BOLD%^%^"+upper_case(col)+"%^"+col+"%^RESET%^ scales. ";

  switch (size) {
    case "medium":
      set_short("a "+col+" dragon");
      long += capitalize(query_subjective())+" is about average size for a dragon.";
    break;

    default:
      set_id(query_id() + ({ size+" "+col+" dragon", size+" dragon" }) );
      set_short("a "+size+" "+col+" dragon");
      long += capitalize(query_subjective())+" is rather "+size+".";
  }

  set_long(long);
  set_class("dragon");
  set_race("dragon");
  set_body_type("dragon");
  set_subclass(col);

  level = sizeinfo[size];
  level = level + random(level/8) - random(level/8);
  set_level(level);

  //set_stats("constitution", query_stats("constitution")*2);
  set_hp(query_max_hp());
  set_max_sp(query_max_sp()*2);
  set_max_mp(query_max_mp()*2);
  set_sp(query_max_sp());
  set_mp(query_max_mp());

  if (random(900) > 300)
    add_money("gold", 50+random(20));
  if (random(900) > 550)
    add_money("platinum", 5+random(3));

  set_spell_chance(50+random(25));
  switch (col) {
    case "blue":
      set_alignment(1000);
      spells +=
        ({ "spire", "cure me", "crystallize me", "dispell", "iceblast" });
    break;

    case "white":
      set_alignment(1500);
      spells +=
        ({ "sunder", "dispell", "faithwing", "solarflare" });
    break;

    case "red":
      spells +=
        ({ "fireshot", "flameclaw", "pyrestrike" });
    break;

    case "black":
      set_alignment(-1000);
      spells +=
        ({ "shadowfang", "annihilate", "void", "darkmist" });
    break;
  }
  set_spells(spells);

  add_action("do_special_check", "usespecial");
  
  if (random(10) == 3) call_out("gotosleep", 2);
}

void gotosleep() { command("rest"); }

// these hit everyone in the room, so only use them when there are no other mobs
int do_special_check(string str) {
  object tp = this_player();
  object tgt = tp->query_current_attacker();
  object env = environment(tp);
  object *mobs;
  mapping specials = ([
    "red" : ({ "breathe", "rage" }),
    "black" : ({ "breathe", "chainlightning", "chaosvapor" }),
    "white" : ({ "breathe", "dispell all" }),
    "blue" : ({ "breathe", "dispell all" }),
  ]);
  string *colspecials;
  string use, col;

  if (!tp || tp != this_object() || !env) return 0;

  mobs = filter(all_inventory(env), (: $1->is_monster() :) );

  if (tp->query_level() < 50 && random(50) < 25 && tgt)
    use = "breathe "+tgt->query_name();
  else if (!sizeof(mobs)) {
    col = tp->query_subclass();
    colspecials = specials[col];
    if (sizeof(colspecials))
      use = colspecials[random(sizeof(colspecials))];
  }

  if (!use) {
    if (tp->query_level() < 50)
      use = "breathe";
    else
      use = "claw";
  }

  command(use);

  return 1;
}

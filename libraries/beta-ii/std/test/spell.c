// The new spell daemon for pd!!!
// ��� pd.iuis.org  Wednesday November 22 2000 -- 23:00 -08:00
/******************************************************************************

   Level of Spells [ 1 - 100 ]
   new: "set_level" : 1


   Damage comes from what?
   new: "set_damage_perc" : ([ "magic attack" : 60,
			       "telepathy"    : 60 ])

  new: "spell_delay" : 2 // rounds


*/
#include <teststd.h>
#include <daemons.h>

inherit DAEMON;

int set_properties(mapping prop);
int player_ok(object tp, int x);
int spell_ok(object tp);
int target_ok(object ob);
int spell_message(string *str, object tp, object ob);
int setup_spell(object tp, object target, string *type);
int get_mon_hp(int level);
int get_raw_damage(object tp);

#define get_base_damage(i) (get_mon_hp(i)/8)

mapping properties = ([]);

static void create()
{
    ::create();
    properties["min_alignment"] = -1500;
    properties["max_alignment"] = 1500;
    properties["req_class"]     = ({ "none" });
    properties["req_subclass"]  = ({ "none" });
    properties["req_level"]     = 1;
    properties["set_level"]     = 1;
    properties["set_delay"]     = 1;
    properties["req_mp"]        = 0;
    properties["min_mp"]        = 0;
    properties["target_properties"] = ({ "living" });
    properties["spell_properties"]  = ({ "no attack" });
    properties["req_skills"] = ([ ]);
    properties["req_stats"]  = ([ ]);
}

int set_properties(mapping prop)
{
    int i;
    string *key;

    if (!mapp(prop)) return -1;
    i = sizeof( key = keys(prop) );
    if (!i) return -1;
    while(i--)
	properties[ key[i] ] = prop [ key[i] ];
} 

int player_ok(object tp, int x)
{
    int i;
    string *key;

    if (member_array("none", properties["req_class"])==-1)
	if (member_array(tp->query_class(), properties["req_class"])==-1)
	    return notify_fail("Your class cannot do that.\n");
    if (member_array("none", properties["req_subclass"])==-1)
	if (member_array(tp->query_subclass(), properties["req_subclass"])==-1)
	    return notify_fail("Your subclass cannot do that.\n");
    if (tp->query_level() < properties["req_level"])
	if(!x)
	    return notify_fail("You are too small to do that.\n");
    if (i = sizeof(key = keys(properties["req_skills"])))
    {
	while(i--)
	{
	    if (properties["req_skills"][key[i]] > tp->query_skill(key[i]))
		return notify_fail("You are not skilled enough to do that.\n");
	}
    }
    if (i = sizeof(key = keys(properties["req_stats"])))
    {
	while(i--)
	{
	    if (properties["req_stats"][key[i]] > tp->query_stats(key[i]))
		return notify_fail("You are not able to do that yet.\n");
	}
    }
    if (properties["min_alignment"] > tp->query_alignment())
	return notify_fail("You are too evil to cast this spell.\n");
    if (properties["max_alignment"] < tp->query_alignment())
	return notify_fail("You are too nice to cast this spell.\n");
    if (tp->query_mp() < properties["req_mp"]) 
	if(!x) return notify_fail("You lack the magical energy to cast this spell.\n");
    if (!x) if (tp->query_disable())
	    return notify_fail("You are too busy finishing up another spell.\n");

    return 1;
}

int spell_ok(object tp)
{
    int i;

    i = sizeof(properties["spell_properties"]);
    while(i--)
    {
	switch(properties["spell_properties"][i])
	{
	case "no attack":
	    if (environment(tp)->query_property("no attack"))
		return notify_fail("You cannot attack in this peaceful area.\n");
	    break;
	case "no magic":
	    if (environment(tp)->query_property("no magic"))
		return notify_fail("You cannot cast magic in this area.\n");
	    break;
	case "not combat":
	    if (tp->query_current_attacker())
		return notify_fail("You cannot use this spell in combat.\n");
	    break;  
	}
    }
    return 1;
}

int target_ok(object ob)
{
    int i;

    i = sizeof(properties["target_properties"]);
    while(i--)
    {
	switch(properties["target_properties"][i])
	{
	case "living":
	    if (ob->query_ghost() || !ob->is_living())
		return notify_fail("You can only cast this on living things.\n");
	    break;
	case "no living":
	    if (ob->is_living())
		return notify_fail("You can only cast this on inanimate objects.\n");
	    break;
	case "no cast me":
	    if (ob == this_player())
		return notify_fail("You cannot cast this on yourself.\n");
	    break;
	}
    }
    return 1;
}

int spell_message(string *str, object tp, object ob)
{
    if (!tp || !ob)
	return 0;

    str[0] = replace_string(str[0], "%^", "%%^");
    str[1] = replace_string(str[1], "%^", "%%^");
    str[2] = replace_string(str[2], "%^", "%%^");
    if (str[0]) message("info", sprintf(str[0], ob->query_cap_name()), tp);
    if (str[1]) message("info", sprintf(str[1], tp->query_cap_name()), ob);
    if (str[2]) message("info", sprintf(str[2], tp->query_cap_name(), ob->query_cap_name()), environment(tp),
	  ({ tp, ob }) );

    return 1;
}
string *query_target() { return properties["target_properties"]; }
int setup_spell(object tp, object target, string *type)
{
    int a, dmg, i;
    string *key;

    /* ----------- HEALING SPELL -------- */
    /*
    if (member_array("heal", type)!=-1)
      {
       dmg = get_raw_damage( tp ) / 2;
       target->heal( dmg );
       if ((a = sizeof(key = keys(properties["skill_perc"]))))  while(a--)
	 tp->add_skill_points(key[a], random(dmg)/3);
       tp->add_mp( - (properties["min_mp"]+dmg/25) );
       tp->set_disable();
       return 1;
      } 
    */
    /* ----------- REGULAR COMBAT SPELL --------- */
    if (member_array("start combat", properties["target_properties"])!=-1)
	tp->kill_ob(target); 
    dmg = get_raw_damage(tp);
    message("info", "raw damage = "+dmg, this_player());
    dmg -= target->query_stats("wisdom")*5+target->query_stats("intelligence")*3;
    message("info", "stats included = "+dmg, this_player());
    if ((a = sizeof(key = keys(properties["skill_perc"]))))
	while(a--)
	    tp->add_skill_points(key[a], random(dmg)/5);
    message("info", "skills inc = "+dmg, this_player());
    tp->add_mp( - (properties["min_mp"]+dmg/50) );
    tp->set_disable();
    message("info", "your damage is "+i=random(dmg), this_player());
    tp->set_casting( i);
    return 1;

}

int get_mon_hp(int level)
{
    if ( level <= 10)
	return ( (level * 20) + 64);

    if (level >= 20)
	return ((level * (level-3))*4/2);

}


int get_raw_damage(object tp)
{
    int a       = 0,
    base    = get_base_damage(properties["set_level"]),
    dskill  = 0;
    string *key;

    if (!(a = sizeof(key = keys(properties["skill_perc"])))) return base;

    while(a--)
	dskill +=  tp->query_skill(key[a]) * (to_float(properties["skill_perc"][key[a]])/150);

    dskill += ((tp->query_stats("wisdom")*7)+tp->query_stats("intelligence")*4)*2;
    return (dskill + base);

}

// modified by stormbringer
// seeker 06/02/2000
// Fixed by Whit 01:03:12 AM 01/04/02
#include <std.h>
#include <daemons.h>
inherit DAEMON;
//--leave abilities meant for Other catagory out of the list--
mapping spell_class= ([
                       "backstab" : "attack",
                       "behead"   : "attack",
                       "charge"   : "attack",
                       "bladedance": "attack",
                       "choke"    : "attack",
                       "circle"   : "attack",
                       "cloak"    : "deception",
                       "cripple"  : "attack",
                       "dakzual"  : "attack",
                       "darkshift": "deception",
                       "denmak"   : "attack",
                       "disarm"   : "defense",
                       "disquise" : "deception",
                       "flick"    : "attack",
                       "gore"     : "attack",
                       "headbutt" : "attack",
                       "impale"   : "attack",
                       "jab"      : "attack",
                       "lunge"    : "attack",
                       "massacre" : "attack",
                       "maul"     : "attack",
                       "mudarmor" : "defense",
                       "mudthrow" : "attack",
                       "mug"      : "attack",
                       "parry"    : "defense",
                       "peek"     : "deception",
                       "pick"     : "deception",
                       "rage"     : "attack",
                       "rush"     : "attack",
                       "sharpen"  : "weapon",
                       "slash"    : "attack",
                       "snapkick" : "attack",
                       "sneak"    : "deception",
                       "stab"     : "attack",
                       "stalk"    : "deception",
                       "steal"    : "deception",
                       "stealth"  : "deception",
                       "strike"   : "attack",
                       "stun"     : "attack",
                       "trip"     : "attack",
                       "whirl"    : "attack"
 ]);
string *directories = 
({
"/cmds/skills/",
"/cmds/hm/" 
});
int cmd_abilities(string str)
{
    string *spell, *can, *attack, *defense, *weapon, *deception, *other;
//    string *spe;
    string tmp;
//    object ob;
    int i, a;
    attack = ({});defense = ({});weapon = ({});deception = ({});other = ({});
    i = sizeof(directories);
    while(i--)
    {
        spell = get_dir(directories[i]);
        if (!spell) continue;
        a = sizeof(spell);
        while(a--)
        {
            if (!spell[a]) continue;
            if (sscanf(spell[a], "%s.c",tmp)!=1) continue;
            tmp = directories[i]+spell[a];
           if (tmp->abil() )
              {
               if (sscanf(spell[a], "_%s.c", tmp)!=1) continue;
               if (!can) can = ({ tmp });
                 else can += ({ tmp });
              }
        }
    }
    a = sizeof(can);
    while(a--)
     {
      if (spell_class[can[a]]=="attack") attack += ({ can[a] });
      if (spell_class[can[a]]=="defense") defense += ({ can[a] });
      if (spell_class[can[a]]=="weapon") weapon += ({ can[a] });
      if (spell_class[can[a]]=="deception") deception += ({ can[a] });
      if (spell_class[can[a]]=="other") other += ({ can[a] });
     }
    other = can - (attack+defense+weapon+deception+other);
    if (attack==({})) attack += ({ "(none)" });
    if (defense==({})) defense += ({ "(none)" });
    if (weapon==({})) weapon += ({ "(none)" });
    if (deception==({})) deception += ({ "(none)" });
    if (other==({})) other += ({ "(none)" });
message("no_wrap", "%^BLUE%^+=+=%^BOLD%^(%^RESET%^ Abilities "%^BLUE%^^%BOLD%^)"
"%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=+=+=+=+=+"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
"+=+=\n",
this_player());
    write("%^RED%^%^BOLD%^[Attack]");
    write("  "+implode(attack, ", "));
    write("%^MAGENTA%^%^BOLD%^[Defense]");
    write("  "+implode(defense, ", "));
    write("%^BLUE%^%^BOLD%^[Weapon]");
    write("  "+implode(weapon, ", "));
    write("%^GREEN%^%^BOLD%^[Deception]");
    write("  "+implode(deception, ", "));
    write("%^CYAN%^%^BOLD%^[Other]");
    write("  "+implode(other, ", "));
/*    
    if (!tmp) return 1;
    i = sizeof(can);
    b= 0;
    while(i--)
     {
      b++;
      if (i) message("no_wrap", can[i]+", ", this_player());
        else message("info", can[i], this_player());
      if (b>=7)  { message("no_wrap", "\n", this_player()); b=0; }
     } */
    return 1;
}
int help()
{
  write( @EndText
Syntax: abilities
Effect: gives a list of the abilities your character has.
See also: spells, songs
EndText
  );
  return 1;
}

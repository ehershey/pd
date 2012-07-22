// seeker 06/02/2000

#include <std.h>
#include <daemons.h>

inherit DAEMON;
//--leave spells meant for Other catagory out of the list--
mapping spell_class= ([
                       "absorb"     : "healing",
                       "acidrain"   : "attack",
                       "annihilate" : "attack", 
                       "armageddon" : "faith",
                       "blast"      : "attack",
                       "bolt"       : "attack",
                       "boost"      : "healing",
                       "buffer"     : "defense",
                       "burn"       : "attack",
                       "chaoswave"  : "attack",
                       "chilltouch" : "attack",
                       "corrupt"    : "attack",
                       "cripple"    : "attack",
                       "cure"       : "healing",
                       "dakzhul"    : "attack",
                       "dark"       : "conjuring",
                       "darkmist"   : "attack",
                       "dazzle"     : "attack",
                       "deathtouch" : "attack",
                       "demonbolt"  : "attack",
                       "demonfire"  : "attack",
                       "demonstrength" : "faith",
                       "denmak"     :  "attack",
                       "detect"     : "faith",
                       "disease"    : "attack",
                       "disintegrate" : "attack",
                       "dispell"    : "attack",
                       "dissolve"   : "attack",
                       "dreamwalk"  : "attack",
                       "ears"       : "conjuring",
                       "earthmaw"   : "attack",
                       "enchant"    : "conjuring",
                       "envelop"    : "attack",
                       "faithbomb"  : "attack",
                       "fear"       : "attack",
                       "fireball"   : "attack",
                       "firebomb"   : "attack",
                       "fizgig"     : "attack",
                       "freeze"     : "attack",
                       "gate"       : "conjuring",
                       "guard"      : "defense",
                       "heal"       : "healing",
                       "hellfire"   : "attack",
                       "hold"       : "conjuring",
                       "hurt"       : "faith",
                       "icestorm"   : "attack",
                       "inferno"    : "attack",
                       "keep"       : "conjuring",
                       "lash"       : "attack",
                       "lifetap"    : "healing",
                       "lifewarp"   : "faith",
                       "light"      : "conjuring",
                       "limbs"      : "faith",
                       "liquify"    : "attack",
                       "lore"       : "conjuring",
                       "mend"       : "healing",
                       "metamorphase" : "dragon",
                       "mheal"      : "healing",
                       "missile"    : "attack",
                       "mysticblade" : "faith",
                       "offer"      : "faith",
                       "pain"       : "attack",
                       "palm"       : "attack",
                       "paralyze"   : "faith", 
                       "peace"      : "faith",
                       "psidrain"   : "healing",
                       "psistorm"   : "attack",
                       "protect"    : "defense",
                       "purge"      : "faith",
                       "purify"     : "healing",
                       "replace"    : "healing",
                       "ressurect"  : "healing",
                       "rot"        : "attack",
                       "sandcone"   : "attack",
                       "sandstorm"  : "attack",
                       "scald"      : "attack",
                       "scorch"     : "attack",
                       "scry"       : "conjuring",
                       "sear"       : "attack",
                       "sense"      : "faith",
                       "shadowburst" : "attack",
                       "shield"     : "defense",
                       "shock"      : "attack",
                       "shroud"     : "attack",
                       "solidify"   : "attack",
                       "soulburn"   : "attack",
                       "spark"      : "attack",
                       "staticshield" : "defense",
                       "supplication" : "faith",
		           "tempestcraft" : "conjuring",
                       "thornwrack" : "attack",
                       "torment"    : "attack",
                       "turn"       : "faith",
                       "vestment"   : "defense",
                       "vortex"     : "attack",
                       "wound"      : "healing"
 ]);

string *directories = 
({
"/cmds/skills/" 
});

int cmd_spells(string str)
{
    string *spell, *can, *attack, *defense, *faith, *healing, *other, *conjuring, *spe;
    string tmp;
    object ob;
    int i, a, b;

    attack = ({});defense = ({});faith = ({}); healing = ({}); other = ({});
    conjuring = ({});
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
           if (tmp->spell() )

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
      if (spell_class[can[a]]=="faith") faith += ({ can[a] });
      if (spell_class[can[a]]=="healing") healing += ({ can[a] });
      if (spell_class[can[a]]=="other") other += ({ can[a] });
      if (spell_class[can[a]]=="conjuring") conjuring += ({ can[a] });
     }
    other = can - (attack+defense+faith+healing+other+conjuring);
    if (attack==({})) attack += ({ "(none)" });
    if (defense==({})) defense += ({ "(none)" });
    if (faith==({})) faith += ({ "(none)" });
    if (healing==({})) healing += ({ "(none)" });
    if (conjuring==({})) conjuring += ({ "(none)" });
    if (other==({})) other += ({ "(none)" });
message("no_wrap", "%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Spells %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n%^RESET%^", this_player());
    write("%^BOLD%^%^RED%^Attack:");
    write("  %^BOLD%^%^WHITE%^"+implode(attack, ", "));
    write("%^BOLD%^%^MAGENTA%^Defense:");
    write("  %^BOLD%^%^WHITE%^"+implode(defense, ", "));
    write("%^BOLD%^%^BLUE%^Faith:");
    write("  %^BOLD%^%^WHITE%^"+implode(faith, ", "));
    write("%^BOLD%^%^GREEN%^Healing:");
    write("  %^BOLD%^%^WHITE%^"+implode(healing, ", "));
    write("%^BOLD%^%^YELLOW%^Conjuring:");
    write("  %^BOLD%^%^WHITE%^"+implode(conjuring, ", "));
    write("%^BOLD%^%^CYAN%^Other:");
    write("  %^BOLD%^%^WHITE%^"+implode(other, ", "));
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
Syntax: spells
Effect: lists spells you know.
See also: score
EndText
  );
  return 1;
}
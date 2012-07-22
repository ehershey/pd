// seeker 06/02/2000
//  Fixed by Whit - 12:02:18 AM 01/04/02
#include <std.h>
#include <daemons.h>
inherit DAEMON;
//--leave spells meant for Other catagory out of the list--
mapping spell_class= ([
                       "splash"     : "attack",
                       "soak"       : "attack",
                       "shards"     : "attack",
                       "crystallize"  : "defense",
                       "arcticblast" : "attack",
                       "hailstorm"   : "attack",
                       "subzero"   : "attack",
                       "mistshield"   : "defense",
                       "burst"     : "attack",
                       "gust"      :  "attack",
                       "ensnare"   :  "attack",
                       "gale"      :  "attack",
                       "tempest"   :  "attack",
                       "surge"     :  "attack",
                       "tornado"   :  "defense",
                       "hurricane"  :  "attack",
                       "absorb"     : "healing",
                       "acidcone"   : "attack",
                       "acidrain"   : "attack",
                       "annihilate" : "attack", 
                       "armageddon" : "attack",
                       "bearsrage"  : "defense",
                       "blast"      : "attack",
                       "bless"      : "faith",
                       "bolt"       : "attack",
                       "boost"      : "healing",
                       "buffer"     : "defense",
                       "burn"       : "attack",
                        "cauterize" : "healing",
                        "chainlightning": "attack",
                       "chaoswave"  : "attack",
                       "chilltouch" : "attack",
                       "coalesce"  : "defense",
                       "corrupt"    : "attack",
                       "cripple"    : "attack",
                       "create"     : "conjuring",
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
                       "eagleblitz"  : "attack",
                       "ears"       : "conjuring",
                       "earthmaw"   : "attack",
                       "enchant"    : "conjuring",
                       "energybolt" : "attack",
                       "envelop"    : "attack",
                       "faithbomb"  : "attack",
                       "faithwing"  : "attack",
                       "fear"       : "attack",
                       "felinefury" : "defense",
                       "fireball"   : "attack",
                       "firebomb"   : "attack",
                       "fizgig"     : "attack",
                       "fog"        : "attack",
                       "fortitude": "defense",
                       "foxeswit" : "defense",
                       "freeze"     : "attack",
                       "gate"       : "conjuring",
                       "guard"      : "defense",
                       "heal"       : "healing",
                       "hellfire"   : "attack",
                       "hold"       : "conjuring",
                       "holyfire"   : "attack",
                       "hurt"       : "attack",
                       "husk"       : "defense",
                       "icestorm"   : "attack",
                       "implode"    : "attack",
                       "inferno"    : "attack",
                       "keep"       : "conjuring",
                       "lash"       : "attack",
                       "levin"      : "attack",
                       "lifetap"    : "attack",
                       "lifewarp"   : "attack",
                       "light"      : "conjuring",
                       "limbs"      : "faith",
                       "liquify"    : "attack",
                       "lore"       : "conjuring",
                       "magicmissile" : "attack",
                       "manablast"    : "attack",
                       "manabolt"     : "attack",
                       "manamissile"  : "attack",
                       "mercurial"   : "defense",
                       "mist"       : "conjuring",
                       "mend"       : "healing",
                       "mheal"      : "healing",
                       "missile"    : "attack",
                       "mysticblade" : "faith",
                       "nova"        : "attack",
                       "offer"      : "faith",
                       "owlsmind" : "defense",
                       "pain"       : "attack",
                       "palm"       : "attack",
                       "paralyze"   : "faith", 
                       "peace"      : "faith",
                       "pillar"     : "attack",
                       "psidrain"   : "healing",
                       "psistorm"   : "attack",
                       "pressure"   : "attack",
                       "protect"    : "defense",
                       "purge"      : "attack",
                       "purify"     : "healing",
                       "raise"      : "conjuring",
                       "replace"    : "healing",
                       "resonate"  : "defense",
                       "resurrect"  : "healing",
                       "rootgrasp"  : "faith",
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
                       "shockwave"  : "attack",
                       "shroud"     : "attack",
                       "solarflare" : "attack",
                       "solidify"   : "attack",
                       "soulburn"   : "attack",
                       "spark"      : "attack",
		       "stasis"     : "conjuring",
                       "staticshield" : "defense",
                       "summon"     : "faith",
                       "supplication" : "faith",
                       "tempestcraft" : "conjuring",
                       "thorns"     : "attack",
                       "thornwrack" : "attack",
                       "torment"    : "attack",
                       "tremble"    : "attack",
                       "turn"       : "faith",
                       "vestment"   : "defense",
                      "vigor"      : "healing",
                       "vinearmour"   : "defense",
                       "vinegrasp"    : "attack",
                       "vortex"     : "attack",
                       "whirlwind"  : "attack",
                       "wound"      : "attack",
 ]);
string *directories = 
({
"/cmds/skills/" 
});
int cmd_spells(string str)
{
//    string *spell, *can, *attack, *defense, *faith, *healing, *other,
//*conjuring, *spe;
    string *spell, *can, *attack, *defense, *faith, *healing, *other,
*conjuring;
    string tmp;
//    object ob;
//    int i, a, b;
int i, a;
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
    if( !can )
        can = ({ });
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
message("no_wrap", "%^BLUE%^+=+=%^BOLD%^(%^RESET%^ Spells %^BLUE%^%^BOLD%^)"
"%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
"+=+=+=+=\n",
this_player());
    write("%^RED%^%^BOLD%^Attack:%^RESET%^");
    write("  "+implode(attack, ", "));
    write("%^MAGENTA%^%^BOLD%^Defense:");
    write("  "+implode(defense, ", "));
    write("%^BLUE%^Faith:%^RESET%^");
    write("  "+implode(faith, ", "));
    write("%^GREEN%^%^BOLD%^Healing:%^RESET%^");
    write("  "+implode(healing, ", "));
    write("%^YELLOW%^Conjuring:%^RESET%^");
    write("  "+implode(conjuring, ", "));
    write("%^CYAN%^%^BOLD%^Other:%^RESET%^");
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
Syntax: spells
Effect: lists spells you know.
See also: score
EndText
  );
  return 1;
}

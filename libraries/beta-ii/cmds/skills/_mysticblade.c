// Seeker,, Paladin spell 
#include <daemons.h>
#include "move.h"
inherit DAEMON;
int spell();
string type() { return "faith"; }
string *weapons = ({
"%^MAGENTA%^A %^BOLD%^%^BLACK%^m%^MAGENTA%^y%^RESET%^%^MAGENTA%^s%^BOLD%^"
"%^BLACK%^t%^MAGENTA%^i%^RESET%^%^MAGENTA%^c %^BOLD%^%^BLACK%^b%^MAGENTA%^"
"l%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^d%^MAGENTA%^e%^RESET%^",
"%^BOLD%^%^CYAN%^A%^WHITE%^n %^BLUE%^i%^CYAN%^c%^WHITE%^e %^CYAN%^b"
"%^WHITE%^l%^BLUE%^a%^CYAN%^d%^WHITE%^e%^RESET%^",
"%^YELLOW%^T%^RESET%^%^ORANGE%^h%^RED%^%^BOLD%^e %^RESET%^%^YELLOW%^d"
"%^RESET%^%^ORANGE%^e%^BOLD%^%^RED%^m%^RESET%^%^YELLOW%^o%^RESET%^%^ORANGE%^n"
"%^BOLD%^%^RED%^ s%^RESET%^%^YELLOW%^l%^RESET%^%^ORANGE%^a%^BOLD%^%^RED%^y"
"%^RESET%^%^YELLOW%^e%^RESET%^%^ORANGE%^r%^RESET%^",
"%^GREEN%^T%^BOLD%^h%^RESET%^%^GREEN%^e %^BOLD%^s%^RESET%^%^GREEN%^o"
"%^BOLD%^u%^RESET%^%^GREEN%^l%^RESET%^-%^GREEN%^%^BOLD%^s%^RESET%^%^GREEN%^e%^BOLD%^e"
"%^RESET%^%^GREEN%^k%^BOLD%^e%^RESET%^%^GREEN%^r %^BOLD%^b%^RESET%^"
"%^GREEN%^l%^BOLD%^a%^RESET%^%^GREEN%^d%^BOLD%^e%^RESET%^",
"%^WHITE%^T%^BOLD%^h%^RESET%^e %^BOLD%^h%^RESET%^o%^BOLD%^l%^RESET%^y"
"%^BOLD%^ a%^RESET%^v%^BOLD%^e%^RESET%^n%^BOLD%^g%^RESET%^e%^BOLD%^r "
"%^RESET%^s%^BOLD%^w%^RESET%^o%^BOLD%^r%^RESET%^d"
});
void do_sword(string st)
{ 
 string *ids;
 object wep;
 int i, b;
 ids = ({});
 if (this_player()->query_skill("faith") < random(100))
   {
    write("The gods did not answer your request.");
    return;
   }
 i = this_player()->query_skill("faith")/30;
 i += random(i)+15;
 wep = new("/d/nopk/standard/obj/magic/mysticblade.c");
 wep->set_name("mystic blade");
if (i < 17) b = 0; else
if (i < 20) b = 1; else
if (i < 23) b = 2; else
if (i < 26) b = 3; else
if (i < 29) b = 4; else b = 4;
if (i > 32) b = 5;
if (b < 5)
 wep->set_short(weapons[b]);
if (b == 5)
 wep->set_short(weapons[4] + " (glowing)");
 wep->set_long("A sword that has been made by the paladin gods.");
 wep->set_mass(random(3));
 wep->set_type("blade");
 wep->set_wc((b*2)+ random(3)+ random(3)+ 3);
 wep->set_value(0);
 wep->set_property("no steal", 1);
 ids += ({ st, "blade" });
if (b == 0) ids += ({ "mystic blade", "mysticblade", "mystic", "sword" });
if (b == 1) ids += ({ "ice blade", "iceblade", "ice", "sword" });
if (b == 2) ids += ({ "fire blade", "fireblade", "fire", "sword" });
if (b == 3) ids += ({ "soulseeker", "soul seeker", "soul", "sword" });
if (b == 4||
    b == 5) ids += ({ "holy avenger", "holyavenger", "avenger", "sword" });
 wep->set_id( ids );
 if (wep->move(this_player()) == MOVE_NO_ROOM)
   {
    write("The gods reject your prayer for you cannot carry the sword they offered.");
    return;
   }
 write("%^BLUE%^%^BOLD%^The gods have answered your prayer.");
say( "%^YELLOW%^The room fills with a bright light as a sword forms in "+this_player()->query_cap_name()+"'s hand.");
 this_player()->force_me("wield "+st);
 
}
int cmd_mysticblade(string str)
{
 object *objec;
 string st;
 int i, a;
 string *warm, *arms;
 if (!spell())
   return notify_fail("What?\n");
 if (this_player()->query_skill("faith") < 20)
   return notify_fail("You do not have enough faith in your god.\n");
 arms = this_player()->query_wielding_limbs();
 warm = this_player()->query_limbs_wielded();
 arms -= warm;
 a = sizeof(arms);
 if (!a)
   return notify_fail("You cannot pray with no free hands.\n");
 if (this_player()->query_mp() < 200 )
   return  notify_fail("You lack the magicial strength to pray to the gods.\n");
 write("%^CYAN%^You pray to the gods for a sword.%^RESET%^");
 this_player()->add_mp(-random(200));
 say( this_player()->query_cap_name() + " mutters a few words and raises "+this_player()->query_possessive()+" hands to the air.");
 st = this_player()->query_name()+"_mysticblade";
 objec = filter(objects(), (: $1->is_weapon() :));
 i = sizeof(objec);
 while(i--) { 
   if (clonep(objec[i])) 
     if (objec[i]->id(st))
   return notify_fail("The gods have already answered your request.\n");
}
 call_out("do_sword", 5, st);
 this_player()->set_paralyzed(5, "You are busy praying to the gods.");
 return 1;
}
int spell()
{
 if (this_player()->query_subclass()!="paladin")
   return 0;
 if (this_player()->query_level() < 10)
   return 0;
 return 1;
}
 
void help()
{
 write("Syntax: <mysticblade>\n\n"
"This spell is used by paladins, where they pray to their god for a sword "
"and hopefully will get their prayer answered. This skill depends on their "
"faith in their god on how good the weapon is.");
}

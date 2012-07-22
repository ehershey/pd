#include <std.h>
#include <daemons.h>
inherit DAEMON;
#define GS(s) (this_player()->query_skill(s))
#define MAX(s) ((this_player()->query_max_skill(s)*this_player()->query_level())/2)
#define tp this_player()
string skill_type(string str) {
string
 *attack = ({ "attack", "melee", "defense"}),
 *weapons = ({ "breath", "claw", "tail" }),
 *magic = ({ "faith", "healing", "conjuring", "magic attack", "magic defense",
            "wizardry", "nature"}),
 *other = ({ "flying", "bargaining", "perception" });
 if (member_array(str, attack)!=-1) return "attack";
 if (member_array(str, weapons)!=-1) return "weapon";
 if (member_array(str, magic)!=-1) return "magic";
 if (member_array(str, other)!=-1) return "other";
 return "other";
}
int magic_class()
{
 if (tp->query_subclass()=="red") return 0;
 return 1;
}
string gtk(string skill)
{
  int a, po, maxs, sk;
  string tmp;
  if (!skill || skill=="") return "";
  a =(int)SKILLS_D->training_formula(this_player()->query_class(),
    this_player()->query_subclass(),
    this_player()->query_base_skill(skill),skill);
 po = this_player()->query_skill_points(skill);
 if (a) a = percent(po, a);
 if (!a) a = 0;
 if (a < 0 ) { this_player()->clean_skill_points(skill); a = 0; }
 if (a > 99) a = 99;
 sk = this_player()->query_base_skill(skill);
 maxs =this_player()->query_max_skill(skill)*(this_player()->query_level())/2;
 if (sk>=maxs)
   {
   tmp = "(MAX)";
   } else
 tmp = "("+a+"%)";
 return tmp;
}
string *put_skills(mapping skills, string type)
{
 int i;
 string *outp=({});
 string *key;
 if (!(i = sizeof(key = keys(skills)))) return ({});
 while(i--) {
  if (skill_type(key[i])==type) outp += ({  key[i] });
  }
 return outp;
}
string to_string(int d) { return sprintf("%d", d); }
int dskills(string str)
{
 mapping skills;
// string *attack, *magic, *deception, *other, *weapon;
  string *attack, *magic, *other, *weapon;
 string seeker;
  int i, a;
 if (!(i = sizeof(skills = tp->query_skills()))) return notify_fail("ERROR: "
"skills null, bug this.\n");
 attack    = sort_array(put_skills(skills, "attack"),1);
 magic     = sort_array(put_skills(skills, "magic"),1);
 other     = sort_array(put_skills(skills, "other"),1);
 weapon    = sort_array(put_skills(skills, "weapon"),1);
write("%^BLUE%^=+=+=%^BOLD%^(%^RESET%^ Skills %^BLUE%^%^BOLD%^)"
"%^RESET%^%^BLUE%^+=+="+repeat_string("+=", 29));
write(
"   %^RED%^Attack           %^CYAN%^Points       Max        %^BLUE%^Magic "
    "%^CYAN%^           Points      Max\n"
"%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
);
 if (sizeof(attack) < sizeof(magic))
   a = sizeof(magic); else a = sizeof(attack);
for(i=0; i < a; i++)
{
  seeker = "";
  if (i <= (sizeof(attack)-1))
    {
     seeker += "   "+capitalize(arrange_string(attack[i], 18));
     seeker += arrange_string(to_string(GS(attack[i])), 5);
     seeker += sprintf("%-7s", gtk(attack[i]));
     seeker += arrange_string(to_string(MAX(attack[i])), 10);
 
    }
  if (!magic_class() && i == 1)
    seeker += "  You do not have magic skills.";
  if (i <= (sizeof(magic)-1))
    {
     if (i > sizeof(attack)-1)
       seeker += arrange_string(" ", 43);
     seeker += " "+capitalize(arrange_string(magic[i], 18));
     seeker += arrange_string(to_string(GS(magic[i])), 4);
     seeker += sprintf("%-6s", gtk(magic[i]));
     seeker += sprintf("%s", to_string(MAX(magic[i])));
    }
  write(seeker);
 }
write(
"%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
"\n   %^GREEN%^Other            %^CYAN%^Points       Max        %^MAGENTA%^Weapons    "     
"%^CYAN%^      Points      Max\n"
"%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
);
 if (sizeof(other) < sizeof(weapon))
   a = sizeof(weapon); else a = sizeof(other);
for(i=0; i < a; i++)
{
  seeker = "";
  if (i <= (sizeof(other)-1))
    {
     seeker += "   "+capitalize(arrange_string(other[i], 18));
     seeker += arrange_string(to_string(GS(other[i])), 5);
     seeker += sprintf("%-7s", gtk(other[i]));
     seeker += arrange_string(to_string(MAX(other[i])), 10);
    }
  if (!sizeof(weapon) && i == 1)
    seeker += "  You do not have other skills.";
  if (i <= (sizeof(weapon)-1))
    {
     if (sizeof(other)-1 < i)
     seeker += repeat_string(" ", 43);
     seeker += " "+capitalize(arrange_string(weapon[i], 18));
     seeker += arrange_string(to_string(GS(weapon[i])), 4);
     seeker += sprintf("%-6s", gtk(weapon[i]));
     seeker += sprintf("%s", to_string(MAX(weapon[i])));
    }
 write(seeker);
}
return 1;
}
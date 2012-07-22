// Originally by Seeker
// Changed to inheritable by Nightshade 
#include <teststd.h>
#include <locations.h>

inherit OBJECT;

string _YourRubMessage, _TColor, _TFirst, _TLast, _HealMessage, _Action;
string _FColor, _FFirst, _FLast;
int Uses, Heals;

void set_uses(int i);

void create()
{
 ::create();
 _TColor = "";
 _FColor = "";
 set_uses(1);
}

int set_id(string *str) {
  str += ({"oilcheck"});
  return ::set_id(str);
}

void set_uses(int i) {
  if(i > 15)
    Uses = 15;
  else if(i < 1)
    Uses = 1;
  else
    Uses = i;
  Heals = Uses;
}

string query_short() {
  string str;

  str = ::query_short();
  str += " %^RESET%^(";
  switch(Uses) {
     case 0: str += "one"; break;
      case 1: str += "one"; break;
      case 2: str += "two"; break;
      case 3: str += "three"; break;
      case 4: str += "four"; break;
      case 5: str += "five"; break;
      case 6: str += "six"; break;
      case 7: str += "seven"; break;
      case 8: str += "eight"; break;
      case 9: str += "nine"; break;
      case 10: str += "ten"; break;
      case 11: str += "eleven"; break;
      case 12: str += "twelve"; break;
      case 13: str += "thirteen"; break;
      case 14: str += "fourteen"; break;
      case 15: str += "fifteen"; break;
      case 16: str += "sixteen"; break;
      case 17: str += "seventeen"; break;
      case 18: str += "eighteen"; break;
      case 19: str += "nineteen"; break;
      case 20: str += "twenty"; break;
  }
  if(Uses > 1)
    str += " uses left)";
  else
    str += " use left)";
  return str;
}

void init()
{
 ::init();
 add_action("fApply", _Action);
}

void set_your_mess(string str) { _YourRubMessage = str; }

varargs void set_their_mess(string str1, string str2, string str3) {
  _TColor = str1;
  _TFirst = str2;
  _TLast = str3;
}

void set_their_heal(string str1, string str2) {
  _FColor = str1;
  _FFirst = str2;
}

void set_heal_mess(string str) { _HealMessage = str; }

void set_action(string str) { _Action = str; }

int fApply(string str)
{
    if(this_object() != present(this_object()->query_id()[0], this_player()))
        return 0;
 if (!str || (!(member_array(str, this_object()->query_id())+1)) )
   {
    notify_fail(capitalize(_Action)+" what?\n");
    return 0;
   }
 if (this_player()->query_paralyzed())
   return notify_fail(this_player()->query_paralyze_message());

 if (this_player()->query_disable() || this_player()->query_magic_round() || this_player()->query_casting())
   {
    write("You are too busy doing something else.");
    return 1;
   }
 this_player()->set_disable();
 write(_YourRubMessage);
 if(_TLast && _TLast != "")
   say(_TColor+this_player()->query_cap_name()+_TFirst+this_player()->query_title_gender()+_TLast);
 else
   say(_TColor+this_player()->query_cap_name()+_TFirst);
 call_out("do_oil", 6, this_player() );
 Uses--;
 if(Uses == 0)
   this_object()->move(TEMP_LOC);
 return 1;
}

int do_oil(object ob)
{
 int i;
 string *st;
  if (!ob) return 0;
 ob->add_hp(110 + random(200) );
 ob->add_sp(50 + random(50) + random(50) + random(50));
 st = ob->query_limbs();
 i = sizeof(st);
 while(i--)
 ob->heal_limb(st[i], random(25)+25 );
 if(_FFirst)
   say( _FColor+this_player()->query_cap_name()+_FFirst);
 message("info", _HealMessage, ob);
 Heals--;
 if(Heals <= 0)
   this_object()->remove();
 return 1;
}

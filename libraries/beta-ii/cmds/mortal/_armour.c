#include <std.h>
#include <daemons.h>

inherit DAEMON;
#define RE "%^RESET%^"
#define BL "%^BOLD%^%^BLUE%^"
#define MA "%^BOLD%^%^MAGENTA%^"
string get_desc(int i) {
 if(i<1) return "%^RESET%^%^CYAN%^Unprotected";
 if(i<3) return "%^RESET%^%^CYAN%^Hardly covered";
 if(i<6) return "%^RESET%^%^CYAN%^Lightly covered";
 if(i<9) return "%^RESET%^%^CYAN%^Hardly protected";
 if(i<12) return "%^RESET%^%^CYAN%^Lightly protected";
 if(i<15) return "%^RESET%^%^CYAN%^Hardly armoured";
 if(i<18) return "%^RESET%^%^CYAN%^Lightly armoured";
 if(i<21) return "%^RESET%^%^CYAN%^Armoured";
 if(i<24) return "%^RESET%^%^CYAN%^Well armoured";
 if(i<27) return "%^RESET%^%^CYAN%^Very well armoured";
 return "%^RESET%^%^CYAN%^Fully armoured";
}
string qcp(string str) { return get_desc(this_player()->query_current_protection(str));}
void display_centaur()
{
 string tmp;

tmp  = "%^ORANGE%^     _ \n" 
"%^ORANGE%^    / \\ %^RESET%^\n"
"%^ORANGE%^    \\_/ %^RESET%^               "+BL+"<--["+MA+"Head"+BL+"]--------- "+qcp("head")+RE+"\n" 
"%^ORANGE%^    _|_ %^RESET%^\n"
"%^ORANGE%^   /| |\\ %^RESET%^              "+BL+"<--["+MA+"Arms"+BL+"]--------- "+qcp("arms")+RE+"\n"
"%^ORANGE%^  / | | \\ %^RESET%^             "+BL+"<--["+MA+"Torso"+BL+"]-------- "+qcp("torso")+RE+"\n"
"%^ORANGE%^ M  | |--M------\\\\ %^RESET%^    "+BL+"<--["+MA+"Hands"+BL+"]-------- "+qcp("hands")+RE+"\n"
"%^ORANGE%^    |-|         | | %^RESET%^   "+BL+"<--["+MA+"Horse Torso"+BL+"]-- "+qcp("horse torso")+RE+"\n"
"%^ORANGE%^    | |_______| | | %^RESET%^   "+BL+"<--["+MA+"Tail"+BL+"]--------- "+qcp("tail")+RE+"\n"
"%^ORANGE%^    | |       | | | %^RESET%^   "+BL+"<--["+MA+"Fore Legs"+BL+"]---- "+qcp("fore legs")+RE+"\n"
"%^ORANGE%^    | |       | | %^RESET%^     "+BL+"<--["+MA+"Rear Legs"+BL+"]---- "+qcp("rear legs")+RE+"\n"
"%^ORANGE%^   - -       - -%^RESET%^       "+BL+"<--["+MA+"Hooves"+BL+"]------- "+qcp("hooves")+RE+"\n";
 message("info", tmp, this_player());

}
int cmd_armour(string str)
{
 string *st, seeker, tmp;

 int i;
 if (!i = sizeof(st = this_player()->query_limbs()))
   return notify_fail("You dont have any limbs!\n");
 
  write("%^BLUE%^=+=+=%^BOLD%^(%^WHITE%^ Armour %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
while(i--) {
 if (i<0) continue;
 if (this_player()->query_magic_protection(st[i]))
   tmp = "%^YELLOW%^";
   else tmp = "";
seeker = arrange_string(tmp+capitalize(st[i]), 15)+"%^RESET%^"+arrange_string(": "+ qcp(st[i]), 20);
if (i>0)
  {
   if (this_player()->query_magic_protection(st[i-1]))
     tmp = "%^YELLOW%^";
     else tmp = "";
   seeker += "%^RESET%^"+tmp+arrange_string(capitalize(st[i-1])+"%^RESET%^", 15)+arrange_string(": "+ qcp(st[i-1]), 20);
   i--;
  }
write(seeker);
}
//if ("/cmds/skills/_mudarmor"->query_mudded(this_player()))
//  write("%^ORANGE%^ ** The mud on you creates a strong layer of protection. **");
  write("%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
 return 1;
}

void help()
{
 write("Command: armour\n\nThis is a function to tell you which part of "
       "your body is protected well and what is not protected very well. "
       "The bodypart will glow in yellow if it is protected by magic.");
 write("The rule of the armour description is that covered is "
       "less armoured than protected, and protected is less "
       "armoured than armoured. Similarly, Hardly is less than "
       "lightly, which is less than well, which is less than very well.");
}

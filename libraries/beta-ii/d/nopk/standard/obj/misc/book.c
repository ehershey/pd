// Seeker - newbie book

#include <std.h>

inherit OBJECT;

static void create()
{
 set_name("book");
 set_short("the %^RED%^%^BOLD%^newbie's %^BLUE%^book");
 set_long("This book can be used to help you on your way around our main "
          "town Sindarii. To start off type %^CYAN%^%^BOLD%^<%^BLUE%^read%^CYAN%^>%^RESET%^ to read the book");
 set_id( ({ "book", "newbie book", "a newbies book" }) );
 set_mass(1);
 set_value(1);
}

void init()
{
 ::init();
 add_action("read", "read");
}

int read(string str)
{
 
 if (!str || (str!="newbie" && str!="weapons" && str!="armour" && str!="class"))
   {
    message("info", 
"%^CYAN%^%^BOLD%^[%^BLUE%^ Table of Contents %^CYAN%^]%^RESET%^\n"
" %^CYAN%^<%^BLUE%^read newbie%^CYAN%^>%^RESET%^  this will give you tips on howto survive being a newbie\n"
" %^CYAN%^<%^BLUE%^read weapons%^CYAN%^>%^RESET%^ this will show you howto wield weapons to use in combat\n"
" %^CYAN%^<%^BLUE%^read armour%^CYAN%^>%^RESET%^  this will show you howto wear armour to protect you\n"
" %^CYAN%^<%^BLUE%^read class%^CYAN%^>%^RESET%^   this will give you information on picking a class\n",
this_player());
   }
 if (str=="newbie")
   {
    message("info",
"%^CYAN%^%^BOLD%^[%^BLUE%^ Being a newbie %^CYAN%^]%^RESET%^\n"
"	Being a newbie on a mud you have never seen before could be rather\n "
"difficult. Or if your new to mudding it could be extremely difficult to "
"learn. But over time you will get the hang of playing muds and they will "
"be easy for you to understand. %^GREEN%^%^BOLD%^Here are some tips to get started:%^RESET%^\n"
"         %^GREEN%^North,South,East,West,Up,Down %^RESET%^are the directions you can walk "
"in. There is a green message telling you what directions you "
"can walk in.\n\n"
"         %^RED%^Hit points, %^CYAN%^Stamina Points, %^MAGENTA%^Magic Points%^RESET%^ are your vital points\n "
"         that you need to watch very closely. %^RED%^Hit points%^RESET%^ determines what\n "
"         condition your body is, being if full your in top shape, if your\n "
"         at low hp and go below 0 you will %^RED%^%^BOLD%^die%^RESET%^ and suffer the consequences\n "
"         of death. %^CYAN%^Stamina points%^RESET%^ determines your endurance while in combat\n "
"         and while walking. %^MAGENTA%^Magic Points%^RESET%^ are needed to cast magicial spells.\n"
"          You can check on your vitals by typing "
"%^CYAN%^%^BOLD%^<%^BLUE%^hp%^CYAN%^>%^RESET%^. Type %^CYAN%^%^BOLD%^<%^BLUE%^hpinfo%^CYAN%^>%^RESET%^ for a\n"
"          vital status prompt.\n\n"
"         There is %^BLUE%^an old well%^RESET%^ that seems to heal newbies who drink from it "
"at Sindarii square. Drink from it when you are at low %^RED%^hit points, %^CYAN%^stamina points,\n"
"or %^MAGENTA%^magic points.%^RESET%^\n\n"
"	If your ever in trouble or get lost type %^CYAN%^%^BOLD%^<%^BLUE%^recall%^CYAN%^>%^RESET%^ and "
"that will take you directly back to Sindarii square if your level 1. For "
"some more information type %^CYAN%^%^BOLD%^<%^BLUE%^"
"faq%^CYAN%^>%^RESET%^ for information on being a newbie. ",this_player());
   }
if (str=="armour")
  {
   message("info", 
"%^CYAN%^%^BOLD%^[%^BLUE%^ Wearing Armour %^CYAN%^]%^RESET%^\n"
"	Armour is what you put on your body to absorb damage while you "
"are in\n combat. As a newbie you automatically get armour to start out with. "
"You get a helmet, gloves, boots, and body armour.\n\n"
"       %^CYAN%^%^BOLD%^<%^BLUE%^wear%^CYAN%^>%^RESET%^ - this is the command you will use to wear all your armour,\n "
"                whether it is rings, hats or etc. You use it by typing \n"
"                %^CYAN%^%^BOLD%^<%^BLUE%^wear %^GREEN%^[%^BLACK%^armour name%^GREEN%^]%^CYAN%^>%^RESET%^, or to wear everything type %^CYAN%^%^BOLD%^<%^BLUE%^wear all%^CYAN%^>%^RESET%^.\n"
"       ex: %^CYAN%^%^BOLD%^<%^BLUE%^wear helmet%^CYAN%^>%^RESET%^, %^CYAN%^%^BOLD%^<%^BLUE%^wear gloves%^CYAN%^>%^RESET%^, %^CYAN%^%^BOLD%^<%^BLUE%^wear boots%^CYAN%^>%^RESET%^, %^CYAN%^%^BOLD%^<%^BLUE%^wear armour%^CYAN%^>%^RESET%^\n\n"
"      %^CYAN%^%^BOLD%^<%^BLUE%^armour%^CYAN%^>%^RESET%^ - this command tells you the level your body is armoured.\n"
"                 Whether your %^BLUE%^%^BOLD%^not covered%^RESET%^ on a certain body part or your\n"
"                 %^CYAN%^fully armoured%^RESET%^.\n\n"
"    * You can see what you are carrying/wearing/wielding by using %^CYAN%^%^BOLD%^<%^BLUE%^inventory%^CYAN%^>%^RESET%^.",
this_player());
  }

 return 1;
}

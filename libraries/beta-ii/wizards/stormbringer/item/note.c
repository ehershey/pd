#include <std.h>
inherit OBJECT;
void create()
{
 ::create();
 set_name("note");
 set_short("a note");
 set_long("A note, you should read it.");
 set_id( ({ "note" }) );
 set_weight(1);
}
void init()
{
 ::init();
 add_action("fRead", "read");
}
int fRead(string str) {
    write( @EndText
  ___________  _______________________________________
 /\          \|                                       \ 
|:::\::;,,..          %^BOLD%^%^RED%^_        _______%^RESET%^            .,;::\ 
|::::\::;,,..        %^BOLD%^%^RED%^( (    /|(  ___  )%^RESET%^            ,,;::\ 
 \::::\::;,,,,,,     %^BOLD%^%^RED%^|  \  ( || (   ) |%^RESET%^            ..,;::\ 
   ``` \::;,,,...    %^BOLD%^%^RED%^|   \ | || |   | |%^RESET%^            ..,,;::\ 
       |::;,,,,.     %^BOLD%^%^RED%^| (\ \) || |   | |%^RESET%^              ,,;::| 
      /::;,,...      %^BOLD%^%^RED%^| | \   || |   | |%^RESET%^           ..,,;::/ 
     /::;,,..        %^BOLD%^%^RED%^| )  \  || (___) |%^RESET%^          ..,,;::/ 
    /::;,,..         %^BOLD%^%^RED%^|/    )_)(_______)%^RESET%^         ..,,;::/ 
   |::;,,..  %^BOLD%^%^RED%^         _______  _______  _______%^RESET%^ .,,;::| 
    \::;,,..%^BOLD%^%^RED%^|\     /|(  ___  )(  ____ )(  ____ \%^RESET%^..,,;::\ 
     \::;,,.%^BOLD%^%^RED%^| )   ( || (   ) || (    )|| (    \/%^RESET%^ ..,,;::\ 
      \::;,,%^BOLD%^%^RED%^| (___) || |   | || (____)|| (__ %^RESET%^     ..,,;::\ 
       \::;,%^BOLD%^%^RED%^|  ___  || |   | ||  _____)|  __) %^RESET%^      .,,;::\ 
        \::;%^BOLD%^%^RED%^| (   ) || |   | || (      | (   %^RESET%^        .,,;::\ 
    _____\::%^BOLD%^%^RED%^| )   ( || (___) || )      | (____/\ %^RESET%^     ..;;::\ 
   /::::::\:%^BOLD%^%^RED%^|/     \|(_______)|/       (_______/%^RESET%^      ..;;::\ 
  l:::::::l::;..                                      .....;::l 
  l:::::::/::;;..                                      ..;;::/ 
   \:::::/::;;,...                                      ;;::/ 
    \::/::;;,.......                                ..,;;::/ 
     \/_____________________________________/|____________/ 
EndText );
return 1;
}

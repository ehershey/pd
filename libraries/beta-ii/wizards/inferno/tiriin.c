#include <std.h>
inherit MONSTER;

static int sing = 1337;
string query_gender();
string query_race();
/*
string query_gender() { if (this_player()) return this_player()->query_gender();
                        else return "male"; }

string query_race() { if (this_player()) return this_player()->query_race();
                      else return "human"; }
*/
void create() {
 ::create();
   set_name("tiriin");
   set_short("Tiriin");
   set_long("Tiriin looks like a strange mixture of everybody you have ever met. "
     "You feel an urge to <ask tiriin to "
     "sing>. You feel there is a message for you there.");
   set_level(100);
   set_heart_beat(1);
   set_body_type("human");
   set_gender("neuter");
   set_race("human");
}

int ask(string str) {
   if (!str || str != "tiriin to sing") return 0;
   if (sing < 1337) return notify_fail("Tiriin is already singing!");
   sing = 1;
   write("Tiriin begins to sing.");
   return 1;
}

void init() {
 ::init();
   add_action("ask", "ask");
}

void heart_beat() {
 ::heart_beat();
   if (sing >= 1337) return;
   switch (sing) {
     case 1:
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ Don't you wish you had it all",
       this_object());
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ Don't you deserve to have it all",
       this_object());
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ Kneel down and tell me what you need",
       this_object());
     break;
     case 4:
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ Fame and money all for you",
       this_object());
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ I can make your every dream come true",
       this_object());
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ Tell me whose more important than you",
       this_object());
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ You're the apple of my ancient eyes",
       this_object());
     case 7:
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ How could the world be so cruel?",
       this_object());
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ I'll make you my own precious jewel",
       this_object());
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ I'm on your side",
       this_object());
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ Sincerely",
       this_object());
     break;
     case 10:
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ I'm the only one that cares",
       this_object());
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ Yes, I'm on your side",
       this_object());
     break;
     case 13:
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ There is one thing;",
       this_object());
     break;
     case 16:
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ I mean everything has a price..",
       this_object());
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ I really hate to repeat myself,",
       this_object());
     say("%^RESET%^%^CYAN%^Tiriin sings:%^RESET%^ But nothing's free.",
       this_object());
     break;
     case 18:
     force_me("emote trails off.");
     break;
   }
   sing++;
   if (sing >= 19) sing = 1337;

}

#include <std.h>
inherit MONSTER;

static int num=4;

int die_sigma();

void create() {
 ::create();
   set_name("sigma");
   set_short("Sigma, mud mascot");
   set_moving(1);
   set_speed(3);
  if (random(10) >= 5)
   set_long("
                                 .
                              .  !\\  _
                              l\\/ ( /(_
                             _ \\\\`--\" _/ .
                             \\\\~\")   (_,/)
                             _)/.   ,\\\\,/
                    _____,-\"~    \\ /   \"~\"-._____
                ,-~\"     \"~-.  .  \"  .  ,-~\"     \"~-.\n"
"              ,^             ^. `. .' ,^             ^.
             /                 \\  ^  /                 \\
            Y___________________Y   Y___________________Y
            I I^~\"I^   _ ^l\"~^l I   I l\"~\"l^ _   ^l\"~\"l l
            l !   l   (_) !   ! l   l !   ! (_)   !   ! I
            l  \\  `\\.___,/'  /  !   l  \\  `\\.___,/'  /  !
             \\  ^.         ,^  /!   !\\  ^.         ,^  /
              ^.  ~-------~  ,^\\`v-v'/^.  ~-------~  ,^
              _)~-._______,-~   }---{   ~-._______,-~(_\n"
"         .--\"~           ,-^7' /     \\ `Y^-,           ~\"--.
        /               (_,/ ,/'     `\\. \\._)    ___        \\
        \\_____.,--\"~~~\"--..,__        ___,..--<\"~   ~\"-.,___/
            / (    __,--~ _.._\"\"~~~~\"\" ,-\"  \"-.`\\     /~.-\"
            `._\"--~_,.--\"~    \\       /        \\ `---' /\n"
"               \"~\"\"            \\     /          \"-.__,/
                               `L   ]'
                                l   !
                                j___L
                               (_____)
                                I   I
                              -(Sigma)-
");
 else
   set_long(@ENDTEXT
                       \//
                    __.---;_
                  .'  './/'0)',\
                  |o)  |     | ';
                  :'--; \.__//'   ;
                   ;.' (         |
              __.-'   _.)        |
        ---==/"=----'''           |
                 ;^;         .  ^+^^;
               ;^  :         :       ^;
                \  {          :_     //
                 ^'-;          :'--'^
                    /",,____,,-'
                 __   _______   ______
       ============(((=======(((============
ENDTEXT
);
   set_level(2);
   set_race("mascot");
   set_body_type("fowl");
   set_invis();
   set_id(({ "bird", "mascot", "dodo", "sigma" }));
   set_max_hp(90000);
   set_hp(88000);
   set_die( (: die_sigma() :) );
}
int die_sigma()
{
  string a;
  mixed ob;
  message("other_action", query_cap_name()+" drops dead before you",
environment(this_object()),({ this_object() }));
  message("info", "Silence overcomes the realm as Sigma dies.\n",users());
/*

  new("/d/standard/obj/mon/mom")->move(environment(this_object()));
  present("mom",
environment(this_object()))->set_killer(this_object()->query_last_attacker());
  message("info", "Sigmas mom runs in to see whats wrong.",
environment(this_object()));  
  message("info", "Sigmas mom looks over the corpse of Sigma",
environment(this_object()));
*/
  return 1;
}

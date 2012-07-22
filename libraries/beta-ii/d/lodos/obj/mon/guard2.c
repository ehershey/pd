#include <std.h>
#include <lodos.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("guard");
   set_short("a strong guard");
   set_gender("male");
   set_long(@ENDTEXT
                  /|
   _______________)|..
 <'______________<(,_|)
            .((()))| ))
            (======)| \
           ((( "."()|_ \
          '())) -`/_/ ' )
          .--/_\ /(  /./
         /'._.--\ .-(_/
        / / )\___:___)
       ( -.'.._  |  /
        \  \_\ ( | )
         '. /\)_(_)|
           '-|  XX |
            %%%%%%%%
           / %%%%%%%\
          ( /.-'%%%. \
         /(.'   %%\ :|
        / ,|    %  ) )
      _|___)   %  (__|_
      )___/       )___(
       |x/      mrf\ >
       |x)         / '.
       |x\       _(____''.__
     --\ -\--
      --\__|--
ENDTEXT);
   set_level(24);
   set_race("human");
   set_body_type("human");
   set_id(({ "guard", "strong guard" }));
   make(WEA"bsword");
   command("wield sword");
}

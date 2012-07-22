#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("me");
   set_id(({ "cat", "garfield", "impatient cat" }));
   set_name("cat");
   set_level(21);
   set_long(@PARADOX
                   .-=. ___
           .    .-;-%%i:-%%,
           ==. / /,.-.;--:/ _,
          '"-\j  /    \   \====
            ,%% i      |   %.
           ,;"""t_____ |__,|".
           i%%.  \+ `'"f`','%|
           |;"  .-`.__.O-< "`;
           `%+  (_,+--'"\_)%/
            `.%% %"     ._%/
             __+.,-.    ' %.
           ,( j-"". `.  ,%%|
         .'-;`. )  )-'  "" :.
         (  [ `-'`-' .  ,.%%i
          `-\.__ ..-"    ""`]
            t.  "       ..%%f
             \,         ."";
              >. ,-.    ,_%
             ,' i  t/  f:%
             ( `'   t ,' j
              `.. `. \;  %+.--.
        ,--.._  `.  `.t,  % -=%%
       j ,    "`-|   ) +"\. -=%/
       (( f      t  "t" ) J..-"
        \_\  ,.__.\.  ).-"
           ""      "-"     LS
PARADOX);
   set_body_type("quadrupe");
   set_race("cat");
   set_gender("male");
}

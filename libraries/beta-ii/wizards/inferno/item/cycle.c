#include <std.h>
inherit "/std/obmount.c";
static object owner;
void create() {
 ::create();
   set_name("motorcycle");
   set_short("%^RESET%^%^RED%^a "
     "%^ORANGE%^m%^RED%^o%^ORANGE%^t%^RED%^o%^ORANGE%^r%^RED%^c%^ORANGE%^y%^RED%^c%^ORANGE%^l%^RED%^e"
   "%^YELLOW%^");
   set_long(@END
.___        _____                           
|   | _____/ ____\___________  ____   ____  
|   |/    \   __\/ __ \_  __ \/    \ /  _ \ 
|   |   |  \  | \  ___/|  | \/   |  (  <_> )
|___|___|  /__|  \___  >__|  |___|  /\____/ 
         \/          \/           \/        
END);
   set_weight(3000);
   set_id(({"cycle", "motorcycle"}));
   set_value(0);
   set_prevent_get("You can't take that!");
   set_heart_beat(1);
}

#include <std.h>
#include <aciri.h>
inherit MONSTER;
 
void create() {
::create();
    set_name("guardian");
    set_short("Acirian Guardian");
    set_long("The Acirian Guardian is extremely powerful.  He is "
         "very skilled and trusted with protecting the fortress. ");
    set("aggressive", 50);
    set_id(({"guardian","acirian guardian"}));
    set_level(45);
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_heart_beat(1);                   
 

new(ARM "rockplatemail.c")->move(this_object());
    command("wear all");

}





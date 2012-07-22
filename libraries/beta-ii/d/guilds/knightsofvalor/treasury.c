#include <std.h>
#include <guild.h>
#include <daemons.h>

inherit TREASURY;

void create() {
    ::create();   
    set_properties( (["light" : 2, "indoors" : 1, "no attack" : 1,
        "no magic" : 1, "no steal" : 1, "no bump" : 1]) );
    set_guild("knightsofvalor");
    set_name("Knights of Valor");
    set_short("Knights of Valor Treasury");
    set_long("This small room under the main meeting hall is used for fundraising purposes.  The Knights of Valor may come here to donate their coins to be used to benefit the greater good of Primal Darkness.");  
    set_smell("default", "A metallic smell from coins flows through the air.");
    set_listen("default", "Clanking coins being counted by treasurers can be heard.");  
set_exits(([
"up" : "/d/guilds/knightsofvalor/hall.c",
 "down" : "/d/guilds/knightsofvalor/storage.c"
 ]));

}

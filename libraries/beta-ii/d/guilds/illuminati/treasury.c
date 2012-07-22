//  Coded by Whit
//  Treasury for guilds
#include <std.h>
#include <guild.h>
#include <daemons.h>

inherit TREASURY;

void create() {
    ::create();   
    set_properties( (["light" : 2, "indoors" : 1, "no attack" : 1,
        "no magic" : 1, "no steal" : 1, "no bump" : 1]) );
    set_guild("illuminati");
    set_short("Illuminati Treasury");
    set_long("%^BOLD%^This is Illuminati's Treasury.  Here is where you donate "
      "money to the guild by using <donate amount> - i.e: donate 1 gold.  If you "
      "would like to view all past transactions, use <read scroll>.  This is"
      " just a temporary room til the old treasury is returned.%^RESET%^");  
    set_items( (["room" : "Can't you read the main description? :P"]) );
    set_smell("default", "The soft scent of roses wafts in the air.");
    set_listen("default", "Soft chanting floats in the air, bringing peace "
      "to the room");  
    set_exits( (["north" : "/d/guilds/illuminati/hall.c"]) );

}

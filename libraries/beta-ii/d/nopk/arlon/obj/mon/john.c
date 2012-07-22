#include <std.h>
#include <daemons.h>
#include <arlon.h>
#include <security.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("john");
   set_short("John, the boat master");
   set_level(30);
   set_race("human");
   set_body_type("human");
   set_gender("male");
   set_id(({ "shop keeper", "shopkeeper", "boat master", "john" }));
   set_long( "He is away at work building boats. ");
}

void init()
{
 ::init();
 add_action("buy_boat", "buy");
}
int buy_boat(string str)
{
 string line;

 if (str!="boat")
   {
    write("Buy what?");
    return 1;
   }
 if ( file_size(DIR_BOATS+"/"+this_player()->query_name()+".c") > 0)
   {
    this_object()->force_me("say You can only buy own one boat.");
    return 1;
   }
 if (this_player()->query_money("gold") < 10000)
   {
    this_object()->force_me("say Your too poor to buy a boat.");
    return 1;
   }
 write("You are the owner of a brand new boat.");
 seteuid(UID_BOATSAVE);
 line = read_file("/std/obj/boat.c");
 write_file(DIR_BOATS+"/"+this_player()->query_name()+".c", line);
 seteuid(geteuid());
 this_player()->add_money("gold", -30000);
 return 1;
}

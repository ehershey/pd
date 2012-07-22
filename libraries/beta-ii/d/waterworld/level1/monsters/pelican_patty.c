///// monster file for Tirun Bay
///     by Ironman,

#include <std.h>
#include <waterworld.h>
#include <daemons.h>

inherit MONSTER;

void toss_out(object tp);

void create()
{
    ::create();
    set_name("patty");
    set_id(({"pelican patty","pelican","patty","waitress"}));
    set_short("%^WHITE%^%^BOLD%^Pelican Patty%^RESET%^%^RED%^, the friendly waitress.\n");
    set_long("Pelican Patty is another charter member of the '%^ORANGE%^Screaming Pelicans%^RESET%^' gang. She is frequently at Pelican Pete's waiting on tables and keeping Pete company.");
    set_level(25);
    set_race("pelican");
    set_gender("female");
    set_body_type("bird");
    set_class("fighter");
    set_subclass("warrior");
    set_property("passive", 1);

    new(ARMOR1"apron.c")->move(this_object());
    force_me("wear all");
}
/// Quest routines
///

void catch_tell(string recieved)
{
    string pname;
    recieved = TERMINAL_D->no_colours(recieved);
    if(sscanf(recieved,"%s asks: %*swhale oil%*sPelican Paul%*s",pname) >= 3)
    {
	call_out("response",2,pname);
	return;
    }
}
void response(string pname)
{
    if(!present(pname))
    {
	force_me("tell "+pname+" I'm sorry but we are currently not set up for deliveries. You will need to come here to request an order.");
    }
    else
    {
	force_me("tell "+pname+" We are currently out of stock. If you can locate Manatee Mike, you can get more from his stockpile.");
	force_me("smile "+pname);
    }
}
int is_invincible() {
    object TP=previous_object();
    string cap_TP=TP->query_cap_name();

    message("info","Pelican Patty crashs into YOU!!!\n You are thrown out of the bar!!",TP);
    message("info","Pelican Patty crashs into "+cap_TP+" !!!\n"+cap_TP+" is thrown out of the bar!!\n",environment(TP),TP);
    call_out("toss_out", 0, TP);
    message("info",(TP->query_cap_name())+" falls into the water before you with a big %^BLUE%^%^BOLD%^SPLASH!!!",environment(TP),TP);
    message("info","You fall into the water north of the bar with a big %^BLUE%^%^BOLD%^SPLASH!!!",TP);
    return 1;
}
void toss_out(object tp) { tp->move(ROOMS1"room-1d3"); }

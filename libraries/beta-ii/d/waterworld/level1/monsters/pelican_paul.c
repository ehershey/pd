
/// Monster for Tirun Bay in Waterworld
///     Written by Ironman

#include <std.h>
#include <waterworld.h>
#include <daemons.h>

inherit MONSTER;

object barrels;

void create() 
{
    ::create();
    set_name("Pelican Paul");
    set_id(({"pelican paul","pelican","paul","captain"}));
    set_short("A Stout and Sturdy sea captain");
    set_long("This is 'Pelican' Paul. A human who was adopted years ago into the '%^ORANGE%^Screaming Pelicans%^RESET%^' by Pelican Pete."
      " This stout sea captain has manned this lighthouse for over 70 years!!"
      " He bears the tattoo of the '%^ORANGE%^Screaming Pelicans%^RESET%^' on his right arm."
      " A pipe dangles from his lips with puffs of smoke rising from it."
    );
    set_level(25);
    set_race("human");
    set_body_type("human");
    set_class("clergy");
    set_subclass("cleric");
    set_gender("male");
    set_stats("strength",1000);
    set_property("passive", 1);
    set_emotes(3,({
	"The sea captain stands at the window of the lighthouse peering over the ocean.",
	"Pelican Paul looks inside the barrels and shakes his head sadly.",
	"The ol' sea captain puffs contently on his pipe.",
	"The captain mutters, 'I wonder if i can get someone to listen to me long enough to get me some......'\n\nThe rest is drowned out by the sound of machinery.",
	"Paul peers at the beacon and sighs sadly....."
      }),0);
    new(WEP1"pipe.c")->move(this_object());
    new(ARMOR1"apron.c")->move(this_object());

    force_me("wear all");
    new(ARMOR1"rain_boots.c")->move(this_object());
    new(ARMOR1"raincoat.c")->move(this_object());
    force_me("wield pipe");
    force_me("wear all");
}
/// quest routines
///
void catch_tell(string recieved) {
    string pname;
    if(sscanf(TERMINAL_D->no_colours(recieved),"%s gives you A 'Screaming Pelicans' brand barrel of whale oil",pname)>=1)
    {call_out("quest_completion",2,pname);}
}

void quest_completion(string pname)
{
    object tp;
    if(barrels=present("barrel")) {
	barrels->remove();
	force_me("say Thank you "+pname+" for retrieving the whale oil for me!!");
	tp=present(pname,environment(this_object()));
	new(ARMOR1"sp_signet.c")->move(tp);
	force_me("say This is the Signet ring of our clan, it will increase your vitality while worn.");
	force_me("grin "+pname);
	if(!tp->set_manual_quest("Order of the Screaming Pelicans",2)) return;
    }
}

int is_invincible() {
    object TP;

    TP=previous_object();
    message("info","Pelican Paul slams into you knocking you through an open window!!\n",TP);
    message("info","Pelican Paul slams into "+TP->query_cap_name()+" knocking "+TP->query_objective()+" through an open window!!\n",environment(TP),TP);
    call_out("move_TP",0,TP);
    return 1;
}
void move_TP(object TP) {
     int x=random(100);
    TP->move(ROOMS1"secret-lighthouse.c");
    TP->damage( TP->query_hp() < x ? TP->query_hp()-1 : x ) ;
    message("info","You fall face first onto the landing in front of the lighthouse!!",TP);
    message("info",(TP->query_cap_name())+" falls face first in front of the lighthouse!!",(ROOMS1"secret-lighthouse.c"),TP);
    TP->describe_current_room(1);
}

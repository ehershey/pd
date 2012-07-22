#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit ROOM;

string loc;
string *dests;
string *todests;
string largestring;
string coachout;
string nomoney;
int costbase;
int departed;

void init() 

{
    ::init();
    add_action("coach", "coach");

}

int coach(string str)
{
    int totalcost;
    int i;
    int gold;
    object mob=present("master");
    object transroom=new(GROOM"ctransroom.c");

    if(!str || str == " to" || str == " to " || str == "to" || str == "to " || str == "to" || str == "to" ) { 
	write("coach to where?");
	return 1;
    }
    if(str == "to "+loc)
    {
	mob->force_me("say You're silly! You're already here!");
	return 1;
    }
    if(member_array(str,todests) == -1)
    {
	write("coach to where? The sign will show valid destinations.");
	return 1;
    }
    else
    {
	i = member_array(str,todests);
    }
    if (this_player()->query_level() < 20)
    {
	gold = 200;
    }
    else if (this_player()->query_level() < 50)
    {
	gold = 500;
    }
    else if (this_player()->query_level() > 49)
    {
	gold = 750;
    }

    totalcost = gold;

    if (this_player()->query_money("gold") < totalcost)
    {
	mob->force_me("say "+nomoney);
	return 1;
    }
    else
    {
	if (departed != 1)
	{
	    this_player()->add_money("gold", -totalcost);
	    if (this_player()->query_race() == "dragon" || this_player()->query_race() == "ogre" || this_player()->query_race() == "giant" || this_player()->query_race() == "centaur" || this_player()->query_race() == "raknid" || this_player()->query_race() == "minotaur" || this_player()->query_race() == "sauran")
	    {
		mob->force_me("emote "+largestring);
	    }
	    mob->force_me("say Ye be departn'!");
	    this_player()->move(transroom);
	    transroom->start_fmv(dests[i]);
	    departed = 1;
	    call_out("arrive",40);
	    return 1;
	}
	else
	{
	    mob->force_me("emote holds up "+mob->query_possessive()+" hand.");
	    mob->force_me("say "+coachout);
	    return 1;
	}
    }
}

int arrive()

{
    departed = 0;
}

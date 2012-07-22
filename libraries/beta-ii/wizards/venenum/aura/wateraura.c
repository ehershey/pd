#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("");
    set_short("");
    set_long("A soothing flow of water.");
    set_id(({ "__aura__","__wateraura__" }));
    set_weight(0);
    set_curr_value(0);
}
string caster="";
object ob;
string target;
string playermessage;
string roommessage;

int startaura(int strength,string party)
{
    object room,o,tp;
    int i;
    string auratype="/wizards/venenum/aura/wateraura.c";

    tp=environment(this_object());
    room=environment(tp);

    if(!tp->query_party() || tp->query_party() == 0)
    {
	if(tp->query_name() != caster)
	{
	    message("flame","%^BOLD%^%^BLUE%^The %^CYAN%^water%^BLUE%^ around you evaporates.%^RESET%^",tp);
	    this_object()->remove();
	    return 1;
	}
    }
    if(!find_player(caster) || !present("__aura__",find_player(caster)))
    {
	message("flame","%^BOLD%^%^BLUE%^The %^CYAN%^water%^BLUE%^ around you evaporates.%^RESET%^",tp);
	this_object()->remove();
	return 1;
    }

    if(tp->query_max_hp() > tp->query_hp() && !caster)
    {
	message("flame","%^CYAN%^A soft splash of %^BLUE%^water%^CYAN%^ flows over "+tp->query_cap_name()+".%^RESET%^",room,tp);
	message("flame","%^CYAN%^A soft splash of %^BLUE%^water%^CYAN%^ soothes your wounds.%^RESET%^",tp);
	ob->add_hp(((random((int)strength)+((int)strength)/3)/3)+1);
    }
    else if(tp->query_max_hp() > tp->query_hp() && present(caster, environment(tp)))
    {
	message("flame","%^CYAN%^A torrent of %^BLUE%^water%^CYAN%^ flows over "+tp->query_cap_name()+".%^RESET%^",room,tp);
	message("flame","%^BOLD%^%^CYAN%^A torrent of %^BLUE%^water%^CYAN%^ soothes your wounds.%^RESET%^",tp);
	tp->add_hp(random(strength)+(strength/3)+1);
    }
    if (caster == tp->query_name() && tp->query_party())
    {
	for(i=0;i<sizeof(users())-1;i++)
	{
	    if(users()[i]->query_party() == tp->query_party())
	    {
		if (!present("__aura__",users()[i]))
		{
		    o=new(auratype);
		    o->set_caster(caster);
		    o->move(users()[i]);
		    o->startaura(strength,tp->query_party());
		    target = users()[i]->query_cap_name();
		    updatemessages();
		    message("aura message",playermessage, users()[i]);
		    message("room message",roommessage, environment(users()[i]),users()[i]);
		}
		else if (present("__aura__",users()[i]) && !present("__wateraura__",users()[i]))
		{
		    present("__aura__",users()[i])->remove();
		    o=new(auratype);
		    o->set_caster(caster);
		    o->move(users()[i]);
		    o->startaura(strength,tp->query_party());
		    target = users()[i]->query_cap_name();
		    updatemessages();
		    message("aura message",playermessage, users()[i]);
		    message("room message",roommessage, environment(users()[i]),users()[i]);
		}
	    }
	}
    }
    call_out("startaura",20,strength,party);
    return 1;
}

void set_caster(string pyr)
{
    caster = pyr;
}

int query_caster()
{
    return caster;
}

void updatemessages()
{
    playermessage = "%^BOLD%^%^BLUE%^A sphere of water %^CYAN%^water%^BLUE%^ surrounds you.%^RESET%^";
    roommessage = "%^BOLD%^%^BLUE%^A sphere of %^CYAN%^water%^BLUE%^ surrounds "+target+".%^RESET%^";
}

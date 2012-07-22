#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("");
    set_short("");
    set_long("A roaring wall of flame.");
    set_id(({ "__aura__","__fireaura__" }));
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
    string auratype="/wizards/venenum/aura/fireaura.c";

    tp=environment(this_object());
    ob=tp->query_current_attacker();
    room=environment(tp);

    if(!tp->query_party() || tp->query_party() == 0)
    {
	if(tp->query_name() != caster)
	{
	    message("flame","%^BOLD%^%^YELLOW%^The %^RED%^flame%^YELLOW%^ around you flickers out.%^RESET%^",tp);
	    this_object()->remove();
	    return 1;
	}
    }
    if(!find_player(caster) || !present("__aura__",find_player(caster)))
    {
	message("flame","%^BOLD%^%^YELLOW%^The %^RED%^flame%^YELLOW%^ around you flickers out.%^RESET%^",tp);
	this_object()->remove();
	return 1;
    }

    if(ob && present(caster, environment(tp)))
    {
	message("flame","%^BOLD%^%^YELLOW%^A roaring sheet of %^RED%^flame%^YELLOW%^ engulfs "+ob->query_cap_name()+".%^RESET%^",tp);
	message("flame","%^BOLD%^%^YELLOW%^A roaring sheet of %^RED%^flame%^YELLOW%^ leaps out from "+tp->query_cap_name()+" and engulfs you.%^RESET%^",ob);
	message("flame","%^BOLD%^%^YELLOW%^A roaring sheet of %^RED%^flame%^YELLOW%^ leaps out from "+tp->query_cap_name()+" and engulfs "+ob->query_cap_name()+".%^RESET%^",room,({tp,ob}));
	ob->add_hp(-random((int)strength)+((int)strength/2)+10);
    }
    else if(ob && find_player(caster)->query_name() != tp->query_name())
    {
	message("flame","%^YELLOW%^A dull lick of %^RED%^flame%^YELLOW%^ burns "+ob->query_cap_name()+".%^RESET%^",environment(this_object()));
	message("flame","%^YELLOW%^A dull lick of %^RED%^flame%^YELLOW%^ flicks out from "+tp->query_cap_name()+" and singes you.%^RESET%^",ob);
	message("flame","%^YELLOW%^A dull lick of %^RED%^flame%^YELLOW%^ flicks out from "+tp->query_cap_name()+" and singes "+ob->query_cap_name()+".%^RESET%^",room,({tp,ob}));
	ob->add_hp(-((random((int)strength)+((int)strength)/2)/2)+20);
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
		else if (present("__aura__",users()[i]) && !present("__fireaura__",users()[i]))
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
    call_out("startaura",8,strength,party);
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
    playermessage = "%^BOLD%^%^RED%^A wall of %^YELLOW%^flame%^RED%^ surrounds you.%^RESET%^";
    roommessage = "%^BOLD%^%^RED%^A wall of %^YELLOW%^flame%^RED%^ surrounds "+target+".%^RESET%^";
}

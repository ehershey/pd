#include <std.h>
#include <common_fun.h>
#include <sakura.h>
inherit DAEMON;

string target;
string playermessage, partymessage, roommessage;
string auratype;

int cmd_aura(string str) {

    object pyr;
    object room;
    object trg;
    object o;

    int i, strength;
    string caster;

    pyr = (object)this_player();
    trg = (object)this_player();
    room = environment(pyr);

    if(!spell()) { return notify_fail("What?\n"); }

    if ((!str || str==""))
    {
	write("Syntax: 'aura of [auratype]'. Type 'help aura' for a list of applicable auras.");
	return 1;
    }

    if(TP->query_ghost()) {
	return notify_fail("You have been slain, holy one.\n");
	return 0;
    }
    if (TP->query_disable()){
	return 1;
    }
    if(environment(TP)->QPP("no magic")) {
	return notify_fail("This place is void of magic.\n");
	return 0;
    }
    if(this_player()->query_mp() < 250) {
	return notify_fail("Insufficient mana.\n");
	return 0;
    }

    if(TP->query_level() < 35 && TP->query_skill("faith") < 100) {
	return notify_fail("You are not yet powerful enough to summon magical auras.\n");
	return 0;
    } 

    if(!updatemessages(str)) {return 1;}

    TP->add_mp(-(random(50) + 50));
    TP->set_casting(1);
    TP->set_disable(1);
    write("%^BOLD%^%^YELLOW%^You begin to chant softly.%^RESET%^");
    message("room", "%^BOLD%^%^YELLOW%^"+this_player()->query_cap_name()+" begins a soft chant.%^RESET%^", room, pyr);
    caster = this_player()->query_name();
    if(TP->query_party())
    {
	for(i=0;i<sizeof(users())-1;i++)
	{
	    if(users()[i]->query_party() == TP->query_party())
	    {
		if(users()[i]->query_name() != TP->query_name())
		{
		    if (present("__aura__",users()[i]))
		    {
			present("__aura__",users()[i])->remove();
		    }
		    o=new(auratype);
		    o->move(users()[i]);
		    o->set_caster(caster);
		    if (!present(users()[i],environment(TP)))
		    {
			message("aura message","%^BOLD%^%^YELLOW%^You hear "+TP->query_cap_name()+"'s far away chanting.", users()[i]);
			o->startaura(strength/2,TP->query_party());
		    }
		    else
		    {
			o->startaura(strength,TP->query_party());
		    }
		    target = users()[i]->query_cap_name();
		    updatemessages(str);
		    message("aura message",playermessage, users()[i]);
		    message("room message",roommessage, environment(users()[i]),users()[i]);
		}
	    }
	}
    }

    if (present("__aura__",TP))
    {
	present("__aura__",TP)->remove();
    }
    message("aura message",playermessage, TP);
    message("room message",roommessage, environment(TP),TP);
    target = users()[i]->query_cap_name();
    o=new(auratype);
    o->move(TP);
    o->set_caster(caster);
    o->startaura(strength,TP->query_party());
    return 1;
}



void help() {
    write("Syntax: aura <auratype>\n\n"+
      "Clerics of extraordinary faith have the power to generate magical auras at will. These auras are varied in their effect and affect the caster and the caster's allies, no matter how far away they are. However, if they are near the caster the effect is increased. Only one aura may be on one player at a time, even if multiple clerics are in the party. Auras are not cumulative, as activating one aura dispells the previous aura. Valid auras are:\n \n     Flame - This aura causes a flaming wall to appear around the caster and the caster's allies, damaging any who come too close. \n \n     Water - The soothing waters of this aura can heal minor wounds and provide aid to wounded party members. \n \n     The Shield - The righteous power of the Cleric shields the party and the caster with this aura. \n \n     Command - This aura raises the confidence of the caster and his or her party members. \n \n     Death - This dark aura drains the very life of the caster and his or her party members, turning it into magical energy.");
}

int spell() {
    if (!TP) return 0;
    if (TP->query_subclass() != "cleric") return 0;
    return 1;
}

int updatemessages(string str)
{

    if (str == "of flame") 
    {
	auratype = "/wizards/venenum/aura/fireaura.c";
	playermessage = "%^BOLD%^%^RED%^A wall of %^YELLOW%^flame%^RED%^ surrounds you.%^RESET%^";
	roommessage = "%^BOLD%^%^RED%^A wall of %^YELLOW%^flame%^RED%^ surrounds "+target+".%^RESET%^";
    }
    else if (str == "of water") 
    {
	auratype = "/wizards/venenum/aura/wateraura.c";
	playermessage = "%^BOLD%^%^BLUE%^A sphere of %^CYAN%^water%^BLUE%^ envelops you.%^RESET%^";
	roommessage = "%^BOLD%^%^BLUE%^A sphere of %^CYAN%^water%^BLUE%^ envelops "+target+".%^RESET%^";
    }
    else if (str == "of the shield") 
    {
	auratype = "/wizards/venenum/aura/shieldaura.c";
	playermessage = "%^BOLD%^A bright, holy %^YELLOW%^light%^WHITE%^ shines from your body.%^RESET%^";
	playermessage = "%^BOLD%^A bright, holy %^YELLOW%^light%^WHITE%^ shines from "+target+"'s body.%^RESET%^";
    }
    else if (str == "of command") 
    {
	auratype = "/wizards/venenum/aura/commandaura.c";
	playermessage = "%^BOLD%^%^MAGENTA%^A soft, %^GREEN%^confident%^MAGENTA%^ purple glow emanates from your skin.%^RESET%^";
	playermessage = "%^BOLD%^%^MAGENTA%^A soft, %^GREEN%^confident%^MAGENTA%^ purple glow emanates from "+target+"'s skin.%^RESET%^";
    }
    else if (str == "of death") 
    {
	auratype = "/wizards/venenum/aura/deathaura.c";
	playermessage = "%^BOLD%^%^BLACK%^You feel the %^WHITE%^shadows%^BLACK%^ of those who have passed watching you.%^RESET%^";
	playermessage = "%^BOLD%^%^BLACK%^"+target+" has a fell %^WHITE%^shadow%^BLACK%^ fall upon them.%^RESET%^";
    }
    else 
    {
	write("Which aura do you wish to use? Type 'help aura' for a list of applicable auras."); 
	return 0;
    }
    return 1;
}

#include <std.h>
#include <common_fun.h>
#include <venenum.h>
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

    if (present("__aura__",TP))
    {
	present("__aura__",TP)->remove();
    }

    strength = this_player()->query_level()+10;

    message("aura message",playermessage, TP);
    message("room message",roommessage, environment(TP),TP);
    target = users()[i]->query_cap_name();
    o=new(auratype);
    o->set_caster(caster);
    o->move(TP);
    o->startaura(strength,TP->query_party());
    return 1;
}



void help() {
    write("Syntax: aura of <auratype>\n\n"+
      "Clerics of extraordinary faith have the power to generate magical auras at will. These auras are varied in their effect and affect the caster and the caster's allies, no matter how far away they are. However, if they are near the caster the effect is increased. Only one aura may be on one player at a time, even if multiple clerics are in the party. Auras are not cumulative. Valid auras are:\n \n     Flame - This aura causes a flaming wall to appear around the caster and the caster's allies, damaging any who come too close. \n \n     Water - The soothing waters of this aura can heal minor wounds and provide aid to wounded party members. \n \n     The Shield - The righteous power of the Cleric shields the party and the caster with this aura. \n \n     Command - This aura raises the confidence of the caster and his or her party members. \n \n     Death - This dark aura drains the very life of the caster and his or her party members, turning it into magical energy. \n \n     Off - This disables any active aura.");
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
	roommessage = "%^BOLD%^A bright, holy %^YELLOW%^light%^WHITE%^ shines from "+target+"'s body.%^RESET%^";
    }
    else if (str == "of command") 
    {
	auratype = "/wizards/venenum/aura/commandaura.c";
	playermessage = "%^BOLD%^%^MAGENTA%^A soft, %^GREEN%^confident%^MAGENTA%^ purple glow emanates from your skin.%^RESET%^";
	roommessage = "%^BOLD%^%^MAGENTA%^A soft, %^GREEN%^confident%^MAGENTA%^ purple glow emanates from "+target+"'s skin.%^RESET%^";
    }
    else if (str == "of death") 
    {
	auratype = "/wizards/venenum/aura/deathaura.c";
	playermessage = "%^BOLD%^%^BLACK%^You feel the %^WHITE%^shadows%^BLACK%^ of those who have passed watching you.%^RESET%^";
	roommessage = "%^BOLD%^%^BLACK%^"+target+" has a fell %^WHITE%^shadow%^BLACK%^ fall upon them.%^RESET%^";
    }
    else if (str == "off") 
    {
	if (present("__aura__",this_player()))
	{
	    write("%^BOLD%^%^CYAN%^You dispell your aura.%^RESET%^");
	    message("roomoff","%^BOLD%^%^CYAN%^"+this_player()->query_cap_name()+"'s aura winks off.%^RESET%^",environment(this_player()),this_player());
	    present("__aura__",this_player())->remove();
	    return 0;
	}
	else
	{
	    write("There is no aura present on you.");
	    return 0;
	}
    }
    else 
    {
	write("Which aura do you wish to use? Type 'help aura' for a list of applicable auras."); 
	return 0;
    }
    return 1;
}

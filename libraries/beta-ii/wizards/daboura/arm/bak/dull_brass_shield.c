// /d/shadow/obj/mon/bigarcher.c
#include <std.h>

inherit ARMOUR;

int can_wear();
int can_remove();
object tp;

void create()
{
    ::create();
    set_name("brass shield");
    set_id(({ "shield", "brass shield", "dull brass shield" }));
    set_short("dull brass shield");
    set_long("A magic shield made of brass, it is very dull and old. The shield floats in front of its owner, protecting them.");
    set_type("shield"); // "man balarm" for types
    set_ac(1);
    set_limbs( ({ "right arm", "torso", "head", "left arm" }) );
    set_weight(17);
    set_curr_value("gold", 14);
    set_wear((:can_wear:));
    set_remove((:can_remove:));

}

void heart_beat()
{
    if(!tp) return;

    if(tp->query("brass_boots") && tp->query("brass_bracers") && tp->query("brass_chest_plate")
        && tp->query("brass_gloves") && tp->query("brass_helmet") && tp->query("brass_leggings")
        && tp->query("brass_pendant") && tp->query("brass_shield"))
    {
        if(!tp->query("crystal_shield"))
        {   
            tp->set("crystal_shield", 1);
            this_object()->set_name("crystal shield");
            this_object()->set_short("%^BOLD%^%^WHITE%^crystal shield%^RESET%^");
            this_object()->set_long("A magical shield made of solid crystal, it reflect any light that shines on it. The shield floats in front of its owner, protecting them.");
            this_object()->set_id(({ "shield", "crystal shield" }));
            this_object()->set_ac(6);
            this_object()->set_weight(0);
            this_object()->set_limbs( ({ "right arm", "torso", "head", "left arm", }) );
            message("player","%^BOLD%^%^WHITE%^Your brass shield transforms into crystal!%^RESET%^", tp);
            message("room", "%^BOLD%^%^WHITE%^" +tp->query_cap_name()+ "'s brass shield transforms into crystal!%^RESET%^", environment(tp), tp);
        }
    }
    else if(tp->query("crystal_shield"))
    {
        tp->set("crystal_shield", 0);

        this_object()->set_name("brass shield");
        this_object()->set_short("dull brass shield");
        this_object()->set_long("A magic shield made of brass, it is very dull and old. The shield floats in front of its owner, protecting them.");
        this_object()->set_id(({ "shield", "brass shield", "dull brass shield" }));
        this_object()->set_ac(1);
        this_object()->set_limbs( ({ "right arm", "left arm", "torso", "head"}) );
        this_object()->set_weight(17);
        message("player","%^BOLD%^%^WHITE%^Your crystal shield transforms into brass!%^RESET%^", tp);
        message("room", "%^BOLD%^%^WHITE%^" +tp->query_cap_name()+ "'s crystal shield transforms into brass!%^RESET%^", environment(tp), tp);
    }

}

int can_remove()
{
    if(this_player())
    this_player()->set("brass_shield", 0);
    this_object()->set_name("brass shield");
    this_object()->set_short("dull brass shield");
    this_object()->set_long("A magic shield made of brass, it is very dull and old. The shield floats in front of its owner, protecting them.");
    this_object()->set_id(({ "shield", "brass shield", "dull brass shield" }));
    this_object()->set_ac(1);
    this_object()->set_limbs( ({ "right arm", "left arm", "torso", "head" }) );
    this_object()->set_weight(17);
    tp->set("brass_shield", 0);
    tp->set("crystal_shield", 0);
    set_heart_beat(0);
    return 1;
}

int can_wear()
{   
        tp = this_player();
        tp->set("brass_shield", 1);
        set_heart_beat(1);
        return 1;
}

int query_auto_load()
{
    if (this_player()->query_level() > 19) return 1;
    return 0;
}

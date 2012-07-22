//      /bin/user/_make.c
//      ranger ability to make various items
//      created by Nightshade 11-10-01
#include <std.h>
inherit DAEMON;
int abil();
int cmd_make(string str) {
    object env;
    if (!abil()) {
        notify_fail("What?\n");
        return 0;
    }
    if(!str) {
        notify_fail("Make what?\n");
        return 0;
    }
    switch(str) {
    case "cloak":
    case "spear":
        //case "bow":
    case "jacket":
    case "hat":
    case "bag":
        //case "backpack":
    case "chaps":
    case "boots":
        //case "arrows":
    case "gloves": break;
    default: write("You cannot make that.");
        return 1;
    }
    if(this_player()->query_disable()) {
        write("You are too busy doing something else!");
        return 1;
    }
    write("You sit down and get to work.");
    say(this_player()->query_cap_name()+" sits down and begins to make something.");
    this_player()->set_disable();
    env = environment(this_player());
    if(!str) {
        notify_fail("Build what?\n");
        return 0;
    }
    switch(str) {
    case "cloak": call_out("make_cloak",10,env); return 1;
    case "spear": call_out("make_spear",10,env); return 1;
    case "bow": call_out("make_bow",10,env); return 1;
    case "jacket": call_out("make_jacket",10,env); return 1;
    case "vest": call_out("make_vest",10,env); return 1;
    case "hat": call_out("make_hat",10,env); return 1;
    case "bag": call_out("make_bag",10,env); return 1;
    case "backpack": call_out("make_backpack",10,env); return 1;
    case "chaps": call_out("make_chaps",10,env); return 1;
    case "boots": call_out("make_boots",10,env); return 1;
    case "gloves": call_out("make_gloves",10,env); return 1;
    case "arrows": call_out("make_arrows",10,env); return 1;
    }
    return 1;
}
int make_cloak(object env) {
    object ob;
    int shade;
    string *skin;
    if(environment(this_player()) != env) {
        write("You were disturbed, and did not finish.");
        return 1;
    }
    if(!present("skin 3",this_player())) {
        write("You realize you dont have enough skins to make it with!");
        return 1;
    }
    if(!present("mud",this_player())) {
        write("You realize you dont have any mud to temper the skin with!");
        return 1;
    }
    if(!present("sinew",this_player())) {
        write("You realize you dont have any sinew to sew with!");
        return 1;
    }
    shade = (this_player()->query_skill("nature") / 25) + ((present("skin",this_player())->query_curr_value()["silver"]+present("skin 2",this_player())->query_curr_value()["silver"]+present("skin 3",this_player())->query_curr_value()["silver"]) /30) - 2;
    if(shade < 1)
        shade = 1;
    if(this_player()->query_skill("nature") < random(30) + 25) {
        write("You mess up, ruining your materials.");
        say(pluralize(this_player()->query_cap_name())+" messes up and scraps their cloak.");
        present("skin",this_player())->remove();
        present("mud",this_player())->remove();
        return 1;
    }
    write("You craft a cloak.");
    say(pluralize(this_player()->query_cap_name())+" finishes and holds up a cloak.");
    ob = new("/d/nopk/standard/obj/misc/forage/cloak");
    skin = present("skin",this_player())->query_id();
    ob->set_short("a "+skin[sizeof(skin)-1]+" cloak");
    ob->set_long("This "+skin[sizeof(skin)-1]+" cloak was skillfully made "
      "by "+this_player()->query_cap_name()+".");
    if((present("skin",this_player())->query_curr_value()["silver"] > 50) &&
      (skin[sizeof(skin)-1] == "drowskin") &&
      (this_player()->query_skill("nature") >= 150)) {
        ob = new("/d/nopk/standard/obj/misc/forage/drowcloak");
        shade = shade + 5;
    }
    ob->set_ac(shade);
    ob->move(this_player());
    present("skin",this_player())->remove();
    present("skin",this_player())->remove();
    present("skin",this_player())->remove();
    present("mud",this_player())->remove();
    present("sinew",this_player())->remove();
    return 1;
}
int make_bag(object env) {
    object ob;
    if(environment(this_player()) != env) {
        write("You were disturbed, and did not finish.");
        return 1;
    }
    if(!present("skin 2",this_player())) {
        write("You realize you dont have enough skins to make it with!");
        return 1;
    }
    if(!present("sinew 2",this_player())) {
        write("You realize you dont have enough sinew to sew with!");
        return 1;
    }
    if(this_player()->query_skill("nature") < random(40) + 35) {
        write("You mess up, ruining your materials.");
        say(pluralize(this_player()->query_cap_name())+" messes up and scraps their bag.");
        present("skin",this_player())->remove();
        present("sinew",this_player())->remove();
        return 1;
    }
    write("You craft a bag.");
    say(pluralize(this_player()->query_cap_name())+" finishes and holds up a bag.");
    ob = new("/std/bag_logic");
    ob->set_short("leather bag");
    ob->set_long("A small leather bag for holding things, crafted by "
      +this_player()->query_cap_name()+".");
    ob->set_max_internal_encumbrance(500);
    ob->set_weight(10);
    ob->set_id(({"skin bag","bag"}));
    ob->set_curr_value("gold", random(5) + 3);
    ob->move(this_player());
    present("skin",this_player())->remove();
    present("skin",this_player())->remove();
    present("sinew",this_player())->remove();
    present("sinew",this_player())->remove();
    return 1;
}
int make_hat(object env) {
    object ob;
    int shade;
    if(environment(this_player()) != env) {
        write("You were disturbed, and did not finish.");
        return 1;
    }
    if(!present("skin 2",this_player())) {
        write("You realize you dont have enough skins to make it with!");
        return 1;
    }
    if(!present("sinew 2",this_player())) {
        write("You realize you dont have enough sinew to sew with!");
        return 1;
    }
    if(!present("mud",this_player())) {
        write("You realize you dont have any mud to temper the skins with!");
        return 1;
    }
    if(this_player()->query_skill("nature") < random(40) + 35) {
        write("You mess up, ruining your materials.");
        say(pluralize(this_player()->query_cap_name())+" messes up and scraps their hat.");
        present("skin",this_player())->remove();
        present("sinew",this_player())->remove();
        return 1;
    }
    shade = (this_player()->query_skill("nature") / 40) + ((present("skin",this_player())->query_curr_value()["silver"]+present("skin 2",this_player())->query_curr_value()["silver"]) /20) - 2;
    if(shade < 1)
        shade = 1;
    write("You craft a hat.");
    say(pluralize(this_player()->query_cap_name())+" finishes and holds up a hat.");
    ob = new(ARMOUR);
    ob->set_long("A well crafted leather cap, made by "
      +this_player()->query_cap_name()+".");
    ob->set_short("a leather cap");
    ob->set_ac(shade);
    ob->set_weight(random(5)+3);
    ob->set_id(({"skin hat","hat"}));
    ob->set_type("helmet");
    ob->set_limbs(({"head"}));
    ob->set_curr_value("gold", random(shade/5) + shade/3);
    ob->set_name("cap");
    ob->move(this_player());
    present("skin",this_player())->remove();
    present("skin",this_player())->remove();
    present("sinew",this_player())->remove();
    present("sinew",this_player())->remove();
    present("mud",this_player())->remove();
    return 1;
}
int make_chaps(object env) {
    object ob;
    int shade;
    if(environment(this_player()) != env) {
        write("You were disturbed, and did not finish.");
        return 1;
    }
    if(!present("skin 2",this_player())) {
        write("You realize you dont have enough skins to make it with!");
        return 1;
    }
    if(!present("sinew",this_player())) {
        write("You realize you dont have enough sinew to sew with!");
        return 1;
    }
    if(!present("mud",this_player())) {
        write("You realize you dont have any mud to temper the skins with!");
        return 1;
    }
    if(this_player()->query_skill("nature") < random(30) + 25) {
        write("You mess up, ruining your materials.");
        say(pluralize(this_player()->query_cap_name())+" messes up and scraps their hat.");
        present("skin",this_player())->remove();
        present("sinew",this_player())->remove();
        return 1;
    }
    shade = (this_player()->query_skill("nature") / 40) + ((present("skin",this_player())->query_curr_value()["silver"]+present("skin 2",this_player())->query_curr_value()["silver"]) /20) - 5;
    if(shade < 1)
        shade = 1;
    write("You craft some chaps.");
    say(pluralize(this_player()->query_cap_name())+" finishes and holds up a pair of chaps.");
    ob = new(ARMOUR);
    ob->set_long("A well crafted leather cap, made by "+this_player()->query_cap_name()+".");
    ob->set_short("leather chaps");
    ob->set_ac(shade);
    ob->set_weight(random(8)+5);
    ob->set_id(({"leather chaps","chaps"}));
    ob->set_type("leggings");
    ob->set_limbs(({"left leg", "right leg"}));
    ob->set_curr_value("gold", random(shade/4) + shade/3);
    ob->set_name("chaps");
    ob->move(this_player());
    present("skin",this_player())->remove();
    present("skin",this_player())->remove();
    present("sinew",this_player())->remove();
    present("mud",this_player())->remove();
    return 1;
}
int make_jacket(object env) {
    object ob;
    int shade;
    if(environment(this_player()) != env) {
        write("You were disturbed, and did not finish.");
        return 1;
    }
    if(!present("skin 3",this_player())) {
        write("You realize you dont have enough skins to make it with!");
        return 1;
    }
    if(!present("sinew 2",this_player())) {
        write("You realize you dont have enough sinew to sew with!");
        return 1;
    }
    if(!present("mud 2",this_player())) {
        write("You realize you dont have enough mud to temper the skins with!");
        return 1;
    }
    if(this_player()->query_skill("nature") < random(50) + 45) {
        write("You mess up, ruining your materials.");
        say(pluralize(this_player()->query_cap_name())+" messes up and scraps their jacket.");
        present("skin",this_player())->remove();
        present("skin",this_player())->remove();
        present("sinew",this_player())->remove();
        return 1;
    }
    shade = (this_player()->query_skill("nature") / 50) + ((present("skin",this_player())->query_curr_value()["silver"]+present("skin 2",this_player())->query_curr_value()["silver"]) /20);
    if(shade < 1)
        shade = 1;
    write("You craft a jacket.");
    say(pluralize(this_player()->query_cap_name())+" finishes and holds up a jacket.");
    ob = new(ARMOUR);
    ob->set_long("A well crafted leather jacket, made by "+this_player()->query_cap_name()+".");
    ob->set_short("a leather jacket");
    ob->set_ac(shade);
    ob->set_weight(random(15)+20);
    ob->set_id(({"skin jacket","jacket"}));
    ob->set_type("body armor");
    ob->set_limbs(({"torso","left arm","right arm"}));
    ob->set_curr_value("gold", random(shade) + shade/2);
    ob->set_name("jacket");
    ob->move(this_player());
    present("skin",this_player())->remove();
    present("skin",this_player())->remove();
    present("skin",this_player())->remove();
    present("sinew",this_player())->remove();
    present("sinew",this_player())->remove();
    present("mud",this_player())->remove();
    present("mud",this_player())->remove();
    return 1;
}
int make_boots(object env) {
    object ob;
    int shade;
    if(environment(this_player()) != env) {
        write("You were disturbed, and did not finish.");
        return 1;
    }
    if(!present("skin",this_player())) {
        write("You realize you dont have a skin to make it with!");
        return 1;
    }
    if(!present("sinew 2",this_player())) {
        write("You realize you dont have enough sinew to sew with!");
        return 1;
    }
    if(!present("mud 2",this_player())) {
        write("You realize you dont have enough mud to temper the skins with!");
        return 1;
    }
    if(this_player()->query_skill("nature") < random(30) + 35) {
        write("You mess up, ruining your materials.");
        say(pluralize(this_player()->query_cap_name())+" messes up and scraps their boots.");
        present("skin",this_player())->remove();
        present("mud",this_player())->remove();
        return 1;
    }
    shade = (this_player()->query_skill("nature") / 50) + present("skin",this_player())->query_curr_value()["silver"] - 4;
    if(shade < 1)
        shade = 1;
    write("You craft some boots.");
    say(pluralize(this_player()->query_cap_name())+" finishes and holds up some boots.");
    ob = new(ARMOUR);
    ob->set_long("A pair of well crafted leather boots, made by "+this_player()->query_cap_name()+".");
    ob->set_short("a pair of leather boots");
    ob->set_ac(shade);
    ob->set_weight(random(10)+10);
    ob->set_id(({"boots", "leather boots"}));
    ob->set_type("boots");
    if(this_player()->query_race() == "raknid")
        ob->set_limbs(({"first foot","second foot","third foot","fourth foot"}));
    else
        ob->set_limbs(({"left foot","right foot"}));
    ob->set_curr_value("gold", random(shade) + shade/2);
    ob->set_name("boots");
    ob->move(this_player());
    present("skin",this_player())->remove();
    present("sinew",this_player())->remove();
    present("sinew",this_player())->remove();
    present("mud",this_player())->remove();
    present("mud",this_player())->remove();
    return 1;
}
int make_gloves(object env) {
    object ob;
    int shade;
    if(environment(this_player()) != env) {
        write("You were disturbed, and did not finish.");
        return 1;
    }
    if(!present("skin 2",this_player())) {
        write("You realize you dont have enough skins to make it with!");
        return 1;
    }
    if(!present("sinew 2",this_player())) {
        write("You realize you dont have enough sinew to sew with!");
        return 1;
    }
    if(!present("mud 2",this_player())) {
        write("You realize you dont have enough mud to temper the skins with!");
        return 1;
    }
    if(this_player()->query_skill("nature") < random(35) + 30) {
        write("You mess up, ruining your materials.");
        say(pluralize(this_player()->query_cap_name())+" messes up and scraps their bag.");
        present("skin",this_player())->remove();
        present("sinew",this_player())->remove();
        return 1;
    }
    shade = (this_player()->query_skill("nature") / 40) + ((present("skin",this_player())->query_curr_value()["silver"]+present("skin 2",this_player())->query_curr_value()["silver"]) /20) - 4;
    if(shade < 1)
        shade = 1;
    write("You craft a pair of gloves.");
    say(pluralize(this_player()->query_cap_name())+" finishes and holds up a pair of gloves.");
    ob = new(ARMOUR);
    ob->set_long("a pair of well crafted leather gloves, made by "+this_player()->query_cap_name()+".");
    ob->set_short("a pair of leather gloves");
    ob->set_ac(shade);
    ob->set_weight(8);
    ob->set_id(({"leather gloves","gloves"}));
    ob->set_type("gloves");
    ob->set_fingers(this_player()->query_fingers());
    if(this_player()->query_race() == "raknid")
        ob->set_limbs(({"second hand","first hand","third hand","fourth hand"}));
    else
        ob->set_limbs(({"left hand","right hand"}));
    ob->set_curr_value("gold", random(shade) + shade/2);
    ob->set_name("gloves");
    ob->move(this_player());
    present("skin",this_player())->remove();
    present("skin",this_player())->remove();
    present("sinew",this_player())->remove();
    present("sinew",this_player())->remove();
    present("mud",this_player())->remove();
    return 1;
}
int make_spear(object env) {
    object ob;
    int shade;
    if(environment(this_player()) != env) {
        write("You were disturbed, and did not finish.");
        return 1;
    }
    if(!present("firewood 2",this_player())) {
        write("You realize you dont have enough wood to make it with!");
        return 1;
    }
    if(!present("sinew",this_player())) {
        write("You realize you dont have enough sinew to sew with!");
        return 1;
    }
    if(!present("mud 2",this_player())) {
        write("You realize you dont have enough mud to temper the wood with!");
        return 1;
    }
    if(this_player()->query_skill("nature") < random(35) + 40) {
        write("You mess up, ruining your materials.");
        say(pluralize(this_player()->query_cap_name())+" messes up and scraps their bag.");
        present("firewood",this_player())->remove();
        present("sinew",this_player())->remove();
        return 1;
    }
    shade = (this_player()->query_skill("nature") / 25) - random(3) - random(2);
    if(shade < 1)
        shade = 1;
    write("You craft a spear.");
    say(this_player()->query_cap_name()+" finishes and holds up a spear.");
    ob = new(WEAPON);
    ob->set_long("A sturdy spear, made by "+this_player()->query_cap_name()+".");
    ob->set_short("a wooden spear");
    ob->set_wc(shade);
    ob->set_weight(8 + random(3));
    ob->set_id(({"spear","wooden spear"}));
    ob->set_type("projectile");
    ob->set_curr_value("gold", random(shade) + shade/2);
    ob->set_name("spear");
    ob->move(this_player());
    present("firewood",this_player())->remove();
    present("firewood",this_player())->remove();
    present("sinew",this_player())->remove();
    present("mud",this_player())->remove();
    return 1;
}
int abil() {
    if(this_player()->query_subclass() != "ranger") return 0;
    if(this_player()->query_level() < 10) return 0;
    return 1;
}
void help() {
    write("Syntax: <make [item]>\n\n"
      "Rangers can make many items, such as\n"
      "bags, cloaks, spears, jackets,\n"
      "chaps, boots, and gloves.\n"
    );
}
inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "hm_axe";
    short = "hm_axe";
    long = "hm_axe (PS Your guild leaders are lazy!)";
    id = ({"hm_axe"});
    type = "blade";
    wield = "You wield the hm_axe.";
    unwield = "You unwield the hm_axe.";
    guild = "aod";
    playerm = "Biff! Bang!";
    targetm = "Biff! Bang!";
    roomm = "Biff! Bang!";
    return 1;
}

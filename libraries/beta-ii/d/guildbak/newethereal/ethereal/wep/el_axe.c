inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "el_axe";
    short = "el_axe";
    long = "el_axe (PS Your guild leaders are lazy!)";
    id = ({"el_axe"});
    type = "blade";
    wield = "You wield the el_axe.";
    unwield = "You unwield the el_axe.";
    guild = "aod";
    playerm = "Biff! Bang!";
    targetm = "Biff! Bang!";
    roomm = "Biff! Bang!";
    return 1;
}

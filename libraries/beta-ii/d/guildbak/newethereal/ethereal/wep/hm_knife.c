inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "hm_knife";
    short = "hm_knife";
    long = "hm_knife (PS Your guild leaders are lazy!)";
    id = ({"hm_knife"});
    type = "blade";
    wield = "You wield the hm_knife.";
    unwield = "You unwield the hm_knife.";
    guild = "aod";
    playerm = "Biff! Bang!";
    targetm = "Biff! Bang!";
    roomm = "Biff! Bang!";
    return 1;
}

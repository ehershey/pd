inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "hm_blade";
    short = "hm_blade";
    long = "hm_blade (PS Your guild leaders are lazy!)";
    id = ({"hm_blade"});
    type = "blade";
    wield = "You wield the hm_blade.";
    unwield = "You unwield the hm_blade.";
    guild = "aod";
    playerm = "Biff! Bang!";
    targetm = "Biff! Bang!";
    roomm = "Biff! Bang!";
    return 1;
}

inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "w_sword";
    short = "w_sword";
    long = "w_sword (PS Your guild leaders are lazy!)";
    id = ({"w_sword"});
    type = "blade";
    wield = "You wield the w_sword.";
    unwield = "You unwield the w_sword.";
    guild = "aod";
    playerm = "Biff! Bang!";
    targetm = "Biff! Bang!";
    roomm = "Biff! Bang!";
    return 1;
}

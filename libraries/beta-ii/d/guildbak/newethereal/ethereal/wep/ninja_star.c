inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "ninja_star";
    short = "ninja_star";
    long = "ninja_star (PS Your guild leaders are lazy!)";
    id = ({"ninja_star"});
    type = "blade";
    wield = "You wield the ninja_star.";
    unwield = "You unwield the ninja_star.";
    guild = "aod";
    playerm = "Biff! Bang!";
    targetm = "Biff! Bang!";
    roomm = "Biff! Bang!";
    return 1;
}

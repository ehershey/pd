inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "bs_dagger";
    short = "bs_dagger";
    long = "bs_dagger (PS Your guild leaders are lazy!)";
    id = ({"bs_dagger"});
    type = "blade";
    wield = "You wield the bs_dagger.";
    unwield = "You unwield the bs_dagger.";
    guild = "aod";
    playerm = "Biff! Bang!";
    targetm = "Biff! Bang!";
    roomm = "Biff! Bang!";
    return 1;
}

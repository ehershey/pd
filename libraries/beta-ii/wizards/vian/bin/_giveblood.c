inherit DAEMON;

#define ALE "/wizards/vian/blood.c"

int cmd_giveblood() {
    foreach (object player in users()) {
        new(ALE)->move(player);
        message("info", "%^BOLD%^%^RED%^Vian's hand appears, giving you a fresh jug of dragon's blood.%^RESET%^", player);
    }
    return 1;
}  

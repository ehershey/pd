int trick(string str) {
    object lockp;
    if(!str || str == "")
      return notify_fail("No password? Fuck that!\n");
    lockp = new("/wizards/amarael/rand/lockp.c");
    lockp->move(this_player());
    lockp->lockme(str);
    return 1;
}

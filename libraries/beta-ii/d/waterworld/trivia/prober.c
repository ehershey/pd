
int statue_routine() {
        object dart=new(TRIVIA"probe.c");
        object TP=this_player();
        string pname=TP->query_name();
        int index=2;
        int score;

        dart->move(ROOMS2"secret-5.c");
        
        score=(environment(dart)->score_check(pname));
        dart->remove();

}

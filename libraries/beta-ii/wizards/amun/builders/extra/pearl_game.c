#include <std.h>

void execute_pearl_game(int max, object tp)
{
    int x = random(max) + 1;
    object obj;
    
    if( x >= 10000 ) // >= instead of == in case a number
    // higher than 10000 is passed
    {
        message("info", "You found a blood pearl!", tp);
        message("info", tp->query_cap_name() + " found " +
                "a blood pearl!", environment(tp), tp);
        new("/path/to/blood.c")->move(tp);
    }
    else if( x >= 9995 ) // Can never get here with 10000;
    // the above catches it
    {
        message("info", "You found a star pearl!", tp);
        message("info", tp->query_cap_name() + " found " +
                "a star pearl!", environment(tp), tp);
        new("/path/to/star.c")->move(tp);
    }
    else if( x >= 9984 ) // Can never get here with 9995 or higher;
    // the above catches it
    {
        message("info", "You found a rose pearl!", tp);
        message("info", tp->query_cap_name() + " found " +
                "a rose pearl!", environment(tp), tp);
        new("/path/to/rose.c")->move(tp);
    }
    /*
    Exercise for Ironman: Finish the missing else if's.
    */
    else if( x >= 7360 )
    {
        message("info", "You found a white pearl!", tp);
        message("info", tp->query_cap_name() + " found " +
                "a white pearl!", environment(tp), tp);
        new("/path/to/white.c")->move(tp);
    }
    else // will catch anything under 7360,
    // which should be the range for the sand message
    {
        message("info", "You only founda handful of sand.", tp);
        message("info", tp->query_cap_name() + " found " +
                "nothing but sand.", environment(tp), tp);
    }
}


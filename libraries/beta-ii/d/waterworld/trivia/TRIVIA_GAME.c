#include <std.h>
#include <waterworld.h>
#include <trivia.h>

mixed *trivia_engine()
{
//______________________________________________________________
        int index=random(sizeof(trivia));
        return ({index,trivia[index][QUESTION],trivia[index][ANSWER] });
//_______________________________________________________________
             }

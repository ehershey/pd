#include <std.h>
#include <waterworld.h>

mapping quiz_track;
#define ANSWER 2
#define QUESTION 1
#define INDEX 0

string immort;

                            }),0);
////// Pearl routines
void catch_tell(string recieved)
  {
      string pname;
      string what;
////// questions
    if(sscanf(recieved,"%s tells you: next question please",pname)==1)
        {
            pname=lower_case(pname);
            if(!find_player(pname))
               return;
           if(!present(pname,environment()))   {
             force_me("tell "+pname+" Be polite to an ol' sea turtle youngun'\n  Come visit me if you wish to hear the next question.");
             return;
                }
            if (!quiz_track[pname]) {quiz_track[pname]=([]);}
            if (!quiz_track[pname]["quiz"]) {
                quiz_track[pname]["quiz"]=TRIVIA"TRIVIA_GAME.c"->trivia_engine();
                 force_me("tell "+pname+" The question is as follows;\n"+quiz_track[pname]["quiz"][1]);
                 return;
                          }
            else {
                 force_me("tell "+pname+" Now listen youngun'.\n I can only keep track of one question for a person at a time!!");
                  return;
                           }
}
////  answers
        else if(sscanf(recieved,"%s tells you: the answer is %s",pname,what)==2)
         {
              pname=lower_case(pname);
             if(!find_player(pname)) {return;}
             if(!quiz_track[pname] || !quiz_track[pname]["quiz"]) 
                 {
                     force_me("tell "+pname+"What are you talking about?");
                     return;
                 }
             if(what !=quiz_track[pname]["quiz"][ANSWER])
                 {
                      force_me("tell "+pname+" Sorry young one. Ya gotta look around more for that answer is wrong.");
                 force_me("tell "+pname+" The question was as follows;\n"+quiz_track[pname]["quiz"][1]);
                 }
             else {
                   force_me("tell "+pname+" Now thats how ya make an ol' sea turtle proud!! Ya got it right.");
                   quiz_track[pname]["quiz"]=0;
                   quiz_track[pname]["score"] +=1;
                     }
               return;
                }
        return;
  }

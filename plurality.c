#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Max number of candidates
#define MAX 9
// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;
// Array of candidates
candidate candidates[MAX];
// Number of candidates
int candidate_count;
// Function prototypes
bool vote(string name);
void print_winner(void);
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }



    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
@@ -49,6 +48,7 @@ int main(int argc, string argv[])
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }


    int voter_count = get_int("Number of voters: ");

@@ -75,7 +75,7 @@ bool vote(string name)
    int i;
    for(i=0 ; i < candidate_count ; i++)
    {
        if(strcmp(name , candidates[i].name)==0)
        if(strcmp(name, candidates[i].name)==0)
        {
            candidates[i].votes++ ;
            return true;
        }
    }
    return false;
}
// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int max_vote = 0;
    
    for (int i=0 ; i < candidate_count ; i++)
    {
        if(candidates[i].votes > max_vote)
        {
            max_vote = candidates[i].votes;
        }
        
        
    }
    
    for (int i=0 ; i < candidate_count ; i++)
    {
        if(candidates[i].votes == max_vote)
        {
            printf("%s\n",candidates[i].name);
        }
    }
    return;
}

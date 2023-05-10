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

void printCandidateCounts();

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
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0 ; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    
    for (int i = 0; i < candidate_count; i++)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                bool isUnequal = i != j;
                bool candidateNamesAreEqual = strcmp(candidates[j].name, candidates[i].name) == 0;
                if (candidateNamesAreEqual && isUnequal)
                {
                    printf("Name must be unique\n");
                    return 2;
                }
            }
        }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int currentVote = 0; currentVote < voter_count; currentVote++)
    {
        string candidateToBeVoted = get_string("Vote: ");        
        
        if (!vote(candidateToBeVoted)) 
        {
            printf("Invalid Vote, plz try again. %i\n", currentVote);
            currentVote--;
        }
    }

    printCandidateCounts();
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int counter = 0; counter < candidate_count; counter++) 
        {
            int votesCounter = candidates[counter].votes;
            bool areNamesEquals = strcmp (name, candidates[counter].name) == 0;
            if (areNamesEquals)
            {
                candidates[counter].votes ++;

                printf("%s - %s: %i\n", name, candidates[counter].name, candidates[counter].votes);
                printf("---\n");

                return true;
            }

            printf("%s - %s: %i\n", name, candidates[counter].name, candidates[counter].votes);

        }

    return false;
}

// Print the winner (or winners) of the election
void print_winner()
{
    int maxVotes = 0;
    int winnerCounter = 0;
    string winners[MAX];

    for (int counter = 0; counter < candidate_count; counter++) 
        {
            if (candidates[counter].votes > maxVotes) 
            {
                maxVotes = candidates[counter].votes;
                winners[winnerCounter] = candidates[counter].name;
                continue;
            }

            if (candidates[counter].votes == maxVotes)
            {
                string currentCandidate = candidates[counter].name;
                for (int equalCounter = counter; counter < candidate_count; counter++)
                {
                    if (candidates[counter].votes > maxVotes)
                    {
                        maxVotes = candidates[counter].votes;
                        winners[winnerCounter] = candidates[counter].name;
                        break;
                    }

                    winnerCounter++;
                    winners[winnerCounter] = currentCandidate;
                }

            }
            
            

        }
    
    if (sizeof(winners) == 1) {
        printf("The winner is %s with %d votes! Gratulation!\n", winners[0], maxVotes);

        return;
    } else
    {
        printf("The winners are: ");
        for (int winnerCounter = 0; winnerCounter < sizeof(winners) - 1; winnerCounter++) {
            printf("%s\n", winners[winnerCounter]);
        }
    }
    
}

void printCandidateCounts() {
    for (int counter = 0; counter < candidate_count; counter++) 
        {
            printf("!!%s: %d\n",candidates[counter].name, candidates[counter].votes);
        }
    
}

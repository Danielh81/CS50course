#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;


// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;


// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
bool is_candidate_already_ranked(int voter, int candidate_number);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // candidateUnique();

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    string name;
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            // Record vote, unless it's invalid
            do
            {
                name = get_string("Rank %i: ", j + 1);
            }
            while (!vote(i, j, name) || name[i] == '\'');
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("Its a tie between: ");
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for ( int candidate_counter = 0; candidate_counter < candidate_count; candidate_counter++)
    {
    bool areNamesEquals = strcmp(name, candidates[candidate_counter].name) == 0;
    if (areNamesEquals && !is_candidate_already_ranked(voter, candidate_counter + 1))
    {
        //printf("yay\n");
        preferences[voter][rank] = candidate_counter + 1;
        //printf("%d", preferences[voter][rank]);
        //printf(":: %s \n",candidates[candidate_counter].name);

        return true;
    }
    //printf("::- %s \n",candidates[candidate_counter].name);
    // printf("Vo : %s", numberOfVotes);
    }
    
    return false;
    
}


// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for ( int i = 0; i < voter_count; i++)
    {
        for ( int j = 0; j < candidate_count; j++)
        {
            int index = preferences[i][j] - 1;
            if (candidates[index].eliminated == false)
            {
                candidates[index].votes++;

                break;
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int halfVotes = voter_count / 2;
    for ( int i = 0; i < voter_count; i++)
    {
        if ( candidates[i].votes > halfVotes)
        {
            printf("Winner is %s with %i votes.\n", candidates[i].name, candidates[i].votes);
            return true;
        }

        if (voter_count == 1)
        {
            printf("Winner is %s with %i votes.\n", candidates[preferences[0][0] - 1].name, candidates[preferences[0][0] - 1].votes);
            return true;
        }

    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int minVotes = voter_count;
    for ( int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < minVotes && candidates[i].eliminated == false)
        {
            minVotes = candidates[i].votes;
        }
    }

    // printf("minvotes: %i", minVotes);
    return minVotes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for ( int i = 0; i < candidate_count; i++)
    {
        
        if (candidates[i].votes == min)
        {
            printf("%s",candidates[i].name);
            candidates[i].eliminated = true;
        }
    }
    
}

bool is_candidate_already_ranked(int voter, int candidate_number)
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        int candidate_index = preferences[voter][i];

        if (candidate_index != 0)
        {
            if (candidate_index == candidate_number)
            {
                return true;
            }
        }
    }
    return false;
}

// void candidateUnique(void)
// {
//     for (int i = 0; i < candidate_count; i++)
//     {
//         for (int j = 0; j < candidate_count; j++)
//         {
//             bool isUnequal = i != j;
//             bool candidateNamesAreEqual = strcmp(candidates[j].name, candidates[i].name) == 0;
//             if (candidateNamesAreEqual && isUnequal)
//             {
//                 printf("Name must be unique\n");
//                 break;
//             }
//         }
//     }
// }
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
    int margin;
}
pair;
pair swap;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
int margin;
int changes;
int hops;

// Function prototypes
bool checkcirc(int from, int to);
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            //printf("Name is in\n");
            ranks[rank] = i;
            //printf("Rank = %d\n", rank);
            return true;
        }
    }
    return false;
}
// TODO

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    /* Print Matrix */
    /*
        for (int i = 0; i < candidate_count; i++)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                printf("%d", preferences[i][j]);
            }
            printf("\n");
        }
    */

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            margin = preferences[i][j] - preferences[j][i];
            if (margin > 0)
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pairs[pair_count].margin = margin;
                //printf("%s %d, %s %d difference: %d\n", candidates[i], pairs[pair_count].winner, candidates[j], pairs[pair_count].loser, margin);
                pair_count++;
            }
            else if (margin < 0)
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pairs[pair_count].margin = -1 * margin;
                //printf("%s %d, %s %d difference: %d\n", candidates[j], pairs[pair_count].winner, candidates[i], pairs[pair_count].loser, -1*margin);
                pair_count++;
            }
            else if (margin == 0)
            {
                // Do nothing
                //printf("%s tied with %s at %d\n", candidates[i], candidates[j], margin);
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    do
    {
        changes = 0;
        for (int i = 0; i < pair_count; i++)
        {
            for (int j = i + 1; j < pair_count; j++)
            {
                if (pairs[i].margin < pairs[j].margin)
                {
                    swap = pairs[i];
                    pairs[i] = pairs[j];
                    pairs[j] = swap;
                    changes++;
                }
            }
        }
    }
    while (changes > 0);

    //fill array with winner preferences
    int sov[pair_count];

    for (int i = 0; i < pair_count; i ++)
    {
        sov[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    }

    //sorting functions
    int sov_temp;
    pair temporal;
    do
    {
        changes = 0;
        for (int i = 0; i < pair_count - 1; i++)
        {
            for (int j = i + 1; j < pair_count - 1; j++)
            {
                if (sov[i] < sov[j])
                {
                    temporal = pairs[i];
                    pairs[i] = pairs[j];
                    pairs[j] = temporal;

                    sov_temp = sov[j];
                    sov[j] = sov[i];
                    sov[i] = sov_temp;
                }
            }
        }
    }
    while (changes > 0);

    /*
        for (int i = 0; i < pair_count; i++)
        {
            printf("Winner: %d Loser: %d Margin %d\n", pairs[i].winner, pairs[i].loser, pairs[i].margin);
        }
    */
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
bool checkcirc(int from, int to)
{
    // first case
    if (from == to)
    {
        return true;// it forms a cycle
    }
    else
    {
        // second case
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[from][i])// next node is found
            {
                return checkcirc(i, to);
            }
        }
        return false;
    }
}


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int winner = 0;
    int loser = 0;
    for (int i = 0; i < pair_count; i++)
    {
        for (int a = 0; a < pair_count; a++)
        {
            locked[i][a] = false;
        }
    }

    for (int i = 0; i < pair_count; i++)
    {
        //printf("i: %d, Winner: %s, Loser: %s\n", i,pairs[i].winner, pairs[i].loser);
        for (int a = 0; a < candidate_count; a++)
        {
            if (a == pairs[i].winner)
            {
                //printf("Winner: %s, %d\n", candidates[a], a);
                winner = a;
            }
            if (a == pairs[i].loser)
            {
                //printf("Loser: %s, %d\n", candidates[a].name, a);
                loser = a;
            }
        } // Old version, not needed anymore
        hops = 0;

        if (checkcirc(loser, winner) == false)
        {
            locked[winner][loser] = true;
        }
        else
        {
            // circular, so do nothing
        }
    }
    //printgraph();
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int counter;
    for (int i = 0; i < candidate_count; i++)
    {
        counter = 0;
        for (int j = 0; j < candidate_count; j++)
        {

            if (locked[j][i] == false)
            {
                counter++;
            }
            if (counter == candidate_count)
            {
                printf("%s\n", candidates[i]);
            }
        }
    }
    return;
}

#include <bits/stdc++.h>
using namespace std;

// Structure to represent a job with its id, deadline, and profit
struct Job
{
    char id;
    int dead;
    int profit;
};

// Comparison function to sort jobs based on profit in descending order
bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

// Function to print the job scheduling with deadlines and profits
void printJobScheduling(Job arr[], int n)
{
    // Sort the jobs based on profit in descending order
    sort(arr, arr + n, comparison); 
    // how does sort(arr, arr + n, comparison) work?
    //it sorts the array arr of size n in descending order based on the comparison function

    // Arrays to store the final result and availability of time slots
    int result[n];
    bool slot[n];

    // Initialize all slots to be available
    for (int i = 0; i < n; i++)
        slot[i] = false;

    // Iterate through all the jobs and fill the time slots
    for (int i = 0; i < n; i++)
    {
        // Find the latest available time slot before the job's deadline
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                // Assign the job to the time slot
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    // Print the job sequence for maximum profit
    cout << "Job sequence for maximum profit: ";
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
}

int main()
{
    // Input the number of jobs
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    // Input job details: id, deadline, and profit
    Job arr[n];
    cout << "Enter the job id, deadline, and profit for each job: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
    }

    // Print the job sequence with maximum profit
    cout << "Following is the maximum profit sequence of jobs\n";
    printJobScheduling(arr, n);
    cout << endl;

    return 0;
}

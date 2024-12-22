#include <stdio.h>
#include <stdlib.h>

void scan(int requests[], int n, int head, char direction)
{
    int total = 0, temp, k, i, a = 1;
    int current = head;
    int alloted[n + 2];
    alloted[0] = head;
    for (i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (requests[j] > requests[j + 1])
            {
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
    if (direction == 'r')
    {
        k = 0;
        while (requests[k] < head)
        {
            k++;
        }
        int j = k - 1;
        for (i = k; i < n; i++)
        {
            total += abs(current - requests[i]);
            current = requests[i];
            alloted[a] = requests[i];
            a++;
        }
        total += abs(current - 199);
        current = 199;
        alloted[a] = 199;
        a++;
        for (int i = j; i >= 0; i--)
        {
            total += abs(current - requests[i]);
            current = requests[i];
            alloted[a] = requests[i];
            a++;
        }
    }
    else if (direction == 'l')
    {
        k = n-1;
        while (requests[k] > head)
        {
            k--;
        }
        int j = k + 1;
        for (i = k; i >= 0; i--)
        {
            total += abs(current - requests[i]);
            current = requests[i];
            alloted[a] = requests[i];
            a++;
        }
        total+=abs(current-0);
        current = 0;
        alloted[a] = 0;
        a++;
        for (int i = j; i < n; i++)
        {
            total += abs(current - requests[i]);
            current = requests[i];
            alloted[a] = requests[i];
            a++;
        }
    }

    printf("Head Movements: ");
    for (int i = 0; i < n + 2; i++)
    {
        printf("%d-->", alloted[i]);
    }
    printf("\nTotal head Movement = %d", total);
}

void main()
{
    int n, head;
    char direction;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }
    printf("Enter the disk head: ");
    scanf("%d", &head);
    printf("Enter the direction: ");
    scanf(" %c", &direction);
    scan(requests, n, head, direction);
}
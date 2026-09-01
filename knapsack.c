#include <stdio.h>

float knapsack(int weight[], int value[], int n, int capacity) {
    float ratio[n];
    float maxValue = 0;

    // Calculate ratio
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }

    // Sort by ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            if (ratio[i] < ratio[j]) {

                // Swap ratio
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap weight
                int t = weight[i];
                weight[i] = weight[j];
                weight[j] = t;

                // Swap value
                t = value[i];
                value[i] = value[j];
                value[j] = t;
            }
        }
    }

    // Greedy selection
    for (int i = 0; i < n; i++) {

        if (weight[i] <= capacity) {
            capacity -= weight[i];
            maxValue += value[i];
        }
        else {
            float fraction = (float)capacity / weight[i];

            maxValue += value[i] * fraction;

            break;
        }
    }

    return maxValue;
}

int main() {

    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value: ");
        scanf("%d %d", &weight[i], &value[i]);
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    printf("Maximum value = %.2f",
           knapsack(weight, value, n, capacity));

    return 0;
}

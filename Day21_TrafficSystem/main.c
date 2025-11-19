#include <stdio.h>
#define N 5     

void inputData(int id[], int speed[], int lane[]) {
    int tid[N]    = {1234, 5678, 9012, 3456, 7890};
    int tspeed[N] = {40, 90, 120, 75, 60};
    int tlane[N]  = {1, 3, 4, 2, 3};

    for (int i = 0; i < N; i++) {
        id[i] = tid[i];
        speed[i] = tspeed[i];
        lane[i] = tlane[i];
    }
}

int countSpeedViolations(int speed[]) {
    int c = 0;
    for (int i = 0; i < N; i++)
        if (speed[i] > 80) c++;
    return c;
}

int countLaneViolations(int id[], int lane[]) {
    int c = 0;
    for (int i = 0; i < N; i++)
        if (id[i] % 4 != lane[i]) c++;
    return c;
}

int busiestLane(int lane[]) {
    int cnt[5] = {0};
    for (int i = 0; i < N; i++) cnt[lane[i]]++;
    int max = 1;
    for (int i = 2; i <= 4; i++)
        if (cnt[i] > cnt[max]) max = i;
    return max;
}

int leastBusyLane(int lane[]) {
    int cnt[5] = {0};
    for (int i = 0; i < N; i++) cnt[lane[i]]++;
    int min = 1;
    for (int i = 2; i <= 4; i++)
        if (cnt[i] < cnt[min]) min = i;
    return min;
}

void displayReport(int id[], int speed[], int lane[]) {
    printf("VehID  Speed  Lane  SViol  LViol\n");
    for (int i = 0; i < N; i++) {
        int sv = speed[i] > 80;
        int lv = (id[i] % 4 != lane[i]);
        printf("%d  %4d   %2d     %d      %d\n",
               id[i], speed[i], lane[i], sv, lv);
    }
}

int main() {
    int id[N], speed[N], lane[N];

    inputData(id, speed, lane);
    displayReport(id, speed, lane);

    printf("\nSpeed Violations : %d", countSpeedViolations(speed));
    printf("\nLane Violations  : %d", countLaneViolations(id, lane));
    printf("\nBusiest Lane     : %d", busiestLane(lane));
    printf("\nLeast Busy Lane  : %d\n", leastBusyLane(lane));

    return 0;
}

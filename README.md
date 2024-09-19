Chakravyuh Problem Solution
Problem Overview
Abhimanyu, a warrior in the Mahabharata, is stuck in the innermost circle of the Chakravyuh, a maze of 11 circles guarded by enemies. Each enemy in these circles has a certain power. Abhimanyu has an initial power p and must defeat all the enemies or use his abilities to either skip or recharge to successfully escape the Chakravyuh.

The problem is to determine if Abhimanyu can escape by defeating or bypassing enemies, considering special abilities like skipping and recharging.

Given:
There are 11 enemies, each with power values k1, k2, ..., k11.
Abhimanyu has initial power p.
He can skip battling a enemies.
He can recharge his power b times.
Enemies at the 3rd and 7th positions can regenerate with half their initial power if Abhimanyu advances to the next circle.
Rules:
Abhimanyu loses power equal to the enemy’s power when battling.
He must have more power than the enemy to proceed.
He loses if he has less power and can’t recharge or skip.
Regenerating enemies (3rd and 7th) can attack again if Abhimanyu moves on to the next circle.
Solution Overview
This solution uses a recursive approach to simulate Abhimanyu's battle progression through the Chakravyuh. It includes conditions to fight, skip, or recharge based on Abhimanyu’s current power, skip count, and recharge count. If Abhimanyu can cross all the 11 circles, the program outputs "Yes", otherwise it outputs "No".

Algorithm
Recursion:

At each circle, Abhimanyu either fights the enemy if his current power is greater than or equal to the enemy’s power, skips the fight, or recharges his power and continues.
Enemy Regeneration:

The enemies at positions 3 and 7 can regenerate once with half their initial power, adding an additional challenge.
Base Case:

If Abhimanyu crosses all 11 circles, he wins, and the function returns true.
Power Comparison:

If Abhimanyu has less power than an enemy, he must either skip or recharge. If both options are exhausted, the function returns false.
Function Definitions
chakravyuh(vector<int>& powerOfEnemies, int initialPower, int skips, int recharge)
Parameters:
powerOfEnemies: A vector of 11 integers representing the power of each enemy.
initialPower: Initial power p of Abhimanyu.
skips: Number of times Abhimanyu can skip an enemy.
recharge: Number of times Abhimanyu can recharge his power.
Returns:
true if Abhimanyu can escape the Chakravyuh, false otherwise.
solve(vector<int>& powerOfEnemies, int initialPower, int enemyNo, int currPower, int skips, int recharge)
Parameters:

enemyNo: The index of the current enemy Abhimanyu is facing.
currPower: Abhimanyu's current power.
skips: Remaining skips available.
recharge: Remaining recharges available.
Returns:
true if Abhimanyu can proceed to the next circle, false otherwise.

Example Test Cases

vector<int> powerOfEnemies1 = {10, 14, 2, 3, 3, 3, 2, 3, 3, 3, 3};
    int p1 = 16;  // initial power of abhimanyu
    int a1 = 1;   // times abhimanyu can skip enemies
    int b1 = 2;   // times abhimanyu can recharge himself with power
    if(chakravyuh(powerOfEnemies1,p1,a1,b1))
        cout<<"Yes";
    else
        cout<<"No";
    cout<<endl;

vector<int> powerOfEnemies2 = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int p2 = 8;
    int a2 = 3;
    int b2 = 1;
    if(chakravyuh(powerOfEnemies2,p2,a2,b2))
        cout<<"Yes";
    else
        cout<<"No";
    cout<<endl;

Output:
Yes
No

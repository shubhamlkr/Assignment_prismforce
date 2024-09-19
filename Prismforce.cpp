#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>& powerOfEnemies, int initialPower, int enemyNo, int currPower, int skips, int recharge)
{
    if(enemyNo == 11)
    {
        // all enemies are passed
        return true;
    }
    if(currPower >= powerOfEnemies[enemyNo])
    {
        // fight
        bool ans1 = solve(powerOfEnemies, initialPower, enemyNo+1, currPower - powerOfEnemies[enemyNo], skips, recharge);
        bool ans2 = false;
        if(skips > 0)
        // skip
        ans2 = solve(powerOfEnemies, initialPower, enemyNo+1, currPower, skips-1, recharge);
        return ans1 || ans2;
    }
    else if(initialPower > powerOfEnemies[enemyNo])
    {
        bool ans1 = false, ans2 = false;
        if(recharge > 0)
        // recharge and fight
        ans1 = solve(powerOfEnemies, initialPower, enemyNo+1, initialPower-powerOfEnemies[enemyNo], skips, recharge-1);
        if(skips > 0)
        // skip
        ans2 = solve(powerOfEnemies, initialPower, enemyNo+1, currPower, skips-1, recharge);
        return ans1 || ans2;
    }
    else
    {
        if(skips > 0)
        // skip
        return solve(powerOfEnemies, initialPower, enemyNo+1, currPower, skips-1, recharge);
        else
        return false;
    }
}

bool chakravyuh(vector<int>& powerOfEnemies, int initialPower, int skips, int recharge)
{
    if(skips >= 11)
    {
        // abhimanyu can skip all the enemies
        return true;
    }
    powerOfEnemies[3] += powerOfEnemies[2]/2;
    powerOfEnemies[7] += powerOfEnemies[6]/2;

    return solve(powerOfEnemies, initialPower, 0, initialPower, skips, recharge);
}

int main()
{
    vector<int> powerOfEnemies1 = {10,14,2,3,3,3,2,3,3,3,3};
    int p1 = 16;  // initial power of abhimanyu
    int a1 = 1;  // times abhimanyu can skip enemies
    int b1 = 2;  // times abhimanyu can recharge himself with power
    if(chakravyuh(powerOfEnemies1,p1,a1,b1))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl;

    vector<int> powerOfEnemies2 = {11,10,9,8,7,6,5,4,3,2,1};
    int p2 = 8;
    int a2 = 3;
    int b2 = 1;
    if(chakravyuh(powerOfEnemies2,p2,a2,b2))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl;
    return 0;
}

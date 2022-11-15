/***
 * @authors
 *  Ousainou Jaiteh (2120216015)
 *  Moses Kargbo (2120216017)
 *  Maduekwe Dominic (2120216020)
 *
 ■ Super Egg Drop Introduction：

 You are given 𝑘 identical eggs and you have access to a building with 𝑛 floors labeled from 1 to 𝑛.
 You know that there exists a floor 𝑓 where 0 <= 𝑓 <= 𝑛 such that any egg dropped at a floor higher than 𝑓 will break,
 and any egg dropped at or below floor 𝑓 will not break. Each move, you may take an unbroken egg and drop it from any
 floor 𝑥 (where 1 <= 𝑥 <= 𝑛). If the egg breaks, you can no longer use it. However, if the egg does not break,
 you may reuse it in future moves. Return the minimum number of moves that you need to determine with certainty
 what the value of 𝑓 is.

 **/
import java.util.Scanner;
public class SuperEggDropTester {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter the of Number of Eggs: ");
        int eggs = input.nextInt();

        Scanner input2 = new Scanner(System.in);
        System.out.println("Enter the number of Floor:");
        int floor = input2.nextInt();

        System.out.println("This are Number of Attempts to Find The Pivot Point: " + superEggDrop(eggs,floor));

    }

    public static int superEggDrop(int K, int N) {
        // Right now, dp[i] represents dp(1, i)
        int[] dp = new int[N+1];
        for (int i = 0; i <= N; ++i)
            dp[i] = i;

        for (int k = 2; k <= K; ++k) {
            // Now, we will develop dp2[i] = dp(k, i)
            int[] dp2 = new int[N+1];
            int x = 1;
            for (int n = 1; n <= N; ++n) {
                /**
                    Let's find dp2[n] = dp(k, n)
                    Increase our optimal x while we can make our answer better.
                    Notice max(dp[x-1], dp2[n-x]) > max(dp[x], dp2[n-x-1])
                    is simply max(T1(x-1), T2(x-1)) > max(T1(x), T2(x)).
                 */
                while (x < n && Math.max(dp[x-1], dp2[n-x]) > Math.max(dp[x], dp2[n-x-1]))
                    x++;

                // The final answer happens at this x.
                dp2[n] = 1 + Math.max(dp[x-1], dp2[n-x]);
            }

            dp = dp2;
        }

        return dp[N];
    }
}

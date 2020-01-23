import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] argv){
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		BigInteger[][] dp=new BigInteger[200][200];
		int i, j, k;
		
		for(i=0; i<160; i++){
			for(j=0; j<160; j++)dp[i][j]=BigInteger.ZERO;
			dp[i][0]=dp[0][i]=dp[i][1]=dp[1][i]=BigInteger.ONE;
		}
		for(i=2; i<=150; i++){
			for(j=2; j<=150; j++){
				for(k=0; k<i; k++) dp[i][j]=dp[i][j].add(dp[k][j-1].multiply(dp[i-k-1][j]));
			}
		}
		while(cin.hasNext()){
			int n=cin.nextInt();
			int d=cin.nextInt();
			n>>=1;
			System.out.println(dp[n][d].subtract(dp[n][d-1]));
		}
	}
}

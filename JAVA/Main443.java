import java.util.Scanner;
public class Main{
	public static int min(int a, int b){
		return a>b?b:a;
	}
	public static void main(String[] argv){
		int[] result=new int[6000];
		String result1;
		int count, loc2, loc3, loc5, loc7;
		int temp2, temp3, temp5, temp7, num, temp;
		Scanner in=new Scanner(System.in);
		result[1]=1; count=1; loc2=loc3=loc5=loc7=1;
		while(count<=5842){
			temp2=result[loc2]*2;
			temp3=result[loc3]*3;
			temp5=result[loc5]*5;
			temp7=result[loc7]*7;
			temp=min(min(temp2,temp3),min(temp5,temp7));
			if(temp>result[count]) result[++count]=temp;
			if(temp==temp2) ++loc2;
			else if(temp==temp3) ++loc3;
			else if(temp==temp5) ++loc5;
			else ++loc7;
		}
		while(in.hasNextInt()){
			num=in.nextInt();
			if(num==0) break;
			result1="The "+Integer.toString(num);
			if(num%10==1 && num%100!=11) result1+="st";
			else if(num%10==2 && num%100!=12) result1+="nd";
			else if(num%10==3 && num%100!=13) result1+="rd";
			else result1+="th";
			System.out.println(result1+" humble number is "+result[num]+".");
		}
	}
}
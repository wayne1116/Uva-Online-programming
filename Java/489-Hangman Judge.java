import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		int i=0, length=0, count=0, round, target;
		String answer, guess;
		boolean[] flag2=new boolean[26];
		int[] flag1=new int[26];
		
		while(in.hasNextInt()){
			round=in.nextInt();
			if(round==-1) break;
			answer=in.next();
			guess=in.next();
			length=answer.length();
			count=0;
			for(i=0; i<26; i++){
				flag1[i]=0;
				flag2[i]=false;
			}
			for(i=0; i<answer.length(); i++) ++flag1[answer.charAt(i)-97];
			for(i=0; i<guess.length(); i++){
				target=(int)guess.charAt(i)-97;
				if(flag1[target]==0 && !flag2[target]){
					++count;
					flag2[target]=true;
					if(count==7) break;
				}
				else if(flag1[target]>0 && !flag2[target]){
					flag2[target]=true;
					length-=flag1[target];
					if(length==0) break;
				}
			}
			System.out.println("Round "+round);
			if(length==0) System.out.println("You win.");
			else if(count==7) System.out.println("You lose.");
			else System.out.println("You chickened out.");
		}
	}
}

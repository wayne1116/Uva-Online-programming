import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		String input;
		Scanner in=new Scanner(System.in);
		int[] result=new int[1024];
		int i=0, j=0, carry=0;
		for(i=0; i<1024; i++) result[i]=0;
		while(true){
			input=in.next();
			if(input.equals("0")) break;
			for(i=input.length()-1, j=0; i>=0; i--, j++){
				result[j]=result[j]+(input.charAt(i)-48);
			}
		}
		carry=0;
		for(i=0; i<1023; i++){
			if(result[i]>9){
				carry=result[i]/10;
				result[i]=result[i]%10;
				result[i+1]=result[i+1]+carry;
			}
		}
		for(i=1023; i>=0; i--) if(result[i]!=0) break;
		for(j=i; j>=0; j--) System.out.print(result[j]);
		System.out.println();
	}
}

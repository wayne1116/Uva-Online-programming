import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		int[] count=new int[52];
		int i=0, max=0;
		String line;
		while(in.hasNext()){
			line=in.nextLine();
			for(i=0; i<52; i++) count[i]=0;
			for(i=0; i<line.length(); i++){
				if(line.charAt(i)>='A' && line.charAt(i)<='Z') count[line.charAt(i)-65]++;
				else if(line.charAt(i)>='a' && line.charAt(i)<='z') count[line.charAt(i)-71]++;
			}
			max=0;
			for(i=0; i<52; i++) if(max<count[i]) max=count[i];
			for(i=0; i<52; i++) if(max==count[i]) System.out.printf("%c", i>=26?i+71:i+65);
			System.out.println(" "+max);
		}
	}
}

import java.util.Scanner;
import java.util.Arrays;
class Lnode implements Comparable<Lnode>{
	public int s;
	public int num;
	public int compareTo(Lnode other){
		if(other.num==this.num) return this.s-other.s;
		return other.num-this.num;
	}
}
public class Main{
	public static void main(String[] argv){
		Lnode[] lnode=new Lnode[26];
		Scanner in=new Scanner(System.in);
		String line;
		int i=0, a=0;
		a=in.nextInt(); in.nextLine();
		for(i=0; i<26; i++){
			lnode[i]=new Lnode();
			lnode[i].s=65+i;
			lnode[i].num=0;
		}
		while(a-->0){
			line=in.nextLine();
			for(i=0; i<line.length(); i++){
				if(line.charAt(i)>='a' && line.charAt(i)<='z') ++lnode[(int)(line.charAt(i))-97].num;
				else if(line.charAt(i)>='A' && line.charAt(i)<='Z') ++lnode[(int)(line.charAt(i))-65].num;
			}
		}
		Arrays.sort(lnode);
		i=0;
		while(lnode[i].num!=0){
			System.out.println((char)lnode[i].s+" "+lnode[i].num);
			++i;
		}
	}
}

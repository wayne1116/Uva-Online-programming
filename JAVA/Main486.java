import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		int result=0, sum1=0, i=0, mul;
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			String[] line=in.nextLine().split(" ");
			mul=1;
			if(line[0].equals("negative")) mul=-1;
			result=0; sum1=0;
			for(i=0; i<line.length; i++){
				if(line[i].equals("zero"))sum1+=0;
				else if(line[i].equals("one"))sum1+=1;
				else if(line[i].equals("two"))sum1+=2;
				else if(line[i].equals("three")) sum1+=3;
				else if(line[i].equals("four")) sum1+=4;
				else if(line[i].equals("five")) sum1+=5;
				else if(line[i].equals("six")) sum1+=6;
				else if(line[i].equals("seven")) sum1+=7;
				else if (line[i].equals("eight")) sum1+=8;
				else if (line[i].equals("nine")) sum1+=9;
				else if (line[i].equals("ten")) sum1+=10;
				else if (line[i].equals("eleven")) sum1+=11;
				else if (line[i].equals("twelve")) sum1+=12;
				else if (line[i].equals("thirteen")) sum1+=13;
				else if (line[i].equals("fourteen")) sum1+=14;
				else if (line[i].equals("fifteen")) sum1+=15;
				else if( line[i].equals("sixteen")) sum1+=16;
				else if( line[i].equals("seventeen")) sum1+=17;
				else if( line[i].equals("eighteen")) sum1+=18;
				else if (line[i].equals("nineteen")) sum1+=19;
				else if (line[i].equals("twenty")) sum1+=20;
				else if (line[i].equals("thirty")) sum1+=30;
				else if (line[i].equals("forty")) sum1+=40;
				else if (line[i].equals("fifty")) sum1+=50;
				else if (line[i].equals("sixty")) sum1+=60;
				else if (line[i].equals("seventy")) sum1+=70;
				else if (line[i].equals("eighty")) sum1+=80;
				else if (line[i].equals("ninety")) sum1+=90;
				else{
					if(line[i].equals("hundred"))sum1*=100;
					else if(line[i].equals("thousand")){
						sum1*=1000;
						result+=sum1;
						sum1=0;
					}
					else if(line[i].equals("million")){
						sum1*=1000000;
						result+=sum1;
						sum1=0;
					}
				}
			}
			System.out.println((result+sum1)*mul);
		}
	}
}
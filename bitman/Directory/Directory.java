import java.util.*;

public class Directory{
	ArrayList<Person> personList = new ArrayList<>();
	
	public static void main(String[] arg){
		DirectoryTips dt = new DirectoryTips();
		dt.showTips();
	}
}

class DirectoryTips{
	private int choice;
	private ChoiceManager cm = new ChoiceManager();
	
	public void showTips(){
		System.out.println("-----------Directory Manager------------");
		System.out.println("<1> Add to Directory");
		System.out.println("<2> Delete Directory");
		System.out.println("<3> Search Directory");
		System.out.println("<4> Show Directory");
		System.out.println("<5> Back");
			
		while(true){
			System.out.println("------------------------------------------");
			System.out.println("\n>>> Please enter 0-5,others are invalid.>>>");
		
			try{
				Scanner getChoice = new Scanner(System.in);
				choice = getChoice.nextInt(); // get user's choice
			}catch(InputMismatchException e){
				System.out.println(">> Invalid Input!");
			}
			
			if(choice != 5){
				cm.manageChoice(choice);
				choice = -1; /** If I don't do this,there will be a singular BUG
								when the user enters something unexpected. **/
			}
			else
				break;
		}
	}
}

class ChoiceManager{
	Directory directory = new Directory();
	
	public void manageChoice(int inChoice){
		switch(inChoice){
			case 1:
				addInformation();
				break;
		
			case 2:
				delInformation();
				break;
			
			case 3:
				searchInformation();
				break;
				
			case 4:
				if(directory.personList.size() == 0)
					System.out.println(">> No Record in the Directory");
				else
					showInformation();
			
				break;
		}
	}
		
	private void addInformation(){
		String inName = null;
		String inTelephone = null;
		Scanner sc = new Scanner(System.in);
		
		inName = getName(inName, sc);
		inTelephone = getTel(inTelephone, sc);
		
		Person ref = new Person(inName, inTelephone);
		directory.personList.add(ref);
	}
	
	private String getName(String inName, Scanner sc){
		System.out.print("\nPlease enter the name: ");
		inName = sc.nextLine();
		
		return inName;
	}
	
	private String getTel(String inTelephone, Scanner sc){
		System.out.print("Please enter the telephone number: ");
		inTelephone = sc.nextLine();
		
		return inTelephone;
	}
		
	private void delInformation(){
		int delChoice = -1;
	
		if(directory.personList.size() == 0)
			System.out.println(">> No Record in the Directory");
		else{
			System.out.println("------------------------------------------");
			System.out.println("\nAll the person's information is as following,"+
					"you can enter the order number to delete the matching one."+
					"If you need to delete all the records,enter \"0\"."+
					"If you are meant to return,please enter any character other than the order number and \"0\".");
			System.out.println("------------------------------------------");
		
			showInformation();
			System.out.println("");
		
			try{
				Scanner sc = new Scanner(System.in);
				delChoice = sc.nextInt();
			}catch(InputMismatchException e){
				;
			}
			judgeChoice(delChoice);
		}
	}
	
	private void judgeChoice(int delChoice){
		if(delChoice == 0){
			directory.personList.clear();
			System.out.println(">> Deleted! Enter \"4\" to check the result.");
		}
		else if(delChoice-1 < directory.personList.size() && delChoice-1 >= 0){
			directory.personList.remove(delChoice-1);
			System.out.println(">> Deleted! Enter \"4\" to check the result.");
		}
		else
			;
	}
	
	private void searchInformation(){
		String type;
					   
		if(directory.personList.size() == 0){
			System.out.println(">> No Record in the Directory");
		}else{
			System.out.println("------------------------------------------");
			System.out.println("<A> Enter \"A\" to search via name\n"+
							   "<B> Enter \"B\" to search via telephone number");
			type = new Scanner(System.in).nextLine();
			searchType(type);			
		}
	}
	
	private void searchType(String type){
		String tmpName;
		String tmpTel;
		Scanner sc = new Scanner(System.in);
		
		if(type.equals("a") || type.equals("A")){
			System.out.print("Please enter the name to search: ");
			tmpName = sc.nextLine();
		
			nameIterator(tmpName);
		}
		else if(type.equals("b") || type.equals("B")){
			System.out.print("Please enter the telephone number to search: ");
			tmpTel = sc.nextLine();
		
			telIterator(tmpTel);
		}else
			System.out.println(">> Invalid Input!Unable to search!");
	}
	
	private void nameIterator(String info){
		Person tmp = null;
		int j;
		int count;
		boolean flag = false;
					   
		for(j = 0, count = 0; j < directory.personList.size() && !flag; j++){
			tmp = directory.personList.get(j);
		
			if(tmp.name.equals(info)){
				count++;
				flag = true; // Once the target found, end the loop
				System.out.println("------------------------------------------");
				System.out.println("\nSearching...");
				System.out.println("Name: " + tmp.name);
				System.out.println("Telephone Number: " + tmp.telephone);
			}
		}
		if(count == 0)
			System.out.println("Not Found!");
	}
	
	private void telIterator(String info){
		Person tmp = null;
		int j;
		int count;
		boolean flag = false;
					   
		for(j = 0, count = 0; j < directory.personList.size() && !flag; j++){
			tmp = directory.personList.get(j);
		
			if(tmp.telephone.equals(info)){
				count++;
				flag = true; // Once the target found, end the loop
				System.out.println("------------------------------------------");
				System.out.println("\nSearching...");
				System.out.println("Name: " + tmp.name);
				System.out.println("Telephone Number: " + tmp.telephone);
			}
		}
		if(count == 0)
			System.out.println("Not Found!");
	}
	
	private void showInformation(){
		System.out.print("\n------------------------------------------");
		for(int i = 0; i < directory.personList.size(); i++){
			Person tmp = directory.personList.get(i);
			System.out.println("\nPerson " + (i+1) + ":");
			System.out.println("Name: " + tmp.name);
			System.out.println("Telephone Number: " + tmp.telephone);
		}
	}
}

class Person{
	String name;
	String telephone;
	
	public Person(String inName, String inTelephone){
		name = inName;
		telephone = inTelephone;
	}
}
import java.util.*;

public class DirectoryConsole{
	public static void main(String[] arg){
		new TipsManager();
	}
}

class TipsManager{
	private ChoiceManager cm = new ChoiceManager();
	boolean flag = true;

	
	public TipsManager(){
		System.out.println("\n----------------Directory-------------------");
		System.out.println("<1> Add to Directory");
		System.out.println("<2> Delete Directory");
		System.out.println("<3> Search Directory");
		System.out.println("<4> Show Directory");
		System.out.println("<5> Back to the menu");
		System.out.println("<6> Exit");
			
		while(flag){
			System.out.println("--------------------------------------------");
			System.out.println("\n>>> Please enter 0-6,others are invalid.>>>");
			
			cm.manageChoice(cm.getChoice());
		}
	}
}

class ChoiceManager{
	private int choice;
	private PersonManager pm = new PersonManager();

	public int getChoice(){
		
		try{
			this.choice = new Scanner(System.in).nextInt();
		}catch(InputMismatchException e){
			this.choice = -1;
		}
		return this.choice;
	}
	
	public void manageChoice(int inChoice){
		
		switch(inChoice){
			case 1:
				pm.addInformation();
				break;
		
			case 2:
				pm.delInformation();
				break;
			
			case 3:
				pm.searchInformation();
				break;
				
			case 4:
				pm.showInformation();
				break;
				
			case 5:
				new TipsManager().flag = false;
				break;
				
			case 6:
				System.exit(0);
				
			default:
				System.out.println(">> Invalid Input!");
				break;
		}
	}
}

class PersonManager extends Directory{
	private Scanner sc = new Scanner(System.in);
	
	public void addInformation(){
		String inName = null;
		String inTelephone = null;
		
		inName = getName(inName, sc);
		inTelephone = getTel(inTelephone, sc);
		
		Person ref = new Person(inName, inTelephone);
		super.personList.add(ref);
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
	
	public void delInformation(){
		int delChoice = -1;
		
		if(!sizeJudger())
			return;
	
		delTips();
		try{
			delChoice = sc.nextInt();
		}catch(InputMismatchException e){
			System.out.println(">> Invalid Input!");
		}
		
		if(delChoice == 0){
			super.personList.clear();
			System.out.println(">> Deleted!");
		}
		else if(delChoice-1 < super.personList.size() && delChoice-1 >= 0){
			super.personList.remove(delChoice-1);
			System.out.println(">> Deleted!");
		}
	}
	
	private void delTips(){
		System.out.println("------------------------------------------");
		System.out.println("\nAll the person's information is as following,"+
				"you can enter the order number to delete the matching one."+
				"If you need to delete all the records,enter \"0\"."+
				"If you want to return,please enter any character other than the order number and \"0\".");
		System.out.println("------------------------------------------");
	
		showInformation();
		System.out.println("");
	}
	
	
	public void searchInformation(){
		String type;
		
		if(!sizeJudger())
			return;
		
        searchTips();		
		type = sc.nextLine();
		searchType(type);
	}
	
	private void searchTips(){
		System.out.println("------------------------------------------");
		System.out.println("<A> Enter \"A\" to search via name\n"+
						   "<B> Enter \"B\" to search via telephone number");
	}
	
	private void searchType(String type){
		String tmpName;
		String tmpTel;
		
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
			System.out.println(">> Invalid Input!");
	}
	
	public void showInformation(){
		sizeJudger();
		
		System.out.print("\n--------------------------------------------");
		for(int i = 0; i < super.personList.size(); i++){
			Person tmp = super.personList.get(i);
			System.out.println("\nPerson " + (i+1) + ":");
			System.out.println("Name: " + tmp.name);
			System.out.println("Telephone Number: " + tmp.telephone);
		}
	}
	
	private void nameIterator(String info){
		Person tmp = null;
		int j;
		int count;
		boolean flag = false;
					   
		for(j = 0, count = 0; j < super.personList.size() && !flag; j++){
			tmp = super.personList.get(j);
		
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
					   
		for(j = 0, count = 0; j < super.personList.size() && !flag; j++){
			tmp = super.personList.get(j);
		
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
	
	private boolean sizeJudger(){
		if(super.personList.isEmpty()){
			System.out.println(">> No Record in the Directory");
			return false;
		}else
			return true;
	}
}

class Directory{
	protected ArrayList<Person> personList = new ArrayList<>();
}

class Person{
	String name;
	String telephone;
	
	public Person(String inName, String inTelephone){
		name = inName;
		telephone = inTelephone;
	}
}